#pragma warning(disable:4514) /* unused inline function */
#pragma warning(disable:4054) /* cast function pointer to data pointer */
#pragma warning(disable:4055) /* cast data pointer to function pointer */
#pragma warning(disable:4127) /* conditional expression is constant */
#pragma warning(disable:4201) /* nonstandard extension, nameless struct/union */
#pragma warning(disable:4214) /* nonstandard extension, non-int bitfield */
struct IRpcStubBuffer; /* warning */
#include <stdio.h>
#include <windows.h>

#undef GetModuleFileName
#undef DeleteFile

#ifndef _WIN64
typedef unsigned long SIZE_T;
#endif

/*
This code unmaps itself.
 it makes a relocated copy of itself
   or maybe position independent
 unmaps the original
 deletes the backing file
 attempts to remap the memory
 copies back

Code running in the copy should be minimized, because
global (and local, up the stack) variables will still point
to the original.
*/

typedef struct _UNMAP
{
    char* OriginalBase;
    char* NewBase;
    size_t Size;
    void * CurrentProcess;
    BOOL (__stdcall * UnmapViewOfFile)(const void*);
    BOOL (__stdcall * VirtualFree)(void*, SIZE_T, DWORD);
    void * (__stdcall * VirtualAlloc)(void*, SIZE_T Size, DWORD AllocationType, DWORD Protect);
    void (__stdcall * FlushInstructionCache)(void*, const void*, SIZE_T);
} UNMAP;

PWSTR
GetModuleFileName(
    void* Base
    )
{
    size_t Length = 32;
    PWSTR Buffer = { 0 };

    while (1)
    {
        free(Buffer);
        Buffer = (PWSTR) calloc(sizeof(WCHAR), Length);
        GetModuleFileNameW(Base, Buffer, Length);
        if (Buffer[Length - 2] == 0)
            return Buffer;
        Length *= 2;
    }
}

void Unmap2(UNMAP* a)
{
    size_t i;
    UNMAP b = *a;

    b.UnmapViewOfFile(b.OriginalBase);
    /*b.VirtualFree(b.OriginalBase, 0, MEM_RELEASE);*/
    b.VirtualAlloc(b.OriginalBase, b.Size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    for (i = 0 ; i != b.Size ; ++i)
        b.OriginalBase[i] = b.NewBase[i];
    b.FlushInstructionCache(b.CurrentProcess, b.OriginalBase, b.Size);
}

void Unmap1(void)
{
    UNMAP a = { 0 };
    PWSTR ModuleFileName = { 0 };
    MEMORY_BASIC_INFORMATION MemInfo[2] = { 0 };
    unsigned char i = { 0 };
    typedef void (*Unmap2_t)(UNMAP* a);
    Unmap2_t pUnmap2 = { 0 };

    /*
    get base and size
    */
    MemInfo[0].BaseAddress = (char*) &Unmap1;
    while (1)
    {
        MemInfo[i ^ 1].BaseAddress = 0;
        MemInfo[i ^ 1].RegionSize = 0;
        if (!VirtualQuery((MemInfo[i].RegionSize + (char*)MemInfo[i].BaseAddress), &MemInfo[i ^ 1], sizeof(MemInfo[i ^ 1])))
            break;
        if (!a.OriginalBase)
        {
            a.OriginalBase = (char*) MemInfo[i ^ 1].AllocationBase;
        }
        else
        {
            if (MemInfo[i ^ 1].AllocationBase != a.OriginalBase)
                break;
        }
        i ^= 1;
    }
    a.Size = ((MemInfo[i].RegionSize + (char*)MemInfo[i].BaseAddress) - a.OriginalBase);
    printf("module is at %p size %x\n", a.OriginalBase, (UINT) a.Size);

    a.VirtualFree = VirtualFree;
    a.UnmapViewOfFile = UnmapViewOfFile;
    a.VirtualAlloc = VirtualAlloc;
    a.FlushInstructionCache = FlushInstructionCache;
    a.CurrentProcess = GetCurrentProcess();

    /*
    make copy
    */
    a.NewBase = a.VirtualAlloc(NULL, a.Size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    CopyMemory(a.NewBase, a.OriginalBase, a.Size);
    a.FlushInstructionCache(a.CurrentProcess, a.NewBase, a.Size);

    ModuleFileName = GetModuleFileName(a.OriginalBase);

    pUnmap2 = (Unmap2_t) ((((char*) Unmap2) - a.OriginalBase) + a.NewBase);

    pUnmap2(&a);

    a.VirtualFree(a.NewBase, 0, MEM_RELEASE);
    /*
    DeleteFileW(ModuleFileName);
    */
    printf("%p\n", CreateFileW(ModuleFileName, GENERIC_WRITE, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_FLAG_DELETE_ON_CLOSE, 0));
    free(ModuleFileName);
}

int main()
{
    Unmap1();

    return 0;

}
