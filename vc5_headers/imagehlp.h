/*++ BUILD Version: 0001     Increment this if a change has global effects

Copyright (c) 1993-1996  Microsoft Corporation

Module Name:

    imagehlp.h

Abstract:

    This module defines the prptotypes and constants required for the image
    help routines.

Revision History:

--*/

#ifndef _IMAGEHLP_
#define _IMAGEHLP_

#ifdef __cplusplus
extern "C" {
#endif

//
// Define checksum return codes.
//

#define CHECKSUM_SUCCESS            0
#define CHECKSUM_OPEN_FAILURE       1
#define CHECKSUM_MAP_FAILURE        2
#define CHECKSUM_MAPVIEW_FAILURE    3
#define CHECKSUM_UNICODE_FAILURE    4

// Define Splitsym flags.

#define SPLITSYM_REMOVE_PRIVATE     0x00000001      // Remove CV types/symbols and Fixup debug
                                                    //  Used for creating .dbg files that ship
                                                    //  as part of the product.

#define SPLITSYM_EXTRACT_ALL        0x00000002      // Extract all debug info from image.
                                                    //  Normally, FPO is left in the image
                                                    //  to allow stack traces through the code.
                                                    //  Using this switch is similar to linking
                                                    //  with -debug:none except the .dbg file
                                                    //  exists...

#if 0
#ifdef _IMAGEHLP_SOURCE_
#define __stdcall __stdcall
#else
#define __stdcall DECLSPEC_IMPORT __stdcall
#endif
#endif
//
// Define checksum function prototypes.
//

PIMAGE_NT_HEADERS
__stdcall
CheckSumMappedFile (
    void* BaseAddress,
    unsigned long FileLength,
    unsigned long* HeaderSum,
    unsigned long* CheckSum
    );

unsigned long
__stdcall
MapFileAndCheckSumA (
    char* Filename,
    unsigned long* HeaderSum,
    unsigned long* CheckSum
    );

unsigned long
__stdcall
MapFileAndCheckSumW (
    wchar_t* Filename,
    unsigned long* HeaderSum,
    unsigned long* CheckSum
    );

#ifdef UNICODE
#define MapFileAndCheckSum  MapFileAndCheckSumW
#else
#define MapFileAndCheckSum  MapFileAndCheckSumA
#endif // !UNICODE


BOOL
__stdcall
TouchFileTimes (
    HANDLE FileHandle,
    LPSYSTEMTIME lpSystemTime
    );

BOOL
__stdcall
SplitSymbols (
    char* ImageName,
    char* SymbolsPath,
    char* SymbolFilePath,
    unsigned long Flags                 // Combination of flags above
    );

HANDLE
__stdcall
FindDebugInfoFile (
    char* FileName,
    char* SymbolPath,
    char* DebugFilePath
    );

HANDLE
__stdcall
FindExecutableImage(
    char* FileName,
    char* SymbolPath,
    char* ImageFilePath
    );

BOOL
__stdcall
UpdateDebugInfoFile(
    char* ImageFileName,
    char* SymbolPath,
    char* DebugFilePath,
    PIMAGE_NT_HEADERS NtHeaders
    );

BOOL
__stdcall
UpdateDebugInfoFileEx(
    char* ImageFileName,
    char* SymbolPath,
    char* DebugFilePath,
    PIMAGE_NT_HEADERS NtHeaders,
    unsigned long OldChecksum
    );

BOOL
__stdcall
BindImage(
    IN char* ImageName,
    IN char* DllPath,
    IN char* SymbolPath
    );

typedef enum _IMAGEHLP_STATUS_REASON {
    BindOutOfMemory,
    BindRvaToVaFailed,
    BindNoRoomInImage,
    BindImportModuleFailed,
    BindImportProcedureFailed,
    BindImportModule,
    BindImportProcedure,
    BindForwarder,
    BindForwarderNOT,
    BindImageModified,
    BindExpandFileHeaders,
    BindImageComplete,
    BindMismatchedSymbols,
    BindSymbolsNotUpdated
} IMAGEHLP_STATUS_REASON;

typedef
BOOL
(__stdcall *PIMAGEHLP_STATUS_ROUTINE)(
    IMAGEHLP_STATUS_REASON Reason,
    char* ImageName,
    char* DllName,
    unsigned long Va,
    unsigned long Parameter
    );


BOOL
__stdcall
BindImageEx(
    IN unsigned long Flags,
    IN char* ImageName,
    IN char* DllPath,
    IN char* SymbolPath,
    IN PIMAGEHLP_STATUS_ROUTINE StatusRoutine
    );

#define BIND_NO_BOUND_IMPORTS 0x00000001
#define BIND_NO_UPDATE        0x00000002
#define BIND_ALL_IMAGES       0x00000004

BOOL
__stdcall
ReBaseImage(
    IN     char* CurrentImageName,
    IN     char* SymbolPath,
    IN     BOOL  fReBase,          // TRUE if actually rebasing, false if only summing
    IN     BOOL  fRebaseSysfileOk, // TRUE is system images s/b rebased
    IN     BOOL  fGoingDown,       // TRUE if the image s/b rebased below the given base
    IN     unsigned long CheckImageSize,   // Max size allowed  (0 if don't care)
    OUT    unsigned long *OldImageSize,    // Returned from the header
    OUT    unsigned long *OldImageBase,    // Returned from the header
    OUT    unsigned long *NewImageSize,    // Image size rounded to next separation boundary
    IN OUT unsigned long *NewImageBase,    // (in) Desired new address.
                                   // (out) Next address (actual if going down)
    IN     unsigned long TimeStamp         // new timestamp for image, if non-zero
    );

#define IMAGE_SEPARATION (64*1024)


typedef struct _LOADED_IMAGE {
    char*                 ModuleName;
    HANDLE                hFile;
    PUCHAR                MappedAddress;
    PIMAGE_NT_HEADERS     FileHeader;
    PIMAGE_SECTION_HEADER LastRvaSection;
    unsigned long                 NumberOfSections;
    PIMAGE_SECTION_HEADER Sections;
    unsigned long                 Characteristics;
    BOOLEAN               fSystemImage;
    BOOLEAN               fDOSImage;
    LIST_ENTRY            Links;
    unsigned long                 SizeOfImage;
} LOADED_IMAGE, *PLOADED_IMAGE;


PLOADED_IMAGE
__stdcall
ImageLoad(
    char* DllName,
    char* DllPath
    );

BOOL
__stdcall
ImageUnload(
    PLOADED_IMAGE LoadedImage
    );

PIMAGE_NT_HEADERS
__stdcall
ImageNtHeader (
    IN void* Base
    );

void*
__stdcall
ImageDirectoryEntryToData (
    IN void* Base,
    IN BOOLEAN MappedAsImage,
    IN USHORT DirectoryEntry,
    OUT PULONG Size
    );

PIMAGE_SECTION_HEADER
__stdcall
ImageRvaToSection(
    IN PIMAGE_NT_HEADERS NtHeaders,
    IN void* Base,
    IN unsigned long Rva
    );

void*
__stdcall
ImageRvaToVa(
    IN PIMAGE_NT_HEADERS NtHeaders,
    IN void* Base,
    IN unsigned long Rva,
    IN OUT PIMAGE_SECTION_HEADER *LastRvaSection
    );

BOOL
__stdcall
MapAndLoad(
    char* ImageName,
    char* DllPath,
    PLOADED_IMAGE LoadedImage,
    BOOL DotDll,
    BOOL ReadOnly
    );

BOOL
__stdcall
GetImageConfigInformation(
    PLOADED_IMAGE LoadedImage,
    PIMAGE_LOAD_CONFIG_DIRECTORY ImageConfigInformation
    );

unsigned long
__stdcall
GetImageUnusedHeaderBytes(
    PLOADED_IMAGE LoadedImage,
    unsigned long* SizeUnusedHeaderBytes
    );

BOOL
__stdcall
SetImageConfigInformation(
    PLOADED_IMAGE LoadedImage,
    PIMAGE_LOAD_CONFIG_DIRECTORY ImageConfigInformation
    );

BOOL
__stdcall
UnMapAndLoad(
   PLOADED_IMAGE LoadedImage
   );

typedef struct _IMAGE_DEBUG_INFORMATION {
    LIST_ENTRY List;
    unsigned long Size;
    void* MappedBase;
    USHORT Machine;
    USHORT Characteristics;
    unsigned long CheckSum;
    unsigned long ImageBase;
    unsigned long SizeOfImage;

    unsigned long NumberOfSections;
    PIMAGE_SECTION_HEADER Sections;

    unsigned long ExportedNamesSize;
    char* ExportedNames;

    unsigned long NumberOfFunctionTableEntries;
    PIMAGE_FUNCTION_ENTRY FunctionTableEntries;
    unsigned long LowestFunctionStartingAddress;
    unsigned long HighestFunctionEndingAddress;

    unsigned long NumberOfFpoTableEntries;
    PFPO_DATA FpoTableEntries;

    unsigned long SizeOfCoffSymbols;
    PIMAGE_COFF_SYMBOLS_HEADER CoffSymbols;

    unsigned long SizeOfCodeViewSymbols;
    void* CodeViewSymbols;

    char* ImageFilePath;
    char* ImageFileName;
    char* DebugFilePath;

    unsigned long TimeDateStamp;

    BOOL  RomImage;
    PIMAGE_DEBUG_DIRECTORY DebugDirectory;
    unsigned long NumberOfDebugDirectories;

    unsigned long Reserved[ 3 ];

} IMAGE_DEBUG_INFORMATION, *PIMAGE_DEBUG_INFORMATION;


PIMAGE_DEBUG_INFORMATION
__stdcall
MapDebugInformation (
    HANDLE FileHandle,
    char* FileName,
    char* SymbolPath,
    unsigned long ImageBase
    );

BOOL
__stdcall
UnmapDebugInformation(
    PIMAGE_DEBUG_INFORMATION DebugInfo
    );

HANDLE
__stdcall
FindExecutableImage(
    char* FileName,
    char* SymbolPath,
    char* ImageFilePath
    );

BOOL
__stdcall
SearchTreeForFile(
    char* RootPath,
    char* InputPathName,
    char* OutputPathBuffer
    );

BOOL
__stdcall
MakeSureDirectoryPathExists(
    const char* DirPath
    );

//
// UnDecorateSymbolName Flags
//

#define UNDNAME_COMPLETE                 (0x0000)  // Enable full undecoration
#define UNDNAME_NO_LEADING_UNDERSCORES   (0x0001)  // Remove leading underscores from MS extended keywords
#define UNDNAME_NO_MS_KEYWORDS           (0x0002)  // Disable expansion of MS extended keywords
#define UNDNAME_NO_FUNCTION_RETURNS      (0x0004)  // Disable expansion of return type for primary declaration
#define UNDNAME_NO_ALLOCATION_MODEL      (0x0008)  // Disable expansion of the declaration model
#define UNDNAME_NO_ALLOCATION_LANGUAGE   (0x0010)  // Disable expansion of the declaration language specifier
#define UNDNAME_NO_MS_THISTYPE           (0x0020)  // NYI Disable expansion of MS keywords on the 'this' type for primary declaration
#define UNDNAME_NO_CV_THISTYPE           (0x0040)  // NYI Disable expansion of CV modifiers on the 'this' type for primary declaration
#define UNDNAME_NO_THISTYPE              (0x0060)  // Disable all modifiers on the 'this' type
#define UNDNAME_NO_ACCESS_SPECIFIERS     (0x0080)  // Disable expansion of access specifiers for members
#define UNDNAME_NO_THROW_SIGNATURES      (0x0100)  // Disable expansion of 'throw-signatures' for functions and pointers to functions
#define UNDNAME_NO_MEMBER_TYPE           (0x0200)  // Disable expansion of 'static' or 'virtual'ness of members
#define UNDNAME_NO_RETURN_UDT_MODEL      (0x0400)  // Disable expansion of MS model for UDT returns
#define UNDNAME_32_BIT_DECODE            (0x0800)  // Undecorate 32-bit decorated names
#define UNDNAME_NAME_ONLY                (0x1000)  // Crack only the name for primary declaration;
                                                                                                   //  return just [scope::]name.  Does expand template params
#define UNDNAME_NO_ARGUMENTS             (0x2000)  // Don't undecorate arguments to function
#define UNDNAME_NO_SPECIAL_SYMS          (0x4000)  // Don't undecorate special names (v-table, vcall, vector xxx, metatype, etc)

unsigned long
__stdcall
UnDecorateSymbolName(
    const char*   DecoratedName,         // Name to undecorate
    char*    UnDecoratedName,       // If NULL, it will be allocated
    unsigned long    UndecoratedLength,     // The maximym length
    unsigned long    Flags                  // See above.
    );

//
// StackWalking API
//

typedef enum {
    AddrMode1616,
    AddrMode1632,
    AddrModeReal,
    AddrModeFlat
} ADDRESS_MODE;

typedef struct _tagADDRESS {
    unsigned long         Offset;
    WORD          Segment;
    ADDRESS_MODE  Mode;
} ADDRESS, *LPADDRESS;


//
// This structure is included in the STACKFRAME structure,
// and is used to trace through usermode callbacks in a thread's
// kernel stack.  The values must be copied by the kernel debugger
// from the DBGKD_GET_VERSION and WAIT_STATE_CHANGE packets.
//
typedef struct _KDHELP {

    //
    // address of kernel thread object, as provided in the
    // WAIT_STATE_CHANGE packet.
    //
    unsigned long   Thread;

    //
    // offset in thread object to pointer to the current callback frame
    // in kernel stack.
    //
    unsigned long   ThCallbackStack;

    //
    // offsets to values in frame:
    //
    // address of next callback frame
    unsigned long   NextCallback;

    // address of saved frame pointer (if applicable)
    unsigned long   FramePointer;

    //
    // Address of the kernel function that calls out to user mode
    //
    unsigned long   KiCallUserMode;

    //
    // Address of the user mode dispatcher function
    //
    unsigned long   KeUserCallbackDispatcher;

} KDHELP, *PKDHELP;


typedef struct _tagSTACKFRAME {
    ADDRESS     AddrPC;               // program counter
    ADDRESS     AddrReturn;           // return address
    ADDRESS     AddrFrame;            // frame pointer
    ADDRESS     AddrStack;            // stack pointer
    void*      FuncTableEntry;       // pointer to pdata/fpo or NULL
    unsigned long       Params[4];            // possible arguments to the function
    BOOL        Far;                  // WOW  call
    BOOL        Virtual;              // is this a virtual frame?
    unsigned long       Reserved[3];          // used internally by StackWalk api
    KDHELP      KdHelp;
} STACKFRAME, *LPSTACKFRAME;

typedef
BOOL
(__stdcall *PREAD_PROCESS_MEMORY_ROUTINE)(
    HANDLE  hProcess,
    const void* lpBaseAddress,
    void*  lpBuffer,
    unsigned long   nSize,
    unsigned long* lpNumberOfBytesRead
    );

typedef
void*
(__stdcall *PFUNCTION_TABLE_ACCESS_ROUTINE)(
    HANDLE  hProcess,
    unsigned long   AddrBase
    );

typedef
unsigned long
(__stdcall *PGET_MODULE_BASE_ROUTINE)(
    HANDLE  hProcess,
    unsigned long   ReturnAddress
    );


typedef
unsigned long
(__stdcall *PTRANSLATE_ADDRESS_ROUTINE)(
    HANDLE    hProcess,
    HANDLE    hThread,
    LPADDRESS lpaddr
    );

BOOL
__stdcall
StackWalk(
    unsigned long                             MachineType,
    HANDLE                            hProcess,
    HANDLE                            hThread,
    LPSTACKFRAME                      StackFrame,
    void*                            ContextRecord,
    PREAD_PROCESS_MEMORY_ROUTINE      ReadMemoryRoutine,
    PFUNCTION_TABLE_ACCESS_ROUTINE    FunctionTableAccessRoutine,
    PGET_MODULE_BASE_ROUTINE          GetModuleBaseRoutine,
    PTRANSLATE_ADDRESS_ROUTINE        TranslateAddress
    );

#define API_VERSION_NUMBER 5

typedef struct API_VERSION {
    USHORT  MajorVersion;
    USHORT  MinorVersion;
    USHORT  Revision;
    USHORT  Reserved;
} API_VERSION, *LPAPI_VERSION;

LPAPI_VERSION
__stdcall
ImagehlpApiVersion(
    void
    );

LPAPI_VERSION
__stdcall
ImagehlpApiVersionEx(
    LPAPI_VERSION AppVersion
    );

unsigned long
__stdcall
GetTimestampForLoadedLibrary(
    HMODULE Module
    );

BOOL
__stdcall
RemovePrivateCvSymbolic(
    char*   DebugData,
    char* * NewDebugData,
    unsigned long * NewDebugSize
    );

void
__stdcall
RemoveRelocations(
    char* ImageName
    );

//
// typedefs for function pointers
//
typedef BOOL
(__stdcall *PSYM_ENUMMODULES_CALLBACK)(
    char* ModuleName,
    unsigned long BaseOfDll,
    void* UserContext
    );

typedef BOOL
(__stdcall *PSYM_ENUMSYMBOLS_CALLBACK)(
    char* SymbolName,
    unsigned long SymbolAddress,
    unsigned long SymbolSize,
    void* UserContext
    );

typedef BOOL
(__stdcall *PENUMLOADED_MODULES_CALLBACK)(
    char* ModuleName,
    unsigned long ModuleBase,
    unsigned long ModuleSize,
    void* UserContext
    );

typedef BOOL
(__stdcall *PSYMBOL_REGISTERED_CALLBACK)(
    HANDLE  hProcess,
    unsigned long   ActionCode,
    void*   CallbackData,
    void*   UserContext
    );

//
// symbol flags
//
#define SYMF_OMAP_GENERATED   0x00000001
#define SYMF_OMAP_MODIFIED    0x00000002

//
// symbol type enumeration
//
typedef enum {
    SymNone,
    SymCoff,
    SymCv,
    SymPdb,
    SymExport,
    SymDeferred,
    SymSym                  // .sym file
} SYM_TYPE;

//
// symbol data structure
//
typedef struct _IMAGEHLP_SYMBOL {
    unsigned long                       SizeOfStruct;           // set to sizeof(IMAGEHLP_SYMBOL)
    unsigned long                       Address;                // virtual address including dll base address
    unsigned long                       Size;                   // estimated size of symbol, can be zero
    unsigned long                       Flags;                  // info about the symbols, see the SYMF defines
    unsigned long                       MaxNameLength;          // maximum size of symbol name in 'Name'
    char                        Name[1];                // symbol name (null terminated string)
} IMAGEHLP_SYMBOL, *PIMAGEHLP_SYMBOL;

//
// module data structure
//
typedef struct _IMAGEHLP_MODULE {
    unsigned long                       SizeOfStruct;           // set to sizeof(IMAGEHLP_MODULE)
    unsigned long                       BaseOfImage;            // base load address of module
    unsigned long                       ImageSize;              // virtual size of the loaded module
    unsigned long                       TimeDateStamp;          // date/time stamp from pe header
    unsigned long                       CheckSum;               // checksum from the pe header
    unsigned long                       NumSyms;                // number of symbols in the symbol table
    SYM_TYPE                    SymType;                // type of symbols loaded
    char                        ModuleName[32];         // module name
    char                        ImageName[256];         // image name
    char                        LoadedImageName[256];   // symbol file name
} IMAGEHLP_MODULE, *PIMAGEHLP_MODULE;

//
// data structures used for registered symbol callbacks
//

#define CBA_DEFERRED_SYMBOL_LOAD_START          0x00000001
#define CBA_DEFERRED_SYMBOL_LOAD_COMPLETE       0x00000002
#define CBA_DEFERRED_SYMBOL_LOAD_FAILURE        0x00000003
#define CBA_SYMBOLS_UNLOADED                    0x00000004
#define CBA_DUPLICATE_SYMBOL                    0x00000005

typedef struct _IMAGEHLP_DEFERRED_SYMBOL_LOAD {
    unsigned long                       SizeOfStruct;           // set to sizeof(IMAGEHLP_DEFERRED_SYMBOL_LOAD)
    unsigned long                       BaseOfImage;            // base load address of module
    unsigned long                       CheckSum;               // checksum from the pe header
    unsigned long                       TimeDateStamp;          // date/time stamp from pe header
    char                        FileName[MAX_PATH];     // symbols file or image name
} IMAGEHLP_DEFERRED_SYMBOL_LOAD, *PIMAGEHLP_DEFERRED_SYMBOL_LOAD;

typedef struct _IMAGEHLP_DUPLICATE_SYMBOL {
    unsigned long                       SizeOfStruct;           // set to sizeof(IMAGEHLP_DUPLICATE_SYMBOL)
    unsigned long                       NumberOfDups;           // number of duplicates in the Symbol array
    PIMAGEHLP_SYMBOL            Symbol;                 // array of duplicate symbols
    unsigned long                       SelectedSymbol;         // symbol selected (-1 to start)
} IMAGEHLP_DUPLICATE_SYMBOL, *PIMAGEHLP_DUPLICATE_SYMBOL;


//
// options that are set/returned by SymSetOptions() & SymGetOptions()
// these are used as a mask
//
#define SYMOPT_CASE_INSENSITIVE  0x00000001
#define SYMOPT_UNDNAME           0x00000002
#define SYMOPT_DEFERRED_LOADS    0x00000004
#define SYMOPT_NO_CPP            0x00000008


unsigned long
__stdcall
SymSetOptions(
    IN unsigned long   SymOptions
    );

unsigned long
__stdcall
SymGetOptions(
    void
    );

BOOL
__stdcall
SymCleanup(
    IN HANDLE hProcess
    );

BOOL
__stdcall
SymEnumerateModules(
    IN HANDLE                       hProcess,
    IN PSYM_ENUMMODULES_CALLBACK    EnumModulesCallback,
    IN void*                        UserContext
    );

BOOL
__stdcall
SymEnumerateSymbols(
    IN HANDLE                       hProcess,
    IN unsigned long                        BaseOfDll,
    IN PSYM_ENUMSYMBOLS_CALLBACK    EnumSymbolsCallback,
    IN void*                        UserContext
    );

BOOL
__stdcall
EnumerateLoadedModules(
    IN HANDLE                           hProcess,
    IN PENUMLOADED_MODULES_CALLBACK     EnumLoadedModulesCallback,
    IN void*                            UserContext
    );

void*
__stdcall
SymFunctionTableAccess(
    HANDLE  hProcess,
    unsigned long   AddrBase
    );

BOOL
__stdcall
SymGetModuleInfo(
    IN  HANDLE              hProcess,
    IN  unsigned long               dwAddr,
    OUT PIMAGEHLP_MODULE    ModuleInfo
    );

unsigned long
__stdcall
SymGetModuleBase(
    IN  HANDLE              hProcess,
    IN  unsigned long               dwAddr
    );

BOOL
__stdcall
SymGetSymFromAddr(
    IN  HANDLE              hProcess,
    IN  unsigned long               dwAddr,
    OUT unsigned long*              pdwDisplacement,
    OUT PIMAGEHLP_SYMBOL    Symbol
    );

BOOL
__stdcall
SymGetSymFromName(
    IN  HANDLE              hProcess,
    IN  char*               Name,
    OUT PIMAGEHLP_SYMBOL    Symbol
    );

BOOL
__stdcall
SymGetSymNext(
    IN     HANDLE              hProcess,
    IN OUT PIMAGEHLP_SYMBOL    Symbol
    );

BOOL
__stdcall
SymGetSymPrev(
    IN     HANDLE              hProcess,
    IN OUT PIMAGEHLP_SYMBOL    Symbol
    );

BOOL
__stdcall
SymInitialize(
    IN HANDLE   hProcess,
    IN char*    UserSearchPath,
    IN BOOL     fInvadeProcess
    );

BOOL
__stdcall
SymGetSearchPath(
    IN  HANDLE          hProcess,
    OUT char*           SearchPath,
    IN  unsigned long           SearchPathLength
    );

BOOL
__stdcall
SymSetSearchPath(
    IN HANDLE           hProcess,
    IN char*            SearchPath
    );

BOOL
__stdcall
SymLoadModule(
    IN  HANDLE          hProcess,
    IN  HANDLE          hFile,
    IN  char*            ImageName,
    IN  char*            ModuleName,
    IN  unsigned long           BaseOfDll,
    IN  unsigned long           SizeOfDll
    );

BOOL
__stdcall
SymUnloadModule(
    IN  HANDLE          hProcess,
    IN  unsigned long           BaseOfDll
    );

BOOL
__stdcall
SymUnDName(
    IN  PIMAGEHLP_SYMBOL sym,               // Symbol to undecorate
    OUT char*            UnDecName,         // Buffer to store undecorated name in
    IN  unsigned long            UnDecNameLength    // Size of the buffer
    );

BOOL
__stdcall
SymRegisterCallback(
    IN HANDLE                       hProcess,
    IN PSYMBOL_REGISTERED_CALLBACK  CallbackFunction,
    IN void*                        UserContext
    );

// Image Integrity API's

#define CERT_PE_IMAGE_DIGEST_DEBUG_INFO         0x01
#define CERT_PE_IMAGE_DIGEST_RESOURCES          0x02
#define CERT_PE_IMAGE_DIGEST_ALL_IMPORT_INFO    0x04

#define CERT_SECTION_TYPE_ANY                   0xFF      // Any Certificate type

typedef void* DIGEST_HANDLE;

typedef BOOL (__stdcall *DIGEST_FUNCTION) (DIGEST_HANDLE refdata, PBYTE pData, unsigned long dwLength);

BOOL
__stdcall
ImageGetDigestStream(
    IN      HANDLE  FileHandle,
    IN      unsigned long   DigestLevel,
    IN      DIGEST_FUNCTION DigestFunction,
    IN      DIGEST_HANDLE   DigestHandle
    );

BOOL
__stdcall
ImageAddCertificate(
    IN      HANDLE  FileHandle,
    IN      LPWIN_CERTIFICATE   Certificate,
    OUT     unsigned long*  Index
    );

BOOL
__stdcall
ImageRemoveCertificate(
    IN      HANDLE   FileHandle,
    IN      unsigned long    Index
    );

BOOL
__stdcall
ImageEnumerateCertificates(
    IN      HANDLE  FileHandle,
    IN      WORD    TypeFilter,
    OUT     unsigned long*  CertificateCount,
    IN OUT  unsigned long*  Indices OPTIONAL,
    IN OUT  unsigned long   IndexCount  OPTIONAL
    );

BOOL
__stdcall
ImageGetCertificateData(
    IN      HANDLE  FileHandle,
    IN      unsigned long   CertificateIndex,
    OUT     LPWIN_CERTIFICATE Certificate,
    IN OUT  unsigned long*  RequiredLength
    );

BOOL
__stdcall
ImageGetCertificateHeader(
    IN      HANDLE  FileHandle,
    IN      unsigned long   CertificateIndex,
    IN OUT  LPWIN_CERTIFICATE Certificateheader
    );

#ifdef __cplusplus
}
#endif

#endif  // _IMAGEHLP_
#pragma once 
