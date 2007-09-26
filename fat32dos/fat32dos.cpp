
#include "fat32dos.h"

void Strategy(void);
void Interrupt(void);

DosDeviceHeader_t DosDeviceHeader =
{
    ~(ULONG)0,
    0xE000,
    Strategy,
    Interrupt,
    { 'J','F','A','T','3','2','0','0' }
};

union
{
    struct
    {
        USHORT Segment;
        USHORT Offset;
    } s;
    void *p;
} RequestHeader;

__declspec(naked) void Strategy(void)
{
    __asm
    {
        mov		cs:RequestHeader.s.Segment,es
        mov		cs:RequestHeader.s.Offset,bx
        ret
    }
}
