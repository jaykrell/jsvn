#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ITERATIONS 10000000
#define TIME_REGULAR_HEAP 0 /* too many iterations make this too slow */
#define TIME_HEAP_CREATE 1

//BigLifoHeapLikeStack beats BigAlloca and BigStack by a lot here
//#define BIG_ALLOCATION_SIZE 100000
//#define BIG_ALLOCATION_SIZE 16000
//#define BIG_ALLOCATION_SIZE 60000
//#define BIG_ALLOCATION_SIZE 0x10000
#define BIG_ALLOCATION_SIZE 0xf000

#define STACK_SIZE 0
//#define STACK_SIZE 0x10000

#ifdef __cplusplus
extern "C" {
#endif

void* __cdecl _alloca(size_t a);
UINT64 __cdecl __rdtsc(void);

#pragma function(strlen)
#pragma intrinsic(_alloca)
#pragma intrinsic(__rdtsc)

void * volatile no_opt;

size_t
GetStackReserve(
    void
    );

void SmallStack(void)
{
  char a[100];
  no_opt = a;
  no_opt = a; // fairness with the tests that store twice
}

void BigStack(void)
{
  char a[BIG_ALLOCATION_SIZE];
  no_opt = a;
  no_opt = a; // fairness with the tests that store twice
}

void SmallAlloca(void)
{
  char* a = (char*) _alloca(100);
  no_opt = a;
  no_opt = a; // fairness with the tests that store twice
}

void BigAlloca(void)
{
  char* a = (char*) _alloca(BIG_ALLOCATION_SIZE);
  no_opt = a;
  no_opt = a; // fairness with the tests that store twice
}

void SmallMalloc(void)
{
  char* a = (char*) malloc(100);
  no_opt = a;
  no_opt = a; // fairness with the tests that store twice
  free(a);
}

void BigMalloc(void)
{
  char* a = (char*) malloc(BIG_ALLOCATION_SIZE);
  no_opt = a;
  no_opt = a; // fairness with the tests that store twice
  free(a);
}

typedef struct LifoHeapLikeStack_t {
    char* Block;
    size_t Reserve;
    size_t Commit;
    size_t Current;
    size_t PageSize;
    size_t CommitGrowthSize;
} LifoHeapLikeStack_t;

SYSTEM_INFO SystemInfo;

void
MyGetSystemInfo(
    void
    )
{
    if (SystemInfo.dwPageSize == 0)
        GetSystemInfo(&SystemInfo);
}

size_t
GetPageSize(
    void
    )
{
    MyGetSystemInfo();
    return SystemInfo.dwPageSize;
}

size_t
GetAllocationGranularity(
    void
    )
{
    MyGetSystemInfo();
    return SystemInfo.dwAllocationGranularity;
}

BOOL
LifoHeapLikeStack_Create(
    LifoHeapLikeStack_t* OutHeap
    )
{
    LifoHeapLikeStack_t Heap = { 0 };
    BOOL Result = FALSE;

    *OutHeap = Heap;
#if 1
    Heap.Reserve = GetStackReserve();
    Heap.PageSize = GetPageSize();
    Heap.CommitGrowthSize = (Heap.PageSize * 16);
    Heap.Block = (char*) VirtualAlloc(NULL, Heap.Reserve, MEM_RESERVE, PAGE_READWRITE);
    if (Heap.Block == NULL)
        goto Exit;
#else
    Heap.Reserve = GetStackReserve();
    Heap.Commit = Heap.Reserve;
    Heap.Block = (char*) VirtualAlloc(NULL, Heap.Reserve, MEM_COMMIT, PAGE_READWRITE);
    if (Heap.Block == NULL)
        goto Exit;
    *Heap.Block = *Heap.Block;
#endif

    Result = TRUE;
Exit:
    if (Result)
        *OutHeap = Heap;
    return Result;
}

void
LifoHeapLikeStack_Destroy(
    LifoHeapLikeStack_t* Heap
    )
{
    if (Heap->Block != NULL)
    {
        VirtualFree(Heap->Block, 0, MEM_RELEASE);
        ZeroMemory(Heap, sizeof(*Heap));
    }
}

#ifdef _WIN64
#define ALLOCATION_GRANULARITY 16
#else
#define ALLOCATION_GRANULARITY 8
#endif

void*
LifoHeapLikeStack_Alloc(
    LifoHeapLikeStack_t* Heap,
    size_t Size
    )
{
    size_t Current;
    char* NextCommitBlock;
    size_t CommitGrowthSize;
    size_t Commit;
    char* Block;

    Block = Heap->Block;
    Commit = Heap->Commit;
    Current = Heap->Current;
    Size = ((Size + ALLOCATION_GRANULARITY - 1) & ~ALLOCATION_GRANULARITY);

    if ((Current + Size) <= Commit)
    {
        Heap->Current = (Current + Size);
        return (Block + Current);
    }
    CommitGrowthSize = Heap->CommitGrowthSize;
    NextCommitBlock = NULL;
    if (Size <= CommitGrowthSize)
    {
        NextCommitBlock = (char*) VirtualAlloc(Block + Commit, CommitGrowthSize, MEM_COMMIT, PAGE_READWRITE);
    }
    if (NextCommitBlock == NULL)
    {
        // fallback to allocating a block of the requested size
        size_t AllocationGranularity = GetAllocationGranularity();
        CommitGrowthSize = Size;
        CommitGrowthSize = (CommitGrowthSize + AllocationGranularity - 1);
        CommitGrowthSize -= (CommitGrowthSize % AllocationGranularity);
        NextCommitBlock = (char*) VirtualAlloc(Block + Commit, CommitGrowthSize, MEM_COMMIT, PAGE_READWRITE);
        if (NextCommitBlock == NULL)
            return NULL;
    }
    Heap->Current = (Current + Size);
    Heap->Commit += CommitGrowthSize;
    return NextCommitBlock;
}

void
LifoHeapLikeStack_Free(
    LifoHeapLikeStack_t *Heap,
    void* Block,
    size_t Size
    )
{
    Size = ((Size + ALLOCATION_GRANULARITY - 1) & ~ALLOCATION_GRANULARITY);
    Heap->Current -= Size;
}

typedef struct LifoHeapBlock_t {
    char* Block;
    size_t Size;
    size_t Current;
} LifoHeapBlock_t;

typedef struct LifoHeap_t {
    LifoHeapBlock_t* Blocks;
    size_t Size;
    size_t Current;
} LifoHeap_t;

size_t
GetStackReserve(
    void
    )
{
    size_t Size = 0;
    void* AllocationBase;
    MEMORY_BASIC_INFORMATION Info;

    VirtualQuery(&Info, &Info, sizeof(Info));

    Info.RegionSize = 0;
    AllocationBase = Info.AllocationBase;
    Info.BaseAddress = AllocationBase;

    while (TRUE)
    {
        if (!VirtualQuery((char*) Info.BaseAddress + Info.RegionSize, &Info, sizeof(Info)))
            break;
        if (Info.AllocationBase == AllocationBase)
            Size += Info.RegionSize;
        else
            break;
    }
    return Size;
}

void
CommitStack(
    void
    )
{
    // This is wrong. Don't use in production.
    void* AllocationBase;
    MEMORY_BASIC_INFORMATION Info;

    VirtualQuery(&Info, &Info, sizeof(Info));

    Info.RegionSize = 0;
    AllocationBase = Info.AllocationBase;
    Info.BaseAddress = AllocationBase;

    while (TRUE)
    {
        if (!VirtualQuery((char*) Info.BaseAddress + Info.RegionSize, &Info, sizeof(Info)))
            break;
        if (Info.AllocationBase == AllocationBase)
            VirtualAlloc(Info.BaseAddress, Info.RegionSize, MEM_COMMIT, PAGE_READWRITE);
        else
            break;
    }
}

size_t
GetCurrentStackCommit(
    void
    )
{
    MEMORY_BASIC_INFORMATION Info;
    VirtualQuery(&Info, &Info, sizeof(Info));
    return Info.RegionSize;
}

void
LifoHeap_Create(
    LifoHeap_t *Heap
    )
{
}

void
LifoHeap_Destroy(
    LifoHeap_t *Heap
    )
{
}

void*
LifoHeap_Alloc(
    LifoHeap_t *Heap,
    size_t Size
    )
{
    LifoHeapBlock_t Block;
    LifoHeapBlock_t* pBlock;
    size_t NextNumberOfBlocks;
    size_t NextBlockSize;
    char* NextBlock;

    pBlock = &Heap->Blocks[Heap->Current];
    Block = *pBlock;
    if ((Block.Size - Block.Current) >= Size)
    {
        pBlock->Current = (Block.Current + Size);
        return (Block.Block + Block.Current);
    }

    pBlock = (LifoHeapBlock_t*) realloc(Heap->Blocks, (sizeof(LifoHeapBlock_t*) * (NextNumberOfBlocks = (Heap->Size + 1)) * 2));
    if (pBlock == NULL)
    {
        pBlock = (LifoHeapBlock_t*) realloc(Heap->Blocks, (sizeof(LifoHeapBlock_t*) * (NextNumberOfBlocks = (Heap->Size + 1))));
        if (pBlock == NULL)
        {
            return NULL;
        }
    }
    Heap->Blocks = pBlock;
    Heap->Size = NextNumberOfBlocks;
    if (Size < 0x10000)
    {
        NextBlockSize = 0x10000;
    }
    else
    {
        NextBlockSize = Size;
    }
    NextBlock = (char*) malloc(NextBlockSize);
    if (NextBlock == NULL)
    {
        return NULL;
    }
    Heap->Current += 1;
    Block.Block = NextBlock;
    Block.Size = NextBlockSize;
    Block.Current = Size;
    pBlock = &Heap->Blocks[Heap->Current];
    *pBlock = Block;
    return NextBlock;
}

void
LifoHeap_Free(
    LifoHeap_t *Heap,
    void* Block,
    size_t Size
    )
{
    if ((Heap->Blocks[Heap->Current].Current -= Size) == 0)
    {
        Heap->Current -= (Heap->Current != 0);
    }
}

void
SmallLifoHeapLikeStack(
    LifoHeapLikeStack_t* Heap
    )
{
  char b[10]; // ensure /GS slows this down like the others
  char* a = (char*) LifoHeapLikeStack_Alloc(Heap, 100);
  no_opt = a;
  no_opt = b;
  LifoHeapLikeStack_Free(Heap, a, 100);
}

void
BigLifoHeapLikeStack(
    LifoHeapLikeStack_t* Heap
    )
{
  char b[10]; // ensure /GS slows this down like the others
  char* a = (char*) LifoHeapLikeStack_Alloc(Heap, BIG_ALLOCATION_SIZE);
  no_opt = a;
  no_opt = b;
  LifoHeapLikeStack_Free(Heap, a, BIG_ALLOCATION_SIZE);
}

unsigned long __readfsdword(unsigned long Offset);
#pragma intrinsic(__readfsdword)

__declspec(naked)
void*
_chkstk(
    void/*size_t Size*/
    )
{
__asm
{
#if 0 // original
    push    ecx
    lea     ecx,[esp+4]
    sub     ecx,eax
    sbb     eax,eax
    not     eax
    and     ecx,eax
    mov     eax,esp
    and     eax,0x0FFFFF000

L1:
    cmp     ecx,eax
    jb L2

    mov     eax,ecx
    pop     ecx
    xchg    eax,esp
    mov     eax,dword ptr [eax]
    mov     dword ptr [esp],eax
    ret

L2:
    sub     eax,0x1000
    test    dword ptr [eax],eax
    jmp     L1
#else
    push    ecx
    lea     ecx,[esp+4]
    sub     ecx,eax
    sbb     eax,eax
    not     eax
    and     ecx,eax
    mov     eax,esp
    and     eax,0x0FFFFF000

L1:
    cmp     ecx,eax
    jb L2

    mov     eax,ecx
    pop     ecx
    xchg    eax,esp
    mov     eax,dword ptr [eax]
    mov     dword ptr [esp],eax
    ret

L2:
    sub     eax,0x1000
    test    dword ptr [eax],eax
    jmp     L1
#endif
}
}

volatile UINT64 Duration;
volatile HANDLE DoneEvent;

DWORD
__stdcall
ThreadMain(
    void * VoidParameter
    )
{
    void (*a)(void*) = (void (*)(void*)) VoidParameter;
    UINT32 b;
    UINT64 TimeStart;
    UINT64 TimeEnd;
    LifoHeapLikeStack_t Heap = { 0 };

    //printf("StackReserve: %x\n", GetStackReserve());
    //printf("CurrentStackCommit: %x\n", GetCurrentStackCommit());
    CommitStack();

#if TIME_HEAP_CREATE
    TimeStart = __rdtsc();
#endif

    if (a == (void*) SmallLifoHeapLikeStack || a == (void*) BigLifoHeapLikeStack)
    {
        LifoHeapLikeStack_Create(&Heap);
    }

#if !TIME_HEAP_CREATE
    TimeStart = __rdtsc();
#endif

    for (b = 0 ; b != ITERATIONS ; ++b)
    {
        a(&Heap);
    }

#if !TIME_HEAP_CREATE
    TimeEnd = __rdtsc();
#endif

    LifoHeapLikeStack_Destroy(&Heap);

#if TIME_HEAP_CREATE
    TimeEnd = __rdtsc();
#endif

    Duration = (TimeEnd - TimeStart);

    SetEvent(DoneEvent);

    // don't exit, keep this stack, so the next thread gets a different one
    Sleep(INFINITE);

    return 0;
}

int
main()
{
    char* a;
    HANDLE ThreadHandle;
    DWORD ThreadId;

    DoneEvent = CreateEventW(NULL, TRUE, FALSE, NULL);

    printf("StackReserve: %x\n", GetStackReserve());
    printf("CurrentStackCommit: %x\n", GetCurrentStackCommit());

#define SPLIT_UINT64(x) (UINT32) (x>>32), ((UINT32) (x & ~(UINT32)0))

    ResetEvent(DoneEvent);
    ThreadHandle = CreateThread(NULL, STACK_SIZE, ThreadMain, SmallStack, 0, &ThreadId);
    WaitForSingleObject(DoneEvent, INFINITE);
    CloseHandle(ThreadHandle);
    printf("SmallStack %08x`%08x\n", SPLIT_UINT64(Duration));

    ResetEvent(DoneEvent);
    ThreadHandle = CreateThread(NULL, STACK_SIZE, ThreadMain, BigStack, 0, &ThreadId);
    WaitForSingleObject(DoneEvent, INFINITE);
    CloseHandle(ThreadHandle);
    printf("BigStack %08x`%08x\n", SPLIT_UINT64(Duration));

    ResetEvent(DoneEvent);
    ThreadHandle = CreateThread(NULL, STACK_SIZE, ThreadMain, SmallAlloca, 0, &ThreadId);
    WaitForSingleObject(DoneEvent, INFINITE);
    CloseHandle(ThreadHandle);
    printf("SmallAlloca %08x`%08x\n", SPLIT_UINT64(Duration));

    ResetEvent(DoneEvent);
    ThreadHandle = CreateThread(NULL, STACK_SIZE, ThreadMain, BigAlloca, 0, &ThreadId);
    WaitForSingleObject(DoneEvent, INFINITE);
    CloseHandle(ThreadHandle);
    printf("BigAlloca %08x`%08x\n", SPLIT_UINT64(Duration));

#if TIME_REGULAR_HEAP

    ResetEvent(DoneEvent);
    ThreadHandle = CreateThread(NULL, STACK_SIZE, ThreadMain, SmallMalloc, 0, &ThreadId);
    WaitForSingleObject(DoneEvent, INFINITE);
    CloseHandle(ThreadHandle);
    printf("SmallMalloc %08x`%08x\n", SPLIT_UINT64(Duration));

    ResetEvent(DoneEvent);
    ThreadHandle = CreateThread(NULL, STACK_SIZE, ThreadMain, BigMalloc, 0, &ThreadId);
    WaitForSingleObject(DoneEvent, INFINITE);
    CloseHandle(ThreadHandle);
    printf("BigMalloc %08x`%08x\n", SPLIT_UINT64(Duration));

#endif

    ResetEvent(DoneEvent);
    ThreadHandle = CreateThread(NULL, STACK_SIZE, ThreadMain, SmallLifoHeapLikeStack, 0, &ThreadId);
    WaitForSingleObject(DoneEvent, INFINITE);
    CloseHandle(ThreadHandle);
    printf("SmallLifoHeapLikeStack %08x`%08x\n", SPLIT_UINT64(Duration));

    ResetEvent(DoneEvent);
    ThreadHandle = CreateThread(NULL, STACK_SIZE, ThreadMain, BigLifoHeapLikeStack, 0, &ThreadId);
    WaitForSingleObject(DoneEvent, INFINITE);
    CloseHandle(ThreadHandle);
    printf("BigLifoHeapLikeStack %08x`%08x\n", SPLIT_UINT64(Duration));

    return 0;
}

#ifdef __cplusplus
}
#endif
