/*++

Copyright (c) 1995-1996 Microsoft Corporation

Module Name:

    setupapi.h

Abstract:

    Public header file for Windows NT Setup services Dll.

Author:

    Ted Miller (tedm) 11-Jan-1995

Revision History:

--*/

#ifndef _INC_SETUPAPI
#define _INC_SETUPAPI

//
// Define API decoration for direct importing of DLL references.
//
#if !defined(_SETUPAPI_)
#define WINSETUPAPI DECLSPEC_IMPORT
#else
#define WINSETUPAPI
#endif

#include <pshpack1.h>   // Assume byte packing throughout

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __LPGUID_DEFINED__
#define __LPGUID_DEFINED__
typedef GUID *LPGUID;
#endif

//
// Include commctrl.h for our use of HIMAGELIST and wizard support.
//
#include <commctrl.h>


//
// Define maximum string length constants as specified by
// Windows 95.
//
#define LINE_LEN                    256 // Win95-compatible maximum for displayable
                                        // strings coming from a device INF.
#define MAX_INF_STRING_LENGTH      4096 // Actual maximum size of an INF string (including
                                        // string substitutions).
#define MAX_TITLE_LEN                60
#define MAX_INSTRUCTION_LEN         256
#define MAX_LABEL_LEN                30
#define MAX_SERVICE_NAME_LEN        256

//
// Define type for reference to loaded inf file
//
typedef void* HINF;

//
// Inf context structure. Applications must not interpret or
// overwrite values in these structures.
//
typedef struct _INFCONTEXT {
    void* Inf;
    void* CurrentInf;
    unsigned Section;
    unsigned Line;
} INFCONTEXT, *PINFCONTEXT;

//
// Inf file information structure.
//
typedef struct _SP_INF_INFORMATION {
    unsigned long InfStyle;
    unsigned long InfCount;
    BYTE VersionData[ANYSIZE_ARRAY];
} SP_INF_INFORMATION, *PSP_INF_INFORMATION;

//
// SP_INF_INFORMATION.InfStyle values
//
#define INF_STYLE_NONE  0       // unrecognized or non-existent
#define INF_STYLE_OLDNT 1       // winnt 3.x
#define INF_STYLE_WIN4  2       // Win95

//
// Target directory specs.
//
#define DIRID_ABSOLUTE          -1              // real 32-bit -1
#define DIRID_ABSOLUTE_16BIT     0xffff         // 16-bit -1 for compat w/setupx
#define DIRID_NULL               0
#define DIRID_SRCPATH            1
#define DIRID_WINDOWS           10
#define DIRID_SYSTEM            11              // system32
#define DIRID_DRIVERS           12
#define DIRID_IOSUBSYS          DIRID_DRIVERS
#define DIRID_INF               17
#define DIRID_HELP              18
#define DIRID_FONTS             20
#define DIRID_VIEWERS           21
#define DIRID_APPS              24
#define DIRID_SHARED            25
#define DIRID_BOOT              30

#define DIRID_SYSTEM16          50
#define DIRID_SPOOL             51
#define DIRID_SPOOLDRIVERS      52
#define DIRID_USERPROFILE       53
#define DIRID_LOADER            54

#define DIRID_DEFAULT           DIRID_SYSTEM

//
// First user-definable dirid. See SetupSetDirectoryId().
//
#define DIRID_USER              0x8000


//
// Setup callback notification routine type
//
typedef unsigned (__stdcall* PSP_FILE_CALLBACK_A)(
    IN void* Context,
    IN unsigned Notification,
    IN unsigned Param1,
    IN unsigned Param2
    );

typedef unsigned (__stdcall* PSP_FILE_CALLBACK_W)(
    IN void* Context,
    IN unsigned Notification,
    IN unsigned Param1,
    IN unsigned Param2
    );

#ifdef UNICODE
#define PSP_FILE_CALLBACK PSP_FILE_CALLBACK_W
#else
#define PSP_FILE_CALLBACK PSP_FILE_CALLBACK_A
#endif


//
// Operation/queue start/end notification. These are ordinal values.
//
#define SPFILENOTIFY_STARTQUEUE         0x00000001
#define SPFILENOTIFY_ENDQUEUE           0x00000002
#define SPFILENOTIFY_STARTSUBQUEUE      0x00000003
#define SPFILENOTIFY_ENDSUBQUEUE        0x00000004
#define SPFILENOTIFY_STARTDELETE        0x00000005
#define SPFILENOTIFY_ENDDELETE          0x00000006
#define SPFILENOTIFY_DELETEERROR        0x00000007
#define SPFILENOTIFY_STARTRENAME        0x00000008
#define SPFILENOTIFY_ENDRENAME          0x00000009
#define SPFILENOTIFY_RENAMEERROR        0x0000000a
#define SPFILENOTIFY_STARTCOPY          0x0000000b
#define SPFILENOTIFY_ENDCOPY            0x0000000c
#define SPFILENOTIFY_COPYERROR          0x0000000d
#define SPFILENOTIFY_NEEDMEDIA          0x0000000e
#define SPFILENOTIFY_QUEUESCAN          0x0000000f
//
// These are used with SetupIterateCabinet().
//
#define SPFILENOTIFY_CABINETINFO        0x00000010
#define SPFILENOTIFY_FILEINCABINET      0x00000011
#define SPFILENOTIFY_NEEDNEWCABINET     0x00000012
#define SPFILENOTIFY_FILEEXTRACTED      0x00000013

#define SPFILENOTIFY_FILEOPDELAYED      0x00000014

//
// Copy notification. These are bit flags that may be combined.
//
#define SPFILENOTIFY_LANGMISMATCH       0x00010000
#define SPFILENOTIFY_TARGETEXISTS       0x00020000
#define SPFILENOTIFY_TARGETNEWER        0x00040000

//
// File operation codes and callback outcomes.
//
#define FILEOP_COPY                     0
#define FILEOP_RENAME                   1
#define FILEOP_DELETE                   2

#define FILEOP_ABORT                    0
#define FILEOP_DOIT                     1
#define FILEOP_SKIP                     2
#define FILEOP_RETRY                    FILEOP_DOIT
#define FILEOP_NEWPATH                  4

//
// Flags in inf copy sections
//
#define COPYFLG_WARN_IF_SKIP            0x00000001      // warn if user tries to skip file
#define COPYFLG_NOSKIP                  0x00000002      // disallow skipping this file
#define COPYFLG_NOVERSIONCHECK          0x00000004      // ignore versions and overwrite target
#define COPYFLG_FORCE_FILE_IN_USE       0x00000008      // force file-in-use behavior
#define COPYFLG_NO_OVERWRITE            0x00000010      // do not copy if file exists on target
#define COPYFLG_NO_VERSION_DIALOG       0x00000020      // do not copy if target is newer
#define COPYFLG_REPLACEONLY             0x00000400      // copy only if file exists on target

//
// Flags in inf delete sections
// New flags go in high word
//
#define DELFLG_IN_USE                   0x00000001      // queue in-use file for delete
#define DELFLG_IN_USE1                  0x00010000      // high-word version of DELFLG_IN_USE

//
// Source and file paths. Used when notifying queue callback
// of SPFILENOTIFY_STARTxxx, SPFILENOTIFY_ENDxxx, and SPFILENOTIFY_xxxERROR.
//
typedef struct _FILEPATHS_A {
    const char*  Target;
    const char*  Source;  // not used for delete operations
    unsigned   Win32Error;
    unsigned long  Flags;   // such as SP_COPY_NOSKIP for copy errors
} FILEPATHS_A, *PFILEPATHS_A;

typedef struct _FILEPATHS_W {
    const wchar_t* Target;
    const wchar_t* Source;  // not used for delete operations
    unsigned   Win32Error;
    unsigned long  Flags;   // such as SP_COPY_NOSKIP for copy errors
} FILEPATHS_W, *PFILEPATHS_W;

#ifdef UNICODE
typedef FILEPATHS_W FILEPATHS;
typedef PFILEPATHS_W PFILEPATHS;
#else
typedef FILEPATHS_A FILEPATHS;
typedef PFILEPATHS_A PFILEPATHS;
#endif


//
// Structure used with SPFILENOTIFY_NEEDMEDIA
//
typedef struct _SOURCE_MEDIA_A {
    const char* Reserved;
    const char* Tagfile;          // may be NULL
    const char* Description;
    //
    // Pathname part and filename part of source file
    // that caused us to need the media.
    //
    const char* SourcePath;
    const char* SourceFile;
    unsigned long Flags;            // subset of SP_COPY_xxx
} SOURCE_MEDIA_A, *PSOURCE_MEDIA_A;

typedef struct _SOURCE_MEDIA_W {
    const wchar_t* Reserved;
    const wchar_t* Tagfile;         // may be NULL
    const wchar_t* Description;
    //
    // Pathname part and filename part of source file
    // that caused us to need the media.
    //
    const wchar_t* SourcePath;
    const wchar_t* SourceFile;
    unsigned long  Flags;           // subset of SP_COPY_xxx
} SOURCE_MEDIA_W, *PSOURCE_MEDIA_W;

#ifdef UNICODE
typedef SOURCE_MEDIA_W SOURCE_MEDIA;
typedef PSOURCE_MEDIA_W PSOURCE_MEDIA;
#else
typedef SOURCE_MEDIA_A SOURCE_MEDIA;
typedef PSOURCE_MEDIA_A PSOURCE_MEDIA;
#endif

//
// Structure used with SPFILENOTIFY_CABINETINFO and
// SPFILENOTIFY_NEEDNEWCABINET
//
typedef struct _CABINET_INFO_A {
    const char* CabinetPath;
    const char* CabinetFile;
    const char* DiskName;
    USHORT SetId;
    USHORT CabinetNumber;
} CABINET_INFO_A, *PCABINET_INFO_A;

typedef struct _CABINET_INFO_W {
    const wchar_t* CabinetPath;
    const wchar_t* CabinetFile;
    const wchar_t* DiskName;
    USHORT SetId;
    USHORT CabinetNumber;
} CABINET_INFO_W, *PCABINET_INFO_W;

#ifdef UNICODE
typedef CABINET_INFO_W CABINET_INFO;
typedef PCABINET_INFO_W PCABINET_INFO;
#else
typedef CABINET_INFO_A CABINET_INFO;
typedef PCABINET_INFO_A PCABINET_INFO;
#endif

//
// Structure used with SPFILENOTIFY_FILEINCABINET
//
typedef struct _FILE_IN_CABINET_INFO_A {
    const char* NameInCabinet;
    unsigned long FileSize;
    unsigned long Win32Error;
    WORD  DosDate;
    WORD  DosTime;
    WORD  DosAttribs;
    CHAR  FullTargetName[MAX_PATH];
} FILE_IN_CABINET_INFO_A, *PFILE_IN_CABINET_INFO_A;

typedef struct _FILE_IN_CABINET_INFO_W {
    const wchar_t* NameInCabinet;
    unsigned long  FileSize;
    unsigned long  Win32Error;
    WORD   DosDate;
    WORD   DosTime;
    WORD   DosAttribs;
    WCHAR  FullTargetName[MAX_PATH];
} FILE_IN_CABINET_INFO_W, *PFILE_IN_CABINET_INFO_W;

#ifdef UNICODE
typedef FILE_IN_CABINET_INFO_W FILE_IN_CABINET_INFO;
typedef PFILE_IN_CABINET_INFO_W PFILE_IN_CABINET_INFO;
#else
typedef FILE_IN_CABINET_INFO_A FILE_IN_CABINET_INFO;
typedef PFILE_IN_CABINET_INFO_A PFILE_IN_CABINET_INFO;
#endif


//
// Define type for setup file queue
//
typedef void* HSPFILEQ;

//
// Define type for reference to device information set
//
typedef void* HDEVINFO;

//
// Device information structure (references a device instance
// that is a member of a device information set)
//
typedef struct _SP_DEVINFO_DATA {
    unsigned long cbSize;
    GUID  ClassGuid;
    unsigned long DevInst;    // DEVINST handle
    unsigned long Reserved;
} SP_DEVINFO_DATA, *PSP_DEVINFO_DATA;


//
// Class installer function codes
//
#define DIF_SELECTDEVICE            0x00000001
#define DIF_INSTALLDEVICE           0x00000002
#define DIF_ASSIGNRESOURCES         0x00000003
#define DIF_PROPERTIES              0x00000004
#define DIF_REMOVE                  0x00000005
#define DIF_FIRSTTIMESETUP          0x00000006
#define DIF_FOUNDDEVICE             0x00000007
#define DIF_SELECTCLASSDRIVERS      0x00000008
#define DIF_VALIDATECLASSDRIVERS    0x00000009
#define DIF_INSTALLCLASSDRIVERS     0x0000000A
#define DIF_CALCDISKSPACE           0x0000000B
#define DIF_DESTROYPRIVATEDATA      0x0000000C
#define DIF_VALIDATEDRIVER          0x0000000D
#define DIF_MOVEDEVICE              0x0000000E
#define DIF_DETECT                  0x0000000F
#define DIF_INSTALLWIZARD           0x00000010
#define DIF_DESTROYWIZARDDATA       0x00000011
#define DIF_PROPERTYCHANGE          0x00000012
#define DIF_ENABLECLASS             0x00000013
#define DIF_DETECTVERIFY            0x00000014
#define DIF_INSTALLDEVICEFILES      0x00000015

typedef unsigned        DI_FUNCTION;    // Function type for device installer


//
// Device installation parameters structure (associated with a
// particular device information element, or globally with a device
// information set)
//
typedef struct _SP_DEVINSTALL_PARAMS_A {
    unsigned long             cbSize;
    unsigned long             Flags;
    unsigned long             FlagsEx;
    HWND              hwndParent;
    PSP_FILE_CALLBACK InstallMsgHandler;
    void*             InstallMsgHandlerContext;
    HSPFILEQ          FileQueue;
    unsigned long             ClassInstallReserved;
    unsigned long             Reserved;
    CHAR              DriverPath[MAX_PATH];
} SP_DEVINSTALL_PARAMS_A, *PSP_DEVINSTALL_PARAMS_A;

typedef struct _SP_DEVINSTALL_PARAMS_W {
    unsigned long             cbSize;
    unsigned long             Flags;
    unsigned long             FlagsEx;
    HWND              hwndParent;
    PSP_FILE_CALLBACK InstallMsgHandler;
    void*             InstallMsgHandlerContext;
    HSPFILEQ          FileQueue;
    unsigned long             ClassInstallReserved;
    unsigned long             Reserved;
    WCHAR             DriverPath[MAX_PATH];
} SP_DEVINSTALL_PARAMS_W, *PSP_DEVINSTALL_PARAMS_W;

#ifdef UNICODE
typedef SP_DEVINSTALL_PARAMS_W SP_DEVINSTALL_PARAMS;
typedef PSP_DEVINSTALL_PARAMS_W PSP_DEVINSTALL_PARAMS;
#else
typedef SP_DEVINSTALL_PARAMS_A SP_DEVINSTALL_PARAMS;
typedef PSP_DEVINSTALL_PARAMS_A PSP_DEVINSTALL_PARAMS;
#endif


//
// SP_DEVINSTALL_PARAMS.Flags values
//
// Flags for choosing a device
//
#define DI_SHOWOEM                  0x00000001L     // support Other... button
#define DI_SHOWCOMPAT               0x00000002L     // show compatibility list
#define DI_SHOWCLASS                0x00000004L     // show class list
#define DI_SHOWALL                  0x00000007L     // both class & compat list shown
#define DI_NOVCP                    0x00000008L     // don't create a new copy queue--use
                                                    // caller-supplied FileQueue
#define DI_DIDCOMPAT                0x00000010L     // Searched for compatible devices
#define DI_DIDCLASS                 0x00000020L     // Searched for class devices
#define DI_AUTOASSIGNRES            0x00000040L     // No UI for resources if possible

// flags returned by DiInstallDevice to indicate need to reboot/restart
#define DI_NEEDRESTART              0x00000080L     // Reboot required to take effect
#define DI_NEEDREBOOT               0x00000100L     // ""

// flags for device installation
#define DI_NOBROWSE                 0x00000200L     // no Browse... in InsertDisk

// Flags set by DiBuildDriverInfoList
#define DI_MULTMFGS                 0x00000400L     // Set if multiple manufacturers in
                                                    // class driver list

// Flag indicates that device is disabled
#define DI_DISABLED                 0x00000800L     // Set if device disabled

// Flags for Device/Class Properties
#define DI_GENERALPAGE_ADDED        0x00001000L
#define DI_RESOURCEPAGE_ADDED       0x00002000L

// Flag to indicate the setting properties for this Device (or class) caused a change
// so the Dev Mgr UI probably needs to be updatd.
#define DI_PROPERTIES_CHANGE        0x00004000L

// Flag to indicate that the sorting from the INF file should be used.
#define DI_INF_IS_SORTED            0x00008000L

// Flag to indicate that only the the INF specified by SP_DEVINSTALL_PARAMS.DriverPath
// should be searched.
#define DI_ENUMSINGLEINF            0x00010000L

// Flag that prevents ConfigMgr from removing/re-enumerating devices during device
// registration, installation, and deletion.
#define DI_DONOTCALLCONFIGMG        0x00020000L

// The following flag can be used to install a device disabled
#define DI_INSTALLDISABLED          0x00040000L

// Flag that causes SetupDiBuildDriverInfoList to build a device's compatible driver
// list from its existing class driver list, instead of the normal INF search.
#define DI_COMPAT_FROM_CLASS        0x00080000L

// This flag is set if the Class Install params should be used.
#define DI_CLASSINSTALLPARAMS       0x00100000L

// This flag is set if the caller of DiCallClassInstaller does NOT
// want the internal default action performed if the Class installer
// returns ERROR_DI_DO_DEFAULT.
#define DI_NODI_DEFAULTACTION       0x00200000L

// The setupx flag, DI_NOSYNCPROCESSING (0x00400000L) is not support in the Setup APIs.

// flags for device installation
#define DI_QUIETINSTALL             0x00800000L     // don't confuse the user with
                                                    // questions or excess info
#define DI_NOFILECOPY               0x01000000L     // No file Copy necessary
#define DI_FORCECOPY                0x02000000L     // Force files to be copied from install path
#define DI_DRIVERPAGE_ADDED         0x04000000L     // Prop provider added Driver page.
#define DI_USECI_SELECTSTRINGS      0x08000000L     // Use Class Installer Provided strings in the Select Device Dlg
#define DI_OVERRIDE_INFFLAGS        0x10000000L     // Override INF flags
#define DI_PROPS_NOCHANGEUSAGE      0x20000000L     // No Enable/Disable in General Props

#define DI_NOSELECTICONS            0x40000000L     // No small icons in select device dialogs

#define DI_NOWRITE_IDS              0x80000000L     // Don't write HW & Compat IDs on install


//
// SP_DEVINSTALL_PARAMS.FlagsEx values
//
#define DI_FLAGSEX_USEOLDINFSEARCH      0x00000001L  // Inf Search functions should not use Index Search
#define DI_FLAGSEX_AUTOSELECTRANK0      0x00000002L  // SetupDiSelectDevice doesn't prompt user if rank 0 match
#define DI_FLAGSEX_CI_FAILED            0x00000004L  // Failed to Load/Call class installer

#define DI_FLAGSEX_DIDINFOLIST          0x00000010L  // Did the Class Info List
#define DI_FLAGSEX_DIDCOMPATINFO        0x00000020L  // Did the Compat Info List

#define DI_FLAGSEX_FILTERCLASSES        0x00000040L
#define DI_FLAGSEX_SETFAILEDINSTALL     0x00000080L
#define DI_FLAGSEX_DEVICECHANGE         0x00000100L
#define DI_FLAGSEX_ALWAYSWRITEIDS       0x00000200L
#define DI_FLAGSEX_ALLOWEXCLUDEDDRVS    0x00000800L
#define DI_FLAGSEX_NOUIONQUERYREMOVE    0x00001000L
#define DI_FLAGSEX_USECLASSFORCOMPAT    0x00002000L  // Use the device's class when building compat drv list.
                                                     // (Ignored if DI_COMPAT_FROM_CLASS flag is specified.)

#define DI_FLAGSEX_OLDINF_IN_CLASSLIST  0x00004000L  // Search legacy INFs when building class driver list.

#define DI_FLAGSEX_NO_DRVREG_MODIFY     0x00008000L  // Don't run AddReg and DelReg for device's software (driver) key.

//
// Class installation parameters header.  This must be the first field of any class install
// parameter structure.  The InstallFunction field must be set to the function code
// corresponding to the structure, and the cbSize field must be set to the size of the
// header structure.  E.g.,
//
// SP_ENABLECLASS_PARAMS EnableClassParams;
//
// EnableClassParams.ClassInstallHeader.cbSize = sizeof(SP_CLASSINSTALL_HEADER);
// EnableClassParams.ClassInstallHeader.InstallFunction = DIF_ENABLECLASS;
//
typedef struct _SP_CLASSINSTALL_HEADER {
    unsigned long       cbSize;
    DI_FUNCTION InstallFunction;
} SP_CLASSINSTALL_HEADER, *PSP_CLASSINSTALL_HEADER;


//
// Structure corresponding to a DIF_ENABLECLASS install function.
//
typedef struct _SP_ENABLECLASS_PARAMS {
    SP_CLASSINSTALL_HEADER ClassInstallHeader;
    GUID                   ClassGuid;
    unsigned long                  EnableMessage;
} SP_ENABLECLASS_PARAMS, *PSP_ENABLECLASS_PARAMS;

#define ENABLECLASS_QUERY   0
#define ENABLECLASS_SUCCESS 1
#define ENABLECLASS_FAILURE 2


//
// Structure corresponding to a DIF_MOVEDEVICE install function.
//
typedef struct _SP_MOVEDEV_PARAMS {
    SP_CLASSINSTALL_HEADER ClassInstallHeader;
    SP_DEVINFO_DATA        SourceDeviceInfoData;
} SP_MOVEDEV_PARAMS, *PSP_MOVEDEV_PARAMS;


//
// Values indicating a change in a device's state
//
#define DICS_ENABLE      0x00000001
#define DICS_DISABLE     0x00000002
#define DICS_PROPCHANGE  0x00000003
#define DICS_START       0x00000004
#define DICS_STOP        0x00000005
//
// Values specifying the scope of a device property change
//
#define DICS_FLAG_GLOBAL         0x00000001  // make change in all hardware profiles
#define DICS_FLAG_CONFIGSPECIFIC 0x00000002  // make change in specified profile only
#define DICS_FLAG_CONFIGGENERAL  0x00000004  // 1 or more hardware profile-specific
                                             // changes to follow.
//
// Structure corresponding to a DIF_PROPERTYCHANGE install function.
//
typedef struct _SP_PROPCHANGE_PARAMS {
    SP_CLASSINSTALL_HEADER ClassInstallHeader;
    unsigned long                  StateChange;
    unsigned long                  Scope;
    unsigned long                  HwProfile;
} SP_PROPCHANGE_PARAMS, *PSP_PROPCHANGE_PARAMS;


//
// Structure corresponding to a DIF_REMOVE install function.
//
typedef struct _SP_REMOVEDEVICE_PARAMS {
    SP_CLASSINSTALL_HEADER ClassInstallHeader;
    unsigned long Scope;
    unsigned long HwProfile;
} SP_REMOVEDEVICE_PARAMS, *PSP_REMOVEDEVICE_PARAMS;

#define DI_REMOVEDEVICE_GLOBAL                  0x00000001
#define DI_REMOVEDEVICE_CONFIGSPECIFIC          0x00000002


//
// Structure corresponding to a DIF_SELECTDEVICE install function.
//
typedef struct _SP_SELECTDEVICE_PARAMS_A {
    SP_CLASSINSTALL_HEADER ClassInstallHeader;
    CHAR                   Title[MAX_TITLE_LEN];
    CHAR                   Instructions[MAX_INSTRUCTION_LEN];
    CHAR                   ListLabel[MAX_LABEL_LEN];
    BYTE                   Reserved[2];                  // unsigned long size alignment
} SP_SELECTDEVICE_PARAMS_A, *PSP_SELECTDEVICE_PARAMS_A;

typedef struct _SP_SELECTDEVICE_PARAMS_W {
    SP_CLASSINSTALL_HEADER ClassInstallHeader;
    WCHAR                  Title[MAX_TITLE_LEN];
    WCHAR                  Instructions[MAX_INSTRUCTION_LEN];
    WCHAR                  ListLabel[MAX_LABEL_LEN];
} SP_SELECTDEVICE_PARAMS_W, *PSP_SELECTDEVICE_PARAMS_W;

#ifdef UNICODE
typedef SP_SELECTDEVICE_PARAMS_W SP_SELECTDEVICE_PARAMS;
typedef PSP_SELECTDEVICE_PARAMS_W PSP_SELECTDEVICE_PARAMS;
#else
typedef SP_SELECTDEVICE_PARAMS_A SP_SELECTDEVICE_PARAMS;
typedef PSP_SELECTDEVICE_PARAMS_A PSP_SELECTDEVICE_PARAMS;
#endif


//
// 'Add New Device' installation wizard structure
//
// Structure corresponding to a DIF_INSTALLWIZARD install function.
// (NOTE: This structure is also applicable for DIF_DESTROYWIZARDDATA,
// but DIF_INSTALLWIZARD is the associated function code in the class
// installation parameter structure in both cases.)
//
// Define maximum number of dynamic wizard pages that can be added to
// hardware install wizard.
//
#define MAX_INSTALLWIZARD_DYNAPAGES             20

typedef struct _SP_INSTALLWIZARD_DATA {
    SP_CLASSINSTALL_HEADER ClassInstallHeader;
    unsigned long                  Flags;
    HPROPSHEETPAGE         DynamicPages[MAX_INSTALLWIZARD_DYNAPAGES];
    unsigned long                  NumDynamicPages;
    unsigned long                  DynamicPageFlags;
    unsigned long                  PrivateFlags;
    LPARAM                 PrivateData;
    HWND                   hwndWizardDlg;
} SP_INSTALLWIZARD_DATA, *PSP_INSTALLWIZARD_DATA;

//
// SP_INSTALLWIZARD_DATA.Flags values
//
#define NDW_INSTALLFLAG_DIDFACTDEFS         0x00000001
#define NDW_INSTALLFLAG_HARDWAREALLREADYIN  0x00000002
#define NDW_INSTALLFLAG_NEEDRESTART         DI_NEEDRESTART
#define NDW_INSTALLFLAG_NEEDREBOOT          DI_NEEDREBOOT
#define NDW_INSTALLFLAG_NEEDSHUTDOWN        0x00000200
#define NDW_INSTALLFLAG_EXPRESSINTRO        0x00000400
#define NDW_INSTALLFLAG_SKIPISDEVINSTALLED  0x00000800
#define NDW_INSTALLFLAG_NODETECTEDDEVS      0x00001000
#define NDW_INSTALLFLAG_INSTALLSPECIFIC     0x00002000
#define NDW_INSTALLFLAG_SKIPCLASSLIST       0x00004000
#define NDW_INSTALLFLAG_CI_PICKED_OEM       0x00008000
#define NDW_INSTALLFLAG_PCMCIAMODE          0x00010000
#define NDW_INSTALLFLAG_PCMCIADEVICE        0x00020000
#define NDW_INSTALLFLAG_USERCANCEL          0x00040000
#define NDW_INSTALLFLAG_KNOWNCLASS          0x00080000


//
// SP_INSTALLWIZARD_DATA.DynamicPageFlags values
//
// This flag is set if a Class installer has added pages to the
// install wizard.
//
#define DYNAWIZ_FLAG_PAGESADDED             0x00000001

//
// The following flags will control the button states when displaying
// the InstallDetectedDevs dialog.
//
#define DYNAWIZ_FLAG_INSTALLDET_NEXT        0x00000002
#define DYNAWIZ_FLAG_INSTALLDET_PREV        0x00000004

// Set this flag if you jump to the analyze page, and want it to
// handle conflicts for you.  NOTE.  You will not get control back
// in the event of a conflict if you set this flag.
//
// BUGBUG (lonnym): Not currently implemented!
//
#define DYNAWIZ_FLAG_ANALYZE_HANDLECONFLICT 0x00000008

//
// Define wizard page resource IDs to be used when adding custom pages
// to the hardware install wizard.
//
// Resource ID for the first page that the install wizard will go to after
// adding the class installer pages.
//
#define IDD_DYNAWIZ_FIRSTPAGE                   10000

//
// Resource ID for the page that the Select Device page will go back to.
//
#define IDD_DYNAWIZ_SELECT_PREVPAGE             10001

//
// Resource ID for the page that the Select Device page will go forward to.
//
#define IDD_DYNAWIZ_SELECT_NEXTPAGE             10002

//
// Resource ID for the page that the Analyze dialog should go back to
// This will only be used in the event that there is a problem, and the user
// selects Back from the analyze proc.
//
#define IDD_DYNAWIZ_ANALYZE_PREVPAGE            10003

//
// Resource ID for the page that the Analyze dialog should go to if it
// continue from the analyze proc.  the wAnalyzeResult in the INSTALLDATA
// struct will contain the anaysis results.
//
#define IDD_DYNAWIZ_ANALYZE_NEXTPAGE            10004

//
// Resource ID for that page that the Install detected devices page will go
// back to.
//
#define IDD_DYNAWIZ_INSTALLDETECTED_PREVPAGE    10006

//
// Resource ID for the page that the Install detected devices page will go
// forward to.
//
#define IDD_DYNAWIZ_INSTALLDETECTED_NEXTPAGE    10007

//
// Resource ID for the page that the Install detected devices page will go
// to in the event that no devices are detected.
//
#define IDD_DYNAWIZ_INSTALLDETECTED_NODEVS      10008

//
// Resource ID of the hardware install wizard's select device page.
// This ID can be used to go directly to the hardware install wizard's select
// device page.
//
#define IDD_DYNAWIZ_SELECTDEV_PAGE              10009

//
// Resource ID of the hardware install wizard's device analysis page.
// This ID can be use to go directly to the hardware install wizard's analysis
// page.
//
#define IDD_DYNAWIZ_ANALYZEDEV_PAGE             10010

//
// Resource ID of the hardware install wizard's install detected devices page.
// This ID can be use to go directly to the hardware install wizard's install
// detected devices page.
//
#define IDD_DYNAWIZ_INSTALLDETECTEDDEVS_PAGE    10011

//
// Resource ID of the hardware install wizard's select class page.
// This ID can be use to go directly to the hardware install wizard's select
// class page.
//
#define IDD_DYNAWIZ_SELECTCLASS_PAGE            10012


//
// Driver information structure (member of a driver info list that may be associated
// with a particular device instance, or (globally) with a device information set)
//
typedef struct _SP_DRVINFO_DATA_A {
    unsigned long cbSize;
    unsigned long DriverType;
    unsigned long Reserved;
    CHAR  Description[LINE_LEN];
    CHAR  MfgName[LINE_LEN];
    CHAR  ProviderName[LINE_LEN];
} SP_DRVINFO_DATA_A, *PSP_DRVINFO_DATA_A;

typedef struct _SP_DRVINFO_DATA_W {
    unsigned long cbSize;
    unsigned long DriverType;
    unsigned long Reserved;
    WCHAR Description[LINE_LEN];
    WCHAR MfgName[LINE_LEN];
    WCHAR ProviderName[LINE_LEN];
} SP_DRVINFO_DATA_W, *PSP_DRVINFO_DATA_W;

#ifdef UNICODE
typedef SP_DRVINFO_DATA_W SP_DRVINFO_DATA;
typedef PSP_DRVINFO_DATA_W PSP_DRVINFO_DATA;
#else
typedef SP_DRVINFO_DATA_A SP_DRVINFO_DATA;
typedef PSP_DRVINFO_DATA_A PSP_DRVINFO_DATA;
#endif


//
// Driver information details structure (provides detailed information about a
// particular driver information structure)
//
typedef struct _SP_DRVINFO_DETAIL_DATA_A {
    unsigned long    cbSize;
    FILETIME InfDate;
    unsigned long    CompatIDsOffset;
    unsigned long    CompatIDsLength;
    unsigned long    Reserved;
    CHAR     SectionName[LINE_LEN];
    CHAR     InfFileName[MAX_PATH];
    CHAR     DrvDescription[LINE_LEN];
    CHAR     HardwareID[ANYSIZE_ARRAY];
} SP_DRVINFO_DETAIL_DATA_A, *PSP_DRVINFO_DETAIL_DATA_A;

typedef struct _SP_DRVINFO_DETAIL_DATA_W {
    unsigned long    cbSize;
    FILETIME InfDate;
    unsigned long    CompatIDsOffset;
    unsigned long    CompatIDsLength;
    unsigned long    Reserved;
    WCHAR    SectionName[LINE_LEN];
    WCHAR    InfFileName[MAX_PATH];
    WCHAR    DrvDescription[LINE_LEN];
    WCHAR    HardwareID[ANYSIZE_ARRAY];
} SP_DRVINFO_DETAIL_DATA_W, *PSP_DRVINFO_DETAIL_DATA_W;

#ifdef UNICODE
typedef SP_DRVINFO_DETAIL_DATA_W SP_DRVINFO_DETAIL_DATA;
typedef PSP_DRVINFO_DETAIL_DATA_W PSP_DRVINFO_DETAIL_DATA;
#else
typedef SP_DRVINFO_DETAIL_DATA_A SP_DRVINFO_DETAIL_DATA;
typedef PSP_DRVINFO_DETAIL_DATA_A PSP_DRVINFO_DETAIL_DATA;
#endif


//
// Driver installation parameters (associated with a particular driver
// information element)
//
typedef struct _SP_DRVINSTALL_PARAMS {
    unsigned long cbSize;
    unsigned long Rank;
    unsigned long Flags;
    unsigned long PrivateData;
    unsigned long Reserved;
} SP_DRVINSTALL_PARAMS, *PSP_DRVINSTALL_PARAMS;

//
// SP_DRVINSTALL_PARAMS.Flags values
//
#define DNF_DUPDESC         0x00000001   // Multiple providers have same desc
#define DNF_OLDDRIVER       0x00000002   // Driver node specifies old/current driver
#define DNF_EXCLUDEFROMLIST 0x00000004   // If set, this driver node will not be
                                         // displayed in any driver select dialogs.
#define DNF_NODRIVER        0x00000008   // if we want to install no driver
                                         // (e.g no mouse drv)
#define DNF_LEGACYINF       0x00000010   // this driver node comes from an old-style INF


//
// Setup callback routine for comparing detection signatures
//
typedef unsigned long (__stdcall* PSP_DETSIG_CMPPROC)(
    IN HDEVINFO         DeviceInfoSet,
    IN PSP_DEVINFO_DATA NewDeviceData,
    IN PSP_DEVINFO_DATA ExistingDeviceData,
    IN void*            CompareContext      OPTIONAL
    );


//
// Structure containing class image list information.
//
typedef struct _SP_CLASSIMAGELIST_DATA {
    unsigned long      cbSize;
    HIMAGELIST ImageList;
    unsigned long      Reserved;
} SP_CLASSIMAGELIST_DATA, *PSP_CLASSIMAGELIST_DATA;


//
// Structure to be passed as first parameter (void* lpv) to ExtensionPropSheetPageProc
// entry point in setupapi.dll.  Used to retrieve a handle for a specified property page.
//
typedef struct _SP_PROPSHEETPAGE_REQUEST {
    unsigned long            cbSize;
    unsigned long            PageRequested;
    HDEVINFO         DeviceInfoSet;
    PSP_DEVINFO_DATA DeviceInfoData;
} SP_PROPSHEETPAGE_REQUEST, *PSP_PROPSHEETPAGE_REQUEST;

//
// Property sheet codes used in SP_PROPSHEETPAGE_REQUEST.PageRequested
//
#define SPPSR_SELECT_DEVICE_RESOURCES  1


//
// Setupapi-specific error codes
//
// Inf parse outcomes
//
#define ERROR_EXPECTED_SECTION_NAME  (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR|0)
#define ERROR_BAD_SECTION_NAME_LINE  (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR|1)
#define ERROR_SECTION_NAME_TOO_LONG  (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR|2)
#define ERROR_GENERAL_SYNTAX         (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR|3)
//
// Inf runtime errors
//
#define ERROR_WRONG_INF_STYLE        (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR|0x100)
#define ERROR_SECTION_NOT_FOUND      (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR|0x101)
#define ERROR_LINE_NOT_FOUND         (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR|0x102)
//
// Device Installer errors
//
#define ERROR_NO_ASSOCIATED_CLASS     (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR|0x200)
#define ERROR_CLASS_MISMATCH          (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR|0x201)
#define ERROR_DUPLICATE_FOUND         (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR|0x202)
#define ERROR_NO_DRIVER_SELECTED      (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR|0x203)
#define ERROR_KEY_DOES_NOT_EXIST      (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR|0x204)
#define ERROR_INVALID_DEVINST_NAME    (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR|0x205)
#define ERROR_INVALID_CLASS           (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR|0x206)
#define ERROR_DEVINST_ALREADY_EXISTS  (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR|0x207)
#define ERROR_DEVINFO_NOT_REGISTERED  (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR|0x208)
#define ERROR_INVALID_REG_PROPERTY    (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR|0x209)
#define ERROR_NO_INF                  (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR|0x20A)
#define ERROR_NO_SUCH_DEVINST         (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR|0x20B)
#define ERROR_CANT_LOAD_CLASS_ICON    (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR|0x20C)
#define ERROR_INVALID_CLASS_INSTALLER (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR|0x20D)
#define ERROR_DI_DO_DEFAULT           (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR|0x20E)
#define ERROR_DI_NOFILECOPY           (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR|0x20F)
#define ERROR_INVALID_HWPROFILE       (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR|0x210)
#define ERROR_NO_DEVICE_SELECTED      (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR|0x211)
#define ERROR_DEVINFO_LIST_LOCKED     (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR|0x212)
#define ERROR_DEVINFO_DATA_LOCKED     (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR|0x213)
#define ERROR_DI_BAD_PATH             (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR|0x214)
#define ERROR_NO_CLASSINSTALL_PARAMS  (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR|0x215)
#define ERROR_FILEQUEUE_LOCKED        (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR|0x216)
#define ERROR_BAD_SERVICE_INSTALLSECT (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR|0x217)
#define ERROR_NO_CLASS_DRIVER_LIST    (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR|0x218)
#define ERROR_NO_ASSOCIATED_SERVICE   (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR|0x219)


/*WINSETUPAPI*/
BOOL
__stdcall
SetupGetInfInformationA(
    IN  LPCVOID             InfSpec,
    IN  unsigned long               SearchControl,
    OUT PSP_INF_INFORMATION ReturnBuffer,     OPTIONAL
    IN  unsigned long               ReturnBufferSize,
    OUT unsigned long*              RequiredSize      OPTIONAL
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupGetInfInformationW(
    IN  LPCVOID             InfSpec,
    IN  unsigned long               SearchControl,
    OUT PSP_INF_INFORMATION ReturnBuffer,     OPTIONAL
    IN  unsigned long               ReturnBufferSize,
    OUT unsigned long*              RequiredSize      OPTIONAL
    );

//
// SearchControl flags for SetupGetInfInformation
//
#define INFINFO_INF_SPEC_IS_HINF        1
#define INFINFO_INF_NAME_IS_ABSOLUTE    2
#define INFINFO_DEFAULT_SEARCH          3
#define INFINFO_REVERSE_DEFAULT_SEARCH  4
#define INFINFO_INF_PATH_LIST_SEARCH    5

#ifdef UNICODE
#define SetupGetInfInformation SetupGetInfInformationW
#else
#define SetupGetInfInformation SetupGetInfInformationA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupQueryInfFileInformationA(
    IN  PSP_INF_INFORMATION InfInformation,
    IN  unsigned                InfIndex,
    OUT char*                ReturnBuffer,     OPTIONAL
    IN  unsigned long               ReturnBufferSize,
    OUT unsigned long*              RequiredSize      OPTIONAL
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupQueryInfFileInformationW(
    IN  PSP_INF_INFORMATION InfInformation,
    IN  unsigned                InfIndex,
    OUT wchar_t*               ReturnBuffer,     OPTIONAL
    IN  unsigned long               ReturnBufferSize,
    OUT unsigned long*              RequiredSize      OPTIONAL
    );

#ifdef UNICODE
#define SetupQueryInfFileInformation SetupQueryInfFileInformationW
#else
#define SetupQueryInfFileInformation SetupQueryInfFileInformationA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupQueryInfVersionInformationA(
    IN  PSP_INF_INFORMATION InfInformation,
    IN  unsigned                InfIndex,
    IN  const char*               Key,              OPTIONAL
    OUT char*                ReturnBuffer,     OPTIONAL
    IN  unsigned long               ReturnBufferSize,
    OUT unsigned long*              RequiredSize      OPTIONAL
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupQueryInfVersionInformationW(
    IN  PSP_INF_INFORMATION InfInformation,
    IN  unsigned                InfIndex,
    IN  const wchar_t*              Key,              OPTIONAL
    OUT wchar_t*               ReturnBuffer,     OPTIONAL
    IN  unsigned long               ReturnBufferSize,
    OUT unsigned long*              RequiredSize      OPTIONAL
    );

#ifdef UNICODE
#define SetupQueryInfVersionInformation SetupQueryInfVersionInformationW
#else
#define SetupQueryInfVersionInformation SetupQueryInfVersionInformationA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupGetInfFileListA(
    IN  const char*  DirectoryPath,    OPTIONAL
    IN  unsigned long  InfStyle,
    OUT char*   ReturnBuffer,     OPTIONAL
    IN  unsigned long  ReturnBufferSize,
    OUT unsigned long* RequiredSize      OPTIONAL
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupGetInfFileListW(
    IN  const wchar_t* DirectoryPath,    OPTIONAL
    IN  unsigned long  InfStyle,
    OUT wchar_t*  ReturnBuffer,     OPTIONAL
    IN  unsigned long  ReturnBufferSize,
    OUT unsigned long* RequiredSize      OPTIONAL
    );

#ifdef UNICODE
#define SetupGetInfFileList SetupGetInfFileListW
#else
#define SetupGetInfFileList SetupGetInfFileListA
#endif


/*WINSETUPAPI*/
HINF
__stdcall
SetupOpenInfFileW(
    IN  const wchar_t* FileName,
    IN  const wchar_t* InfClass,    OPTIONAL
    IN  unsigned long  InfStyle,
    OUT PUINT  ErrorLine    OPTIONAL
    );

/*WINSETUPAPI*/
HINF
__stdcall
SetupOpenInfFileA(
    IN  const char* FileName,
    IN  const char* InfClass,     OPTIONAL
    IN  unsigned long InfStyle,
    OUT PUINT ErrorLine     OPTIONAL
    );

#ifdef UNICODE
#define SetupOpenInfFile SetupOpenInfFileW
#else
#define SetupOpenInfFile SetupOpenInfFileA
#endif


/*WINSETUPAPI*/
HINF
__stdcall
SetupOpenMasterInf(
    void
    );


/*WINSETUPAPI*/
BOOL
__stdcall
SetupOpenAppendInfFileW(
    IN  const wchar_t* FileName,    OPTIONAL
    IN  HINF   InfHandle,
    OUT PUINT  ErrorLine    OPTIONAL
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupOpenAppendInfFileA(
    IN  const char* FileName,     OPTIONAL
    IN  HINF  InfHandle,
    OUT PUINT ErrorLine     OPTIONAL
    );

#ifdef UNICODE
#define SetupOpenAppendInfFile SetupOpenAppendInfFileW
#else
#define SetupOpenAppendInfFile SetupOpenAppendInfFileA
#endif


/*WINSETUPAPI*/
void
__stdcall
SetupCloseInfFile(
    IN HINF InfHandle
    );


/*WINSETUPAPI*/
BOOL
__stdcall
SetupFindFirstLineA(
    IN  HINF        InfHandle,
    IN  const char*       Section,
    IN  const char*       Key,          OPTIONAL
    OUT PINFCONTEXT Context
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupFindFirstLineW(
    IN  HINF        InfHandle,
    IN  const wchar_t*      Section,
    IN  const wchar_t*      Key,          OPTIONAL
    OUT PINFCONTEXT Context
    );

#ifdef UNICODE
#define SetupFindFirstLine SetupFindFirstLineW
#else
#define SetupFindFirstLine SetupFindFirstLineA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupFindNextLine(
    IN  PINFCONTEXT ContextIn,
    OUT PINFCONTEXT ContextOut
    );


/*WINSETUPAPI*/
BOOL
__stdcall
SetupFindNextMatchLineA(
    IN  PINFCONTEXT ContextIn,
    IN  const char*       Key,        OPTIONAL
    OUT PINFCONTEXT ContextOut
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupFindNextMatchLineW(
    IN  PINFCONTEXT ContextIn,
    IN  const wchar_t*      Key,        OPTIONAL
    OUT PINFCONTEXT ContextOut
    );

#ifdef UNICODE
#define SetupFindNextMatchLine SetupFindNextMatchLineW
#else
#define SetupFindNextMatchLine SetupFindNextMatchLineA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupGetLineByIndexA(
    IN  HINF        InfHandle,
    IN  const char*       Section,
    IN  unsigned long       Index,
    OUT PINFCONTEXT Context
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupGetLineByIndexW(
    IN  HINF        InfHandle,
    IN  const wchar_t*      Section,
    IN  unsigned long       Index,
    OUT PINFCONTEXT Context
    );

#ifdef UNICODE
#define SetupGetLineByIndex SetupGetLineByIndexW
#else
#define SetupGetLineByIndex SetupGetLineByIndexA
#endif


/*WINSETUPAPI*/
LONG
__stdcall
SetupGetLineCountA(
    IN HINF  InfHandle,
    IN const char* Section
    );

/*WINSETUPAPI*/
LONG
__stdcall
SetupGetLineCountW(
    IN HINF   InfHandle,
    IN const wchar_t* Section
    );

#ifdef UNICODE
#define SetupGetLineCount SetupGetLineCountW
#else
#define SetupGetLineCount SetupGetLineCountA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupGetLineTextA(
    IN  PINFCONTEXT Context,          OPTIONAL
    IN  HINF        InfHandle,        OPTIONAL
    IN  const char*       Section,          OPTIONAL
    IN  const char*       Key,              OPTIONAL
    OUT char*        ReturnBuffer,     OPTIONAL
    IN  unsigned long       ReturnBufferSize,
    OUT unsigned long*      RequiredSize      OPTIONAL
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupGetLineTextW(
    IN  PINFCONTEXT Context,          OPTIONAL
    IN  HINF        InfHandle,        OPTIONAL
    IN  const wchar_t*      Section,          OPTIONAL
    IN  const wchar_t*      Key,              OPTIONAL
    OUT wchar_t*       ReturnBuffer,     OPTIONAL
    IN  unsigned long       ReturnBufferSize,
    OUT unsigned long*      RequiredSize      OPTIONAL
    );

#ifdef UNICODE
#define SetupGetLineText SetupGetLineTextW
#else
#define SetupGetLineText SetupGetLineTextA
#endif


/*WINSETUPAPI*/
unsigned long
__stdcall
SetupGetFieldCount(
    IN PINFCONTEXT Context
    );


/*WINSETUPAPI*/
BOOL
__stdcall
SetupGetStringFieldA(
    IN  PINFCONTEXT Context,
    IN  unsigned long       FieldIndex,
    OUT char*        ReturnBuffer,     OPTIONAL
    IN  unsigned long       ReturnBufferSize,
    OUT unsigned long*      RequiredSize      OPTIONAL
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupGetStringFieldW(
    IN  PINFCONTEXT Context,
    IN  unsigned long       FieldIndex,
    OUT wchar_t*       ReturnBuffer,     OPTIONAL
    IN  unsigned long       ReturnBufferSize,
    OUT unsigned long*      RequiredSize      OPTIONAL
    );

#ifdef UNICODE
#define SetupGetStringField SetupGetStringFieldW
#else
#define SetupGetStringField SetupGetStringFieldA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupGetIntField(
    IN  PINFCONTEXT Context,
    IN  unsigned long       FieldIndex,
    OUT PINT        IntegerValue
    );


/*WINSETUPAPI*/
BOOL
__stdcall
SetupGetMultiSzFieldA(
    IN  PINFCONTEXT Context,
    IN  unsigned long       FieldIndex,
    OUT char*        ReturnBuffer,     OPTIONAL
    IN  unsigned long       ReturnBufferSize,
    OUT LPDWORD     RequiredSize      OPTIONAL
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupGetMultiSzFieldW(
    IN  PINFCONTEXT Context,
    IN  unsigned long       FieldIndex,
    OUT wchar_t*       ReturnBuffer,     OPTIONAL
    IN  unsigned long       ReturnBufferSize,
    OUT LPDWORD     RequiredSize      OPTIONAL
    );

#ifdef UNICODE
#define SetupGetMultiSzField SetupGetMultiSzFieldW
#else
#define SetupGetMultiSzField SetupGetMultiSzFieldA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupGetBinaryField(
    IN  PINFCONTEXT Context,
    IN  unsigned long       FieldIndex,
    OUT PBYTE       ReturnBuffer,     OPTIONAL
    IN  unsigned long       ReturnBufferSize,
    OUT LPDWORD     RequiredSize      OPTIONAL
    );


/*WINSETUPAPI*/
unsigned long
__stdcall
SetupGetFileCompressionInfoA(
    IN  const char*   SourceFileName,
    OUT char*   *ActualSourceFileName,
    OUT unsigned long*  SourceFileSize,
    OUT unsigned long*  TargetFileSize,
    OUT PUINT   CompressionType
    );

/*WINSETUPAPI*/
unsigned long
__stdcall
SetupGetFileCompressionInfoW(
    IN  const wchar_t*  SourceFileName,
    OUT wchar_t*  *ActualSourceFileName,
    OUT unsigned long*  SourceFileSize,
    OUT unsigned long*  TargetFileSize,
    OUT PUINT   CompressionType
    );

#ifdef UNICODE
#define SetupGetFileCompressionInfo SetupGetFileCompressionInfoW
#else
#define SetupGetFileCompressionInfo SetupGetFileCompressionInfoA
#endif


//
// Compression types
//
#define FILE_COMPRESSION_NONE       0
#define FILE_COMPRESSION_WINLZA     1
#define FILE_COMPRESSION_MSZIP      2


/*WINSETUPAPI*/
unsigned long
__stdcall
SetupDecompressOrCopyFileA(
    IN const char* SourceFileName,
    IN const char* TargetFileName,
    IN PUINT CompressionType OPTIONAL
    );

/*WINSETUPAPI*/
unsigned long
__stdcall
SetupDecompressOrCopyFileW(
    IN const wchar_t* SourceFileName,
    IN const wchar_t* TargetFileName,
    IN PUINT  CompressionType OPTIONAL
    );

#ifdef UNICODE
#define SetupDecompressOrCopyFile SetupDecompressOrCopyFileW
#else
#define SetupDecompressOrCopyFile SetupDecompressOrCopyFileA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupGetSourceFileLocationA(
    IN  HINF        InfHandle,
    IN  PINFCONTEXT InfContext,       OPTIONAL
    IN  const char*       FileName,         OPTIONAL
    OUT PUINT       SourceId,
    OUT char*        ReturnBuffer,     OPTIONAL
    IN  unsigned long       ReturnBufferSize,
    OUT unsigned long*      RequiredSize      OPTIONAL
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupGetSourceFileLocationW(
    IN  HINF        InfHandle,
    IN  PINFCONTEXT InfContext,       OPTIONAL
    IN  const wchar_t*      FileName,         OPTIONAL
    OUT PUINT       SourceId,
    OUT wchar_t*       ReturnBuffer,     OPTIONAL
    IN  unsigned long       ReturnBufferSize,
    OUT unsigned long*      RequiredSize      OPTIONAL
    );

#ifdef UNICODE
#define SetupGetSourceFileLocation SetupGetSourceFileLocationW
#else
#define SetupGetSourceFileLocation SetupGetSourceFileLocationA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupGetSourceFileSizeA(
    IN  HINF        InfHandle,
    IN  PINFCONTEXT InfContext,     OPTIONAL
    IN  const char*       FileName,       OPTIONAL
    IN  const char*       Section,        OPTIONAL
    OUT unsigned long*      FileSize,
    IN  unsigned        RoundingFactor  OPTIONAL
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupGetSourceFileSizeW(
    IN  HINF        InfHandle,
    IN  PINFCONTEXT InfContext,     OPTIONAL
    IN  const wchar_t*      FileName,       OPTIONAL
    IN  const wchar_t*      Section,        OPTIONAL
    OUT unsigned long*      FileSize,
    IN  unsigned        RoundingFactor  OPTIONAL
    );

#ifdef UNICODE
#define SetupGetSourceFileSize SetupGetSourceFileSizeW
#else
#define SetupGetSourceFileSize SetupGetSourceFileSizeA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupGetTargetPathA(
    IN  HINF        InfHandle,
    IN  PINFCONTEXT InfContext,       OPTIONAL
    IN  const char*       Section,          OPTIONAL
    OUT char*        ReturnBuffer,     OPTIONAL
    IN  unsigned long       ReturnBufferSize,
    OUT unsigned long*      RequiredSize      OPTIONAL
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupGetTargetPathW(
    IN  HINF        InfHandle,
    IN  PINFCONTEXT InfContext,       OPTIONAL
    IN  const wchar_t*      Section,          OPTIONAL
    OUT wchar_t*       ReturnBuffer,     OPTIONAL
    IN  unsigned long       ReturnBufferSize,
    OUT unsigned long*      RequiredSize      OPTIONAL
    );

#ifdef UNICODE
#define SetupGetTargetPath SetupGetTargetPathW
#else
#define SetupGetTargetPath SetupGetTargetPathA
#endif


//
// Define flags for SourceList APIs.
//
#define SRCLIST_TEMPORARY       0x00000001
#define SRCLIST_NOBROWSE        0x00000002
#define SRCLIST_SYSTEM          0x00000010
#define SRCLIST_USER            0x00000020
#define SRCLIST_SYSIFADMIN      0x00000040
#define SRCLIST_SUBDIRS         0x00000100
#define SRCLIST_APPEND          0x00000200
#define SRCLIST_NOSTRIPPLATFORM 0x00000400


/*WINSETUPAPI*/
BOOL
__stdcall
SetupSetSourceListA(
    IN unsigned long  Flags,
    IN const char* *SourceList,
    IN unsigned   SourceCount
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupSetSourceListW(
    IN unsigned long   Flags,
    IN const wchar_t* *SourceList,
    IN unsigned    SourceCount
    );

#ifdef UNICODE
#define SetupSetSourceList SetupSetSourceListW
#else
#define SetupSetSourceList SetupSetSourceListA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupCancelTemporarySourceList(
    void
    );


/*WINSETUPAPI*/
BOOL
__stdcall
SetupAddToSourceListA(
    IN unsigned long Flags,
    IN const char* Source
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupAddToSourceListW(
    IN unsigned long  Flags,
    IN const wchar_t* Source
    );

#ifdef UNICODE
#define SetupAddToSourceList SetupAddToSourceListW
#else
#define SetupAddToSourceList SetupAddToSourceListA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupRemoveFromSourceListA(
    IN unsigned long Flags,
    IN const char* Source
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupRemoveFromSourceListW(
    IN unsigned long  Flags,
    IN const wchar_t* Source
    );

#ifdef UNICODE
#define SetupRemoveFromSourceList SetupRemoveFromSourceListW
#else
#define SetupRemoveFromSourceList SetupRemoveFromSourceListA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupQuerySourceListA(
    IN  unsigned long   Flags,
    OUT const char* **List,
    OUT PUINT   Count
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupQuerySourceListW(
    IN  unsigned long    Flags,
    OUT const wchar_t* **List,
    OUT PUINT    Count
    );

#ifdef UNICODE
#define SetupQuerySourceList SetupQuerySourceListW
#else
#define SetupQuerySourceList SetupQuerySourceListA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupFreeSourceListA(
    IN OUT const char* **List,
    IN     unsigned    Count
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupFreeSourceListW(
    IN OUT const wchar_t* **List,
    IN     unsigned     Count
    );

#ifdef UNICODE
#define SetupFreeSourceList SetupFreeSourceListW
#else
#define SetupFreeSourceList SetupFreeSourceListA
#endif


/*WINSETUPAPI*/
unsigned
__stdcall
SetupPromptForDiskA(
    IN  HWND   hwndParent,
    IN  const char*  DialogTitle,      OPTIONAL
    IN  const char*  DiskName,         OPTIONAL
    IN  const char*  PathToSource,     OPTIONAL
    IN  const char*  FileSought,
    IN  const char*  TagFile,          OPTIONAL
    IN  unsigned long  DiskPromptStyle,
    OUT char*   PathBuffer,
    IN  unsigned long  PathBufferSize,
    OUT unsigned long* PathRequiredSize
    );

/*WINSETUPAPI*/
unsigned
__stdcall
SetupPromptForDiskW(
    IN  HWND   hwndParent,
    IN  const wchar_t* DialogTitle,      OPTIONAL
    IN  const wchar_t* DiskName,         OPTIONAL
    IN  const wchar_t* PathToSource,     OPTIONAL
    IN  const wchar_t* FileSought,
    IN  const wchar_t* TagFile,          OPTIONAL
    IN  unsigned long  DiskPromptStyle,
    OUT wchar_t*  PathBuffer,
    IN  unsigned long  PathBufferSize,
    OUT unsigned long* PathRequiredSize
    );

#ifdef UNICODE
#define SetupPromptForDisk SetupPromptForDiskW
#else
#define SetupPromptForDisk SetupPromptForDiskA
#endif


/*WINSETUPAPI*/
unsigned
__stdcall
SetupCopyErrorA(
    IN  HWND   hwndParent,
    IN  const char*  DialogTitle,     OPTIONAL
    IN  const char*  DiskName,        OPTIONAL
    IN  const char*  PathToSource,
    IN  const char*  SourceFile,
    IN  const char*  TargetPathFile,  OPTIONAL
    IN  unsigned   Win32ErrorCode,
    IN  unsigned long  Style,
    OUT char*   PathBuffer,      OPTIONAL
    IN  unsigned long  PathBufferSize,
    OUT unsigned long* PathRequiredSize OPTIONAL
    );

/*WINSETUPAPI*/
unsigned
__stdcall
SetupCopyErrorW(
    IN  HWND   hwndParent,
    IN  const wchar_t* DialogTitle,     OPTIONAL
    IN  const wchar_t* DiskName,        OPTIONAL
    IN  const wchar_t* PathToSource,
    IN  const wchar_t* SourceFile,
    IN  const wchar_t* TargetPathFile,  OPTIONAL
    IN  unsigned   Win32ErrorCode,
    IN  unsigned long  Style,
    OUT wchar_t*  PathBuffer,      OPTIONAL
    IN  unsigned long  PathBufferSize,
    OUT unsigned long* PathRequiredSize OPTIONAL
    );

#ifdef UNICODE
#define SetupCopyError SetupCopyErrorW
#else
#define SetupCopyError SetupCopyErrorA
#endif


/*WINSETUPAPI*/
unsigned
__stdcall
SetupRenameErrorA(
    IN  HWND   hwndParent,
    IN  const char*  DialogTitle,     OPTIONAL
    IN  const char*  SourceFile,
    IN  const char*  TargetFile,
    IN  unsigned   Win32ErrorCode,
    IN  unsigned long  Style
    );

/*WINSETUPAPI*/
unsigned
__stdcall
SetupRenameErrorW(
    IN  HWND   hwndParent,
    IN  const wchar_t* DialogTitle,     OPTIONAL
    IN  const wchar_t* SourceFile,
    IN  const wchar_t* TargetFile,
    IN  unsigned   Win32ErrorCode,
    IN  unsigned long  Style
    );

#ifdef UNICODE
#define SetupRenameError SetupRenameErrorW
#else
#define SetupRenameError SetupRenameErrorA
#endif


/*WINSETUPAPI*/
unsigned
__stdcall
SetupDeleteErrorA(
    IN  HWND   hwndParent,
    IN  const char*  DialogTitle,     OPTIONAL
    IN  const char*  File,
    IN  unsigned   Win32ErrorCode,
    IN  unsigned long  Style
    );

/*WINSETUPAPI*/
unsigned
__stdcall
SetupDeleteErrorW(
    IN  HWND   hwndParent,
    IN  const wchar_t* DialogTitle,     OPTIONAL
    IN  const wchar_t* File,
    IN  unsigned   Win32ErrorCode,
    IN  unsigned long  Style
    );

#ifdef UNICODE
#define SetupDeleteError SetupDeleteErrorW
#else
#define SetupDeleteError SetupDeleteErrorA
#endif


//
// Styles for SetupPromptForDisk, SetupCopyError,
// SetupRenameError, SetupDeleteError
//
#define IDF_NOBROWSE        0x00000001
#define IDF_NOSKIP          0x00000002
#define IDF_NODETAILS       0x00000004
#define IDF_NOCOMPRESSED    0x00000008
#define IDF_CHECKFIRST      0x00000100
#define IDF_NOBEEP          0x00000200
#define IDF_NOFOREGROUND    0x00000400
#define IDF_WARNIFSKIP      0x00000800
#define IDF_OEMDISK         0x80000000

//
// Return values for SetupPromptForDisk, SetupCopyError,
// SetupRenameError, SetupDeleteError
//
#define DPROMPT_SUCCESS         0
#define DPROMPT_CANCEL          1
#define DPROMPT_SKIPFILE        2
#define DPROMPT_BUFFERTOOSMALL  3
#define DPROMPT_OUTOFMEMORY     4


/*WINSETUPAPI*/
BOOL
__stdcall
SetupSetDirectoryIdA(
    IN HINF  InfHandle,
    IN unsigned long Id,            OPTIONAL
    IN const char* Directory      OPTIONAL
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupSetDirectoryIdW(
    IN HINF   InfHandle,
    IN unsigned long  Id,           OPTIONAL
    IN const wchar_t* Directory     OPTIONAL
    );

#ifdef UNICODE
#define SetupSetDirectoryId SetupSetDirectoryIdW
#else
#define SetupSetDirectoryId SetupSetDirectoryIdA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupGetSourceInfoA(
    IN  HINF   InfHandle,
    IN  unsigned   SourceId,
    IN  unsigned   InfoDesired,
    OUT char*   ReturnBuffer,     OPTIONAL
    IN  unsigned long  ReturnBufferSize,
    OUT unsigned long* RequiredSize      OPTIONAL
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupGetSourceInfoW(
    IN  HINF   InfHandle,
    IN  unsigned   SourceId,
    IN  unsigned   InfoDesired,
    OUT wchar_t*  ReturnBuffer,     OPTIONAL
    IN  unsigned long  ReturnBufferSize,
    OUT unsigned long* RequiredSize      OPTIONAL
    );

#ifdef UNICODE
#define SetupGetSourceInfo SetupGetSourceInfoW
#else
#define SetupGetSourceInfo SetupGetSourceInfoA
#endif

//
// InfoDesired values for SetupGetSourceInfo
//
#define SRCINFO_PATH            1
#define SRCINFO_TAGFILE         2
#define SRCINFO_DESCRIPTION     3


/*WINSETUPAPI*/
BOOL
__stdcall
SetupInstallFileA(
    IN HINF                InfHandle,         OPTIONAL
    IN PINFCONTEXT         InfContext,        OPTIONAL
    IN const char*               SourceFile,        OPTIONAL
    IN const char*               SourcePathRoot,    OPTIONAL
    IN const char*               DestinationName,   OPTIONAL
    IN unsigned long               CopyStyle,
    IN PSP_FILE_CALLBACK_A CopyMsgHandler,    OPTIONAL
    IN void*               Context            OPTIONAL
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupInstallFileW(
    IN HINF                InfHandle,         OPTIONAL
    IN PINFCONTEXT         InfContext,        OPTIONAL
    IN const wchar_t*              SourceFile,        OPTIONAL
    IN const wchar_t*              SourcePathRoot,    OPTIONAL
    IN const wchar_t*              DestinationName,   OPTIONAL
    IN unsigned long               CopyStyle,
    IN PSP_FILE_CALLBACK_W CopyMsgHandler,    OPTIONAL
    IN void*               Context            OPTIONAL
    );

#ifdef UNICODE
#define SetupInstallFile SetupInstallFileW
#else
#define SetupInstallFile SetupInstallFileA
#endif

/*WINSETUPAPI*/
BOOL
__stdcall
SetupInstallFileExA(
    IN  HINF                InfHandle,         OPTIONAL
    IN  PINFCONTEXT         InfContext,        OPTIONAL
    IN  const char*               SourceFile,        OPTIONAL
    IN  const char*               SourcePathRoot,    OPTIONAL
    IN  const char*               DestinationName,   OPTIONAL
    IN  unsigned long               CopyStyle,
    IN  PSP_FILE_CALLBACK_A CopyMsgHandler,    OPTIONAL
    IN  void*               Context,           OPTIONAL
    OUT BOOL*               FileWasInUse
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupInstallFileExW(
    IN  HINF                InfHandle,         OPTIONAL
    IN  PINFCONTEXT         InfContext,        OPTIONAL
    IN  const wchar_t*              SourceFile,        OPTIONAL
    IN  const wchar_t*              SourcePathRoot,    OPTIONAL
    IN  const wchar_t*              DestinationName,   OPTIONAL
    IN  unsigned long               CopyStyle,
    IN  PSP_FILE_CALLBACK_W CopyMsgHandler,    OPTIONAL
    IN  void*               Context,           OPTIONAL
    OUT BOOL*               FileWasInUse
    );

#ifdef UNICODE
#define SetupInstallFileEx SetupInstallFileExW
#else
#define SetupInstallFileEx SetupInstallFileExA
#endif

//
// CopyStyle values for copy and queue-related APIs
//
#define SP_COPY_DELETESOURCE        0x0000001   // delete source file on successful copy
#define SP_COPY_REPLACEONLY         0x0000002   // copy only if target file already present
#define SP_COPY_NEWER               0x0000004   // copy only if source file newer than target
#define SP_COPY_NOOVERWRITE         0x0000008   // copy only if target doesn't exist
#define SP_COPY_NODECOMP            0x0000010   // don't decompress source file while copying
#define SP_COPY_LANGUAGEAWARE       0x0000020   // don't overwrite file of different language
#define SP_COPY_SOURCE_ABSOLUTE     0x0000040   // SourceFile is a full source path
#define SP_COPY_SOURCEPATH_ABSOLUTE 0x0000080   // SourcePathRoot is the full path
#define SP_COPY_IN_USE_NEEDS_REBOOT 0x0000100   // System needs reboot if file in use
#define SP_COPY_FORCE_IN_USE        0x0000200   // Force target-in-use behavior
#define SP_COPY_NOSKIP              0x0000400   // Skip is disallowed for this file or section
#define SP_FLAG_CABINETCONTINUATION 0x0000800   // Used with need media notification
#define SP_COPY_FORCE_NOOVERWRITE   0x0001000   // like NOOVERWRITE but no callback nofitication
#define SP_COPY_FORCE_NEWER         0x0002000   // like NEWER but no callback nofitication
#define SP_COPY_WARNIFSKIP          0x0004000   // system critical file: warn if user tries to skip
#define SP_COPY_NOBROWSE            0x0008000   // Browsing is disallowed for this file or section


/*WINSETUPAPI*/
HSPFILEQ
__stdcall
SetupOpenFileQueue(
    void
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupCloseFileQueue(
    IN HSPFILEQ QueueHandle
    );


/*WINSETUPAPI*/
BOOL
__stdcall
SetupSetPlatformPathOverrideA(
    IN const char* Override   OPTIONAL
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupSetPlatformPathOverrideW(
    IN const wchar_t* Override  OPTIONAL
    );

#ifdef UNICODE
#define SetupSetPlatformPathOverride SetupSetPlatformPathOverrideW
#else
#define SetupSetPlatformPathOverride SetupSetPlatformPathOverrideA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupQueueCopyA(
    IN HSPFILEQ QueueHandle,
    IN const char*    SourceRootPath,
    IN const char*    SourcePath,         OPTIONAL
    IN const char*    SourceFilename,
    IN const char*    SourceDescription,  OPTIONAL
    IN const char*    SourceTagfile,      OPTIONAL
    IN const char*    TargetDirectory,
    IN const char*    TargetFilename,     OPTIONAL
    IN unsigned long    CopyStyle
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupQueueCopyW(
    IN HSPFILEQ QueueHandle,
    IN const wchar_t*   SourceRootPath,
    IN const wchar_t*   SourcePath,         OPTIONAL
    IN const wchar_t*   SourceFilename,
    IN const wchar_t*   SourceDescription,  OPTIONAL
    IN const wchar_t*   SourceTagfile,      OPTIONAL
    IN const wchar_t*   TargetDirectory,
    IN const wchar_t*   TargetFilename,     OPTIONAL
    IN unsigned long    CopyStyle
    );

#ifdef UNICODE
#define SetupQueueCopy SetupQueueCopyW
#else
#define SetupQueueCopy SetupQueueCopyA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupQueueDefaultCopyA(
    IN HSPFILEQ QueueHandle,
    IN HINF     InfHandle,
    IN const char*    SourceRootPath,
    IN const char*    SourceFilename,
    IN const char*    TargetFilename,
    IN unsigned long    CopyStyle
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupQueueDefaultCopyW(
    IN HSPFILEQ QueueHandle,
    IN HINF     InfHandle,
    IN const wchar_t*   SourceRootPath,
    IN const wchar_t*   SourceFilename,
    IN const wchar_t*   TargetFilename,
    IN unsigned long    CopyStyle
    );

#ifdef UNICODE
#define SetupQueueDefaultCopy SetupQueueDefaultCopyW
#else
#define SetupQueueDefaultCopy SetupQueueDefaultCopyA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupQueueCopySectionA(
    IN HSPFILEQ QueueHandle,
    IN const char*    SourceRootPath,
    IN HINF     InfHandle,
    IN HINF     ListInfHandle,   OPTIONAL
    IN const char*    Section,
    IN unsigned long    CopyStyle
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupQueueCopySectionW(
    IN HSPFILEQ QueueHandle,
    IN const wchar_t*   SourceRootPath,
    IN HINF     InfHandle,
    IN HINF     ListInfHandle,   OPTIONAL
    IN const wchar_t*   Section,
    IN unsigned long    CopyStyle
    );

#ifdef UNICODE
#define SetupQueueCopySection SetupQueueCopySectionW
#else
#define SetupQueueCopySection SetupQueueCopySectionA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupQueueDeleteA(
    IN HSPFILEQ QueueHandle,
    IN const char*    PathPart1,
    IN const char*    PathPart2       OPTIONAL
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupQueueDeleteW(
    IN HSPFILEQ QueueHandle,
    IN const wchar_t*   PathPart1,
    IN const wchar_t*   PathPart2       OPTIONAL
    );

#ifdef UNICODE
#define SetupQueueDelete SetupQueueDeleteW
#else
#define SetupQueueDelete SetupQueueDeleteA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupQueueDeleteSectionA(
    IN HSPFILEQ QueueHandle,
    IN HINF     InfHandle,
    IN HINF     ListInfHandle,   OPTIONAL
    IN const char*    Section
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupQueueDeleteSectionW(
    IN HSPFILEQ QueueHandle,
    IN HINF     InfHandle,
    IN HINF     ListInfHandle,   OPTIONAL
    IN const wchar_t*   Section
    );

#ifdef UNICODE
#define SetupQueueDeleteSection SetupQueueDeleteSectionW
#else
#define SetupQueueDeleteSection SetupQueueDeleteSectionA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupQueueRenameA(
    IN HSPFILEQ QueueHandle,
    IN const char*    SourcePath,
    IN const char*    SourceFilename, OPTIONAL
    IN const char*    TargetPath,     OPTIONAL
    IN const char*    TargetFilename
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupQueueRenameW(
    IN HSPFILEQ QueueHandle,
    IN const wchar_t*   SourcePath,
    IN const wchar_t*   SourceFilename, OPTIONAL
    IN const wchar_t*   TargetPath,     OPTIONAL
    IN const wchar_t*   TargetFilename
    );

#ifdef UNICODE
#define SetupQueueRename SetupQueueRenameW
#else
#define SetupQueueRename SetupQueueRenameA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupQueueRenameSectionA(
    IN HSPFILEQ QueueHandle,
    IN HINF     InfHandle,
    IN HINF     ListInfHandle,   OPTIONAL
    IN const char*    Section
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupQueueRenameSectionW(
    IN HSPFILEQ QueueHandle,
    IN HINF     InfHandle,
    IN HINF     ListInfHandle,   OPTIONAL
    IN const wchar_t*   Section
    );

#ifdef UNICODE
#define SetupQueueRenameSection SetupQueueRenameSectionW
#else
#define SetupQueueRenameSection SetupQueueRenameSectionA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupCommitFileQueueA(
    IN HWND                Owner,         OPTIONAL
    IN HSPFILEQ            QueueHandle,
    IN PSP_FILE_CALLBACK_A MsgHandler,
    IN void*               Context
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupCommitFileQueueW(
    IN HWND                Owner,         OPTIONAL
    IN HSPFILEQ            QueueHandle,
    IN PSP_FILE_CALLBACK_W MsgHandler,
    IN void*               Context
    );

#ifdef UNICODE
#define SetupCommitFileQueue SetupCommitFileQueueW
#else
#define SetupCommitFileQueue SetupCommitFileQueueA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupScanFileQueueA(
    IN  HSPFILEQ            FileQueue,
    IN  unsigned long               Flags,
    IN  HWND                Window,            OPTIONAL
    IN  PSP_FILE_CALLBACK_A CallbackRoutine,   OPTIONAL
    IN  void*               CallbackContext,   OPTIONAL
    OUT unsigned long*              Result
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupScanFileQueueW(
    IN  HSPFILEQ            FileQueue,
    IN  unsigned long               Flags,
    IN  HWND                Window,            OPTIONAL
    IN  PSP_FILE_CALLBACK_W CallbackRoutine,   OPTIONAL
    IN  void*               CallbackContext,   OPTIONAL
    OUT unsigned long*              Result
    );

#ifdef UNICODE
#define SetupScanFileQueue SetupScanFileQueueW
#else
#define SetupScanFileQueue SetupScanFileQueueA
#endif

//
// Define flags for SetupScanFileQueue.
//
#define SPQ_SCAN_FILE_PRESENCE  0x00000001
#define SPQ_SCAN_FILE_VALIDITY  0x00000002
#define SPQ_SCAN_USE_CALLBACK   0x00000004
#define SPQ_SCAN_INFORM_USER    0x00000010

//
// Define flags used with Param2 for SPFILENOTIFY_QUEUESCAN
//
#define SPQ_DELAYED_COPY        0x00000001  // file was in use; registered for delayed copy

//
// Cabinet APIs
//

/*WINSETUPAPI*/
BOOL
__stdcall
SetupIterateCabinetA(
    IN  const char*               CabinetFile,
    IN  unsigned long               Reserved,
    IN  PSP_FILE_CALLBACK_A MsgHandler,
    IN  void*               Context
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupIterateCabinetW(
    IN  const wchar_t*              CabinetFile,
    IN  unsigned long               Reserved,
    IN  PSP_FILE_CALLBACK_W MsgHandler,
    IN  void*               Context
    );

#ifdef UNICODE
#define SetupIterateCabinet SetupIterateCabinetW
#else
#define SetupIterateCabinet SetupIterateCabinetA
#endif


/*WINSETUPAPI*/
INT
__stdcall
SetupPromptReboot(
    IN HSPFILEQ FileQueue,  OPTIONAL
    IN HWND     Owner,
    IN BOOL     ScanOnly
    );

//
// Define flags that are returned by SetupPromptReboot
//
#define SPFILEQ_FILE_IN_USE         0x00000001
#define SPFILEQ_REBOOT_RECOMMENDED  0x00000002
#define SPFILEQ_REBOOT_IN_PROGRESS  0x00000004


/*WINSETUPAPI*/
void*
__stdcall
SetupInitDefaultQueueCallback(
    IN HWND OwnerWindow
    );

/*WINSETUPAPI*/
void*
__stdcall
SetupInitDefaultQueueCallbackEx(
    IN HWND  OwnerWindow,
    IN HWND  AlternateProgressWindow, OPTIONAL
    IN unsigned  ProgressMessage,
    IN unsigned long Reserved1,
    IN void* Reserved2
    );

/*WINSETUPAPI*/
void
__stdcall
SetupTermDefaultQueueCallback(
    IN void* Context
    );

/*WINSETUPAPI*/
unsigned
__stdcall
SetupDefaultQueueCallbackA(
    IN void* Context,
    IN unsigned  Notification,
    IN unsigned  Param1,
    IN unsigned  Param2
    );

/*WINSETUPAPI*/
unsigned
__stdcall
SetupDefaultQueueCallbackW(
    IN void* Context,
    IN unsigned  Notification,
    IN unsigned  Param1,
    IN unsigned  Param2
    );

#ifdef UNICODE
#define SetupDefaultQueueCallback SetupDefaultQueueCallbackW
#else
#define SetupDefaultQueueCallback SetupDefaultQueueCallbackA
#endif


//
// Flags for AddReg section lines in INF.  The corresponding value
// is <ValueType> in the AddReg line format given below:
//
// <RegRootString>,<SubKey>,<ValueName>,<ValueType>,<Value>...
//
// The low word contains basic flags concerning the general data type
// and AddReg action. The high word contains values that more specifically
// identify the data type of the registry value.  The high word is ignored
// by the 16-bit Windows 95 SETUPX APIs.
//
#define FLG_ADDREG_BINVALUETYPE     ( 0x00000001 )
#define FLG_ADDREG_NOCLOBBER        ( 0x00000002 )
#define FLG_ADDREG_DELVAL           ( 0x00000004 )
#define FLG_ADDREG_APPEND           ( 0x00000008 ) // Currently supported only
                                                   // for REG_MULTI_SZ values.

#define FLG_ADDREG_TYPE_MASK        ( 0xFFFF0000 | FLG_ADDREG_BINVALUETYPE )
#define FLG_ADDREG_TYPE_SZ          ( 0x00000000                           )
#define FLG_ADDREG_TYPE_MULTI_SZ    ( 0x00010000                           )
#define FLG_ADDREG_TYPE_EXPAND_SZ   ( 0x00020000                           )
#define FLG_ADDREG_TYPE_BINARY      ( 0x00000000 | FLG_ADDREG_BINVALUETYPE )
#define FLG_ADDREG_TYPE_DWORD       ( 0x00010000 | FLG_ADDREG_BINVALUETYPE )
#define FLG_ADDREG_TYPE_NONE        ( 0x00020000 | FLG_ADDREG_BINVALUETYPE )

//
// The INF may supply any arbitrary data type ordinal in the highword except
// for the following: REG_NONE, REG_SZ, REG_EXPAND_SZ, REG_MULTI_SZ.  If this
// technique is used, then the data is given in binary format, one byte per
// field.
//


/*WINSETUPAPI*/
BOOL
__stdcall
SetupInstallFromInfSectionA(
    IN HWND                Owner,
    IN HINF                InfHandle,
    IN const char*               SectionName,
    IN unsigned                Flags,
    IN HKEY                RelativeKeyRoot,   OPTIONAL
    IN const char*               SourceRootPath,    OPTIONAL
    IN unsigned                CopyFlags,
    IN PSP_FILE_CALLBACK_A MsgHandler,
    IN void*               Context,
    IN HDEVINFO            DeviceInfoSet,     OPTIONAL
    IN PSP_DEVINFO_DATA    DeviceInfoData     OPTIONAL
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupInstallFromInfSectionW(
    IN HWND                Owner,
    IN HINF                InfHandle,
    IN const wchar_t*              SectionName,
    IN unsigned                Flags,
    IN HKEY                RelativeKeyRoot,   OPTIONAL
    IN const wchar_t*              SourceRootPath,    OPTIONAL
    IN unsigned                CopyFlags,
    IN PSP_FILE_CALLBACK_W MsgHandler,
    IN void*               Context,
    IN HDEVINFO            DeviceInfoSet,     OPTIONAL
    IN PSP_DEVINFO_DATA    DeviceInfoData     OPTIONAL
    );

#ifdef UNICODE
#define SetupInstallFromInfSection SetupInstallFromInfSectionW
#else
#define SetupInstallFromInfSection SetupInstallFromInfSectionA
#endif

//
// Flags for SetupInstallFromInfSection
//
#define SPINST_LOGCONFIG        0x00000001
#define SPINST_INIFILES         0x00000002
#define SPINST_REGISTRY         0x00000004
#define SPINST_INI2REG          0x00000008
#define SPINST_FILES            0x00000010
#define SPINST_ALL              0x0000001f


/*WINSETUPAPI*/
BOOL
__stdcall
SetupInstallFilesFromInfSectionA(
    IN HINF     InfHandle,
    IN HINF     LayoutInfHandle,    OPTIONAL
    IN HSPFILEQ FileQueue,
    IN const char*    SectionName,
    IN const char*    SourceRootPath,     OPTIONAL
    IN unsigned     CopyFlags
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupInstallFilesFromInfSectionW(
    IN HINF     InfHandle,
    IN HINF     LayoutInfHandle,    OPTIONAL
    IN HSPFILEQ FileQueue,
    IN const wchar_t*   SectionName,
    IN const wchar_t*   SourceRootPath,     OPTIONAL
    IN unsigned     CopyFlags
    );

#ifdef UNICODE
#define SetupInstallFilesFromInfSection SetupInstallFilesFromInfSectionW
#else
#define SetupInstallFilesFromInfSection SetupInstallFilesFromInfSectionA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupInstallServicesFromInfSectionA(
    IN HINF   InfHandle,
    IN const char*  SectionName,
    IN unsigned long  Flags
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupInstallServicesFromInfSectionW(
    IN HINF   InfHandle,
    IN const wchar_t* SectionName,
    IN unsigned long  Flags
    );

#ifdef UNICODE
#define SetupInstallServicesFromInfSection SetupInstallServicesFromInfSectionW
#else
#define SetupInstallServicesFromInfSection SetupInstallServicesFromInfSectionA
#endif

//
// Flags for SetupInstallServicesFromInfSection.  These flags are also used in
// the flags field of an AddService line in a device INF.  However, in that case,
// additional flags are permitted that are not used by this API.  These flags
// are marked as such below.
//
#define SPSVCINST_TAGTOFRONT    (0x00000001)  // move service's tag to front of its group order list
#define SPSVCINST_ASSOCSERVICE  (0x00000002)  // associate this service with the device being installed
                                              // (flag is ignored by SetupInstallServicesFromInfSection)

//
// Define handle type for Setup file log.
//
typedef void* HSPFILELOG;

/*WINSETUPAPI*/
HSPFILELOG
__stdcall
SetupInitializeFileLogA(
    IN const char* LogFileName,   OPTIONAL
    IN unsigned long Flags
    );

/*WINSETUPAPI*/
HSPFILELOG
__stdcall
SetupInitializeFileLogW(
    IN const wchar_t* LogFileName,  OPTIONAL
    IN unsigned long  Flags
    );

#ifdef UNICODE
#define SetupInitializeFileLog SetupInitializeFileLogW
#else
#define SetupInitializeFileLog SetupInitializeFileLogA
#endif

//
// Flags for SetupInitializeFileLog
//
#define SPFILELOG_SYSTEMLOG     0x00000001  // use system log -- must be Administrator
#define SPFILELOG_FORCENEW      0x00000002  // not valid with SPFILELOG_SYSTEMLOG
#define SPFILELOG_QUERYONLY     0x00000004  // allows non-administrators to read system log


/*WINSETUPAPI*/
BOOL
__stdcall
SetupTerminateFileLog(
    IN HSPFILELOG FileLogHandle
    );


/*WINSETUPAPI*/
BOOL
__stdcall
SetupLogFileA(
    IN HSPFILELOG FileLogHandle,
    IN const char*      LogSectionName,   OPTIONAL
    IN const char*      SourceFilename,
    IN const char*      TargetFilename,
    IN unsigned long      Checksum,         OPTIONAL
    IN const char*      DiskTagfile,      OPTIONAL
    IN const char*      DiskDescription,  OPTIONAL
    IN const char*      OtherInfo,        OPTIONAL
    IN unsigned long      Flags
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupLogFileW(
    IN HSPFILELOG FileLogHandle,
    IN const wchar_t*     LogSectionName,   OPTIONAL
    IN const wchar_t*     SourceFilename,
    IN const wchar_t*     TargetFilename,
    IN unsigned long      Checksum,         OPTIONAL
    IN const wchar_t*     DiskTagfile,      OPTIONAL
    IN const wchar_t*     DiskDescription,  OPTIONAL
    IN const wchar_t*     OtherInfo,        OPTIONAL
    IN unsigned long      Flags
    );

#ifdef UNICODE
#define SetupLogFile SetupLogFileW
#else
#define SetupLogFile SetupLogFileA
#endif

//
// Flags for SetupLogFile
//
#define SPFILELOG_OEMFILE   0x00000001


/*WINSETUPAPI*/
BOOL
__stdcall
SetupRemoveFileLogEntryA(
    IN HSPFILELOG FileLogHandle,
    IN const char*      LogSectionName,   OPTIONAL
    IN const char*      TargetFilename    OPTIONAL
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupRemoveFileLogEntryW(
    IN HSPFILELOG FileLogHandle,
    IN const wchar_t*     LogSectionName,   OPTIONAL
    IN const wchar_t*     TargetFilename    OPTIONAL
    );

#ifdef UNICODE
#define SetupRemoveFileLogEntry SetupRemoveFileLogEntryW
#else
#define SetupRemoveFileLogEntry SetupRemoveFileLogEntryA
#endif


//
// Items retrievable from SetupQueryFileLog()
//
typedef enum {
    SetupFileLogSourceFilename,
    SetupFileLogChecksum,
    SetupFileLogDiskTagfile,
    SetupFileLogDiskDescription,
    SetupFileLogOtherInfo,
    SetupFileLogMax
} SetupFileLogInfo;

/*WINSETUPAPI*/
BOOL
__stdcall
SetupQueryFileLogA(
    IN  HSPFILELOG       FileLogHandle,
    IN  const char*            LogSectionName,   OPTIONAL
    IN  const char*            TargetFilename,
    IN  SetupFileLogInfo DesiredInfo,
    OUT char*             DataOut,          OPTIONAL
    IN  unsigned long            ReturnBufferSize,
    OUT unsigned long*           RequiredSize      OPTIONAL
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupQueryFileLogW(
    IN  HSPFILELOG       FileLogHandle,
    IN  const wchar_t*           LogSectionName,   OPTIONAL
    IN  const wchar_t*           TargetFilename,
    IN  SetupFileLogInfo DesiredInfo,
    OUT wchar_t*            DataOut,          OPTIONAL
    IN  unsigned long            ReturnBufferSize,
    OUT unsigned long*           RequiredSize      OPTIONAL
    );

#ifdef UNICODE
#define SetupQueryFileLog SetupQueryFileLogW
#else
#define SetupQueryFileLog SetupQueryFileLogA
#endif


//
// Device Installer APIs
//

/*WINSETUPAPI*/
HDEVINFO
__stdcall
SetupDiCreateDeviceInfoList(
    IN LPGUID ClassGuid, OPTIONAL
    IN HWND   hwndParent OPTIONAL
    );


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiGetDeviceInfoListClass(
    IN  HDEVINFO DeviceInfoSet,
    OUT LPGUID   ClassGuid
    );


//
// Flags for SetupDiCreateDeviceInfo
//
#define DICD_GENERATE_ID        0x00000001
#define DICD_INHERIT_CLASSDRVS  0x00000002

/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiCreateDeviceInfoA(
    IN  HDEVINFO         DeviceInfoSet,
    IN  const char*            DeviceName,
    IN  LPGUID           ClassGuid,
    IN  const char*            DeviceDescription, OPTIONAL
    IN  HWND             hwndParent,        OPTIONAL
    IN  unsigned long            CreationFlags,
    OUT PSP_DEVINFO_DATA DeviceInfoData     OPTIONAL
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiCreateDeviceInfoW(
    IN  HDEVINFO         DeviceInfoSet,
    IN  const wchar_t*           DeviceName,
    IN  LPGUID           ClassGuid,
    IN  const wchar_t*           DeviceDescription, OPTIONAL
    IN  HWND             hwndParent,        OPTIONAL
    IN  unsigned long            CreationFlags,
    OUT PSP_DEVINFO_DATA DeviceInfoData     OPTIONAL
    );

#ifdef UNICODE
#define SetupDiCreateDeviceInfo SetupDiCreateDeviceInfoW
#else
#define SetupDiCreateDeviceInfo SetupDiCreateDeviceInfoA
#endif


//
// Flags for SetupDiOpenDeviceInfo
//
#define DIOD_INHERIT_CLASSDRVS  0x00000002
#define DIOD_CANCEL_REMOVE      0x00000004

/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiOpenDeviceInfoA(
    IN  HDEVINFO         DeviceInfoSet,
    IN  const char*            DeviceInstanceId,
    IN  HWND             hwndParent,       OPTIONAL
    IN  unsigned long            OpenFlags,
    OUT PSP_DEVINFO_DATA DeviceInfoData    OPTIONAL
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiOpenDeviceInfoW(
    IN  HDEVINFO         DeviceInfoSet,
    IN  const wchar_t*           DeviceInstanceId,
    IN  HWND             hwndParent,       OPTIONAL
    IN  unsigned long            OpenFlags,
    OUT PSP_DEVINFO_DATA DeviceInfoData    OPTIONAL
    );

#ifdef UNICODE
#define SetupDiOpenDeviceInfo SetupDiOpenDeviceInfoW
#else
#define SetupDiOpenDeviceInfo SetupDiOpenDeviceInfoA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiGetDeviceInstanceIdA(
    IN  HDEVINFO         DeviceInfoSet,
    IN  PSP_DEVINFO_DATA DeviceInfoData,
    OUT char*             DeviceInstanceId,
    IN  unsigned long            DeviceInstanceIdSize,
    OUT unsigned long*           RequiredSize          OPTIONAL
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiGetDeviceInstanceIdW(
    IN  HDEVINFO         DeviceInfoSet,
    IN  PSP_DEVINFO_DATA DeviceInfoData,
    OUT wchar_t*            DeviceInstanceId,
    IN  unsigned long            DeviceInstanceIdSize,
    OUT unsigned long*           RequiredSize          OPTIONAL
    );

#ifdef UNICODE
#define SetupDiGetDeviceInstanceId SetupDiGetDeviceInstanceIdW
#else
#define SetupDiGetDeviceInstanceId SetupDiGetDeviceInstanceIdA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiDeleteDeviceInfo(
    IN HDEVINFO         DeviceInfoSet,
    IN PSP_DEVINFO_DATA DeviceInfoData
    );


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiEnumDeviceInfo(
    IN  HDEVINFO         DeviceInfoSet,
    IN  unsigned long            MemberIndex,
    OUT PSP_DEVINFO_DATA DeviceInfoData
    );


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiDestroyDeviceInfoList(
    IN HDEVINFO DeviceInfoSet
    );


//
// Flags for SetupDiRegisterDeviceInfo
//
#define SPRDI_FIND_DUPS        0x00000001

/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiRegisterDeviceInfo(
    IN     HDEVINFO           DeviceInfoSet,
    IN OUT PSP_DEVINFO_DATA   DeviceInfoData,
    IN     unsigned long              Flags,
    IN     PSP_DETSIG_CMPPROC CompareProc,      OPTIONAL
    IN     void*              CompareContext,   OPTIONAL
    OUT    PSP_DEVINFO_DATA   DupDeviceInfoData OPTIONAL
    );


//
// Ordinal values distinguishing between class drivers and
// device drivers.
// (Passed in 'DriverType' parameter of driver information list APIs)
//
#define SPDIT_NODRIVER           0x00000000
#define SPDIT_CLASSDRIVER        0x00000001
#define SPDIT_COMPATDRIVER       0x00000002

/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiBuildDriverInfoList(
    IN     HDEVINFO         DeviceInfoSet,
    IN OUT PSP_DEVINFO_DATA DeviceInfoData, OPTIONAL
    IN     unsigned long            DriverType
    );


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiCancelDriverInfoSearch(
    IN HDEVINFO DeviceInfoSet
    );


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiEnumDriverInfoA(
    IN  HDEVINFO           DeviceInfoSet,
    IN  PSP_DEVINFO_DATA   DeviceInfoData, OPTIONAL
    IN  unsigned long              DriverType,
    IN  unsigned long              MemberIndex,
    OUT PSP_DRVINFO_DATA_A DriverInfoData
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiEnumDriverInfoW(
    IN  HDEVINFO           DeviceInfoSet,
    IN  PSP_DEVINFO_DATA   DeviceInfoData, OPTIONAL
    IN  unsigned long              DriverType,
    IN  unsigned long              MemberIndex,
    OUT PSP_DRVINFO_DATA_W DriverInfoData
    );

#ifdef UNICODE
#define SetupDiEnumDriverInfo SetupDiEnumDriverInfoW
#else
#define SetupDiEnumDriverInfo SetupDiEnumDriverInfoA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiGetSelectedDriverA(
    IN  HDEVINFO           DeviceInfoSet,
    IN  PSP_DEVINFO_DATA   DeviceInfoData, OPTIONAL
    OUT PSP_DRVINFO_DATA_A DriverInfoData
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiGetSelectedDriverW(
    IN  HDEVINFO           DeviceInfoSet,
    IN  PSP_DEVINFO_DATA   DeviceInfoData, OPTIONAL
    OUT PSP_DRVINFO_DATA_W DriverInfoData
    );

#ifdef UNICODE
#define SetupDiGetSelectedDriver SetupDiGetSelectedDriverW
#else
#define SetupDiGetSelectedDriver SetupDiGetSelectedDriverA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiSetSelectedDriverA(
    IN     HDEVINFO           DeviceInfoSet,
    IN     PSP_DEVINFO_DATA   DeviceInfoData, OPTIONAL
    IN OUT PSP_DRVINFO_DATA_A DriverInfoData  OPTIONAL
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiSetSelectedDriverW(
    IN     HDEVINFO           DeviceInfoSet,
    IN     PSP_DEVINFO_DATA   DeviceInfoData, OPTIONAL
    IN OUT PSP_DRVINFO_DATA_W DriverInfoData  OPTIONAL
    );

#ifdef UNICODE
#define SetupDiSetSelectedDriver SetupDiSetSelectedDriverW
#else
#define SetupDiSetSelectedDriver SetupDiSetSelectedDriverA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiGetDriverInfoDetailA(
    IN  HDEVINFO                  DeviceInfoSet,
    IN  PSP_DEVINFO_DATA          DeviceInfoData,           OPTIONAL
    IN  PSP_DRVINFO_DATA_A        DriverInfoData,
    OUT PSP_DRVINFO_DETAIL_DATA_A DriverInfoDetailData,     OPTIONAL
    IN  unsigned long                     DriverInfoDetailDataSize,
    OUT unsigned long*                    RequiredSize              OPTIONAL
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiGetDriverInfoDetailW(
    IN  HDEVINFO                  DeviceInfoSet,
    IN  PSP_DEVINFO_DATA          DeviceInfoData,           OPTIONAL
    IN  PSP_DRVINFO_DATA_W        DriverInfoData,
    OUT PSP_DRVINFO_DETAIL_DATA_W DriverInfoDetailData,     OPTIONAL
    IN  unsigned long                     DriverInfoDetailDataSize,
    OUT unsigned long*                    RequiredSize              OPTIONAL
    );

#ifdef UNICODE
#define SetupDiGetDriverInfoDetail SetupDiGetDriverInfoDetailW
#else
#define SetupDiGetDriverInfoDetail SetupDiGetDriverInfoDetailA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiDestroyDriverInfoList(
    IN HDEVINFO         DeviceInfoSet,
    IN PSP_DEVINFO_DATA DeviceInfoData, OPTIONAL
    IN unsigned long            DriverType
    );


//
// Flags controlling what is included in the device information set built
// by SetupDiGetClassDevs
//
// #define DIGCF_DEFAULT        0x00000001  // defined but not implemented by setupx
#define DIGCF_PRESENT           0x00000002
#define DIGCF_ALLCLASSES        0x00000004
#define DIGCF_PROFILE           0x00000008

/*WINSETUPAPI*/
HDEVINFO
__stdcall
SetupDiGetClassDevsA(
    IN LPGUID ClassGuid,  OPTIONAL
    IN const char*  Enumerator, OPTIONAL
    IN HWND   hwndParent, OPTIONAL
    IN unsigned long  Flags
    );

/*WINSETUPAPI*/
HDEVINFO
__stdcall
SetupDiGetClassDevsW(
    IN LPGUID ClassGuid,  OPTIONAL
    IN const wchar_t* Enumerator, OPTIONAL
    IN HWND   hwndParent, OPTIONAL
    IN unsigned long  Flags
    );

#ifdef UNICODE
#define SetupDiGetClassDevs SetupDiGetClassDevsW
#else
#define SetupDiGetClassDevs SetupDiGetClassDevsA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiGetINFClassA(
    IN  const char*  InfName,
    OUT LPGUID ClassGuid,
    OUT char*   ClassName,
    IN  unsigned long  ClassNameSize,
    OUT unsigned long* RequiredSize   OPTIONAL
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiGetINFClassW(
    IN  const wchar_t* InfName,
    OUT LPGUID ClassGuid,
    OUT wchar_t*  ClassName,
    IN  unsigned long  ClassNameSize,
    OUT unsigned long* RequiredSize   OPTIONAL
    );

#ifdef UNICODE
#define SetupDiGetINFClass SetupDiGetINFClassW
#else
#define SetupDiGetINFClass SetupDiGetINFClassA
#endif


//
// Flags controlling exclusion from the class information list built
// by SetupDiBuildClassInfoList
//
#define DIBCI_NOINSTALLCLASS   0x00000001
#define DIBCI_NODISPLAYCLASS   0x00000002

/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiBuildClassInfoList(
    IN  unsigned long  Flags,
    OUT LPGUID ClassGuidList,
    IN  unsigned long  ClassGuidListSize,
    OUT unsigned long* RequiredSize
    );


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiGetClassDescriptionA(
    IN  LPGUID ClassGuid,
    OUT char*   ClassDescription,
    IN  unsigned long  ClassDescriptionSize,
    OUT unsigned long* RequiredSize          OPTIONAL
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiGetClassDescriptionW(
    IN  LPGUID ClassGuid,
    OUT wchar_t*  ClassDescription,
    IN  unsigned long  ClassDescriptionSize,
    OUT unsigned long* RequiredSize          OPTIONAL
    );

#ifdef UNICODE
#define SetupDiGetClassDescription SetupDiGetClassDescriptionW
#else
#define SetupDiGetClassDescription SetupDiGetClassDescriptionA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiCallClassInstaller(
    IN DI_FUNCTION      InstallFunction,
    IN HDEVINFO         DeviceInfoSet,
    IN PSP_DEVINFO_DATA DeviceInfoData OPTIONAL
    );


//
// Default install handler for DIF_SELECTDEVICE
//
/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiSelectDevice(
    IN     HDEVINFO         DeviceInfoSet,
    IN OUT PSP_DEVINFO_DATA DeviceInfoData OPTIONAL
    );


//
// Default install handler for DIF_INSTALLDEVICE
//
/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiInstallDevice(
    IN     HDEVINFO         DeviceInfoSet,
    IN OUT PSP_DEVINFO_DATA DeviceInfoData
    );


//
// Default install handler for DIF_INSTALLDEVICEFILES
//
/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiInstallDriverFiles(
    IN HDEVINFO         DeviceInfoSet,
    IN PSP_DEVINFO_DATA DeviceInfoData OPTIONAL
    );


//
// Default install handler for DIF_REMOVE
//
/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiRemoveDevice(
    IN     HDEVINFO         DeviceInfoSet,
    IN OUT PSP_DEVINFO_DATA DeviceInfoData
    );


//
// Default install handler for DIF_MOVEDEVICE
//
/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiMoveDuplicateDevice(
    IN HDEVINFO         DeviceInfoSet,
    IN PSP_DEVINFO_DATA DestinationDeviceInfoData
    );


//
// Default install handler for DIF_PROPERTYCHANGE
//
/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiChangeState(
    IN     HDEVINFO         DeviceInfoSet,
    IN OUT PSP_DEVINFO_DATA DeviceInfoData
    );


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiInstallClassA(
    IN HWND     hwndParent,  OPTIONAL
    IN const char*    InfFileName,
    IN unsigned long    Flags,
    IN HSPFILEQ FileQueue    OPTIONAL
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiInstallClassW(
    IN HWND     hwndParent,  OPTIONAL
    IN const wchar_t*   InfFileName,
    IN unsigned long    Flags,
    IN HSPFILEQ FileQueue    OPTIONAL
    );

#ifdef UNICODE
#define SetupDiInstallClass SetupDiInstallClassW
#else
#define SetupDiInstallClass SetupDiInstallClassA
#endif


/*WINSETUPAPI*/
HKEY
__stdcall
SetupDiOpenClassRegKey(
    IN LPGUID ClassGuid, OPTIONAL
    IN REGSAM samDesired
    );


//
// KeyType values for SetupDiCreateDevRegKey, SetupDiOpenDevRegKey, and
// SetupDiDeleteDevRegKey.
//
#define DIREG_DEV       0x00000001          // Open/Create/Delete device key
#define DIREG_DRV       0x00000002          // Open/Create/Delete driver key
#define DIREG_BOTH      0x00000004          // Delete both driver and Device key

/*WINSETUPAPI*/
HKEY
__stdcall
SetupDiCreateDevRegKeyA(
    IN HDEVINFO         DeviceInfoSet,
    IN PSP_DEVINFO_DATA DeviceInfoData,
    IN unsigned long            Scope,
    IN unsigned long            HwProfile,
    IN unsigned long            KeyType,
    IN HINF             InfHandle,      OPTIONAL
    IN const char*            InfSectionName  OPTIONAL
    );

/*WINSETUPAPI*/
HKEY
__stdcall
SetupDiCreateDevRegKeyW(
    IN HDEVINFO         DeviceInfoSet,
    IN PSP_DEVINFO_DATA DeviceInfoData,
    IN unsigned long            Scope,
    IN unsigned long            HwProfile,
    IN unsigned long            KeyType,
    IN HINF             InfHandle,      OPTIONAL
    IN const wchar_t*           InfSectionName  OPTIONAL
    );

#ifdef UNICODE
#define SetupDiCreateDevRegKey SetupDiCreateDevRegKeyW
#else
#define SetupDiCreateDevRegKey SetupDiCreateDevRegKeyA
#endif


/*WINSETUPAPI*/
HKEY
__stdcall
SetupDiOpenDevRegKey(
    IN HDEVINFO         DeviceInfoSet,
    IN PSP_DEVINFO_DATA DeviceInfoData,
    IN unsigned long            Scope,
    IN unsigned long            HwProfile,
    IN unsigned long            KeyType,
    IN REGSAM           samDesired
    );


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiDeleteDevRegKey(
    IN HDEVINFO         DeviceInfoSet,
    IN PSP_DEVINFO_DATA DeviceInfoData,
    IN unsigned long            Scope,
    IN unsigned long            HwProfile,
    IN unsigned long            KeyType
    );


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiGetHwProfileList(
    OUT unsigned long* HwProfileList,
    IN  unsigned long  HwProfileListSize,
    OUT unsigned long* RequiredSize,
    OUT unsigned long* CurrentlyActiveIndex OPTIONAL
    );


//
// Device registry property codes
// (Codes marked as read-only (R) may only be used for
// SetupDiGetDeviceRegistryProperty)
//
// These values should cover the same set of registry properties
// as defined by the CM_DRP codes in cfgmgr32.h.
//
#define SPDRP_DEVICEDESC           (0x00000000)  // DeviceDesc (R/W)
#define SPDRP_HARDWAREID           (0x00000001)  // HardwareID (R/W)
#define SPDRP_COMPATIBLEIDS        (0x00000002)  // CompatibleIDs (R/W)
#define SPDRP_NTDEVICEPATHS        (0x00000003)  // NtDevicePaths (R)
#define SPDRP_SERVICE              (0x00000004)  // Service (R/W)
#define SPDRP_CONFIGURATION        (0x00000005)  // Configuration (R)
#define SPDRP_CONFIGURATIONVECTOR  (0x00000006)  // ConfigurationVector (R)
#define SPDRP_CLASS                (0x00000007)  // Class (R--tied to ClassGUID)
#define SPDRP_CLASSGUID            (0x00000008)  // ClassGUID (R/W)
#define SPDRP_DRIVER               (0x00000009)  // Driver (R/W)
#define SPDRP_CONFIGFLAGS          (0x0000000A)  // ConfigFlags (R/W)
#define SPDRP_MFG                  (0x0000000B)  // Mfg (R/W)
#define SPDRP_FRIENDLYNAME         (0x0000000C)  // FriendlyName (R/W)
#define SPDRP_MAXIMUM_PROPERTY     (0x0000000D)  // Upper bound on ordinals

/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiGetDeviceRegistryPropertyA(
    IN  HDEVINFO         DeviceInfoSet,
    IN  PSP_DEVINFO_DATA DeviceInfoData,
    IN  unsigned long            Property,
    OUT unsigned long*           PropertyRegDataType, OPTIONAL
    OUT PBYTE            PropertyBuffer,
    IN  unsigned long            PropertyBufferSize,
    OUT unsigned long*           RequiredSize         OPTIONAL
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiGetDeviceRegistryPropertyW(
    IN  HDEVINFO         DeviceInfoSet,
    IN  PSP_DEVINFO_DATA DeviceInfoData,
    IN  unsigned long            Property,
    OUT unsigned long*           PropertyRegDataType, OPTIONAL
    OUT PBYTE            PropertyBuffer,
    IN  unsigned long            PropertyBufferSize,
    OUT unsigned long*           RequiredSize         OPTIONAL
    );

#ifdef UNICODE
#define SetupDiGetDeviceRegistryProperty SetupDiGetDeviceRegistryPropertyW
#else
#define SetupDiGetDeviceRegistryProperty SetupDiGetDeviceRegistryPropertyA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiSetDeviceRegistryPropertyA(
    IN     HDEVINFO         DeviceInfoSet,
    IN OUT PSP_DEVINFO_DATA DeviceInfoData,
    IN     unsigned long            Property,
    IN     CONST BYTE*      PropertyBuffer,
    IN     unsigned long            PropertyBufferSize
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiSetDeviceRegistryPropertyW(
    IN     HDEVINFO         DeviceInfoSet,
    IN OUT PSP_DEVINFO_DATA DeviceInfoData,
    IN     unsigned long            Property,
    IN     CONST BYTE*      PropertyBuffer,
    IN     unsigned long            PropertyBufferSize
    );

#ifdef UNICODE
#define SetupDiSetDeviceRegistryProperty SetupDiSetDeviceRegistryPropertyW
#else
#define SetupDiSetDeviceRegistryProperty SetupDiSetDeviceRegistryPropertyA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiGetDeviceInstallParamsA(
    IN  HDEVINFO                DeviceInfoSet,
    IN  PSP_DEVINFO_DATA        DeviceInfoData,          OPTIONAL
    OUT PSP_DEVINSTALL_PARAMS_A DeviceInstallParams
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiGetDeviceInstallParamsW(
    IN  HDEVINFO                DeviceInfoSet,
    IN  PSP_DEVINFO_DATA        DeviceInfoData,          OPTIONAL
    OUT PSP_DEVINSTALL_PARAMS_W DeviceInstallParams
    );

#ifdef UNICODE
#define SetupDiGetDeviceInstallParams SetupDiGetDeviceInstallParamsW
#else
#define SetupDiGetDeviceInstallParams SetupDiGetDeviceInstallParamsA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiGetClassInstallParamsA(
    IN  HDEVINFO                DeviceInfoSet,
    IN  PSP_DEVINFO_DATA        DeviceInfoData,         OPTIONAL
    OUT PSP_CLASSINSTALL_HEADER ClassInstallParams,     OPTIONAL
    IN  unsigned long                   ClassInstallParamsSize,
    OUT unsigned long*                  RequiredSize            OPTIONAL
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiGetClassInstallParamsW(
    IN  HDEVINFO                DeviceInfoSet,
    IN  PSP_DEVINFO_DATA        DeviceInfoData,         OPTIONAL
    OUT PSP_CLASSINSTALL_HEADER ClassInstallParams,     OPTIONAL
    IN  unsigned long                   ClassInstallParamsSize,
    OUT unsigned long*                  RequiredSize            OPTIONAL
    );

#ifdef UNICODE
#define SetupDiGetClassInstallParams SetupDiGetClassInstallParamsW
#else
#define SetupDiGetClassInstallParams SetupDiGetClassInstallParamsA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiSetDeviceInstallParamsA(
    IN HDEVINFO                DeviceInfoSet,
    IN PSP_DEVINFO_DATA        DeviceInfoData,     OPTIONAL
    IN PSP_DEVINSTALL_PARAMS_A DeviceInstallParams
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiSetDeviceInstallParamsW(
    IN HDEVINFO                DeviceInfoSet,
    IN PSP_DEVINFO_DATA        DeviceInfoData,     OPTIONAL
    IN PSP_DEVINSTALL_PARAMS_W DeviceInstallParams
    );

#ifdef UNICODE
#define SetupDiSetDeviceInstallParams SetupDiSetDeviceInstallParamsW
#else
#define SetupDiSetDeviceInstallParams SetupDiSetDeviceInstallParamsA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiSetClassInstallParamsA(
    IN HDEVINFO                DeviceInfoSet,
    IN PSP_DEVINFO_DATA        DeviceInfoData,        OPTIONAL
    IN PSP_CLASSINSTALL_HEADER ClassInstallParams,    OPTIONAL
    IN unsigned long                   ClassInstallParamsSize
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiSetClassInstallParamsW(
    IN HDEVINFO                DeviceInfoSet,
    IN PSP_DEVINFO_DATA        DeviceInfoData,        OPTIONAL
    IN PSP_CLASSINSTALL_HEADER ClassInstallParams,    OPTIONAL
    IN unsigned long                   ClassInstallParamsSize
    );

#ifdef UNICODE
#define SetupDiSetClassInstallParams SetupDiSetClassInstallParamsW
#else
#define SetupDiSetClassInstallParams SetupDiSetClassInstallParamsA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiGetDriverInstallParamsA(
    IN  HDEVINFO              DeviceInfoSet,
    IN  PSP_DEVINFO_DATA      DeviceInfoData,     OPTIONAL
    IN  PSP_DRVINFO_DATA_A    DriverInfoData,
    OUT PSP_DRVINSTALL_PARAMS DriverInstallParams
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiGetDriverInstallParamsW(
    IN  HDEVINFO              DeviceInfoSet,
    IN  PSP_DEVINFO_DATA      DeviceInfoData,     OPTIONAL
    IN  PSP_DRVINFO_DATA_W    DriverInfoData,
    OUT PSP_DRVINSTALL_PARAMS DriverInstallParams
    );

#ifdef UNICODE
#define SetupDiGetDriverInstallParams SetupDiGetDriverInstallParamsW
#else
#define SetupDiGetDriverInstallParams SetupDiGetDriverInstallParamsA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiSetDriverInstallParamsA(
    IN HDEVINFO              DeviceInfoSet,
    IN PSP_DEVINFO_DATA      DeviceInfoData,     OPTIONAL
    IN PSP_DRVINFO_DATA_A    DriverInfoData,
    IN PSP_DRVINSTALL_PARAMS DriverInstallParams
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiSetDriverInstallParamsW(
    IN HDEVINFO              DeviceInfoSet,
    IN PSP_DEVINFO_DATA      DeviceInfoData,     OPTIONAL
    IN PSP_DRVINFO_DATA_W    DriverInfoData,
    IN PSP_DRVINSTALL_PARAMS DriverInstallParams
    );

#ifdef UNICODE
#define SetupDiSetDriverInstallParams SetupDiSetDriverInstallParamsW
#else
#define SetupDiSetDriverInstallParams SetupDiSetDriverInstallParamsA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiLoadClassIcon(
    IN  LPGUID  ClassGuid,
    OUT HICON  *LargeIcon,    OPTIONAL
    OUT PINT    MiniIconIndex OPTIONAL
    );


//
// Flags controlling the drawing of mini-icons
//
#define DMI_MASK      0x00000001
#define DMI_BKCOLOR   0x00000002
#define DMI_USERECT   0x00000004

/*WINSETUPAPI*/
INT
__stdcall
SetupDiDrawMiniIcon(
    IN HDC   hdc,
    IN RECT  rc,
    IN INT   MiniIconIndex,
    IN unsigned long Flags
    );


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiGetClassBitmapIndex(
    IN  LPGUID ClassGuid,
    OUT PINT   MiniIconIndex
    );


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiGetClassImageList(
    OUT PSP_CLASSIMAGELIST_DATA ClassImageListData
    );


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiGetClassImageIndex(
    IN  PSP_CLASSIMAGELIST_DATA ClassImageListData,
    IN  LPGUID                  ClassGuid,
    OUT PINT                    ImageIndex
    );


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiDestroyClassImageList(
    IN PSP_CLASSIMAGELIST_DATA ClassImageListData
    );


//
// Flags for the SetupDiGetClassDevPropertySheets API
//
#define DIGCDP_FLAG_BASIC           0x00000001
#define DIGCDP_FLAG_ADVANCED        0x00000002

/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiGetClassDevPropertySheetsA(
    IN HDEVINFO           DeviceInfoSet,
    IN PSP_DEVINFO_DATA   DeviceInfoData,      OPTIONAL
    IN LPPROPSHEETHEADERA PropertySheetHeader,
    IN unsigned long              Flags
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiGetClassDevPropertySheetsW(
    IN HDEVINFO           DeviceInfoSet,
    IN PSP_DEVINFO_DATA   DeviceInfoData,      OPTIONAL
    IN LPPROPSHEETHEADERW PropertySheetHeader,
    IN unsigned long              Flags
    );

#ifdef UNICODE
#define SetupDiGetClassDevPropertySheets SetupDiGetClassDevPropertySheetsW
#else
#define SetupDiGetClassDevPropertySheets SetupDiGetClassDevPropertySheetsA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiAskForOEMDisk(
    IN HDEVINFO         DeviceInfoSet,
    IN PSP_DEVINFO_DATA DeviceInfoData OPTIONAL
    );


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiSelectOEMDrv(
    IN     HWND             hwndParent,    OPTIONAL
    IN     HDEVINFO         DeviceInfoSet,
    IN OUT PSP_DEVINFO_DATA DeviceInfoData OPTIONAL
    );


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiClassNameFromGuidA(
    IN  LPGUID ClassGuid,
    OUT char*   ClassName,
    IN  unsigned long  ClassNameSize,
    OUT unsigned long* RequiredSize   OPTIONAL
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiClassNameFromGuidW(
    IN  LPGUID ClassGuid,
    OUT wchar_t*  ClassName,
    IN  unsigned long  ClassNameSize,
    OUT unsigned long* RequiredSize   OPTIONAL
    );

#ifdef UNICODE
#define SetupDiClassNameFromGuid SetupDiClassNameFromGuidW
#else
#define SetupDiClassNameFromGuid SetupDiClassNameFromGuidA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiClassGuidsFromNameA(
    IN  const char*  ClassName,
    OUT LPGUID ClassGuidList,
    IN  unsigned long  ClassGuidListSize,
    OUT unsigned long* RequiredSize
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiClassGuidsFromNameW(
    IN  const wchar_t* ClassName,
    OUT LPGUID ClassGuidList,
    IN  unsigned long  ClassGuidListSize,
    OUT unsigned long* RequiredSize
    );

#ifdef UNICODE
#define SetupDiClassGuidsFromName SetupDiClassGuidsFromNameW
#else
#define SetupDiClassGuidsFromName SetupDiClassGuidsFromNameA
#endif


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiGetHwProfileFriendlyNameA(
    IN  unsigned long  HwProfile,
    OUT char*   FriendlyName,
    IN  unsigned long  FriendlyNameSize,
    OUT unsigned long* RequiredSize      OPTIONAL
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiGetHwProfileFriendlyNameW(
    IN  unsigned long  HwProfile,
    OUT wchar_t*  FriendlyName,
    IN  unsigned long  FriendlyNameSize,
    OUT unsigned long* RequiredSize      OPTIONAL
    );

#ifdef UNICODE
#define SetupDiGetHwProfileFriendlyName SetupDiGetHwProfileFriendlyNameW
#else
#define SetupDiGetHwProfileFriendlyName SetupDiGetHwProfileFriendlyNameA
#endif


//
// PageType values for SetupDiGetWizardPage API
//
#define SPWPT_SELECTDEVICE      0x00000001

//
// Flags for SetupDiGetWizardPage API
//
#define SPWP_USE_DEVINFO_DATA   0x00000001

/*WINSETUPAPI*/
HPROPSHEETPAGE
__stdcall
SetupDiGetWizardPage(
    IN HDEVINFO               DeviceInfoSet,
    IN PSP_DEVINFO_DATA       DeviceInfoData,    OPTIONAL
    IN PSP_INSTALLWIZARD_DATA InstallWizardData,
    IN unsigned long                  PageType,
    IN unsigned long                  Flags
    );


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiGetSelectedDevice(
    IN  HDEVINFO         DeviceInfoSet,
    OUT PSP_DEVINFO_DATA DeviceInfoData
    );


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiSetSelectedDevice(
    IN HDEVINFO         DeviceInfoSet,
    IN PSP_DEVINFO_DATA DeviceInfoData
    );


/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiGetActualSectionToInstallA(
    IN  HINF    InfHandle,
    IN  const char*   InfSectionName,
    OUT char*    InfSectionWithExt,     OPTIONAL
    IN  unsigned long   InfSectionWithExtSize,
    OUT unsigned long*  RequiredSize,          OPTIONAL
    OUT char*   *Extension              OPTIONAL
    );

/*WINSETUPAPI*/
BOOL
__stdcall
SetupDiGetActualSectionToInstallW(
    IN  HINF    InfHandle,
    IN  const wchar_t*  InfSectionName,
    OUT wchar_t*   InfSectionWithExt,     OPTIONAL
    IN  unsigned long   InfSectionWithExtSize,
    OUT unsigned long*  RequiredSize,          OPTIONAL
    OUT wchar_t*  *Extension              OPTIONAL
    );

#ifdef UNICODE
#define SetupDiGetActualSectionToInstall SetupDiGetActualSectionToInstallW
#else
#define SetupDiGetActualSectionToInstall SetupDiGetActualSectionToInstallA
#endif


#ifdef __cplusplus
}
#endif

#include <poppack.h>

#endif // _INC_SETUPAPI

#pragma once 
