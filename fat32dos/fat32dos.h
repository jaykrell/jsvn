
typedef unsigned char UCHAR;
typedef unsigned short USHORT:
typedef unsigned long ULONG;

typedef struct DosRequest_t
{
    UCHAR   Length;
    UCHAR   Unit;
    UCHAR   Command;
    USHORT  Status;
    UCHAR   Reserved[8];
} DosRequest_t;

typedef struct DosBPB_t
{
    USHORT  SectorSize;
    UCHAR   AllocationUnits;
    USHORT  ReservedBootSectors;
    UCHAR   NumberOfFats;
    USHORT  DirectorySizeInFiles;
    USHORT  TotalSectors;
    UCHAR   MediaDescriptor;
    USHORT  FatSectors;
    USHORT  SectorsPerTrack;
    USHORT  NumberOfHeads;
    ULONG   HiddenSectors;
    ULONG   LargeSectorCount;
} DosBPB_t;

typedef struct DosInit_t
{
    DosRequest_t        Header;
    UCHAR               NumberOfUnits;
    char far *          BreakAddress;
    DosBPB_t far **     BPBs;
    char                Drive;
} DosInit_t;

typedef struct DosDeviceHeader_t {
    ULONG   NextDevice;
    USHORT  Attributes;
    void    (*Strategy)(void);
    void    (*Interrupt)(void);
    char    Name[8];
} DosDeviceHeader_t;
