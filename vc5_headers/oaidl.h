/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.00.39 */
/* at Sat Jul 13 21:56:52 1996
 */
/* Compiler settings for c:\oa\src\idl\oaidl.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"
#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __oaidl_h__
#define __oaidl_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __ICreateTypeInfo_FWD_DEFINED__
#define __ICreateTypeInfo_FWD_DEFINED__
typedef interface ICreateTypeInfo ICreateTypeInfo;
#endif 	/* __ICreateTypeInfo_FWD_DEFINED__ */


#ifndef __ICreateTypeInfo2_FWD_DEFINED__
#define __ICreateTypeInfo2_FWD_DEFINED__
typedef interface ICreateTypeInfo2 ICreateTypeInfo2;
#endif 	/* __ICreateTypeInfo2_FWD_DEFINED__ */


#ifndef __ICreateTypeLib_FWD_DEFINED__
#define __ICreateTypeLib_FWD_DEFINED__
typedef interface ICreateTypeLib ICreateTypeLib;
#endif 	/* __ICreateTypeLib_FWD_DEFINED__ */


#ifndef __ICreateTypeLib2_FWD_DEFINED__
#define __ICreateTypeLib2_FWD_DEFINED__
typedef interface ICreateTypeLib2 ICreateTypeLib2;
#endif 	/* __ICreateTypeLib2_FWD_DEFINED__ */


#ifndef __IDispatch_FWD_DEFINED__
#define __IDispatch_FWD_DEFINED__
typedef interface IDispatch IDispatch;
#endif 	/* __IDispatch_FWD_DEFINED__ */


#ifndef __IEnumVARIANT_FWD_DEFINED__
#define __IEnumVARIANT_FWD_DEFINED__
typedef interface IEnumVARIANT IEnumVARIANT;
#endif 	/* __IEnumVARIANT_FWD_DEFINED__ */


#ifndef __ITypeComp_FWD_DEFINED__
#define __ITypeComp_FWD_DEFINED__
typedef interface ITypeComp ITypeComp;
#endif 	/* __ITypeComp_FWD_DEFINED__ */


#ifndef __ITypeInfo_FWD_DEFINED__
#define __ITypeInfo_FWD_DEFINED__
typedef interface ITypeInfo ITypeInfo;
#endif 	/* __ITypeInfo_FWD_DEFINED__ */


#ifndef __ITypeInfo2_FWD_DEFINED__
#define __ITypeInfo2_FWD_DEFINED__
typedef interface ITypeInfo2 ITypeInfo2;
#endif 	/* __ITypeInfo2_FWD_DEFINED__ */


#ifndef __ITypeLib_FWD_DEFINED__
#define __ITypeLib_FWD_DEFINED__
typedef interface ITypeLib ITypeLib;
#endif 	/* __ITypeLib_FWD_DEFINED__ */


#ifndef __ITypeLib2_FWD_DEFINED__
#define __ITypeLib2_FWD_DEFINED__
typedef interface ITypeLib2 ITypeLib2;
#endif 	/* __ITypeLib2_FWD_DEFINED__ */


#ifndef __ITypeChangeEvents_FWD_DEFINED__
#define __ITypeChangeEvents_FWD_DEFINED__
typedef interface ITypeChangeEvents ITypeChangeEvents;
#endif 	/* __ITypeChangeEvents_FWD_DEFINED__ */


#ifndef __IErrorInfo_FWD_DEFINED__
#define __IErrorInfo_FWD_DEFINED__
typedef interface IErrorInfo IErrorInfo;
#endif 	/* __IErrorInfo_FWD_DEFINED__ */


#ifndef __ICreateErrorInfo_FWD_DEFINED__
#define __ICreateErrorInfo_FWD_DEFINED__
typedef interface ICreateErrorInfo ICreateErrorInfo;
#endif 	/* __ICreateErrorInfo_FWD_DEFINED__ */


#ifndef __ISupportErrorInfo_FWD_DEFINED__
#define __ISupportErrorInfo_FWD_DEFINED__
typedef interface ISupportErrorInfo ISupportErrorInfo;
#endif 	/* __ISupportErrorInfo_FWD_DEFINED__ */


/* header files for imported files */
#include "objidl.h"

void  * __stdcall MIDL_user_allocate(size_t);
void __stdcall MIDL_user_free( void  * ); 

/****************************************
 * Generated header for interface: __MIDL__intf_0000
 * at Sat Jul 13 21:56:52 1996
 * using MIDL 3.00.39
 ****************************************/
/* [local] */ 


//+-------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright (C) Microsoft Corporation, 1992 - 1996.
//
//--------------------------------------------------------------------------

















extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_s_ifspec;

#ifndef __IOleAutomationTypes_INTERFACE_DEFINED__
#define __IOleAutomationTypes_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IOleAutomationTypes
 * at Sat Jul 13 21:56:52 1996
 * using MIDL 3.00.39
 ****************************************/
/* [auto_handle][unique][version] */ 


typedef CY CURRENCY;

typedef struct  tagSAFEARRAYBOUND
    {
    unsigned long cElements;
    long lLbound;
    }	SAFEARRAYBOUND;

typedef struct tagSAFEARRAYBOUND  *LPSAFEARRAYBOUND;

#if defined(_OLEAUT32_)
/* the following is what MIDL knows how to remote */
typedef /* [unique] */ struct _wireVARIANT  *wireVARIANT;

typedef struct  _wireSAFEARR_BSTR
    {
    unsigned long Size;
    /* [ref][size_is] */ wireBSTR  *aBstr;
    }	SAFEARR_BSTR;

typedef struct  _wireSAFEARR_UNKNOWN
    {
    unsigned long Size;
    /* [ref][size_is] */ IUnknown  * *apUnknown;
    }	SAFEARR_UNKNOWN;

typedef struct  _wireSAFEARR_DISPATCH
    {
    unsigned long Size;
    /* [ref][size_is] */ IDispatch  * *apDispatch;
    }	SAFEARR_DISPATCH;

typedef struct  _wireSAFEARR_VARIANT
    {
    unsigned long Size;
    /* [ref][size_is] */ wireVARIANT  *aVariant;
    }	SAFEARR_VARIANT;

typedef /* [v1_enum] */ 
enum tagSF_TYPE
    {	SF_ERROR	= VT_ERROR,
	SF_I1	= VT_I1,
	SF_I2	= VT_I2,
	SF_I4	= VT_I4,
	SF_I8	= VT_I8,
	SF_BSTR	= VT_BSTR,
	SF_UNKNOWN	= VT_UNKNOWN,
	SF_DISPATCH	= VT_DISPATCH,
	SF_VARIANT	= VT_VARIANT
    }	SF_TYPE;

typedef struct  _wireSAFEARRAY_UNION
    {
    unsigned long sfType;
    /* [switch_is] */ /* [switch_type] */ union __MIDL_IOleAutomationTypes_0001
        {
        /* [case()] */ SAFEARR_BSTR BstrStr;
        /* [case()] */ SAFEARR_UNKNOWN UnknownStr;
        /* [case()] */ SAFEARR_DISPATCH DispatchStr;
        /* [case()] */ SAFEARR_VARIANT VariantStr;
        /* [case()] */ BYTE_SIZEDARR ByteStr;
        /* [case()] */ WORD_SIZEDARR WordStr;
        /* [case()] */ DWORD_SIZEDARR LongStr;
        /* [case()] */ HYPER_SIZEDARR HyperStr;
        /* [default] */  /* Empty union arm */ 
        }	u;
    }	SAFEARRAYUNION;

typedef /* [unique] */ struct  _wireSAFEARRAY
    {
    unsigned short cDims;
    unsigned short fFeatures;
    unsigned long cbElements;
    unsigned long cLocks;
    SAFEARRAYUNION uArrayStructs;
    /* [size_is] */ SAFEARRAYBOUND rgsabound[ 1 ];
    }	 *wireSAFEARRAY;

typedef /* [unique] */ wireSAFEARRAY  *wirePSAFEARRAY;

#endif /* _OLEAUT32_ */
typedef struct  tagSAFEARRAY
    {
    unsigned short cDims;
    unsigned short fFeatures;
    unsigned long cbElements;
    unsigned long cLocks;
    void* pvData;
    SAFEARRAYBOUND rgsabound[ 1 ];
    }	SAFEARRAY;

typedef /* [wire_marshal] */ SAFEARRAY  *LPSAFEARRAY;

#define	FADF_AUTO	( 0x1 )

#define	FADF_STATIC	( 0x2 )

#define	FADF_EMBEDDED	( 0x4 )

#define	FADF_FIXEDSIZE	( 0x10 )

#define	FADF_BSTR	( 0x100 )

#define	FADF_UNKNOWN	( 0x200 )

#define	FADF_DISPATCH	( 0x400 )

#define	FADF_VARIANT	( 0x800 )

#define	FADF_RESERVED	( 0xf0e8 )

/* VARIANT STRUCTURE
 *
 *  VARTYPE vt;
 *  WORD wReserved1;
 *  WORD wReserved2;
 *  WORD wReserved3;
 *  union {
 *    long           VT_I4
 *    BYTE           VT_UI1
 *    short          VT_I2
 *    float          VT_R4
 *    double         VT_R8
 *    VARIANT_BOOL   VT_BOOL
 *    SCODE          VT_ERROR
 *    CY             VT_CY
 *    DATE           VT_DATE
 *    BSTR           VT_BSTR
 *    IUnknown *     VT_UNKNOWN
 *    IDispatch *    VT_DISPATCH
 *    SAFEARRAY *    VT_ARRAY
 *    BYTE *         VT_BYREF|VT_UI1
 *    short *        VT_BYREF|VT_I2
 *    long *         VT_BYREF|VT_I4
 *    float *        VT_BYREF|VT_R4
 *    double *       VT_BYREF|VT_R8
 *    VARIANT_BOOL * VT_BYREF|VT_BOOL
 *    SCODE *        VT_BYREF|VT_ERROR
 *    CY *           VT_BYREF|VT_CY
 *    DATE *         VT_BYREF|VT_DATE
 *    BSTR *         VT_BYREF|VT_BSTR
 *    IUnknown **    VT_BYREF|VT_UNKNOWN
 *    IDispatch **   VT_BYREF|VT_DISPATCH
 *    SAFEARRAY **   VT_BYREF|VT_ARRAY
 *    VARIANT *      VT_BYREF|VT_VARIANT
 *    void*          VT_BYREF (Generic ByRef)
 *    char           VT_I1
 *    unsigned short         VT_UI2
 *    unsigned long          VT_UI4
 *    int            VT_INT
 *    unsigned           VT_UINT
 *    DECIMAL *      VT_BYREF|VT_DECIMAL
 *    char *         VT_BYREF|VT_I1
 *    unsigned short *       VT_BYREF|VT_UI2
 *    unsigned long *        VT_BYREF|VT_UI4
 *    int *          VT_BYREF|VT_INT
 *    unsigned *         VT_BYREF|VT_UINT
 *  }
 */
#if (__STDC__ && !defined(_FORCENAMELESSUNION)) || defined(NONAMELESSUNION)
#define __VARIANT_NAME_1 n1
#define __VARIANT_NAME_2 n2
#define __VARIANT_NAME_3 n3
#else
#define __tagVARIANT
#define __VARIANT_NAME_1
#define __VARIANT_NAME_2
#define __VARIANT_NAME_3
#endif
typedef /* [wire_marshal] */ struct tagVARIANT VARIANT;

struct  tagVARIANT
    {
    union 
        {
        struct  __tagVARIANT
            {
            VARTYPE vt;
            WORD wReserved1;
            WORD wReserved2;
            WORD wReserved3;
            union 
                {
                long lVal;
                BYTE bVal;
                short iVal;
                float fltVal;
                double dblVal;
                VARIANT_BOOL boolVal;
                _VARIANT_BOOL bool;
                SCODE scode;
                CY cyVal;
                DATE date;
                BSTR bstrVal;
                IUnknown  *punkVal;
                IDispatch  *pdispVal;
                SAFEARRAY  *parray;
                BYTE  *pbVal;
                short  *piVal;
                long  *plVal;
                float  *pfltVal;
                double  *pdblVal;
                VARIANT_BOOL  *pboolVal;
                _VARIANT_BOOL  *pbool;
                SCODE  *pscode;
                CY  *pcyVal;
                DATE  *pdate;
                BSTR  *pbstrVal;
                IUnknown  * *ppunkVal;
                IDispatch  * *ppdispVal;
                SAFEARRAY  * *pparray;
                VARIANT  *pvarVal;
                void* byref;
                char cVal;
                unsigned short uiVal;
                unsigned long ulVal;
                int intVal;
                unsigned uintVal;
                DECIMAL  *pdecVal;
                char  *pcVal;
                unsigned short  *puiVal;
                unsigned long  *pulVal;
                int  *pintVal;
                unsigned  *puintVal;
                }	__VARIANT_NAME_3;
            }	__VARIANT_NAME_2;
        DECIMAL decVal;
        }	__VARIANT_NAME_1;
    };
typedef VARIANT  *LPVARIANT;

typedef VARIANT VARIANTARG;

typedef VARIANT  *LPVARIANTARG;

#if defined(_OLEAUT32_)
/* the following is what MIDL knows how to remote */
struct  _wireVARIANT
    {
    unsigned long clSize;
    unsigned long rpcReserved;
    unsigned short vt;
    unsigned short wReserved1;
    unsigned short wReserved2;
    unsigned short wReserved3;
    /* [switch_is][switch_type] */ union 
        {
        /* [case()] */ long lVal;
        /* [case()] */ BYTE bVal;
        /* [case()] */ short iVal;
        /* [case()] */ float fltVal;
        /* [case()] */ double dblVal;
        /* [case()] */ VARIANT_BOOL boolVal;
        /* [case()] */ SCODE scode;
        /* [case()] */ CY cyVal;
        /* [case()] */ DATE date;
        /* [case()] */ wireBSTR bstrVal;
        /* [case()] */ IUnknown  *punkVal;
        /* [case()] */ IDispatch  *pdispVal;
        /* [case()] */ wireSAFEARRAY parray;
        /* [case()] */ BYTE  *pbVal;
        /* [case()] */ short  *piVal;
        /* [case()] */ long  *plVal;
        /* [case()] */ float  *pfltVal;
        /* [case()] */ double  *pdblVal;
        /* [case()] */ VARIANT_BOOL  *pboolVal;
        /* [case()] */ SCODE  *pscode;
        /* [case()] */ CY  *pcyVal;
        /* [case()] */ DATE  *pdate;
        /* [case()] */ wireBSTR  *pbstrVal;
        /* [case()] */ IUnknown  * *ppunkVal;
        /* [case()] */ IDispatch  * *ppdispVal;
        /* [case()] */ wireSAFEARRAY  *pparray;
        /* [case()] */ wireVARIANT  *pvarVal;
        /* [case()] */ char cVal;
        /* [case()] */ unsigned short uiVal;
        /* [case()] */ unsigned long ulVal;
        /* [case()] */ int intVal;
        /* [case()] */ unsigned uintVal;
        /* [case()] */ DECIMAL decVal;
        /* [case()] */ DECIMAL  *pdecVal;
        /* [case()] */ char  *pcVal;
        /* [case()] */ unsigned short  *puiVal;
        /* [case()] */ unsigned long  *pulVal;
        /* [case()] */ int  *pintVal;
        /* [case()] */ unsigned  *puintVal;
        /* [case()] */  /* Empty union arm */ 
        /* [case()] */  /* Empty union arm */ 
        }	;
    };
#endif /* _OLEAUT32_ */
typedef long DISPID;

typedef DISPID MEMBERID;

typedef unsigned long HREFTYPE;

typedef /* [v1_enum] */ 
enum tagTYPEKIND
    {	TKIND_ENUM	= 0,
	TKIND_RECORD	= TKIND_ENUM + 1,
	TKIND_MODULE	= TKIND_RECORD + 1,
	TKIND_INTERFACE	= TKIND_MODULE + 1,
	TKIND_DISPATCH	= TKIND_INTERFACE + 1,
	TKIND_COCLASS	= TKIND_DISPATCH + 1,
	TKIND_ALIAS	= TKIND_COCLASS + 1,
	TKIND_UNION	= TKIND_ALIAS + 1,
	TKIND_MAX	= TKIND_UNION + 1
    }	TYPEKIND;

typedef struct  tagTYPEDESC
    {
    /* [switch_is][switch_type] */ union 
        {
        /* [case()] */ struct tagTYPEDESC  *lptdesc;
        /* [case()] */ struct tagARRAYDESC  *lpadesc;
        /* [case()] */ HREFTYPE hreftype;
        /* [default] */  /* Empty union arm */ 
        }	;
    VARTYPE vt;
    }	TYPEDESC;

typedef struct  tagARRAYDESC
    {
    TYPEDESC tdescElem;
    unsigned short cDims;
    /* [size_is] */ SAFEARRAYBOUND rgbounds[ 1 ];
    }	ARRAYDESC;

typedef struct  tagPARAMDESCEX
    {
    unsigned long cBytes;
    VARIANTARG varDefaultValue;
    }	PARAMDESCEX;

typedef struct tagPARAMDESCEX  *LPPARAMDESCEX;

typedef struct  tagPARAMDESC
    {
    LPPARAMDESCEX pparamdescex;
    unsigned short wParamFlags;
    }	PARAMDESC;

typedef struct tagPARAMDESC  *LPPARAMDESC;

#define	PARAMFLAG_NONE	( 0 )

#define	PARAMFLAG_FIN	( 0x1 )

#define	PARAMFLAG_FOUT	( 0x2 )

#define	PARAMFLAG_FLCID	( 0x4 )

#define	PARAMFLAG_FRETVAL	( 0x8 )

#define	PARAMFLAG_FOPT	( 0x10 )

#define	PARAMFLAG_FHASDEFAULT	( 0x20 )

typedef struct  tagIDLDESC
    {
    unsigned long dwReserved;
    unsigned short wIDLFlags;
    }	IDLDESC;

typedef struct tagIDLDESC  *LPIDLDESC;

#define	IDLFLAG_NONE	( PARAMFLAG_NONE )

#define	IDLFLAG_FIN	( PARAMFLAG_FIN )

#define	IDLFLAG_FOUT	( PARAMFLAG_FOUT )

#define	IDLFLAG_FLCID	( PARAMFLAG_FLCID )

#define	IDLFLAG_FRETVAL	( PARAMFLAG_FRETVAL )

#if 0
/* the following is what MIDL knows how to remote */
typedef struct  tagELEMDESC
    {
    TYPEDESC tdesc;
    PARAMDESC paramdesc;
    }	ELEMDESC;

#else /* 0 */
typedef struct tagELEMDESC {
    TYPEDESC tdesc;             /* the type of the element */
    union {
        IDLDESC idldesc;        /* info for remoting the element */
        PARAMDESC paramdesc;    /* info about the parameter */
    };
} ELEMDESC, * LPELEMDESC;
#endif /* 0 */
typedef struct  tagTYPEATTR
    {
    GUID guid;
    LCID lcid;
    unsigned long dwReserved;
    MEMBERID memidConstructor;
    MEMBERID memidDestructor;
    LPOLESTR lpstrSchema;
    unsigned long cbSizeInstance;
    TYPEKIND typekind;
    WORD cFuncs;
    WORD cVars;
    WORD cImplTypes;
    WORD cbSizeVft;
    WORD cbAlignment;
    WORD wTypeFlags;
    WORD wMajorVerNum;
    WORD wMinorVerNum;
    TYPEDESC tdescAlias;
    IDLDESC idldescType;
    }	TYPEATTR;

typedef struct tagTYPEATTR  *LPTYPEATTR;

typedef struct  tagDISPPARAMS
    {
    /* [size_is] */ VARIANTARG  *rgvarg;
    /* [size_is] */ DISPID  *rgdispidNamedArgs;
    unsigned cArgs;
    unsigned cNamedArgs;
    }	DISPPARAMS;

#if 0
/* the following is what MIDL knows how to remote */
typedef struct  tagEXCEPINFO
    {
    WORD wCode;
    WORD wReserved;
    BSTR bstrSource;
    BSTR bstrDescription;
    BSTR bstrHelpFile;
    unsigned long dwHelpContext;
    unsigned long pvReserved;
    unsigned long pfnDeferredFillIn;
    SCODE scode;
    }	EXCEPINFO;

#else /* 0 */
typedef struct tagEXCEPINFO {
    WORD  wCode;
    WORD  wReserved;
    BSTR  bstrSource;
    BSTR  bstrDescription;
    BSTR  bstrHelpFile;
    unsigned long dwHelpContext;
    void* pvReserved;
    HRESULT (__stdcall *pfnDeferredFillIn)(struct tagEXCEPINFO *);
    SCODE scode;
} EXCEPINFO, * LPEXCEPINFO;
#endif /* 0 */
typedef /* [v1_enum] */ 
enum tagCALLCONV
    {	CC_FASTCALL	= 0,
	CC_CDECL	= 1,
	CC_MSCPASCAL	= CC_CDECL + 1,
	CC_PASCAL	= CC_MSCPASCAL,
	CC_MACPASCAL	= CC_PASCAL + 1,
	CC_STDCALL	= CC_MACPASCAL + 1,
	CC_FPFASTCALL	= CC_STDCALL + 1,
	CC_SYSCALL	= CC_FPFASTCALL + 1,
	CC_MPWCDECL	= CC_SYSCALL + 1,
	CC_MPWPASCAL	= CC_MPWCDECL + 1,
	CC_MAX	= CC_MPWPASCAL + 1
    }	CALLCONV;

typedef /* [v1_enum] */ 
enum tagFUNCKIND
    {	FUNC_VIRTUAL	= 0,
	FUNC_PUREVIRTUAL	= FUNC_VIRTUAL + 1,
	FUNC_NONVIRTUAL	= FUNC_PUREVIRTUAL + 1,
	FUNC_STATIC	= FUNC_NONVIRTUAL + 1,
	FUNC_DISPATCH	= FUNC_STATIC + 1
    }	FUNCKIND;

typedef /* [v1_enum] */ 
enum tagINVOKEKIND
    {	INVOKE_FUNC	= 1,
	INVOKE_PROPERTYGET	= 2,
	INVOKE_PROPERTYPUT	= 4,
	INVOKE_PROPERTYPUTREF	= 8
    }	INVOKEKIND;

typedef struct  tagFUNCDESC
    {
    MEMBERID memid;
    /* [size_is] */ SCODE  *lprgscode;
    /* [size_is] */ ELEMDESC  *lprgelemdescParam;
    FUNCKIND funckind;
    INVOKEKIND invkind;
    CALLCONV callconv;
    short cParams;
    short cParamsOpt;
    short oVft;
    short cScodes;
    ELEMDESC elemdescFunc;
    WORD wFuncFlags;
    }	FUNCDESC;

typedef struct tagFUNCDESC  *LPFUNCDESC;

typedef /* [v1_enum] */ 
enum tagVARKIND
    {	VAR_PERINSTANCE	= 0,
	VAR_STATIC	= VAR_PERINSTANCE + 1,
	VAR_CONST	= VAR_STATIC + 1,
	VAR_DISPATCH	= VAR_CONST + 1
    }	VARKIND;

#define	IMPLTYPEFLAG_FDEFAULT	( 0x1 )

#define	IMPLTYPEFLAG_FSOURCE	( 0x2 )

#define	IMPLTYPEFLAG_FRESTRICTED	( 0x4 )

#define	IMPLTYPEFLAG_FDEFAULTVTABLE	( 0x8 )

typedef struct  tagVARDESC
    {
    MEMBERID memid;
    LPOLESTR lpstrSchema;
    /* [switch_is][switch_type] */ union 
        {
        /* [case()] */ unsigned long oInst;
        /* [case()] */ VARIANT  *lpvarValue;
        }	;
    ELEMDESC elemdescVar;
    WORD wVarFlags;
    VARKIND varkind;
    }	VARDESC;

typedef struct tagVARDESC  *LPVARDESC;

typedef 
enum tagTYPEFLAGS
    {	TYPEFLAG_FAPPOBJECT	= 0x1,
	TYPEFLAG_FCANCREATE	= 0x2,
	TYPEFLAG_FLICENSED	= 0x4,
	TYPEFLAG_FPREDECLID	= 0x8,
	TYPEFLAG_FHIDDEN	= 0x10,
	TYPEFLAG_FCONTROL	= 0x20,
	TYPEFLAG_FDUAL	= 0x40,
	TYPEFLAG_FNONEXTENSIBLE	= 0x80,
	TYPEFLAG_FOLEAUTOMATION	= 0x100,
	TYPEFLAG_FRESTRICTED	= 0x200,
	TYPEFLAG_FAGGREGATABLE	= 0x400,
	TYPEFLAG_FREPLACEABLE	= 0x800,
	TYPEFLAG_FDISPATCHABLE	= 0x1000,
	TYPEFLAG_FREVERSEBIND	= 0x2000
    }	TYPEFLAGS;

typedef 
enum tagFUNCFLAGS
    {	FUNCFLAG_FRESTRICTED	= 0x1,
	FUNCFLAG_FSOURCE	= 0x2,
	FUNCFLAG_FBINDABLE	= 0x4,
	FUNCFLAG_FREQUESTEDIT	= 0x8,
	FUNCFLAG_FDISPLAYBIND	= 0x10,
	FUNCFLAG_FDEFAULTBIND	= 0x20,
	FUNCFLAG_FHIDDEN	= 0x40,
	FUNCFLAG_FUSESGETLASTERROR	= 0x80,
	FUNCFLAG_FDEFAULTCOLLELEM	= 0x100,
	FUNCFLAG_FUIDEFAULT	= 0x200,
	FUNCFLAG_FNONBROWSABLE	= 0x400,
	FUNCFLAG_FREPLACEABLE	= 0x800,
	FUNCFLAG_FIMMEDIATEBIND	= 0x1000
    }	FUNCFLAGS;

typedef 
enum tagVARFLAGS
    {	VARFLAG_FREADONLY	= 0x1,
	VARFLAG_FSOURCE	= 0x2,
	VARFLAG_FBINDABLE	= 0x4,
	VARFLAG_FREQUESTEDIT	= 0x8,
	VARFLAG_FDISPLAYBIND	= 0x10,
	VARFLAG_FDEFAULTBIND	= 0x20,
	VARFLAG_FHIDDEN	= 0x40,
	VARFLAG_FRESTRICTED	= 0x80,
	VARFLAG_FDEFAULTCOLLELEM	= 0x100,
	VARFLAG_FUIDEFAULT	= 0x200,
	VARFLAG_FNONBROWSABLE	= 0x400,
	VARFLAG_FREPLACEABLE	= 0x800,
	VARFLAG_FIMMEDIATEBIND	= 0x1000
    }	VARFLAGS;

typedef /* [wire_marshal] */ struct  tagCLEANLOCALSTORAGE
    {
    IUnknown  *pInterface;
    void* pStorage;
    unsigned long flags;
    }	CLEANLOCALSTORAGE;

typedef struct  tagCUSTDATAITEM
    {
    GUID guid;
    VARIANTARG varValue;
    }	CUSTDATAITEM;

typedef struct tagCUSTDATAITEM  *LPCUSTDATAITEM;

typedef struct  tagCUSTDATA
    {
    unsigned long cCustData;
    /* [size_is] */ LPCUSTDATAITEM prgCustData;
    }	CUSTDATA;

typedef struct tagCUSTDATA  *LPCUSTDATA;



extern RPC_IF_HANDLE IOleAutomationTypes_v1_0_c_ifspec;
extern RPC_IF_HANDLE IOleAutomationTypes_v1_0_s_ifspec;
#endif /* __IOleAutomationTypes_INTERFACE_DEFINED__ */

#ifndef __ICreateTypeInfo_INTERFACE_DEFINED__
#define __ICreateTypeInfo_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ICreateTypeInfo
 * at Sat Jul 13 21:56:52 1996
 * using MIDL 3.00.39
 ****************************************/
/* [local][unique][uuid][object] */ 


typedef /* [unique] */ ICreateTypeInfo  *LPCREATETYPEINFO;


EXTERN_C const IID IID_ICreateTypeInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ICreateTypeInfo : public IUnknown
    {
    public:
        virtual HRESULT __stdcall SetGuid( 
            /* [in] */ REFGUID guid) = 0;
        
        virtual HRESULT __stdcall SetTypeFlags( 
            /* [in] */ unsigned uTypeFlags) = 0;
        
        virtual HRESULT __stdcall SetDocString( 
            /* [in] */ LPOLESTR pStrDoc) = 0;
        
        virtual HRESULT __stdcall SetHelpContext( 
            /* [in] */ unsigned long dwHelpContext) = 0;
        
        virtual HRESULT __stdcall SetVersion( 
            /* [in] */ WORD wMajorVerNum,
            /* [in] */ WORD wMinorVerNum) = 0;
        
        virtual HRESULT __stdcall AddRefTypeInfo( 
            /* [in] */ ITypeInfo  *pTInfo,
            /* [in] */ HREFTYPE  *phRefType) = 0;
        
        virtual HRESULT __stdcall AddFuncDesc( 
            /* [in] */ unsigned index,
            /* [in] */ FUNCDESC  *pFuncDesc) = 0;
        
        virtual HRESULT __stdcall AddImplType( 
            /* [in] */ unsigned index,
            /* [in] */ HREFTYPE hRefType) = 0;
        
        virtual HRESULT __stdcall SetImplTypeFlags( 
            /* [in] */ unsigned index,
            /* [in] */ int implTypeFlags) = 0;
        
        virtual HRESULT __stdcall SetAlignment( 
            /* [in] */ WORD cbAlignment) = 0;
        
        virtual HRESULT __stdcall SetSchema( 
            /* [in] */ LPOLESTR pStrSchema) = 0;
        
        virtual HRESULT __stdcall AddVarDesc( 
            /* [in] */ unsigned index,
            /* [in] */ VARDESC  *pVarDesc) = 0;
        
        virtual HRESULT __stdcall SetFuncAndParamNames( 
            /* [in] */ unsigned index,
            /* [in][size_is][in] */ LPOLESTR  *rgszNames,
            /* [in] */ unsigned cNames) = 0;
        
        virtual HRESULT __stdcall SetVarName( 
            /* [in] */ unsigned index,
            /* [in] */ LPOLESTR szName) = 0;
        
        virtual HRESULT __stdcall SetTypeDescAlias( 
            /* [in] */ TYPEDESC  *pTDescAlias) = 0;
        
        virtual HRESULT __stdcall DefineFuncAsDllEntry( 
            /* [in] */ unsigned index,
            /* [in] */ LPOLESTR szDllName,
            /* [in] */ LPOLESTR szProcName) = 0;
        
        virtual HRESULT __stdcall SetFuncDocString( 
            /* [in] */ unsigned index,
            /* [in] */ LPOLESTR szDocString) = 0;
        
        virtual HRESULT __stdcall SetVarDocString( 
            /* [in] */ unsigned index,
            /* [in] */ LPOLESTR szDocString) = 0;
        
        virtual HRESULT __stdcall SetFuncHelpContext( 
            /* [in] */ unsigned index,
            /* [in] */ unsigned long dwHelpContext) = 0;
        
        virtual HRESULT __stdcall SetVarHelpContext( 
            /* [in] */ unsigned index,
            /* [in] */ unsigned long dwHelpContext) = 0;
        
        virtual HRESULT __stdcall SetMops( 
            /* [in] */ unsigned index,
            /* [in] */ BSTR bstrMops) = 0;
        
        virtual HRESULT __stdcall SetTypeIdldesc( 
            /* [in] */ IDLDESC  *pIdlDesc) = 0;
        
        virtual HRESULT __stdcall LayOut( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICreateTypeInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            ICreateTypeInfo  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            ICreateTypeInfo  * This);
        
        unsigned long ( __stdcall  *Release )( 
            ICreateTypeInfo  * This);
        
        HRESULT ( __stdcall  *SetGuid )( 
            ICreateTypeInfo  * This,
            /* [in] */ REFGUID guid);
        
        HRESULT ( __stdcall  *SetTypeFlags )( 
            ICreateTypeInfo  * This,
            /* [in] */ unsigned uTypeFlags);
        
        HRESULT ( __stdcall  *SetDocString )( 
            ICreateTypeInfo  * This,
            /* [in] */ LPOLESTR pStrDoc);
        
        HRESULT ( __stdcall  *SetHelpContext )( 
            ICreateTypeInfo  * This,
            /* [in] */ unsigned long dwHelpContext);
        
        HRESULT ( __stdcall  *SetVersion )( 
            ICreateTypeInfo  * This,
            /* [in] */ WORD wMajorVerNum,
            /* [in] */ WORD wMinorVerNum);
        
        HRESULT ( __stdcall  *AddRefTypeInfo )( 
            ICreateTypeInfo  * This,
            /* [in] */ ITypeInfo  *pTInfo,
            /* [in] */ HREFTYPE  *phRefType);
        
        HRESULT ( __stdcall  *AddFuncDesc )( 
            ICreateTypeInfo  * This,
            /* [in] */ unsigned index,
            /* [in] */ FUNCDESC  *pFuncDesc);
        
        HRESULT ( __stdcall  *AddImplType )( 
            ICreateTypeInfo  * This,
            /* [in] */ unsigned index,
            /* [in] */ HREFTYPE hRefType);
        
        HRESULT ( __stdcall  *SetImplTypeFlags )( 
            ICreateTypeInfo  * This,
            /* [in] */ unsigned index,
            /* [in] */ int implTypeFlags);
        
        HRESULT ( __stdcall  *SetAlignment )( 
            ICreateTypeInfo  * This,
            /* [in] */ WORD cbAlignment);
        
        HRESULT ( __stdcall  *SetSchema )( 
            ICreateTypeInfo  * This,
            /* [in] */ LPOLESTR pStrSchema);
        
        HRESULT ( __stdcall  *AddVarDesc )( 
            ICreateTypeInfo  * This,
            /* [in] */ unsigned index,
            /* [in] */ VARDESC  *pVarDesc);
        
        HRESULT ( __stdcall  *SetFuncAndParamNames )( 
            ICreateTypeInfo  * This,
            /* [in] */ unsigned index,
            /* [in][size_is][in] */ LPOLESTR  *rgszNames,
            /* [in] */ unsigned cNames);
        
        HRESULT ( __stdcall  *SetVarName )( 
            ICreateTypeInfo  * This,
            /* [in] */ unsigned index,
            /* [in] */ LPOLESTR szName);
        
        HRESULT ( __stdcall  *SetTypeDescAlias )( 
            ICreateTypeInfo  * This,
            /* [in] */ TYPEDESC  *pTDescAlias);
        
        HRESULT ( __stdcall  *DefineFuncAsDllEntry )( 
            ICreateTypeInfo  * This,
            /* [in] */ unsigned index,
            /* [in] */ LPOLESTR szDllName,
            /* [in] */ LPOLESTR szProcName);
        
        HRESULT ( __stdcall  *SetFuncDocString )( 
            ICreateTypeInfo  * This,
            /* [in] */ unsigned index,
            /* [in] */ LPOLESTR szDocString);
        
        HRESULT ( __stdcall  *SetVarDocString )( 
            ICreateTypeInfo  * This,
            /* [in] */ unsigned index,
            /* [in] */ LPOLESTR szDocString);
        
        HRESULT ( __stdcall  *SetFuncHelpContext )( 
            ICreateTypeInfo  * This,
            /* [in] */ unsigned index,
            /* [in] */ unsigned long dwHelpContext);
        
        HRESULT ( __stdcall  *SetVarHelpContext )( 
            ICreateTypeInfo  * This,
            /* [in] */ unsigned index,
            /* [in] */ unsigned long dwHelpContext);
        
        HRESULT ( __stdcall  *SetMops )( 
            ICreateTypeInfo  * This,
            /* [in] */ unsigned index,
            /* [in] */ BSTR bstrMops);
        
        HRESULT ( __stdcall  *SetTypeIdldesc )( 
            ICreateTypeInfo  * This,
            /* [in] */ IDLDESC  *pIdlDesc);
        
        HRESULT ( __stdcall  *LayOut )( 
            ICreateTypeInfo  * This);
        
        END_INTERFACE
    } ICreateTypeInfoVtbl;

    interface ICreateTypeInfo
    {
        CONST_VTBL struct ICreateTypeInfoVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICreateTypeInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICreateTypeInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICreateTypeInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICreateTypeInfo_SetGuid(This,guid)	\
    (This)->lpVtbl -> SetGuid(This,guid)

#define ICreateTypeInfo_SetTypeFlags(This,uTypeFlags)	\
    (This)->lpVtbl -> SetTypeFlags(This,uTypeFlags)

#define ICreateTypeInfo_SetDocString(This,pStrDoc)	\
    (This)->lpVtbl -> SetDocString(This,pStrDoc)

#define ICreateTypeInfo_SetHelpContext(This,dwHelpContext)	\
    (This)->lpVtbl -> SetHelpContext(This,dwHelpContext)

#define ICreateTypeInfo_SetVersion(This,wMajorVerNum,wMinorVerNum)	\
    (This)->lpVtbl -> SetVersion(This,wMajorVerNum,wMinorVerNum)

#define ICreateTypeInfo_AddRefTypeInfo(This,pTInfo,phRefType)	\
    (This)->lpVtbl -> AddRefTypeInfo(This,pTInfo,phRefType)

#define ICreateTypeInfo_AddFuncDesc(This,index,pFuncDesc)	\
    (This)->lpVtbl -> AddFuncDesc(This,index,pFuncDesc)

#define ICreateTypeInfo_AddImplType(This,index,hRefType)	\
    (This)->lpVtbl -> AddImplType(This,index,hRefType)

#define ICreateTypeInfo_SetImplTypeFlags(This,index,implTypeFlags)	\
    (This)->lpVtbl -> SetImplTypeFlags(This,index,implTypeFlags)

#define ICreateTypeInfo_SetAlignment(This,cbAlignment)	\
    (This)->lpVtbl -> SetAlignment(This,cbAlignment)

#define ICreateTypeInfo_SetSchema(This,pStrSchema)	\
    (This)->lpVtbl -> SetSchema(This,pStrSchema)

#define ICreateTypeInfo_AddVarDesc(This,index,pVarDesc)	\
    (This)->lpVtbl -> AddVarDesc(This,index,pVarDesc)

#define ICreateTypeInfo_SetFuncAndParamNames(This,index,rgszNames,cNames)	\
    (This)->lpVtbl -> SetFuncAndParamNames(This,index,rgszNames,cNames)

#define ICreateTypeInfo_SetVarName(This,index,szName)	\
    (This)->lpVtbl -> SetVarName(This,index,szName)

#define ICreateTypeInfo_SetTypeDescAlias(This,pTDescAlias)	\
    (This)->lpVtbl -> SetTypeDescAlias(This,pTDescAlias)

#define ICreateTypeInfo_DefineFuncAsDllEntry(This,index,szDllName,szProcName)	\
    (This)->lpVtbl -> DefineFuncAsDllEntry(This,index,szDllName,szProcName)

#define ICreateTypeInfo_SetFuncDocString(This,index,szDocString)	\
    (This)->lpVtbl -> SetFuncDocString(This,index,szDocString)

#define ICreateTypeInfo_SetVarDocString(This,index,szDocString)	\
    (This)->lpVtbl -> SetVarDocString(This,index,szDocString)

#define ICreateTypeInfo_SetFuncHelpContext(This,index,dwHelpContext)	\
    (This)->lpVtbl -> SetFuncHelpContext(This,index,dwHelpContext)

#define ICreateTypeInfo_SetVarHelpContext(This,index,dwHelpContext)	\
    (This)->lpVtbl -> SetVarHelpContext(This,index,dwHelpContext)

#define ICreateTypeInfo_SetMops(This,index,bstrMops)	\
    (This)->lpVtbl -> SetMops(This,index,bstrMops)

#define ICreateTypeInfo_SetTypeIdldesc(This,pIdlDesc)	\
    (This)->lpVtbl -> SetTypeIdldesc(This,pIdlDesc)

#define ICreateTypeInfo_LayOut(This)	\
    (This)->lpVtbl -> LayOut(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall ICreateTypeInfo_SetGuid_Proxy( 
    ICreateTypeInfo  * This,
    /* [in] */ REFGUID guid);


void __stdcall ICreateTypeInfo_SetGuid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeInfo_SetTypeFlags_Proxy( 
    ICreateTypeInfo  * This,
    /* [in] */ unsigned uTypeFlags);


void __stdcall ICreateTypeInfo_SetTypeFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeInfo_SetDocString_Proxy( 
    ICreateTypeInfo  * This,
    /* [in] */ LPOLESTR pStrDoc);


void __stdcall ICreateTypeInfo_SetDocString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeInfo_SetHelpContext_Proxy( 
    ICreateTypeInfo  * This,
    /* [in] */ unsigned long dwHelpContext);


void __stdcall ICreateTypeInfo_SetHelpContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeInfo_SetVersion_Proxy( 
    ICreateTypeInfo  * This,
    /* [in] */ WORD wMajorVerNum,
    /* [in] */ WORD wMinorVerNum);


void __stdcall ICreateTypeInfo_SetVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeInfo_AddRefTypeInfo_Proxy( 
    ICreateTypeInfo  * This,
    /* [in] */ ITypeInfo  *pTInfo,
    /* [in] */ HREFTYPE  *phRefType);


void __stdcall ICreateTypeInfo_AddRefTypeInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeInfo_AddFuncDesc_Proxy( 
    ICreateTypeInfo  * This,
    /* [in] */ unsigned index,
    /* [in] */ FUNCDESC  *pFuncDesc);


void __stdcall ICreateTypeInfo_AddFuncDesc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeInfo_AddImplType_Proxy( 
    ICreateTypeInfo  * This,
    /* [in] */ unsigned index,
    /* [in] */ HREFTYPE hRefType);


void __stdcall ICreateTypeInfo_AddImplType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeInfo_SetImplTypeFlags_Proxy( 
    ICreateTypeInfo  * This,
    /* [in] */ unsigned index,
    /* [in] */ int implTypeFlags);


void __stdcall ICreateTypeInfo_SetImplTypeFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeInfo_SetAlignment_Proxy( 
    ICreateTypeInfo  * This,
    /* [in] */ WORD cbAlignment);


void __stdcall ICreateTypeInfo_SetAlignment_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeInfo_SetSchema_Proxy( 
    ICreateTypeInfo  * This,
    /* [in] */ LPOLESTR pStrSchema);


void __stdcall ICreateTypeInfo_SetSchema_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeInfo_AddVarDesc_Proxy( 
    ICreateTypeInfo  * This,
    /* [in] */ unsigned index,
    /* [in] */ VARDESC  *pVarDesc);


void __stdcall ICreateTypeInfo_AddVarDesc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeInfo_SetFuncAndParamNames_Proxy( 
    ICreateTypeInfo  * This,
    /* [in] */ unsigned index,
    /* [in][size_is][in] */ LPOLESTR  *rgszNames,
    /* [in] */ unsigned cNames);


void __stdcall ICreateTypeInfo_SetFuncAndParamNames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeInfo_SetVarName_Proxy( 
    ICreateTypeInfo  * This,
    /* [in] */ unsigned index,
    /* [in] */ LPOLESTR szName);


void __stdcall ICreateTypeInfo_SetVarName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeInfo_SetTypeDescAlias_Proxy( 
    ICreateTypeInfo  * This,
    /* [in] */ TYPEDESC  *pTDescAlias);


void __stdcall ICreateTypeInfo_SetTypeDescAlias_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeInfo_DefineFuncAsDllEntry_Proxy( 
    ICreateTypeInfo  * This,
    /* [in] */ unsigned index,
    /* [in] */ LPOLESTR szDllName,
    /* [in] */ LPOLESTR szProcName);


void __stdcall ICreateTypeInfo_DefineFuncAsDllEntry_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeInfo_SetFuncDocString_Proxy( 
    ICreateTypeInfo  * This,
    /* [in] */ unsigned index,
    /* [in] */ LPOLESTR szDocString);


void __stdcall ICreateTypeInfo_SetFuncDocString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeInfo_SetVarDocString_Proxy( 
    ICreateTypeInfo  * This,
    /* [in] */ unsigned index,
    /* [in] */ LPOLESTR szDocString);


void __stdcall ICreateTypeInfo_SetVarDocString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeInfo_SetFuncHelpContext_Proxy( 
    ICreateTypeInfo  * This,
    /* [in] */ unsigned index,
    /* [in] */ unsigned long dwHelpContext);


void __stdcall ICreateTypeInfo_SetFuncHelpContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeInfo_SetVarHelpContext_Proxy( 
    ICreateTypeInfo  * This,
    /* [in] */ unsigned index,
    /* [in] */ unsigned long dwHelpContext);


void __stdcall ICreateTypeInfo_SetVarHelpContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeInfo_SetMops_Proxy( 
    ICreateTypeInfo  * This,
    /* [in] */ unsigned index,
    /* [in] */ BSTR bstrMops);


void __stdcall ICreateTypeInfo_SetMops_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeInfo_SetTypeIdldesc_Proxy( 
    ICreateTypeInfo  * This,
    /* [in] */ IDLDESC  *pIdlDesc);


void __stdcall ICreateTypeInfo_SetTypeIdldesc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeInfo_LayOut_Proxy( 
    ICreateTypeInfo  * This);


void __stdcall ICreateTypeInfo_LayOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __ICreateTypeInfo_INTERFACE_DEFINED__ */


#ifndef __ICreateTypeInfo2_INTERFACE_DEFINED__
#define __ICreateTypeInfo2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ICreateTypeInfo2
 * at Sat Jul 13 21:56:52 1996
 * using MIDL 3.00.39
 ****************************************/
/* [local][unique][uuid][object] */ 


typedef /* [unique] */ ICreateTypeInfo2  *LPCREATETYPEINFO2;


EXTERN_C const IID IID_ICreateTypeInfo2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ICreateTypeInfo2 : public ICreateTypeInfo
    {
    public:
        virtual HRESULT __stdcall DeleteFuncDesc( 
            /* [in] */ unsigned index) = 0;
        
        virtual HRESULT __stdcall DeleteFuncDescByMemId( 
            /* [in] */ MEMBERID memid,
            /* [in] */ INVOKEKIND invKind) = 0;
        
        virtual HRESULT __stdcall DeleteVarDesc( 
            /* [in] */ unsigned index) = 0;
        
        virtual HRESULT __stdcall DeleteVarDescByMemId( 
            /* [in] */ MEMBERID memid) = 0;
        
        virtual HRESULT __stdcall DeleteImplType( 
            /* [in] */ unsigned index) = 0;
        
        virtual HRESULT __stdcall SetCustData( 
            /* [in] */ REFGUID guid,
            /* [in] */ VARIANT  *pVarVal) = 0;
        
        virtual HRESULT __stdcall SetFuncCustData( 
            /* [in] */ unsigned index,
            /* [in] */ REFGUID guid,
            /* [in] */ VARIANT  *pVarVal) = 0;
        
        virtual HRESULT __stdcall SetParamCustData( 
            /* [in] */ unsigned indexFunc,
            /* [in] */ unsigned indexParam,
            /* [in] */ REFGUID guid,
            /* [in] */ VARIANT  *pVarVal) = 0;
        
        virtual HRESULT __stdcall SetVarCustData( 
            /* [in] */ unsigned index,
            /* [in] */ REFGUID guid,
            /* [in] */ VARIANT  *pVarVal) = 0;
        
        virtual HRESULT __stdcall SetImplTypeCustData( 
            /* [in] */ unsigned index,
            /* [in] */ REFGUID guid,
            /* [in] */ VARIANT  *pVarVal) = 0;
        
        virtual HRESULT __stdcall SetHelpStringContext( 
            /* [in] */ unsigned long dwHelpStringContext) = 0;
        
        virtual HRESULT __stdcall SetFuncHelpStringContext( 
            /* [in] */ unsigned index,
            /* [in] */ unsigned long dwHelpStringContext) = 0;
        
        virtual HRESULT __stdcall SetVarHelpStringContext( 
            /* [in] */ unsigned index,
            /* [in] */ unsigned long dwHelpStringContext) = 0;
        
        virtual HRESULT __stdcall Invalidate( void) = 0;
        
        virtual HRESULT __stdcall SetName( 
            /* [in] */ LPOLESTR szName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICreateTypeInfo2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            ICreateTypeInfo2  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            ICreateTypeInfo2  * This);
        
        unsigned long ( __stdcall  *Release )( 
            ICreateTypeInfo2  * This);
        
        HRESULT ( __stdcall  *SetGuid )( 
            ICreateTypeInfo2  * This,
            /* [in] */ REFGUID guid);
        
        HRESULT ( __stdcall  *SetTypeFlags )( 
            ICreateTypeInfo2  * This,
            /* [in] */ unsigned uTypeFlags);
        
        HRESULT ( __stdcall  *SetDocString )( 
            ICreateTypeInfo2  * This,
            /* [in] */ LPOLESTR pStrDoc);
        
        HRESULT ( __stdcall  *SetHelpContext )( 
            ICreateTypeInfo2  * This,
            /* [in] */ unsigned long dwHelpContext);
        
        HRESULT ( __stdcall  *SetVersion )( 
            ICreateTypeInfo2  * This,
            /* [in] */ WORD wMajorVerNum,
            /* [in] */ WORD wMinorVerNum);
        
        HRESULT ( __stdcall  *AddRefTypeInfo )( 
            ICreateTypeInfo2  * This,
            /* [in] */ ITypeInfo  *pTInfo,
            /* [in] */ HREFTYPE  *phRefType);
        
        HRESULT ( __stdcall  *AddFuncDesc )( 
            ICreateTypeInfo2  * This,
            /* [in] */ unsigned index,
            /* [in] */ FUNCDESC  *pFuncDesc);
        
        HRESULT ( __stdcall  *AddImplType )( 
            ICreateTypeInfo2  * This,
            /* [in] */ unsigned index,
            /* [in] */ HREFTYPE hRefType);
        
        HRESULT ( __stdcall  *SetImplTypeFlags )( 
            ICreateTypeInfo2  * This,
            /* [in] */ unsigned index,
            /* [in] */ int implTypeFlags);
        
        HRESULT ( __stdcall  *SetAlignment )( 
            ICreateTypeInfo2  * This,
            /* [in] */ WORD cbAlignment);
        
        HRESULT ( __stdcall  *SetSchema )( 
            ICreateTypeInfo2  * This,
            /* [in] */ LPOLESTR pStrSchema);
        
        HRESULT ( __stdcall  *AddVarDesc )( 
            ICreateTypeInfo2  * This,
            /* [in] */ unsigned index,
            /* [in] */ VARDESC  *pVarDesc);
        
        HRESULT ( __stdcall  *SetFuncAndParamNames )( 
            ICreateTypeInfo2  * This,
            /* [in] */ unsigned index,
            /* [in][size_is][in] */ LPOLESTR  *rgszNames,
            /* [in] */ unsigned cNames);
        
        HRESULT ( __stdcall  *SetVarName )( 
            ICreateTypeInfo2  * This,
            /* [in] */ unsigned index,
            /* [in] */ LPOLESTR szName);
        
        HRESULT ( __stdcall  *SetTypeDescAlias )( 
            ICreateTypeInfo2  * This,
            /* [in] */ TYPEDESC  *pTDescAlias);
        
        HRESULT ( __stdcall  *DefineFuncAsDllEntry )( 
            ICreateTypeInfo2  * This,
            /* [in] */ unsigned index,
            /* [in] */ LPOLESTR szDllName,
            /* [in] */ LPOLESTR szProcName);
        
        HRESULT ( __stdcall  *SetFuncDocString )( 
            ICreateTypeInfo2  * This,
            /* [in] */ unsigned index,
            /* [in] */ LPOLESTR szDocString);
        
        HRESULT ( __stdcall  *SetVarDocString )( 
            ICreateTypeInfo2  * This,
            /* [in] */ unsigned index,
            /* [in] */ LPOLESTR szDocString);
        
        HRESULT ( __stdcall  *SetFuncHelpContext )( 
            ICreateTypeInfo2  * This,
            /* [in] */ unsigned index,
            /* [in] */ unsigned long dwHelpContext);
        
        HRESULT ( __stdcall  *SetVarHelpContext )( 
            ICreateTypeInfo2  * This,
            /* [in] */ unsigned index,
            /* [in] */ unsigned long dwHelpContext);
        
        HRESULT ( __stdcall  *SetMops )( 
            ICreateTypeInfo2  * This,
            /* [in] */ unsigned index,
            /* [in] */ BSTR bstrMops);
        
        HRESULT ( __stdcall  *SetTypeIdldesc )( 
            ICreateTypeInfo2  * This,
            /* [in] */ IDLDESC  *pIdlDesc);
        
        HRESULT ( __stdcall  *LayOut )( 
            ICreateTypeInfo2  * This);
        
        HRESULT ( __stdcall  *DeleteFuncDesc )( 
            ICreateTypeInfo2  * This,
            /* [in] */ unsigned index);
        
        HRESULT ( __stdcall  *DeleteFuncDescByMemId )( 
            ICreateTypeInfo2  * This,
            /* [in] */ MEMBERID memid,
            /* [in] */ INVOKEKIND invKind);
        
        HRESULT ( __stdcall  *DeleteVarDesc )( 
            ICreateTypeInfo2  * This,
            /* [in] */ unsigned index);
        
        HRESULT ( __stdcall  *DeleteVarDescByMemId )( 
            ICreateTypeInfo2  * This,
            /* [in] */ MEMBERID memid);
        
        HRESULT ( __stdcall  *DeleteImplType )( 
            ICreateTypeInfo2  * This,
            /* [in] */ unsigned index);
        
        HRESULT ( __stdcall  *SetCustData )( 
            ICreateTypeInfo2  * This,
            /* [in] */ REFGUID guid,
            /* [in] */ VARIANT  *pVarVal);
        
        HRESULT ( __stdcall  *SetFuncCustData )( 
            ICreateTypeInfo2  * This,
            /* [in] */ unsigned index,
            /* [in] */ REFGUID guid,
            /* [in] */ VARIANT  *pVarVal);
        
        HRESULT ( __stdcall  *SetParamCustData )( 
            ICreateTypeInfo2  * This,
            /* [in] */ unsigned indexFunc,
            /* [in] */ unsigned indexParam,
            /* [in] */ REFGUID guid,
            /* [in] */ VARIANT  *pVarVal);
        
        HRESULT ( __stdcall  *SetVarCustData )( 
            ICreateTypeInfo2  * This,
            /* [in] */ unsigned index,
            /* [in] */ REFGUID guid,
            /* [in] */ VARIANT  *pVarVal);
        
        HRESULT ( __stdcall  *SetImplTypeCustData )( 
            ICreateTypeInfo2  * This,
            /* [in] */ unsigned index,
            /* [in] */ REFGUID guid,
            /* [in] */ VARIANT  *pVarVal);
        
        HRESULT ( __stdcall  *SetHelpStringContext )( 
            ICreateTypeInfo2  * This,
            /* [in] */ unsigned long dwHelpStringContext);
        
        HRESULT ( __stdcall  *SetFuncHelpStringContext )( 
            ICreateTypeInfo2  * This,
            /* [in] */ unsigned index,
            /* [in] */ unsigned long dwHelpStringContext);
        
        HRESULT ( __stdcall  *SetVarHelpStringContext )( 
            ICreateTypeInfo2  * This,
            /* [in] */ unsigned index,
            /* [in] */ unsigned long dwHelpStringContext);
        
        HRESULT ( __stdcall  *Invalidate )( 
            ICreateTypeInfo2  * This);
        
        HRESULT ( __stdcall  *SetName )( 
            ICreateTypeInfo2  * This,
            /* [in] */ LPOLESTR szName);
        
        END_INTERFACE
    } ICreateTypeInfo2Vtbl;

    interface ICreateTypeInfo2
    {
        CONST_VTBL struct ICreateTypeInfo2Vtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICreateTypeInfo2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICreateTypeInfo2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICreateTypeInfo2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICreateTypeInfo2_SetGuid(This,guid)	\
    (This)->lpVtbl -> SetGuid(This,guid)

#define ICreateTypeInfo2_SetTypeFlags(This,uTypeFlags)	\
    (This)->lpVtbl -> SetTypeFlags(This,uTypeFlags)

#define ICreateTypeInfo2_SetDocString(This,pStrDoc)	\
    (This)->lpVtbl -> SetDocString(This,pStrDoc)

#define ICreateTypeInfo2_SetHelpContext(This,dwHelpContext)	\
    (This)->lpVtbl -> SetHelpContext(This,dwHelpContext)

#define ICreateTypeInfo2_SetVersion(This,wMajorVerNum,wMinorVerNum)	\
    (This)->lpVtbl -> SetVersion(This,wMajorVerNum,wMinorVerNum)

#define ICreateTypeInfo2_AddRefTypeInfo(This,pTInfo,phRefType)	\
    (This)->lpVtbl -> AddRefTypeInfo(This,pTInfo,phRefType)

#define ICreateTypeInfo2_AddFuncDesc(This,index,pFuncDesc)	\
    (This)->lpVtbl -> AddFuncDesc(This,index,pFuncDesc)

#define ICreateTypeInfo2_AddImplType(This,index,hRefType)	\
    (This)->lpVtbl -> AddImplType(This,index,hRefType)

#define ICreateTypeInfo2_SetImplTypeFlags(This,index,implTypeFlags)	\
    (This)->lpVtbl -> SetImplTypeFlags(This,index,implTypeFlags)

#define ICreateTypeInfo2_SetAlignment(This,cbAlignment)	\
    (This)->lpVtbl -> SetAlignment(This,cbAlignment)

#define ICreateTypeInfo2_SetSchema(This,pStrSchema)	\
    (This)->lpVtbl -> SetSchema(This,pStrSchema)

#define ICreateTypeInfo2_AddVarDesc(This,index,pVarDesc)	\
    (This)->lpVtbl -> AddVarDesc(This,index,pVarDesc)

#define ICreateTypeInfo2_SetFuncAndParamNames(This,index,rgszNames,cNames)	\
    (This)->lpVtbl -> SetFuncAndParamNames(This,index,rgszNames,cNames)

#define ICreateTypeInfo2_SetVarName(This,index,szName)	\
    (This)->lpVtbl -> SetVarName(This,index,szName)

#define ICreateTypeInfo2_SetTypeDescAlias(This,pTDescAlias)	\
    (This)->lpVtbl -> SetTypeDescAlias(This,pTDescAlias)

#define ICreateTypeInfo2_DefineFuncAsDllEntry(This,index,szDllName,szProcName)	\
    (This)->lpVtbl -> DefineFuncAsDllEntry(This,index,szDllName,szProcName)

#define ICreateTypeInfo2_SetFuncDocString(This,index,szDocString)	\
    (This)->lpVtbl -> SetFuncDocString(This,index,szDocString)

#define ICreateTypeInfo2_SetVarDocString(This,index,szDocString)	\
    (This)->lpVtbl -> SetVarDocString(This,index,szDocString)

#define ICreateTypeInfo2_SetFuncHelpContext(This,index,dwHelpContext)	\
    (This)->lpVtbl -> SetFuncHelpContext(This,index,dwHelpContext)

#define ICreateTypeInfo2_SetVarHelpContext(This,index,dwHelpContext)	\
    (This)->lpVtbl -> SetVarHelpContext(This,index,dwHelpContext)

#define ICreateTypeInfo2_SetMops(This,index,bstrMops)	\
    (This)->lpVtbl -> SetMops(This,index,bstrMops)

#define ICreateTypeInfo2_SetTypeIdldesc(This,pIdlDesc)	\
    (This)->lpVtbl -> SetTypeIdldesc(This,pIdlDesc)

#define ICreateTypeInfo2_LayOut(This)	\
    (This)->lpVtbl -> LayOut(This)


#define ICreateTypeInfo2_DeleteFuncDesc(This,index)	\
    (This)->lpVtbl -> DeleteFuncDesc(This,index)

#define ICreateTypeInfo2_DeleteFuncDescByMemId(This,memid,invKind)	\
    (This)->lpVtbl -> DeleteFuncDescByMemId(This,memid,invKind)

#define ICreateTypeInfo2_DeleteVarDesc(This,index)	\
    (This)->lpVtbl -> DeleteVarDesc(This,index)

#define ICreateTypeInfo2_DeleteVarDescByMemId(This,memid)	\
    (This)->lpVtbl -> DeleteVarDescByMemId(This,memid)

#define ICreateTypeInfo2_DeleteImplType(This,index)	\
    (This)->lpVtbl -> DeleteImplType(This,index)

#define ICreateTypeInfo2_SetCustData(This,guid,pVarVal)	\
    (This)->lpVtbl -> SetCustData(This,guid,pVarVal)

#define ICreateTypeInfo2_SetFuncCustData(This,index,guid,pVarVal)	\
    (This)->lpVtbl -> SetFuncCustData(This,index,guid,pVarVal)

#define ICreateTypeInfo2_SetParamCustData(This,indexFunc,indexParam,guid,pVarVal)	\
    (This)->lpVtbl -> SetParamCustData(This,indexFunc,indexParam,guid,pVarVal)

#define ICreateTypeInfo2_SetVarCustData(This,index,guid,pVarVal)	\
    (This)->lpVtbl -> SetVarCustData(This,index,guid,pVarVal)

#define ICreateTypeInfo2_SetImplTypeCustData(This,index,guid,pVarVal)	\
    (This)->lpVtbl -> SetImplTypeCustData(This,index,guid,pVarVal)

#define ICreateTypeInfo2_SetHelpStringContext(This,dwHelpStringContext)	\
    (This)->lpVtbl -> SetHelpStringContext(This,dwHelpStringContext)

#define ICreateTypeInfo2_SetFuncHelpStringContext(This,index,dwHelpStringContext)	\
    (This)->lpVtbl -> SetFuncHelpStringContext(This,index,dwHelpStringContext)

#define ICreateTypeInfo2_SetVarHelpStringContext(This,index,dwHelpStringContext)	\
    (This)->lpVtbl -> SetVarHelpStringContext(This,index,dwHelpStringContext)

#define ICreateTypeInfo2_Invalidate(This)	\
    (This)->lpVtbl -> Invalidate(This)

#define ICreateTypeInfo2_SetName(This,szName)	\
    (This)->lpVtbl -> SetName(This,szName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall ICreateTypeInfo2_DeleteFuncDesc_Proxy( 
    ICreateTypeInfo2  * This,
    /* [in] */ unsigned index);


void __stdcall ICreateTypeInfo2_DeleteFuncDesc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeInfo2_DeleteFuncDescByMemId_Proxy( 
    ICreateTypeInfo2  * This,
    /* [in] */ MEMBERID memid,
    /* [in] */ INVOKEKIND invKind);


void __stdcall ICreateTypeInfo2_DeleteFuncDescByMemId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeInfo2_DeleteVarDesc_Proxy( 
    ICreateTypeInfo2  * This,
    /* [in] */ unsigned index);


void __stdcall ICreateTypeInfo2_DeleteVarDesc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeInfo2_DeleteVarDescByMemId_Proxy( 
    ICreateTypeInfo2  * This,
    /* [in] */ MEMBERID memid);


void __stdcall ICreateTypeInfo2_DeleteVarDescByMemId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeInfo2_DeleteImplType_Proxy( 
    ICreateTypeInfo2  * This,
    /* [in] */ unsigned index);


void __stdcall ICreateTypeInfo2_DeleteImplType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeInfo2_SetCustData_Proxy( 
    ICreateTypeInfo2  * This,
    /* [in] */ REFGUID guid,
    /* [in] */ VARIANT  *pVarVal);


void __stdcall ICreateTypeInfo2_SetCustData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeInfo2_SetFuncCustData_Proxy( 
    ICreateTypeInfo2  * This,
    /* [in] */ unsigned index,
    /* [in] */ REFGUID guid,
    /* [in] */ VARIANT  *pVarVal);


void __stdcall ICreateTypeInfo2_SetFuncCustData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeInfo2_SetParamCustData_Proxy( 
    ICreateTypeInfo2  * This,
    /* [in] */ unsigned indexFunc,
    /* [in] */ unsigned indexParam,
    /* [in] */ REFGUID guid,
    /* [in] */ VARIANT  *pVarVal);


void __stdcall ICreateTypeInfo2_SetParamCustData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeInfo2_SetVarCustData_Proxy( 
    ICreateTypeInfo2  * This,
    /* [in] */ unsigned index,
    /* [in] */ REFGUID guid,
    /* [in] */ VARIANT  *pVarVal);


void __stdcall ICreateTypeInfo2_SetVarCustData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeInfo2_SetImplTypeCustData_Proxy( 
    ICreateTypeInfo2  * This,
    /* [in] */ unsigned index,
    /* [in] */ REFGUID guid,
    /* [in] */ VARIANT  *pVarVal);


void __stdcall ICreateTypeInfo2_SetImplTypeCustData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeInfo2_SetHelpStringContext_Proxy( 
    ICreateTypeInfo2  * This,
    /* [in] */ unsigned long dwHelpStringContext);


void __stdcall ICreateTypeInfo2_SetHelpStringContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeInfo2_SetFuncHelpStringContext_Proxy( 
    ICreateTypeInfo2  * This,
    /* [in] */ unsigned index,
    /* [in] */ unsigned long dwHelpStringContext);


void __stdcall ICreateTypeInfo2_SetFuncHelpStringContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeInfo2_SetVarHelpStringContext_Proxy( 
    ICreateTypeInfo2  * This,
    /* [in] */ unsigned index,
    /* [in] */ unsigned long dwHelpStringContext);


void __stdcall ICreateTypeInfo2_SetVarHelpStringContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeInfo2_Invalidate_Proxy( 
    ICreateTypeInfo2  * This);


void __stdcall ICreateTypeInfo2_Invalidate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeInfo2_SetName_Proxy( 
    ICreateTypeInfo2  * This,
    /* [in] */ LPOLESTR szName);


void __stdcall ICreateTypeInfo2_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __ICreateTypeInfo2_INTERFACE_DEFINED__ */


#ifndef __ICreateTypeLib_INTERFACE_DEFINED__
#define __ICreateTypeLib_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ICreateTypeLib
 * at Sat Jul 13 21:56:52 1996
 * using MIDL 3.00.39
 ****************************************/
/* [local][unique][uuid][object] */ 


typedef /* [unique] */ ICreateTypeLib  *LPCREATETYPELIB;


EXTERN_C const IID IID_ICreateTypeLib;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ICreateTypeLib : public IUnknown
    {
    public:
        virtual HRESULT __stdcall CreateTypeInfo( 
            /* [in] */ LPOLESTR szName,
            /* [in] */ TYPEKIND tkind,
            /* [out] */ ICreateTypeInfo  * *ppCTInfo) = 0;
        
        virtual HRESULT __stdcall SetName( 
            /* [in] */ LPOLESTR szName) = 0;
        
        virtual HRESULT __stdcall SetVersion( 
            /* [in] */ WORD wMajorVerNum,
            /* [in] */ WORD wMinorVerNum) = 0;
        
        virtual HRESULT __stdcall SetGuid( 
            /* [in] */ REFGUID guid) = 0;
        
        virtual HRESULT __stdcall SetDocString( 
            /* [in] */ LPOLESTR szDoc) = 0;
        
        virtual HRESULT __stdcall SetHelpFileName( 
            /* [in] */ LPOLESTR szHelpFileName) = 0;
        
        virtual HRESULT __stdcall SetHelpContext( 
            /* [in] */ unsigned long dwHelpContext) = 0;
        
        virtual HRESULT __stdcall SetLcid( 
            /* [in] */ LCID lcid) = 0;
        
        virtual HRESULT __stdcall SetLibFlags( 
            /* [in] */ unsigned uLibFlags) = 0;
        
        virtual HRESULT __stdcall SaveAllChanges( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICreateTypeLibVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            ICreateTypeLib  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            ICreateTypeLib  * This);
        
        unsigned long ( __stdcall  *Release )( 
            ICreateTypeLib  * This);
        
        HRESULT ( __stdcall  *CreateTypeInfo )( 
            ICreateTypeLib  * This,
            /* [in] */ LPOLESTR szName,
            /* [in] */ TYPEKIND tkind,
            /* [out] */ ICreateTypeInfo  * *ppCTInfo);
        
        HRESULT ( __stdcall  *SetName )( 
            ICreateTypeLib  * This,
            /* [in] */ LPOLESTR szName);
        
        HRESULT ( __stdcall  *SetVersion )( 
            ICreateTypeLib  * This,
            /* [in] */ WORD wMajorVerNum,
            /* [in] */ WORD wMinorVerNum);
        
        HRESULT ( __stdcall  *SetGuid )( 
            ICreateTypeLib  * This,
            /* [in] */ REFGUID guid);
        
        HRESULT ( __stdcall  *SetDocString )( 
            ICreateTypeLib  * This,
            /* [in] */ LPOLESTR szDoc);
        
        HRESULT ( __stdcall  *SetHelpFileName )( 
            ICreateTypeLib  * This,
            /* [in] */ LPOLESTR szHelpFileName);
        
        HRESULT ( __stdcall  *SetHelpContext )( 
            ICreateTypeLib  * This,
            /* [in] */ unsigned long dwHelpContext);
        
        HRESULT ( __stdcall  *SetLcid )( 
            ICreateTypeLib  * This,
            /* [in] */ LCID lcid);
        
        HRESULT ( __stdcall  *SetLibFlags )( 
            ICreateTypeLib  * This,
            /* [in] */ unsigned uLibFlags);
        
        HRESULT ( __stdcall  *SaveAllChanges )( 
            ICreateTypeLib  * This);
        
        END_INTERFACE
    } ICreateTypeLibVtbl;

    interface ICreateTypeLib
    {
        CONST_VTBL struct ICreateTypeLibVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICreateTypeLib_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICreateTypeLib_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICreateTypeLib_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICreateTypeLib_CreateTypeInfo(This,szName,tkind,ppCTInfo)	\
    (This)->lpVtbl -> CreateTypeInfo(This,szName,tkind,ppCTInfo)

#define ICreateTypeLib_SetName(This,szName)	\
    (This)->lpVtbl -> SetName(This,szName)

#define ICreateTypeLib_SetVersion(This,wMajorVerNum,wMinorVerNum)	\
    (This)->lpVtbl -> SetVersion(This,wMajorVerNum,wMinorVerNum)

#define ICreateTypeLib_SetGuid(This,guid)	\
    (This)->lpVtbl -> SetGuid(This,guid)

#define ICreateTypeLib_SetDocString(This,szDoc)	\
    (This)->lpVtbl -> SetDocString(This,szDoc)

#define ICreateTypeLib_SetHelpFileName(This,szHelpFileName)	\
    (This)->lpVtbl -> SetHelpFileName(This,szHelpFileName)

#define ICreateTypeLib_SetHelpContext(This,dwHelpContext)	\
    (This)->lpVtbl -> SetHelpContext(This,dwHelpContext)

#define ICreateTypeLib_SetLcid(This,lcid)	\
    (This)->lpVtbl -> SetLcid(This,lcid)

#define ICreateTypeLib_SetLibFlags(This,uLibFlags)	\
    (This)->lpVtbl -> SetLibFlags(This,uLibFlags)

#define ICreateTypeLib_SaveAllChanges(This)	\
    (This)->lpVtbl -> SaveAllChanges(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall ICreateTypeLib_CreateTypeInfo_Proxy( 
    ICreateTypeLib  * This,
    /* [in] */ LPOLESTR szName,
    /* [in] */ TYPEKIND tkind,
    /* [out] */ ICreateTypeInfo  * *ppCTInfo);


void __stdcall ICreateTypeLib_CreateTypeInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeLib_SetName_Proxy( 
    ICreateTypeLib  * This,
    /* [in] */ LPOLESTR szName);


void __stdcall ICreateTypeLib_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeLib_SetVersion_Proxy( 
    ICreateTypeLib  * This,
    /* [in] */ WORD wMajorVerNum,
    /* [in] */ WORD wMinorVerNum);


void __stdcall ICreateTypeLib_SetVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeLib_SetGuid_Proxy( 
    ICreateTypeLib  * This,
    /* [in] */ REFGUID guid);


void __stdcall ICreateTypeLib_SetGuid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeLib_SetDocString_Proxy( 
    ICreateTypeLib  * This,
    /* [in] */ LPOLESTR szDoc);


void __stdcall ICreateTypeLib_SetDocString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeLib_SetHelpFileName_Proxy( 
    ICreateTypeLib  * This,
    /* [in] */ LPOLESTR szHelpFileName);


void __stdcall ICreateTypeLib_SetHelpFileName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeLib_SetHelpContext_Proxy( 
    ICreateTypeLib  * This,
    /* [in] */ unsigned long dwHelpContext);


void __stdcall ICreateTypeLib_SetHelpContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeLib_SetLcid_Proxy( 
    ICreateTypeLib  * This,
    /* [in] */ LCID lcid);


void __stdcall ICreateTypeLib_SetLcid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeLib_SetLibFlags_Proxy( 
    ICreateTypeLib  * This,
    /* [in] */ unsigned uLibFlags);


void __stdcall ICreateTypeLib_SetLibFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeLib_SaveAllChanges_Proxy( 
    ICreateTypeLib  * This);


void __stdcall ICreateTypeLib_SaveAllChanges_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __ICreateTypeLib_INTERFACE_DEFINED__ */


#ifndef __ICreateTypeLib2_INTERFACE_DEFINED__
#define __ICreateTypeLib2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ICreateTypeLib2
 * at Sat Jul 13 21:56:52 1996
 * using MIDL 3.00.39
 ****************************************/
/* [local][unique][uuid][object] */ 


typedef /* [unique] */ ICreateTypeLib2  *LPCREATETYPELIB2;


EXTERN_C const IID IID_ICreateTypeLib2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ICreateTypeLib2 : public ICreateTypeLib
    {
    public:
        virtual HRESULT __stdcall DeleteTypeInfo( 
            /* [in] */ LPOLESTR szName) = 0;
        
        virtual HRESULT __stdcall SetCustData( 
            /* [in] */ REFGUID guid,
            /* [in] */ VARIANT  *pVarVal) = 0;
        
        virtual HRESULT __stdcall SetHelpStringContext( 
            /* [in] */ unsigned long dwHelpStringContext) = 0;
        
        virtual HRESULT __stdcall SetHelpStringDll( 
            /* [in] */ LPOLESTR szFileName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICreateTypeLib2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            ICreateTypeLib2  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            ICreateTypeLib2  * This);
        
        unsigned long ( __stdcall  *Release )( 
            ICreateTypeLib2  * This);
        
        HRESULT ( __stdcall  *CreateTypeInfo )( 
            ICreateTypeLib2  * This,
            /* [in] */ LPOLESTR szName,
            /* [in] */ TYPEKIND tkind,
            /* [out] */ ICreateTypeInfo  * *ppCTInfo);
        
        HRESULT ( __stdcall  *SetName )( 
            ICreateTypeLib2  * This,
            /* [in] */ LPOLESTR szName);
        
        HRESULT ( __stdcall  *SetVersion )( 
            ICreateTypeLib2  * This,
            /* [in] */ WORD wMajorVerNum,
            /* [in] */ WORD wMinorVerNum);
        
        HRESULT ( __stdcall  *SetGuid )( 
            ICreateTypeLib2  * This,
            /* [in] */ REFGUID guid);
        
        HRESULT ( __stdcall  *SetDocString )( 
            ICreateTypeLib2  * This,
            /* [in] */ LPOLESTR szDoc);
        
        HRESULT ( __stdcall  *SetHelpFileName )( 
            ICreateTypeLib2  * This,
            /* [in] */ LPOLESTR szHelpFileName);
        
        HRESULT ( __stdcall  *SetHelpContext )( 
            ICreateTypeLib2  * This,
            /* [in] */ unsigned long dwHelpContext);
        
        HRESULT ( __stdcall  *SetLcid )( 
            ICreateTypeLib2  * This,
            /* [in] */ LCID lcid);
        
        HRESULT ( __stdcall  *SetLibFlags )( 
            ICreateTypeLib2  * This,
            /* [in] */ unsigned uLibFlags);
        
        HRESULT ( __stdcall  *SaveAllChanges )( 
            ICreateTypeLib2  * This);
        
        HRESULT ( __stdcall  *DeleteTypeInfo )( 
            ICreateTypeLib2  * This,
            /* [in] */ LPOLESTR szName);
        
        HRESULT ( __stdcall  *SetCustData )( 
            ICreateTypeLib2  * This,
            /* [in] */ REFGUID guid,
            /* [in] */ VARIANT  *pVarVal);
        
        HRESULT ( __stdcall  *SetHelpStringContext )( 
            ICreateTypeLib2  * This,
            /* [in] */ unsigned long dwHelpStringContext);
        
        HRESULT ( __stdcall  *SetHelpStringDll )( 
            ICreateTypeLib2  * This,
            /* [in] */ LPOLESTR szFileName);
        
        END_INTERFACE
    } ICreateTypeLib2Vtbl;

    interface ICreateTypeLib2
    {
        CONST_VTBL struct ICreateTypeLib2Vtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICreateTypeLib2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICreateTypeLib2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICreateTypeLib2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICreateTypeLib2_CreateTypeInfo(This,szName,tkind,ppCTInfo)	\
    (This)->lpVtbl -> CreateTypeInfo(This,szName,tkind,ppCTInfo)

#define ICreateTypeLib2_SetName(This,szName)	\
    (This)->lpVtbl -> SetName(This,szName)

#define ICreateTypeLib2_SetVersion(This,wMajorVerNum,wMinorVerNum)	\
    (This)->lpVtbl -> SetVersion(This,wMajorVerNum,wMinorVerNum)

#define ICreateTypeLib2_SetGuid(This,guid)	\
    (This)->lpVtbl -> SetGuid(This,guid)

#define ICreateTypeLib2_SetDocString(This,szDoc)	\
    (This)->lpVtbl -> SetDocString(This,szDoc)

#define ICreateTypeLib2_SetHelpFileName(This,szHelpFileName)	\
    (This)->lpVtbl -> SetHelpFileName(This,szHelpFileName)

#define ICreateTypeLib2_SetHelpContext(This,dwHelpContext)	\
    (This)->lpVtbl -> SetHelpContext(This,dwHelpContext)

#define ICreateTypeLib2_SetLcid(This,lcid)	\
    (This)->lpVtbl -> SetLcid(This,lcid)

#define ICreateTypeLib2_SetLibFlags(This,uLibFlags)	\
    (This)->lpVtbl -> SetLibFlags(This,uLibFlags)

#define ICreateTypeLib2_SaveAllChanges(This)	\
    (This)->lpVtbl -> SaveAllChanges(This)


#define ICreateTypeLib2_DeleteTypeInfo(This,szName)	\
    (This)->lpVtbl -> DeleteTypeInfo(This,szName)

#define ICreateTypeLib2_SetCustData(This,guid,pVarVal)	\
    (This)->lpVtbl -> SetCustData(This,guid,pVarVal)

#define ICreateTypeLib2_SetHelpStringContext(This,dwHelpStringContext)	\
    (This)->lpVtbl -> SetHelpStringContext(This,dwHelpStringContext)

#define ICreateTypeLib2_SetHelpStringDll(This,szFileName)	\
    (This)->lpVtbl -> SetHelpStringDll(This,szFileName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall ICreateTypeLib2_DeleteTypeInfo_Proxy( 
    ICreateTypeLib2  * This,
    /* [in] */ LPOLESTR szName);


void __stdcall ICreateTypeLib2_DeleteTypeInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeLib2_SetCustData_Proxy( 
    ICreateTypeLib2  * This,
    /* [in] */ REFGUID guid,
    /* [in] */ VARIANT  *pVarVal);


void __stdcall ICreateTypeLib2_SetCustData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeLib2_SetHelpStringContext_Proxy( 
    ICreateTypeLib2  * This,
    /* [in] */ unsigned long dwHelpStringContext);


void __stdcall ICreateTypeLib2_SetHelpStringContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateTypeLib2_SetHelpStringDll_Proxy( 
    ICreateTypeLib2  * This,
    /* [in] */ LPOLESTR szFileName);


void __stdcall ICreateTypeLib2_SetHelpStringDll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __ICreateTypeLib2_INTERFACE_DEFINED__ */


#ifndef __IDispatch_INTERFACE_DEFINED__
#define __IDispatch_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IDispatch
 * at Sat Jul 13 21:56:52 1996
 * using MIDL 3.00.39
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IDispatch  *LPDISPATCH;

/* DISPID reserved to indicate an "unknown" name */
/* only reserved for data members (properties); reused as a method dispid below */
#define	DISPID_UNKNOWN	( -1 )

/* DISPID reserved for the "value" property */
#define	DISPID_VALUE	( 0 )

/* The following DISPID is reserved to indicate the param
 * that is the right-hand-side (or "put" value) of a PropertyPut
 */
#define	DISPID_PROPERTYPUT	( -3 )

/* DISPID reserved for the standard "NewEnum" method */
#define	DISPID_NEWENUM	( -4 )

/* DISPID reserved for the standard "Evaluate" method */
#define	DISPID_EVALUATE	( -5 )

#define	DISPID_CONSTRUCTOR	( -6 )

#define	DISPID_DESTRUCTOR	( -7 )

#define	DISPID_COLLECT	( -8 )

/* The range -500 through -999 is reserved for Controls */
/* The range 0x80010000 through 0x8001FFFF is reserved for Controls */
/* The range -5000 through -5499 is reserved for ActiveX Accessibility */
/* The remainder of the negative DISPIDs are reserved for future use */

EXTERN_C const IID IID_IDispatch;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IDispatch : public IUnknown
    {
    public:
        virtual HRESULT __stdcall GetTypeInfoCount( 
            /* [out] */ unsigned  *pctinfo) = 0;
        
        virtual HRESULT __stdcall GetTypeInfo( 
            /* [in] */ unsigned iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo  * *ppTInfo) = 0;
        
        virtual HRESULT __stdcall GetIDsOfNames( 
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR  *rgszNames,
            /* [in] */ unsigned cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID  *rgDispId) = 0;
        
        virtual /* [local] */ HRESULT __stdcall Invoke( 
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS  *pDispParams,
            /* [out] */ VARIANT  *pVarResult,
            /* [out] */ EXCEPINFO  *pExcepInfo,
            /* [out] */ unsigned  *puArgErr) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDispatchVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IDispatch  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IDispatch  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IDispatch  * This);
        
        HRESULT ( __stdcall  *GetTypeInfoCount )( 
            IDispatch  * This,
            /* [out] */ unsigned  *pctinfo);
        
        HRESULT ( __stdcall  *GetTypeInfo )( 
            IDispatch  * This,
            /* [in] */ unsigned iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo  * *ppTInfo);
        
        HRESULT ( __stdcall  *GetIDsOfNames )( 
            IDispatch  * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR  *rgszNames,
            /* [in] */ unsigned cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID  *rgDispId);
        
        /* [local] */ HRESULT ( __stdcall  *Invoke )( 
            IDispatch  * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS  *pDispParams,
            /* [out] */ VARIANT  *pVarResult,
            /* [out] */ EXCEPINFO  *pExcepInfo,
            /* [out] */ unsigned  *puArgErr);
        
        END_INTERFACE
    } IDispatchVtbl;

    interface IDispatch
    {
        CONST_VTBL struct IDispatchVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDispatch_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDispatch_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDispatch_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDispatch_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDispatch_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDispatch_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDispatch_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IDispatch_GetTypeInfoCount_Proxy( 
    IDispatch  * This,
    /* [out] */ unsigned  *pctinfo);


void __stdcall IDispatch_GetTypeInfoCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IDispatch_GetTypeInfo_Proxy( 
    IDispatch  * This,
    /* [in] */ unsigned iTInfo,
    /* [in] */ LCID lcid,
    /* [out] */ ITypeInfo  * *ppTInfo);


void __stdcall IDispatch_GetTypeInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IDispatch_GetIDsOfNames_Proxy( 
    IDispatch  * This,
    /* [in] */ REFIID riid,
    /* [size_is][in] */ LPOLESTR  *rgszNames,
    /* [in] */ unsigned cNames,
    /* [in] */ LCID lcid,
    /* [size_is][out] */ DISPID  *rgDispId);


void __stdcall IDispatch_GetIDsOfNames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall IDispatch_RemoteInvoke_Proxy( 
    IDispatch  * This,
    /* [in] */ DISPID dispIdMember,
    /* [in] */ REFIID riid,
    /* [in] */ LCID lcid,
    /* [in] */ unsigned long dwFlags,
    /* [in] */ DISPPARAMS  *pDispParams,
    /* [out] */ VARIANT  *pVarResult,
    /* [out] */ EXCEPINFO  *pExcepInfo,
    /* [out] */ unsigned  *pArgErr,
    /* [in] */ unsigned cVarRef,
    /* [size_is][in] */ unsigned  *rgVarRefIdx,
    /* [size_is][out][in] */ VARIANTARG  *rgVarRef);


void __stdcall IDispatch_RemoteInvoke_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IDispatch_INTERFACE_DEFINED__ */


#ifndef __IEnumVARIANT_INTERFACE_DEFINED__
#define __IEnumVARIANT_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IEnumVARIANT
 * at Sat Jul 13 21:56:52 1996
 * using MIDL 3.00.39
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IEnumVARIANT  *LPENUMVARIANT;


EXTERN_C const IID IID_IEnumVARIANT;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IEnumVARIANT : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT __stdcall Next( 
            /* [in] */ unsigned long celt,
            /* [length_is][size_is][out] */ VARIANT  *rgVar,
            /* [out] */ unsigned long  *pCeltFetched) = 0;
        
        virtual HRESULT __stdcall Skip( 
            /* [in] */ unsigned long celt) = 0;
        
        virtual HRESULT __stdcall Reset( void) = 0;
        
        virtual HRESULT __stdcall Clone( 
            /* [out] */ IEnumVARIANT  * *ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumVARIANTVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IEnumVARIANT  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IEnumVARIANT  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IEnumVARIANT  * This);
        
        /* [local] */ HRESULT ( __stdcall  *Next )( 
            IEnumVARIANT  * This,
            /* [in] */ unsigned long celt,
            /* [length_is][size_is][out] */ VARIANT  *rgVar,
            /* [out] */ unsigned long  *pCeltFetched);
        
        HRESULT ( __stdcall  *Skip )( 
            IEnumVARIANT  * This,
            /* [in] */ unsigned long celt);
        
        HRESULT ( __stdcall  *Reset )( 
            IEnumVARIANT  * This);
        
        HRESULT ( __stdcall  *Clone )( 
            IEnumVARIANT  * This,
            /* [out] */ IEnumVARIANT  * *ppEnum);
        
        END_INTERFACE
    } IEnumVARIANTVtbl;

    interface IEnumVARIANT
    {
        CONST_VTBL struct IEnumVARIANTVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumVARIANT_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumVARIANT_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumVARIANT_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumVARIANT_Next(This,celt,rgVar,pCeltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgVar,pCeltFetched)

#define IEnumVARIANT_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumVARIANT_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumVARIANT_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT __stdcall IEnumVARIANT_RemoteNext_Proxy( 
    IEnumVARIANT  * This,
    /* [in] */ unsigned long celt,
    /* [length_is][size_is][out] */ VARIANT  *rgVar,
    /* [out] */ unsigned long  *pCeltFetched);


void __stdcall IEnumVARIANT_RemoteNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumVARIANT_Skip_Proxy( 
    IEnumVARIANT  * This,
    /* [in] */ unsigned long celt);


void __stdcall IEnumVARIANT_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumVARIANT_Reset_Proxy( 
    IEnumVARIANT  * This);


void __stdcall IEnumVARIANT_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumVARIANT_Clone_Proxy( 
    IEnumVARIANT  * This,
    /* [out] */ IEnumVARIANT  * *ppEnum);


void __stdcall IEnumVARIANT_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IEnumVARIANT_INTERFACE_DEFINED__ */


#ifndef __ITypeComp_INTERFACE_DEFINED__
#define __ITypeComp_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITypeComp
 * at Sat Jul 13 21:56:52 1996
 * using MIDL 3.00.39
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ ITypeComp  *LPTYPECOMP;

typedef /* [v1_enum] */ 
enum tagDESCKIND
    {	DESCKIND_NONE	= 0,
	DESCKIND_FUNCDESC	= DESCKIND_NONE + 1,
	DESCKIND_VARDESC	= DESCKIND_FUNCDESC + 1,
	DESCKIND_TYPECOMP	= DESCKIND_VARDESC + 1,
	DESCKIND_IMPLICITAPPOBJ	= DESCKIND_TYPECOMP + 1,
	DESCKIND_MAX	= DESCKIND_IMPLICITAPPOBJ + 1
    }	DESCKIND;

typedef union tagBINDPTR
    {
    FUNCDESC  *lpfuncdesc;
    VARDESC  *lpvardesc;
    ITypeComp  *lptcomp;
    }	BINDPTR;

typedef union tagBINDPTR  *LPBINDPTR;


EXTERN_C const IID IID_ITypeComp;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ITypeComp : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT __stdcall Bind( 
            /* [in] */ LPOLESTR szName,
            /* [in] */ unsigned long lHashVal,
            /* [in] */ WORD wFlags,
            /* [out] */ ITypeInfo  * *ppTInfo,
            /* [out] */ DESCKIND  *pDescKind,
            /* [out] */ BINDPTR  *pBindPtr) = 0;
        
        virtual /* [local] */ HRESULT __stdcall BindType( 
            /* [in] */ LPOLESTR szName,
            /* [in] */ unsigned long lHashVal,
            /* [out] */ ITypeInfo  * *ppTInfo,
            /* [out] */ ITypeComp  * *ppTComp) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITypeCompVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            ITypeComp  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            ITypeComp  * This);
        
        unsigned long ( __stdcall  *Release )( 
            ITypeComp  * This);
        
        /* [local] */ HRESULT ( __stdcall  *Bind )( 
            ITypeComp  * This,
            /* [in] */ LPOLESTR szName,
            /* [in] */ unsigned long lHashVal,
            /* [in] */ WORD wFlags,
            /* [out] */ ITypeInfo  * *ppTInfo,
            /* [out] */ DESCKIND  *pDescKind,
            /* [out] */ BINDPTR  *pBindPtr);
        
        /* [local] */ HRESULT ( __stdcall  *BindType )( 
            ITypeComp  * This,
            /* [in] */ LPOLESTR szName,
            /* [in] */ unsigned long lHashVal,
            /* [out] */ ITypeInfo  * *ppTInfo,
            /* [out] */ ITypeComp  * *ppTComp);
        
        END_INTERFACE
    } ITypeCompVtbl;

    interface ITypeComp
    {
        CONST_VTBL struct ITypeCompVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITypeComp_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITypeComp_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITypeComp_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITypeComp_Bind(This,szName,lHashVal,wFlags,ppTInfo,pDescKind,pBindPtr)	\
    (This)->lpVtbl -> Bind(This,szName,lHashVal,wFlags,ppTInfo,pDescKind,pBindPtr)

#define ITypeComp_BindType(This,szName,lHashVal,ppTInfo,ppTComp)	\
    (This)->lpVtbl -> BindType(This,szName,lHashVal,ppTInfo,ppTComp)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT __stdcall ITypeComp_RemoteBind_Proxy( 
    ITypeComp  * This,
    /* [in] */ LPOLESTR szName,
    /* [in] */ unsigned long lHashVal,
    /* [in] */ WORD wFlags,
    /* [out] */ ITypeInfo  * *ppTInfo,
    /* [out] */ DESCKIND  *pDescKind,
    /* [out] */ LPFUNCDESC  *ppFuncDesc,
    /* [out] */ LPVARDESC  *ppVarDesc,
    /* [out] */ ITypeComp  * *ppTypeComp,
    /* [out] */ CLEANLOCALSTORAGE  *pDummy);


void __stdcall ITypeComp_RemoteBind_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall ITypeComp_RemoteBindType_Proxy( 
    ITypeComp  * This,
    /* [in] */ LPOLESTR szName,
    /* [in] */ unsigned long lHashVal,
    /* [out] */ ITypeInfo  * *ppTInfo);


void __stdcall ITypeComp_RemoteBindType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __ITypeComp_INTERFACE_DEFINED__ */


#ifndef __ITypeInfo_INTERFACE_DEFINED__
#define __ITypeInfo_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITypeInfo
 * at Sat Jul 13 21:56:52 1996
 * using MIDL 3.00.39
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ ITypeInfo  *LPTYPEINFO;


EXTERN_C const IID IID_ITypeInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ITypeInfo : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT __stdcall GetTypeAttr( 
            /* [out] */ TYPEATTR  * *ppTypeAttr) = 0;
        
        virtual HRESULT __stdcall GetTypeComp( 
            /* [out] */ ITypeComp  * *ppTComp) = 0;
        
        virtual /* [local] */ HRESULT __stdcall GetFuncDesc( 
            /* [in] */ unsigned index,
            /* [out] */ FUNCDESC  * *ppFuncDesc) = 0;
        
        virtual /* [local] */ HRESULT __stdcall GetVarDesc( 
            /* [in] */ unsigned index,
            /* [out] */ VARDESC  * *ppVarDesc) = 0;
        
        virtual /* [local] */ HRESULT __stdcall GetNames( 
            /* [in] */ MEMBERID memid,
            /* [length_is][size_is][out] */ BSTR  *rgBstrNames,
            /* [in] */ unsigned cMaxNames,
            /* [out] */ unsigned  *pcNames) = 0;
        
        virtual HRESULT __stdcall GetRefTypeOfImplType( 
            /* [in] */ unsigned index,
            /* [out] */ HREFTYPE  *pRefType) = 0;
        
        virtual HRESULT __stdcall GetImplTypeFlags( 
            /* [in] */ unsigned index,
            /* [out] */ int  *pImplTypeFlags) = 0;
        
        virtual HRESULT __stdcall GetIDsOfNames( 
            /* [size_is][in] */ LPOLESTR  *rgszNames,
            /* [in] */ unsigned cNames,
            /* [size_is][out] */ MEMBERID  *pMemId) = 0;
        
        virtual /* [local] */ HRESULT __stdcall Invoke( 
            /* [in] */ void* pvInstance,
            /* [in] */ MEMBERID memid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS  *pDispParams,
            /* [out] */ VARIANT  *pVarResult,
            /* [out] */ EXCEPINFO  *pExcepInfo,
            /* [out] */ unsigned  *puArgErr) = 0;
        
        virtual /* [local] */ HRESULT __stdcall GetDocumentation( 
            /* [in] */ MEMBERID memid,
            /* [out] */ BSTR  *pBstrName,
            /* [out] */ BSTR  *pBstrDocString,
            /* [out] */ unsigned long  *pdwHelpContext,
            /* [out] */ BSTR  *pBstrHelpFile) = 0;
        
        virtual /* [local] */ HRESULT __stdcall GetDllEntry( 
            /* [in] */ MEMBERID memid,
            /* [in] */ INVOKEKIND invKind,
            /* [out] */ BSTR  *pBstrDllName,
            /* [out] */ BSTR  *pBstrName,
            /* [out] */ WORD  *pwOrdinal) = 0;
        
        virtual HRESULT __stdcall GetRefTypeInfo( 
            /* [in] */ HREFTYPE hRefType,
            /* [out] */ ITypeInfo  * *ppTInfo) = 0;
        
        virtual /* [local] */ HRESULT __stdcall AddressOfMember( 
            /* [in] */ MEMBERID memid,
            /* [in] */ INVOKEKIND invKind,
            /* [out] */ void*  *ppv) = 0;
        
        virtual /* [local] */ HRESULT __stdcall CreateInstance( 
            /* [in] */ IUnknown  *pUnkOuter,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void*  *ppvObj) = 0;
        
        virtual HRESULT __stdcall GetMops( 
            /* [in] */ MEMBERID memid,
            /* [out] */ BSTR  *pBstrMops) = 0;
        
        virtual /* [local] */ HRESULT __stdcall GetContainingTypeLib( 
            /* [out] */ ITypeLib  * *ppTLib,
            /* [out] */ unsigned  *pIndex) = 0;
        
        virtual /* [local] */ void __stdcall ReleaseTypeAttr( 
            /* [in] */ TYPEATTR  *pTypeAttr) = 0;
        
        virtual /* [local] */ void __stdcall ReleaseFuncDesc( 
            /* [in] */ FUNCDESC  *pFuncDesc) = 0;
        
        virtual /* [local] */ void __stdcall ReleaseVarDesc( 
            /* [in] */ VARDESC  *pVarDesc) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITypeInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            ITypeInfo  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            ITypeInfo  * This);
        
        unsigned long ( __stdcall  *Release )( 
            ITypeInfo  * This);
        
        /* [local] */ HRESULT ( __stdcall  *GetTypeAttr )( 
            ITypeInfo  * This,
            /* [out] */ TYPEATTR  * *ppTypeAttr);
        
        HRESULT ( __stdcall  *GetTypeComp )( 
            ITypeInfo  * This,
            /* [out] */ ITypeComp  * *ppTComp);
        
        /* [local] */ HRESULT ( __stdcall  *GetFuncDesc )( 
            ITypeInfo  * This,
            /* [in] */ unsigned index,
            /* [out] */ FUNCDESC  * *ppFuncDesc);
        
        /* [local] */ HRESULT ( __stdcall  *GetVarDesc )( 
            ITypeInfo  * This,
            /* [in] */ unsigned index,
            /* [out] */ VARDESC  * *ppVarDesc);
        
        /* [local] */ HRESULT ( __stdcall  *GetNames )( 
            ITypeInfo  * This,
            /* [in] */ MEMBERID memid,
            /* [length_is][size_is][out] */ BSTR  *rgBstrNames,
            /* [in] */ unsigned cMaxNames,
            /* [out] */ unsigned  *pcNames);
        
        HRESULT ( __stdcall  *GetRefTypeOfImplType )( 
            ITypeInfo  * This,
            /* [in] */ unsigned index,
            /* [out] */ HREFTYPE  *pRefType);
        
        HRESULT ( __stdcall  *GetImplTypeFlags )( 
            ITypeInfo  * This,
            /* [in] */ unsigned index,
            /* [out] */ int  *pImplTypeFlags);
        
        HRESULT ( __stdcall  *GetIDsOfNames )( 
            ITypeInfo  * This,
            /* [size_is][in] */ LPOLESTR  *rgszNames,
            /* [in] */ unsigned cNames,
            /* [size_is][out] */ MEMBERID  *pMemId);
        
        /* [local] */ HRESULT ( __stdcall  *Invoke )( 
            ITypeInfo  * This,
            /* [in] */ void* pvInstance,
            /* [in] */ MEMBERID memid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS  *pDispParams,
            /* [out] */ VARIANT  *pVarResult,
            /* [out] */ EXCEPINFO  *pExcepInfo,
            /* [out] */ unsigned  *puArgErr);
        
        /* [local] */ HRESULT ( __stdcall  *GetDocumentation )( 
            ITypeInfo  * This,
            /* [in] */ MEMBERID memid,
            /* [out] */ BSTR  *pBstrName,
            /* [out] */ BSTR  *pBstrDocString,
            /* [out] */ unsigned long  *pdwHelpContext,
            /* [out] */ BSTR  *pBstrHelpFile);
        
        /* [local] */ HRESULT ( __stdcall  *GetDllEntry )( 
            ITypeInfo  * This,
            /* [in] */ MEMBERID memid,
            /* [in] */ INVOKEKIND invKind,
            /* [out] */ BSTR  *pBstrDllName,
            /* [out] */ BSTR  *pBstrName,
            /* [out] */ WORD  *pwOrdinal);
        
        HRESULT ( __stdcall  *GetRefTypeInfo )( 
            ITypeInfo  * This,
            /* [in] */ HREFTYPE hRefType,
            /* [out] */ ITypeInfo  * *ppTInfo);
        
        /* [local] */ HRESULT ( __stdcall  *AddressOfMember )( 
            ITypeInfo  * This,
            /* [in] */ MEMBERID memid,
            /* [in] */ INVOKEKIND invKind,
            /* [out] */ void*  *ppv);
        
        /* [local] */ HRESULT ( __stdcall  *CreateInstance )( 
            ITypeInfo  * This,
            /* [in] */ IUnknown  *pUnkOuter,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void*  *ppvObj);
        
        HRESULT ( __stdcall  *GetMops )( 
            ITypeInfo  * This,
            /* [in] */ MEMBERID memid,
            /* [out] */ BSTR  *pBstrMops);
        
        /* [local] */ HRESULT ( __stdcall  *GetContainingTypeLib )( 
            ITypeInfo  * This,
            /* [out] */ ITypeLib  * *ppTLib,
            /* [out] */ unsigned  *pIndex);
        
        /* [local] */ void ( __stdcall  *ReleaseTypeAttr )( 
            ITypeInfo  * This,
            /* [in] */ TYPEATTR  *pTypeAttr);
        
        /* [local] */ void ( __stdcall  *ReleaseFuncDesc )( 
            ITypeInfo  * This,
            /* [in] */ FUNCDESC  *pFuncDesc);
        
        /* [local] */ void ( __stdcall  *ReleaseVarDesc )( 
            ITypeInfo  * This,
            /* [in] */ VARDESC  *pVarDesc);
        
        END_INTERFACE
    } ITypeInfoVtbl;

    interface ITypeInfo
    {
        CONST_VTBL struct ITypeInfoVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITypeInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITypeInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITypeInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITypeInfo_GetTypeAttr(This,ppTypeAttr)	\
    (This)->lpVtbl -> GetTypeAttr(This,ppTypeAttr)

#define ITypeInfo_GetTypeComp(This,ppTComp)	\
    (This)->lpVtbl -> GetTypeComp(This,ppTComp)

#define ITypeInfo_GetFuncDesc(This,index,ppFuncDesc)	\
    (This)->lpVtbl -> GetFuncDesc(This,index,ppFuncDesc)

#define ITypeInfo_GetVarDesc(This,index,ppVarDesc)	\
    (This)->lpVtbl -> GetVarDesc(This,index,ppVarDesc)

#define ITypeInfo_GetNames(This,memid,rgBstrNames,cMaxNames,pcNames)	\
    (This)->lpVtbl -> GetNames(This,memid,rgBstrNames,cMaxNames,pcNames)

#define ITypeInfo_GetRefTypeOfImplType(This,index,pRefType)	\
    (This)->lpVtbl -> GetRefTypeOfImplType(This,index,pRefType)

#define ITypeInfo_GetImplTypeFlags(This,index,pImplTypeFlags)	\
    (This)->lpVtbl -> GetImplTypeFlags(This,index,pImplTypeFlags)

#define ITypeInfo_GetIDsOfNames(This,rgszNames,cNames,pMemId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,rgszNames,cNames,pMemId)

#define ITypeInfo_Invoke(This,pvInstance,memid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,pvInstance,memid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#define ITypeInfo_GetDocumentation(This,memid,pBstrName,pBstrDocString,pdwHelpContext,pBstrHelpFile)	\
    (This)->lpVtbl -> GetDocumentation(This,memid,pBstrName,pBstrDocString,pdwHelpContext,pBstrHelpFile)

#define ITypeInfo_GetDllEntry(This,memid,invKind,pBstrDllName,pBstrName,pwOrdinal)	\
    (This)->lpVtbl -> GetDllEntry(This,memid,invKind,pBstrDllName,pBstrName,pwOrdinal)

#define ITypeInfo_GetRefTypeInfo(This,hRefType,ppTInfo)	\
    (This)->lpVtbl -> GetRefTypeInfo(This,hRefType,ppTInfo)

#define ITypeInfo_AddressOfMember(This,memid,invKind,ppv)	\
    (This)->lpVtbl -> AddressOfMember(This,memid,invKind,ppv)

#define ITypeInfo_CreateInstance(This,pUnkOuter,riid,ppvObj)	\
    (This)->lpVtbl -> CreateInstance(This,pUnkOuter,riid,ppvObj)

#define ITypeInfo_GetMops(This,memid,pBstrMops)	\
    (This)->lpVtbl -> GetMops(This,memid,pBstrMops)

#define ITypeInfo_GetContainingTypeLib(This,ppTLib,pIndex)	\
    (This)->lpVtbl -> GetContainingTypeLib(This,ppTLib,pIndex)

#define ITypeInfo_ReleaseTypeAttr(This,pTypeAttr)	\
    (This)->lpVtbl -> ReleaseTypeAttr(This,pTypeAttr)

#define ITypeInfo_ReleaseFuncDesc(This,pFuncDesc)	\
    (This)->lpVtbl -> ReleaseFuncDesc(This,pFuncDesc)

#define ITypeInfo_ReleaseVarDesc(This,pVarDesc)	\
    (This)->lpVtbl -> ReleaseVarDesc(This,pVarDesc)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT __stdcall ITypeInfo_RemoteGetTypeAttr_Proxy( 
    ITypeInfo  * This,
    /* [out] */ LPTYPEATTR  *ppTypeAttr,
    /* [out] */ CLEANLOCALSTORAGE  *pDummy);


void __stdcall ITypeInfo_RemoteGetTypeAttr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ITypeInfo_GetTypeComp_Proxy( 
    ITypeInfo  * This,
    /* [out] */ ITypeComp  * *ppTComp);


void __stdcall ITypeInfo_GetTypeComp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall ITypeInfo_RemoteGetFuncDesc_Proxy( 
    ITypeInfo  * This,
    /* [in] */ unsigned index,
    /* [out] */ LPFUNCDESC  *ppFuncDesc,
    /* [out] */ CLEANLOCALSTORAGE  *pDummy);


void __stdcall ITypeInfo_RemoteGetFuncDesc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall ITypeInfo_RemoteGetVarDesc_Proxy( 
    ITypeInfo  * This,
    /* [in] */ unsigned index,
    /* [out] */ LPVARDESC  *ppVarDesc,
    /* [out] */ CLEANLOCALSTORAGE  *pDummy);


void __stdcall ITypeInfo_RemoteGetVarDesc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall ITypeInfo_RemoteGetNames_Proxy( 
    ITypeInfo  * This,
    /* [in] */ MEMBERID memid,
    /* [length_is][size_is][out] */ BSTR  *rgBstrNames,
    /* [in] */ unsigned cMaxNames,
    /* [out] */ unsigned  *pcNames);


void __stdcall ITypeInfo_RemoteGetNames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ITypeInfo_GetRefTypeOfImplType_Proxy( 
    ITypeInfo  * This,
    /* [in] */ unsigned index,
    /* [out] */ HREFTYPE  *pRefType);


void __stdcall ITypeInfo_GetRefTypeOfImplType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ITypeInfo_GetImplTypeFlags_Proxy( 
    ITypeInfo  * This,
    /* [in] */ unsigned index,
    /* [out] */ int  *pImplTypeFlags);


void __stdcall ITypeInfo_GetImplTypeFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ITypeInfo_GetIDsOfNames_Proxy( 
    ITypeInfo  * This,
    /* [size_is][in] */ LPOLESTR  *rgszNames,
    /* [in] */ unsigned cNames,
    /* [size_is][out] */ MEMBERID  *pMemId);


void __stdcall ITypeInfo_GetIDsOfNames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall ITypeInfo_RemoteInvoke_Proxy( 
    ITypeInfo  * This,
    /* [in] */ IUnknown  *pIUnk,
    /* [in] */ MEMBERID memid,
    /* [in] */ unsigned long dwFlags,
    /* [in] */ DISPPARAMS  *pDispParams,
    /* [out] */ VARIANT  *pVarResult,
    /* [out] */ EXCEPINFO  *pExcepInfo,
    /* [out] */ unsigned  *pArgErr,
    /* [in] */ unsigned cVarRef,
    /* [size_is][in] */ unsigned  *rgVarRefIdx,
    /* [size_is][out][in] */ VARIANTARG  *rgVarRef);


void __stdcall ITypeInfo_RemoteInvoke_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall ITypeInfo_RemoteGetDocumentation_Proxy( 
    ITypeInfo  * This,
    /* [in] */ MEMBERID memid,
    /* [in] */ unsigned long refPtrFlags,
    /* [out] */ BSTR  *pBstrName,
    /* [out] */ BSTR  *pBstrDocString,
    /* [out] */ unsigned long  *pdwHelpContext,
    /* [out] */ BSTR  *pBstrHelpFile);


void __stdcall ITypeInfo_RemoteGetDocumentation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall ITypeInfo_RemoteGetDllEntry_Proxy( 
    ITypeInfo  * This,
    /* [in] */ MEMBERID memid,
    /* [in] */ INVOKEKIND invKind,
    /* [in] */ unsigned long refPtrFlags,
    /* [out] */ BSTR  *pBstrDllName,
    /* [out] */ BSTR  *pBstrName,
    /* [out] */ WORD  *pwOrdinal);


void __stdcall ITypeInfo_RemoteGetDllEntry_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ITypeInfo_GetRefTypeInfo_Proxy( 
    ITypeInfo  * This,
    /* [in] */ HREFTYPE hRefType,
    /* [out] */ ITypeInfo  * *ppTInfo);


void __stdcall ITypeInfo_GetRefTypeInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [nocode][call_as] */ HRESULT __stdcall ITypeInfo_LocalAddressOfMember_Proxy( 
    ITypeInfo  * This);


void __stdcall ITypeInfo_LocalAddressOfMember_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall ITypeInfo_RemoteCreateInstance_Proxy( 
    ITypeInfo  * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown  * *ppvObj);


void __stdcall ITypeInfo_RemoteCreateInstance_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ITypeInfo_GetMops_Proxy( 
    ITypeInfo  * This,
    /* [in] */ MEMBERID memid,
    /* [out] */ BSTR  *pBstrMops);


void __stdcall ITypeInfo_GetMops_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall ITypeInfo_RemoteGetContainingTypeLib_Proxy( 
    ITypeInfo  * This,
    /* [out] */ ITypeLib  * *ppTLib,
    /* [out] */ unsigned  *pIndex);


void __stdcall ITypeInfo_RemoteGetContainingTypeLib_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [nocode][call_as] */ HRESULT __stdcall ITypeInfo_LocalReleaseTypeAttr_Proxy( 
    ITypeInfo  * This);


void __stdcall ITypeInfo_LocalReleaseTypeAttr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [nocode][call_as] */ HRESULT __stdcall ITypeInfo_LocalReleaseFuncDesc_Proxy( 
    ITypeInfo  * This);


void __stdcall ITypeInfo_LocalReleaseFuncDesc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [nocode][call_as] */ HRESULT __stdcall ITypeInfo_LocalReleaseVarDesc_Proxy( 
    ITypeInfo  * This);


void __stdcall ITypeInfo_LocalReleaseVarDesc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __ITypeInfo_INTERFACE_DEFINED__ */


#ifndef __ITypeInfo2_INTERFACE_DEFINED__
#define __ITypeInfo2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITypeInfo2
 * at Sat Jul 13 21:56:52 1996
 * using MIDL 3.00.39
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ ITypeInfo2  *LPTYPEINFO2;


EXTERN_C const IID IID_ITypeInfo2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ITypeInfo2 : public ITypeInfo
    {
    public:
        virtual HRESULT __stdcall GetTypeKind( 
            /* [out] */ TYPEKIND  *pTypeKind) = 0;
        
        virtual HRESULT __stdcall GetTypeFlags( 
            /* [out] */ unsigned long  *pTypeFlags) = 0;
        
        virtual HRESULT __stdcall GetFuncIndexOfMemId( 
            /* [in] */ MEMBERID memid,
            /* [in] */ INVOKEKIND invKind,
            /* [out] */ unsigned  *pFuncIndex) = 0;
        
        virtual HRESULT __stdcall GetVarIndexOfMemId( 
            /* [in] */ MEMBERID memid,
            /* [out] */ unsigned  *pVarIndex) = 0;
        
        virtual HRESULT __stdcall GetCustData( 
            /* [in] */ REFGUID guid,
            /* [out] */ VARIANT  *pVarVal) = 0;
        
        virtual HRESULT __stdcall GetFuncCustData( 
            /* [in] */ unsigned index,
            /* [in] */ REFGUID guid,
            /* [out] */ VARIANT  *pVarVal) = 0;
        
        virtual HRESULT __stdcall GetParamCustData( 
            /* [in] */ unsigned indexFunc,
            /* [in] */ unsigned indexParam,
            /* [in] */ REFGUID guid,
            /* [out] */ VARIANT  *pVarVal) = 0;
        
        virtual HRESULT __stdcall GetVarCustData( 
            /* [in] */ unsigned index,
            /* [in] */ REFGUID guid,
            /* [out] */ VARIANT  *pVarVal) = 0;
        
        virtual HRESULT __stdcall GetImplTypeCustData( 
            /* [in] */ unsigned index,
            /* [in] */ REFGUID guid,
            /* [out] */ VARIANT  *pVarVal) = 0;
        
        virtual /* [local] */ HRESULT __stdcall GetDocumentation2( 
            /* [in] */ MEMBERID memid,
            /* [in] */ LCID lcid,
            /* [out] */ BSTR  *pbstrHelpString,
            /* [out] */ unsigned long  *pdwHelpStringContext,
            /* [out] */ BSTR  *pbstrHelpStringDll) = 0;
        
        virtual HRESULT __stdcall GetAllCustData( 
            /* [out] */ CUSTDATA  *pCustData) = 0;
        
        virtual HRESULT __stdcall GetAllFuncCustData( 
            /* [in] */ unsigned index,
            /* [out] */ CUSTDATA  *pCustData) = 0;
        
        virtual HRESULT __stdcall GetAllParamCustData( 
            /* [in] */ unsigned indexFunc,
            /* [in] */ unsigned indexParam,
            /* [out] */ CUSTDATA  *pCustData) = 0;
        
        virtual HRESULT __stdcall GetAllVarCustData( 
            /* [in] */ unsigned index,
            /* [out] */ CUSTDATA  *pCustData) = 0;
        
        virtual HRESULT __stdcall GetAllImplTypeCustData( 
            /* [in] */ unsigned index,
            /* [out] */ CUSTDATA  *pCustData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITypeInfo2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            ITypeInfo2  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            ITypeInfo2  * This);
        
        unsigned long ( __stdcall  *Release )( 
            ITypeInfo2  * This);
        
        /* [local] */ HRESULT ( __stdcall  *GetTypeAttr )( 
            ITypeInfo2  * This,
            /* [out] */ TYPEATTR  * *ppTypeAttr);
        
        HRESULT ( __stdcall  *GetTypeComp )( 
            ITypeInfo2  * This,
            /* [out] */ ITypeComp  * *ppTComp);
        
        /* [local] */ HRESULT ( __stdcall  *GetFuncDesc )( 
            ITypeInfo2  * This,
            /* [in] */ unsigned index,
            /* [out] */ FUNCDESC  * *ppFuncDesc);
        
        /* [local] */ HRESULT ( __stdcall  *GetVarDesc )( 
            ITypeInfo2  * This,
            /* [in] */ unsigned index,
            /* [out] */ VARDESC  * *ppVarDesc);
        
        /* [local] */ HRESULT ( __stdcall  *GetNames )( 
            ITypeInfo2  * This,
            /* [in] */ MEMBERID memid,
            /* [length_is][size_is][out] */ BSTR  *rgBstrNames,
            /* [in] */ unsigned cMaxNames,
            /* [out] */ unsigned  *pcNames);
        
        HRESULT ( __stdcall  *GetRefTypeOfImplType )( 
            ITypeInfo2  * This,
            /* [in] */ unsigned index,
            /* [out] */ HREFTYPE  *pRefType);
        
        HRESULT ( __stdcall  *GetImplTypeFlags )( 
            ITypeInfo2  * This,
            /* [in] */ unsigned index,
            /* [out] */ int  *pImplTypeFlags);
        
        HRESULT ( __stdcall  *GetIDsOfNames )( 
            ITypeInfo2  * This,
            /* [size_is][in] */ LPOLESTR  *rgszNames,
            /* [in] */ unsigned cNames,
            /* [size_is][out] */ MEMBERID  *pMemId);
        
        /* [local] */ HRESULT ( __stdcall  *Invoke )( 
            ITypeInfo2  * This,
            /* [in] */ void* pvInstance,
            /* [in] */ MEMBERID memid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS  *pDispParams,
            /* [out] */ VARIANT  *pVarResult,
            /* [out] */ EXCEPINFO  *pExcepInfo,
            /* [out] */ unsigned  *puArgErr);
        
        /* [local] */ HRESULT ( __stdcall  *GetDocumentation )( 
            ITypeInfo2  * This,
            /* [in] */ MEMBERID memid,
            /* [out] */ BSTR  *pBstrName,
            /* [out] */ BSTR  *pBstrDocString,
            /* [out] */ unsigned long  *pdwHelpContext,
            /* [out] */ BSTR  *pBstrHelpFile);
        
        /* [local] */ HRESULT ( __stdcall  *GetDllEntry )( 
            ITypeInfo2  * This,
            /* [in] */ MEMBERID memid,
            /* [in] */ INVOKEKIND invKind,
            /* [out] */ BSTR  *pBstrDllName,
            /* [out] */ BSTR  *pBstrName,
            /* [out] */ WORD  *pwOrdinal);
        
        HRESULT ( __stdcall  *GetRefTypeInfo )( 
            ITypeInfo2  * This,
            /* [in] */ HREFTYPE hRefType,
            /* [out] */ ITypeInfo  * *ppTInfo);
        
        /* [local] */ HRESULT ( __stdcall  *AddressOfMember )( 
            ITypeInfo2  * This,
            /* [in] */ MEMBERID memid,
            /* [in] */ INVOKEKIND invKind,
            /* [out] */ void*  *ppv);
        
        /* [local] */ HRESULT ( __stdcall  *CreateInstance )( 
            ITypeInfo2  * This,
            /* [in] */ IUnknown  *pUnkOuter,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void*  *ppvObj);
        
        HRESULT ( __stdcall  *GetMops )( 
            ITypeInfo2  * This,
            /* [in] */ MEMBERID memid,
            /* [out] */ BSTR  *pBstrMops);
        
        /* [local] */ HRESULT ( __stdcall  *GetContainingTypeLib )( 
            ITypeInfo2  * This,
            /* [out] */ ITypeLib  * *ppTLib,
            /* [out] */ unsigned  *pIndex);
        
        /* [local] */ void ( __stdcall  *ReleaseTypeAttr )( 
            ITypeInfo2  * This,
            /* [in] */ TYPEATTR  *pTypeAttr);
        
        /* [local] */ void ( __stdcall  *ReleaseFuncDesc )( 
            ITypeInfo2  * This,
            /* [in] */ FUNCDESC  *pFuncDesc);
        
        /* [local] */ void ( __stdcall  *ReleaseVarDesc )( 
            ITypeInfo2  * This,
            /* [in] */ VARDESC  *pVarDesc);
        
        HRESULT ( __stdcall  *GetTypeKind )( 
            ITypeInfo2  * This,
            /* [out] */ TYPEKIND  *pTypeKind);
        
        HRESULT ( __stdcall  *GetTypeFlags )( 
            ITypeInfo2  * This,
            /* [out] */ unsigned long  *pTypeFlags);
        
        HRESULT ( __stdcall  *GetFuncIndexOfMemId )( 
            ITypeInfo2  * This,
            /* [in] */ MEMBERID memid,
            /* [in] */ INVOKEKIND invKind,
            /* [out] */ unsigned  *pFuncIndex);
        
        HRESULT ( __stdcall  *GetVarIndexOfMemId )( 
            ITypeInfo2  * This,
            /* [in] */ MEMBERID memid,
            /* [out] */ unsigned  *pVarIndex);
        
        HRESULT ( __stdcall  *GetCustData )( 
            ITypeInfo2  * This,
            /* [in] */ REFGUID guid,
            /* [out] */ VARIANT  *pVarVal);
        
        HRESULT ( __stdcall  *GetFuncCustData )( 
            ITypeInfo2  * This,
            /* [in] */ unsigned index,
            /* [in] */ REFGUID guid,
            /* [out] */ VARIANT  *pVarVal);
        
        HRESULT ( __stdcall  *GetParamCustData )( 
            ITypeInfo2  * This,
            /* [in] */ unsigned indexFunc,
            /* [in] */ unsigned indexParam,
            /* [in] */ REFGUID guid,
            /* [out] */ VARIANT  *pVarVal);
        
        HRESULT ( __stdcall  *GetVarCustData )( 
            ITypeInfo2  * This,
            /* [in] */ unsigned index,
            /* [in] */ REFGUID guid,
            /* [out] */ VARIANT  *pVarVal);
        
        HRESULT ( __stdcall  *GetImplTypeCustData )( 
            ITypeInfo2  * This,
            /* [in] */ unsigned index,
            /* [in] */ REFGUID guid,
            /* [out] */ VARIANT  *pVarVal);
        
        /* [local] */ HRESULT ( __stdcall  *GetDocumentation2 )( 
            ITypeInfo2  * This,
            /* [in] */ MEMBERID memid,
            /* [in] */ LCID lcid,
            /* [out] */ BSTR  *pbstrHelpString,
            /* [out] */ unsigned long  *pdwHelpStringContext,
            /* [out] */ BSTR  *pbstrHelpStringDll);
        
        HRESULT ( __stdcall  *GetAllCustData )( 
            ITypeInfo2  * This,
            /* [out] */ CUSTDATA  *pCustData);
        
        HRESULT ( __stdcall  *GetAllFuncCustData )( 
            ITypeInfo2  * This,
            /* [in] */ unsigned index,
            /* [out] */ CUSTDATA  *pCustData);
        
        HRESULT ( __stdcall  *GetAllParamCustData )( 
            ITypeInfo2  * This,
            /* [in] */ unsigned indexFunc,
            /* [in] */ unsigned indexParam,
            /* [out] */ CUSTDATA  *pCustData);
        
        HRESULT ( __stdcall  *GetAllVarCustData )( 
            ITypeInfo2  * This,
            /* [in] */ unsigned index,
            /* [out] */ CUSTDATA  *pCustData);
        
        HRESULT ( __stdcall  *GetAllImplTypeCustData )( 
            ITypeInfo2  * This,
            /* [in] */ unsigned index,
            /* [out] */ CUSTDATA  *pCustData);
        
        END_INTERFACE
    } ITypeInfo2Vtbl;

    interface ITypeInfo2
    {
        CONST_VTBL struct ITypeInfo2Vtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITypeInfo2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITypeInfo2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITypeInfo2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITypeInfo2_GetTypeAttr(This,ppTypeAttr)	\
    (This)->lpVtbl -> GetTypeAttr(This,ppTypeAttr)

#define ITypeInfo2_GetTypeComp(This,ppTComp)	\
    (This)->lpVtbl -> GetTypeComp(This,ppTComp)

#define ITypeInfo2_GetFuncDesc(This,index,ppFuncDesc)	\
    (This)->lpVtbl -> GetFuncDesc(This,index,ppFuncDesc)

#define ITypeInfo2_GetVarDesc(This,index,ppVarDesc)	\
    (This)->lpVtbl -> GetVarDesc(This,index,ppVarDesc)

#define ITypeInfo2_GetNames(This,memid,rgBstrNames,cMaxNames,pcNames)	\
    (This)->lpVtbl -> GetNames(This,memid,rgBstrNames,cMaxNames,pcNames)

#define ITypeInfo2_GetRefTypeOfImplType(This,index,pRefType)	\
    (This)->lpVtbl -> GetRefTypeOfImplType(This,index,pRefType)

#define ITypeInfo2_GetImplTypeFlags(This,index,pImplTypeFlags)	\
    (This)->lpVtbl -> GetImplTypeFlags(This,index,pImplTypeFlags)

#define ITypeInfo2_GetIDsOfNames(This,rgszNames,cNames,pMemId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,rgszNames,cNames,pMemId)

#define ITypeInfo2_Invoke(This,pvInstance,memid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,pvInstance,memid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#define ITypeInfo2_GetDocumentation(This,memid,pBstrName,pBstrDocString,pdwHelpContext,pBstrHelpFile)	\
    (This)->lpVtbl -> GetDocumentation(This,memid,pBstrName,pBstrDocString,pdwHelpContext,pBstrHelpFile)

#define ITypeInfo2_GetDllEntry(This,memid,invKind,pBstrDllName,pBstrName,pwOrdinal)	\
    (This)->lpVtbl -> GetDllEntry(This,memid,invKind,pBstrDllName,pBstrName,pwOrdinal)

#define ITypeInfo2_GetRefTypeInfo(This,hRefType,ppTInfo)	\
    (This)->lpVtbl -> GetRefTypeInfo(This,hRefType,ppTInfo)

#define ITypeInfo2_AddressOfMember(This,memid,invKind,ppv)	\
    (This)->lpVtbl -> AddressOfMember(This,memid,invKind,ppv)

#define ITypeInfo2_CreateInstance(This,pUnkOuter,riid,ppvObj)	\
    (This)->lpVtbl -> CreateInstance(This,pUnkOuter,riid,ppvObj)

#define ITypeInfo2_GetMops(This,memid,pBstrMops)	\
    (This)->lpVtbl -> GetMops(This,memid,pBstrMops)

#define ITypeInfo2_GetContainingTypeLib(This,ppTLib,pIndex)	\
    (This)->lpVtbl -> GetContainingTypeLib(This,ppTLib,pIndex)

#define ITypeInfo2_ReleaseTypeAttr(This,pTypeAttr)	\
    (This)->lpVtbl -> ReleaseTypeAttr(This,pTypeAttr)

#define ITypeInfo2_ReleaseFuncDesc(This,pFuncDesc)	\
    (This)->lpVtbl -> ReleaseFuncDesc(This,pFuncDesc)

#define ITypeInfo2_ReleaseVarDesc(This,pVarDesc)	\
    (This)->lpVtbl -> ReleaseVarDesc(This,pVarDesc)


#define ITypeInfo2_GetTypeKind(This,pTypeKind)	\
    (This)->lpVtbl -> GetTypeKind(This,pTypeKind)

#define ITypeInfo2_GetTypeFlags(This,pTypeFlags)	\
    (This)->lpVtbl -> GetTypeFlags(This,pTypeFlags)

#define ITypeInfo2_GetFuncIndexOfMemId(This,memid,invKind,pFuncIndex)	\
    (This)->lpVtbl -> GetFuncIndexOfMemId(This,memid,invKind,pFuncIndex)

#define ITypeInfo2_GetVarIndexOfMemId(This,memid,pVarIndex)	\
    (This)->lpVtbl -> GetVarIndexOfMemId(This,memid,pVarIndex)

#define ITypeInfo2_GetCustData(This,guid,pVarVal)	\
    (This)->lpVtbl -> GetCustData(This,guid,pVarVal)

#define ITypeInfo2_GetFuncCustData(This,index,guid,pVarVal)	\
    (This)->lpVtbl -> GetFuncCustData(This,index,guid,pVarVal)

#define ITypeInfo2_GetParamCustData(This,indexFunc,indexParam,guid,pVarVal)	\
    (This)->lpVtbl -> GetParamCustData(This,indexFunc,indexParam,guid,pVarVal)

#define ITypeInfo2_GetVarCustData(This,index,guid,pVarVal)	\
    (This)->lpVtbl -> GetVarCustData(This,index,guid,pVarVal)

#define ITypeInfo2_GetImplTypeCustData(This,index,guid,pVarVal)	\
    (This)->lpVtbl -> GetImplTypeCustData(This,index,guid,pVarVal)

#define ITypeInfo2_GetDocumentation2(This,memid,lcid,pbstrHelpString,pdwHelpStringContext,pbstrHelpStringDll)	\
    (This)->lpVtbl -> GetDocumentation2(This,memid,lcid,pbstrHelpString,pdwHelpStringContext,pbstrHelpStringDll)

#define ITypeInfo2_GetAllCustData(This,pCustData)	\
    (This)->lpVtbl -> GetAllCustData(This,pCustData)

#define ITypeInfo2_GetAllFuncCustData(This,index,pCustData)	\
    (This)->lpVtbl -> GetAllFuncCustData(This,index,pCustData)

#define ITypeInfo2_GetAllParamCustData(This,indexFunc,indexParam,pCustData)	\
    (This)->lpVtbl -> GetAllParamCustData(This,indexFunc,indexParam,pCustData)

#define ITypeInfo2_GetAllVarCustData(This,index,pCustData)	\
    (This)->lpVtbl -> GetAllVarCustData(This,index,pCustData)

#define ITypeInfo2_GetAllImplTypeCustData(This,index,pCustData)	\
    (This)->lpVtbl -> GetAllImplTypeCustData(This,index,pCustData)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall ITypeInfo2_GetTypeKind_Proxy( 
    ITypeInfo2  * This,
    /* [out] */ TYPEKIND  *pTypeKind);


void __stdcall ITypeInfo2_GetTypeKind_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ITypeInfo2_GetTypeFlags_Proxy( 
    ITypeInfo2  * This,
    /* [out] */ unsigned long  *pTypeFlags);


void __stdcall ITypeInfo2_GetTypeFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ITypeInfo2_GetFuncIndexOfMemId_Proxy( 
    ITypeInfo2  * This,
    /* [in] */ MEMBERID memid,
    /* [in] */ INVOKEKIND invKind,
    /* [out] */ unsigned  *pFuncIndex);


void __stdcall ITypeInfo2_GetFuncIndexOfMemId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ITypeInfo2_GetVarIndexOfMemId_Proxy( 
    ITypeInfo2  * This,
    /* [in] */ MEMBERID memid,
    /* [out] */ unsigned  *pVarIndex);


void __stdcall ITypeInfo2_GetVarIndexOfMemId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ITypeInfo2_GetCustData_Proxy( 
    ITypeInfo2  * This,
    /* [in] */ REFGUID guid,
    /* [out] */ VARIANT  *pVarVal);


void __stdcall ITypeInfo2_GetCustData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ITypeInfo2_GetFuncCustData_Proxy( 
    ITypeInfo2  * This,
    /* [in] */ unsigned index,
    /* [in] */ REFGUID guid,
    /* [out] */ VARIANT  *pVarVal);


void __stdcall ITypeInfo2_GetFuncCustData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ITypeInfo2_GetParamCustData_Proxy( 
    ITypeInfo2  * This,
    /* [in] */ unsigned indexFunc,
    /* [in] */ unsigned indexParam,
    /* [in] */ REFGUID guid,
    /* [out] */ VARIANT  *pVarVal);


void __stdcall ITypeInfo2_GetParamCustData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ITypeInfo2_GetVarCustData_Proxy( 
    ITypeInfo2  * This,
    /* [in] */ unsigned index,
    /* [in] */ REFGUID guid,
    /* [out] */ VARIANT  *pVarVal);


void __stdcall ITypeInfo2_GetVarCustData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ITypeInfo2_GetImplTypeCustData_Proxy( 
    ITypeInfo2  * This,
    /* [in] */ unsigned index,
    /* [in] */ REFGUID guid,
    /* [out] */ VARIANT  *pVarVal);


void __stdcall ITypeInfo2_GetImplTypeCustData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall ITypeInfo2_RemoteGetDocumentation2_Proxy( 
    ITypeInfo2  * This,
    /* [in] */ MEMBERID memid,
    /* [in] */ LCID lcid,
    /* [in] */ unsigned long refPtrFlags,
    /* [out] */ BSTR  *pbstrHelpString,
    /* [out] */ unsigned long  *pdwHelpStringContext,
    /* [out] */ BSTR  *pbstrHelpStringDll);


void __stdcall ITypeInfo2_RemoteGetDocumentation2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ITypeInfo2_GetAllCustData_Proxy( 
    ITypeInfo2  * This,
    /* [out] */ CUSTDATA  *pCustData);


void __stdcall ITypeInfo2_GetAllCustData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ITypeInfo2_GetAllFuncCustData_Proxy( 
    ITypeInfo2  * This,
    /* [in] */ unsigned index,
    /* [out] */ CUSTDATA  *pCustData);


void __stdcall ITypeInfo2_GetAllFuncCustData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ITypeInfo2_GetAllParamCustData_Proxy( 
    ITypeInfo2  * This,
    /* [in] */ unsigned indexFunc,
    /* [in] */ unsigned indexParam,
    /* [out] */ CUSTDATA  *pCustData);


void __stdcall ITypeInfo2_GetAllParamCustData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ITypeInfo2_GetAllVarCustData_Proxy( 
    ITypeInfo2  * This,
    /* [in] */ unsigned index,
    /* [out] */ CUSTDATA  *pCustData);


void __stdcall ITypeInfo2_GetAllVarCustData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ITypeInfo2_GetAllImplTypeCustData_Proxy( 
    ITypeInfo2  * This,
    /* [in] */ unsigned index,
    /* [out] */ CUSTDATA  *pCustData);


void __stdcall ITypeInfo2_GetAllImplTypeCustData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __ITypeInfo2_INTERFACE_DEFINED__ */


#ifndef __ITypeLib_INTERFACE_DEFINED__
#define __ITypeLib_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITypeLib
 * at Sat Jul 13 21:56:52 1996
 * using MIDL 3.00.39
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [v1_enum] */ 
enum tagSYSKIND
    {	SYS_WIN16	= 0,
	SYS_WIN32	= SYS_WIN16 + 1,
	SYS_MAC	= SYS_WIN32 + 1
    }	SYSKIND;

typedef /* [v1_enum] */ 
enum tagLIBFLAGS
    {	LIBFLAG_FRESTRICTED	= 0x1,
	LIBFLAG_FCONTROL	= 0x2,
	LIBFLAG_FHIDDEN	= 0x4,
	LIBFLAG_FHASDISKIMAGE	= 0x8
    }	LIBFLAGS;

typedef /* [unique] */ ITypeLib  *LPTYPELIB;

typedef struct  tagTLIBATTR
    {
    GUID guid;
    LCID lcid;
    SYSKIND syskind;
    WORD wMajorVerNum;
    WORD wMinorVerNum;
    WORD wLibFlags;
    }	TLIBATTR;

typedef struct tagTLIBATTR  *LPTLIBATTR;


EXTERN_C const IID IID_ITypeLib;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ITypeLib : public IUnknown
    {
    public:
        virtual /* [local] */ unsigned __stdcall GetTypeInfoCount( void) = 0;
        
        virtual HRESULT __stdcall GetTypeInfo( 
            /* [in] */ unsigned index,
            /* [out] */ ITypeInfo  * *ppTInfo) = 0;
        
        virtual HRESULT __stdcall GetTypeInfoType( 
            /* [in] */ unsigned index,
            /* [out] */ TYPEKIND  *pTKind) = 0;
        
        virtual HRESULT __stdcall GetTypeInfoOfGuid( 
            /* [in] */ REFGUID guid,
            /* [out] */ ITypeInfo  * *ppTinfo) = 0;
        
        virtual /* [local] */ HRESULT __stdcall GetLibAttr( 
            /* [out] */ TLIBATTR  * *ppTLibAttr) = 0;
        
        virtual HRESULT __stdcall GetTypeComp( 
            /* [out] */ ITypeComp  * *ppTComp) = 0;
        
        virtual /* [local] */ HRESULT __stdcall GetDocumentation( 
            /* [in] */ int index,
            /* [out] */ BSTR  *pBstrName,
            /* [out] */ BSTR  *pBstrDocString,
            /* [out] */ unsigned long  *pdwHelpContext,
            /* [out] */ BSTR  *pBstrHelpFile) = 0;
        
        virtual /* [local] */ HRESULT __stdcall IsName( 
            /* [out][in] */ LPOLESTR szNameBuf,
            /* [in] */ unsigned long lHashVal,
            /* [out] */ BOOL  *pfName) = 0;
        
        virtual /* [local] */ HRESULT __stdcall FindName( 
            /* [out][in] */ LPOLESTR szNameBuf,
            /* [in] */ unsigned long lHashVal,
            /* [length_is][size_is][out] */ ITypeInfo  * *ppTInfo,
            /* [length_is][size_is][out] */ MEMBERID  *rgMemId,
            /* [out][in] */ unsigned short  *pcFound) = 0;
        
        virtual /* [local] */ void __stdcall ReleaseTLibAttr( 
            /* [in] */ TLIBATTR  *pTLibAttr) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITypeLibVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            ITypeLib  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            ITypeLib  * This);
        
        unsigned long ( __stdcall  *Release )( 
            ITypeLib  * This);
        
        /* [local] */ unsigned ( __stdcall  *GetTypeInfoCount )( 
            ITypeLib  * This);
        
        HRESULT ( __stdcall  *GetTypeInfo )( 
            ITypeLib  * This,
            /* [in] */ unsigned index,
            /* [out] */ ITypeInfo  * *ppTInfo);
        
        HRESULT ( __stdcall  *GetTypeInfoType )( 
            ITypeLib  * This,
            /* [in] */ unsigned index,
            /* [out] */ TYPEKIND  *pTKind);
        
        HRESULT ( __stdcall  *GetTypeInfoOfGuid )( 
            ITypeLib  * This,
            /* [in] */ REFGUID guid,
            /* [out] */ ITypeInfo  * *ppTinfo);
        
        /* [local] */ HRESULT ( __stdcall  *GetLibAttr )( 
            ITypeLib  * This,
            /* [out] */ TLIBATTR  * *ppTLibAttr);
        
        HRESULT ( __stdcall  *GetTypeComp )( 
            ITypeLib  * This,
            /* [out] */ ITypeComp  * *ppTComp);
        
        /* [local] */ HRESULT ( __stdcall  *GetDocumentation )( 
            ITypeLib  * This,
            /* [in] */ int index,
            /* [out] */ BSTR  *pBstrName,
            /* [out] */ BSTR  *pBstrDocString,
            /* [out] */ unsigned long  *pdwHelpContext,
            /* [out] */ BSTR  *pBstrHelpFile);
        
        /* [local] */ HRESULT ( __stdcall  *IsName )( 
            ITypeLib  * This,
            /* [out][in] */ LPOLESTR szNameBuf,
            /* [in] */ unsigned long lHashVal,
            /* [out] */ BOOL  *pfName);
        
        /* [local] */ HRESULT ( __stdcall  *FindName )( 
            ITypeLib  * This,
            /* [out][in] */ LPOLESTR szNameBuf,
            /* [in] */ unsigned long lHashVal,
            /* [length_is][size_is][out] */ ITypeInfo  * *ppTInfo,
            /* [length_is][size_is][out] */ MEMBERID  *rgMemId,
            /* [out][in] */ unsigned short  *pcFound);
        
        /* [local] */ void ( __stdcall  *ReleaseTLibAttr )( 
            ITypeLib  * This,
            /* [in] */ TLIBATTR  *pTLibAttr);
        
        END_INTERFACE
    } ITypeLibVtbl;

    interface ITypeLib
    {
        CONST_VTBL struct ITypeLibVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITypeLib_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITypeLib_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITypeLib_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITypeLib_GetTypeInfoCount(This)	\
    (This)->lpVtbl -> GetTypeInfoCount(This)

#define ITypeLib_GetTypeInfo(This,index,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,index,ppTInfo)

#define ITypeLib_GetTypeInfoType(This,index,pTKind)	\
    (This)->lpVtbl -> GetTypeInfoType(This,index,pTKind)

#define ITypeLib_GetTypeInfoOfGuid(This,guid,ppTinfo)	\
    (This)->lpVtbl -> GetTypeInfoOfGuid(This,guid,ppTinfo)

#define ITypeLib_GetLibAttr(This,ppTLibAttr)	\
    (This)->lpVtbl -> GetLibAttr(This,ppTLibAttr)

#define ITypeLib_GetTypeComp(This,ppTComp)	\
    (This)->lpVtbl -> GetTypeComp(This,ppTComp)

#define ITypeLib_GetDocumentation(This,index,pBstrName,pBstrDocString,pdwHelpContext,pBstrHelpFile)	\
    (This)->lpVtbl -> GetDocumentation(This,index,pBstrName,pBstrDocString,pdwHelpContext,pBstrHelpFile)

#define ITypeLib_IsName(This,szNameBuf,lHashVal,pfName)	\
    (This)->lpVtbl -> IsName(This,szNameBuf,lHashVal,pfName)

#define ITypeLib_FindName(This,szNameBuf,lHashVal,ppTInfo,rgMemId,pcFound)	\
    (This)->lpVtbl -> FindName(This,szNameBuf,lHashVal,ppTInfo,rgMemId,pcFound)

#define ITypeLib_ReleaseTLibAttr(This,pTLibAttr)	\
    (This)->lpVtbl -> ReleaseTLibAttr(This,pTLibAttr)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT __stdcall ITypeLib_RemoteGetTypeInfoCount_Proxy( 
    ITypeLib  * This,
    /* [out] */ unsigned  *pcTInfo);


void __stdcall ITypeLib_RemoteGetTypeInfoCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ITypeLib_GetTypeInfo_Proxy( 
    ITypeLib  * This,
    /* [in] */ unsigned index,
    /* [out] */ ITypeInfo  * *ppTInfo);


void __stdcall ITypeLib_GetTypeInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ITypeLib_GetTypeInfoType_Proxy( 
    ITypeLib  * This,
    /* [in] */ unsigned index,
    /* [out] */ TYPEKIND  *pTKind);


void __stdcall ITypeLib_GetTypeInfoType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ITypeLib_GetTypeInfoOfGuid_Proxy( 
    ITypeLib  * This,
    /* [in] */ REFGUID guid,
    /* [out] */ ITypeInfo  * *ppTinfo);


void __stdcall ITypeLib_GetTypeInfoOfGuid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall ITypeLib_RemoteGetLibAttr_Proxy( 
    ITypeLib  * This,
    /* [out] */ LPTLIBATTR  *ppTLibAttr,
    /* [out] */ CLEANLOCALSTORAGE  *pDummy);


void __stdcall ITypeLib_RemoteGetLibAttr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ITypeLib_GetTypeComp_Proxy( 
    ITypeLib  * This,
    /* [out] */ ITypeComp  * *ppTComp);


void __stdcall ITypeLib_GetTypeComp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall ITypeLib_RemoteGetDocumentation_Proxy( 
    ITypeLib  * This,
    /* [in] */ int index,
    /* [in] */ unsigned long refPtrFlags,
    /* [out] */ BSTR  *pBstrName,
    /* [out] */ BSTR  *pBstrDocString,
    /* [out] */ unsigned long  *pdwHelpContext,
    /* [out] */ BSTR  *pBstrHelpFile);


void __stdcall ITypeLib_RemoteGetDocumentation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall ITypeLib_RemoteIsName_Proxy( 
    ITypeLib  * This,
    /* [in] */ LPOLESTR szNameBuf,
    /* [in] */ unsigned long lHashVal,
    /* [out] */ BOOL  *pfName,
    /* [out] */ BSTR  *pBstrLibName);


void __stdcall ITypeLib_RemoteIsName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall ITypeLib_RemoteFindName_Proxy( 
    ITypeLib  * This,
    /* [in] */ LPOLESTR szNameBuf,
    /* [in] */ unsigned long lHashVal,
    /* [length_is][size_is][out] */ ITypeInfo  * *ppTInfo,
    /* [length_is][size_is][out] */ MEMBERID  *rgMemId,
    /* [out][in] */ unsigned short  *pcFound,
    /* [out] */ BSTR  *pBstrLibName);


void __stdcall ITypeLib_RemoteFindName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [nocode][call_as] */ HRESULT __stdcall ITypeLib_LocalReleaseTLibAttr_Proxy( 
    ITypeLib  * This);


void __stdcall ITypeLib_LocalReleaseTLibAttr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __ITypeLib_INTERFACE_DEFINED__ */


#ifndef __ITypeLib2_INTERFACE_DEFINED__
#define __ITypeLib2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITypeLib2
 * at Sat Jul 13 21:56:52 1996
 * using MIDL 3.00.39
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ ITypeLib2  *LPTYPELIB2;


EXTERN_C const IID IID_ITypeLib2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ITypeLib2 : public ITypeLib
    {
    public:
        virtual HRESULT __stdcall GetCustData( 
            /* [in] */ REFGUID guid,
            /* [out] */ VARIANT  *pVarVal) = 0;
        
        virtual /* [local] */ HRESULT __stdcall GetLibStatistics( 
            /* [out] */ unsigned long  *pcUniqueNames,
            /* [out] */ unsigned long  *pcchUniqueNames) = 0;
        
        virtual /* [local] */ HRESULT __stdcall GetDocumentation2( 
            /* [in] */ int index,
            /* [in] */ LCID lcid,
            /* [out] */ BSTR  *pbstrHelpString,
            /* [out] */ unsigned long  *pdwHelpStringContext,
            /* [out] */ BSTR  *pbstrHelpStringDll) = 0;
        
        virtual HRESULT __stdcall GetAllCustData( 
            /* [out] */ CUSTDATA  *pCustData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITypeLib2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            ITypeLib2  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            ITypeLib2  * This);
        
        unsigned long ( __stdcall  *Release )( 
            ITypeLib2  * This);
        
        /* [local] */ unsigned ( __stdcall  *GetTypeInfoCount )( 
            ITypeLib2  * This);
        
        HRESULT ( __stdcall  *GetTypeInfo )( 
            ITypeLib2  * This,
            /* [in] */ unsigned index,
            /* [out] */ ITypeInfo  * *ppTInfo);
        
        HRESULT ( __stdcall  *GetTypeInfoType )( 
            ITypeLib2  * This,
            /* [in] */ unsigned index,
            /* [out] */ TYPEKIND  *pTKind);
        
        HRESULT ( __stdcall  *GetTypeInfoOfGuid )( 
            ITypeLib2  * This,
            /* [in] */ REFGUID guid,
            /* [out] */ ITypeInfo  * *ppTinfo);
        
        /* [local] */ HRESULT ( __stdcall  *GetLibAttr )( 
            ITypeLib2  * This,
            /* [out] */ TLIBATTR  * *ppTLibAttr);
        
        HRESULT ( __stdcall  *GetTypeComp )( 
            ITypeLib2  * This,
            /* [out] */ ITypeComp  * *ppTComp);
        
        /* [local] */ HRESULT ( __stdcall  *GetDocumentation )( 
            ITypeLib2  * This,
            /* [in] */ int index,
            /* [out] */ BSTR  *pBstrName,
            /* [out] */ BSTR  *pBstrDocString,
            /* [out] */ unsigned long  *pdwHelpContext,
            /* [out] */ BSTR  *pBstrHelpFile);
        
        /* [local] */ HRESULT ( __stdcall  *IsName )( 
            ITypeLib2  * This,
            /* [out][in] */ LPOLESTR szNameBuf,
            /* [in] */ unsigned long lHashVal,
            /* [out] */ BOOL  *pfName);
        
        /* [local] */ HRESULT ( __stdcall  *FindName )( 
            ITypeLib2  * This,
            /* [out][in] */ LPOLESTR szNameBuf,
            /* [in] */ unsigned long lHashVal,
            /* [length_is][size_is][out] */ ITypeInfo  * *ppTInfo,
            /* [length_is][size_is][out] */ MEMBERID  *rgMemId,
            /* [out][in] */ unsigned short  *pcFound);
        
        /* [local] */ void ( __stdcall  *ReleaseTLibAttr )( 
            ITypeLib2  * This,
            /* [in] */ TLIBATTR  *pTLibAttr);
        
        HRESULT ( __stdcall  *GetCustData )( 
            ITypeLib2  * This,
            /* [in] */ REFGUID guid,
            /* [out] */ VARIANT  *pVarVal);
        
        /* [local] */ HRESULT ( __stdcall  *GetLibStatistics )( 
            ITypeLib2  * This,
            /* [out] */ unsigned long  *pcUniqueNames,
            /* [out] */ unsigned long  *pcchUniqueNames);
        
        /* [local] */ HRESULT ( __stdcall  *GetDocumentation2 )( 
            ITypeLib2  * This,
            /* [in] */ int index,
            /* [in] */ LCID lcid,
            /* [out] */ BSTR  *pbstrHelpString,
            /* [out] */ unsigned long  *pdwHelpStringContext,
            /* [out] */ BSTR  *pbstrHelpStringDll);
        
        HRESULT ( __stdcall  *GetAllCustData )( 
            ITypeLib2  * This,
            /* [out] */ CUSTDATA  *pCustData);
        
        END_INTERFACE
    } ITypeLib2Vtbl;

    interface ITypeLib2
    {
        CONST_VTBL struct ITypeLib2Vtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITypeLib2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITypeLib2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITypeLib2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITypeLib2_GetTypeInfoCount(This)	\
    (This)->lpVtbl -> GetTypeInfoCount(This)

#define ITypeLib2_GetTypeInfo(This,index,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,index,ppTInfo)

#define ITypeLib2_GetTypeInfoType(This,index,pTKind)	\
    (This)->lpVtbl -> GetTypeInfoType(This,index,pTKind)

#define ITypeLib2_GetTypeInfoOfGuid(This,guid,ppTinfo)	\
    (This)->lpVtbl -> GetTypeInfoOfGuid(This,guid,ppTinfo)

#define ITypeLib2_GetLibAttr(This,ppTLibAttr)	\
    (This)->lpVtbl -> GetLibAttr(This,ppTLibAttr)

#define ITypeLib2_GetTypeComp(This,ppTComp)	\
    (This)->lpVtbl -> GetTypeComp(This,ppTComp)

#define ITypeLib2_GetDocumentation(This,index,pBstrName,pBstrDocString,pdwHelpContext,pBstrHelpFile)	\
    (This)->lpVtbl -> GetDocumentation(This,index,pBstrName,pBstrDocString,pdwHelpContext,pBstrHelpFile)

#define ITypeLib2_IsName(This,szNameBuf,lHashVal,pfName)	\
    (This)->lpVtbl -> IsName(This,szNameBuf,lHashVal,pfName)

#define ITypeLib2_FindName(This,szNameBuf,lHashVal,ppTInfo,rgMemId,pcFound)	\
    (This)->lpVtbl -> FindName(This,szNameBuf,lHashVal,ppTInfo,rgMemId,pcFound)

#define ITypeLib2_ReleaseTLibAttr(This,pTLibAttr)	\
    (This)->lpVtbl -> ReleaseTLibAttr(This,pTLibAttr)


#define ITypeLib2_GetCustData(This,guid,pVarVal)	\
    (This)->lpVtbl -> GetCustData(This,guid,pVarVal)

#define ITypeLib2_GetLibStatistics(This,pcUniqueNames,pcchUniqueNames)	\
    (This)->lpVtbl -> GetLibStatistics(This,pcUniqueNames,pcchUniqueNames)

#define ITypeLib2_GetDocumentation2(This,index,lcid,pbstrHelpString,pdwHelpStringContext,pbstrHelpStringDll)	\
    (This)->lpVtbl -> GetDocumentation2(This,index,lcid,pbstrHelpString,pdwHelpStringContext,pbstrHelpStringDll)

#define ITypeLib2_GetAllCustData(This,pCustData)	\
    (This)->lpVtbl -> GetAllCustData(This,pCustData)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall ITypeLib2_GetCustData_Proxy( 
    ITypeLib2  * This,
    /* [in] */ REFGUID guid,
    /* [out] */ VARIANT  *pVarVal);


void __stdcall ITypeLib2_GetCustData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall ITypeLib2_RemoteGetLibStatistics_Proxy( 
    ITypeLib2  * This,
    /* [out] */ unsigned long  *pcUniqueNames,
    /* [out] */ unsigned long  *pcchUniqueNames);


void __stdcall ITypeLib2_RemoteGetLibStatistics_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall ITypeLib2_RemoteGetDocumentation2_Proxy( 
    ITypeLib2  * This,
    /* [in] */ int index,
    /* [in] */ LCID lcid,
    /* [in] */ unsigned long refPtrFlags,
    /* [out] */ BSTR  *pbstrHelpString,
    /* [out] */ unsigned long  *pdwHelpStringContext,
    /* [out] */ BSTR  *pbstrHelpStringDll);


void __stdcall ITypeLib2_RemoteGetDocumentation2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ITypeLib2_GetAllCustData_Proxy( 
    ITypeLib2  * This,
    /* [out] */ CUSTDATA  *pCustData);


void __stdcall ITypeLib2_GetAllCustData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __ITypeLib2_INTERFACE_DEFINED__ */


#ifndef __ITypeChangeEvents_INTERFACE_DEFINED__
#define __ITypeChangeEvents_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITypeChangeEvents
 * at Sat Jul 13 21:56:52 1996
 * using MIDL 3.00.39
 ****************************************/
/* [local][unique][uuid][object] */ 


typedef /* [unique] */ ITypeChangeEvents  *LPTYPECHANGEEVENTS;

typedef 
enum tagCHANGEKIND
    {	CHANGEKIND_ADDMEMBER	= 0,
	CHANGEKIND_DELETEMEMBER	= CHANGEKIND_ADDMEMBER + 1,
	CHANGEKIND_SETNAMES	= CHANGEKIND_DELETEMEMBER + 1,
	CHANGEKIND_SETDOCUMENTATION	= CHANGEKIND_SETNAMES + 1,
	CHANGEKIND_GENERAL	= CHANGEKIND_SETDOCUMENTATION + 1,
	CHANGEKIND_INVALIDATE	= CHANGEKIND_GENERAL + 1,
	CHANGEKIND_CHANGEFAILED	= CHANGEKIND_INVALIDATE + 1,
	CHANGEKIND_MAX	= CHANGEKIND_CHANGEFAILED + 1
    }	CHANGEKIND;


EXTERN_C const IID IID_ITypeChangeEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ITypeChangeEvents : public IUnknown
    {
    public:
        virtual HRESULT __stdcall RequestTypeChange( 
            /* [in] */ CHANGEKIND changeKind,
            /* [in] */ ITypeInfo  *pTInfoBefore,
            /* [in] */ LPOLESTR pStrName,
            /* [out] */ int  *pfCancel) = 0;
        
        virtual HRESULT __stdcall AfterTypeChange( 
            /* [in] */ CHANGEKIND changeKind,
            /* [in] */ ITypeInfo  *pTInfoAfter,
            /* [in] */ LPOLESTR pStrName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITypeChangeEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            ITypeChangeEvents  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            ITypeChangeEvents  * This);
        
        unsigned long ( __stdcall  *Release )( 
            ITypeChangeEvents  * This);
        
        HRESULT ( __stdcall  *RequestTypeChange )( 
            ITypeChangeEvents  * This,
            /* [in] */ CHANGEKIND changeKind,
            /* [in] */ ITypeInfo  *pTInfoBefore,
            /* [in] */ LPOLESTR pStrName,
            /* [out] */ int  *pfCancel);
        
        HRESULT ( __stdcall  *AfterTypeChange )( 
            ITypeChangeEvents  * This,
            /* [in] */ CHANGEKIND changeKind,
            /* [in] */ ITypeInfo  *pTInfoAfter,
            /* [in] */ LPOLESTR pStrName);
        
        END_INTERFACE
    } ITypeChangeEventsVtbl;

    interface ITypeChangeEvents
    {
        CONST_VTBL struct ITypeChangeEventsVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITypeChangeEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITypeChangeEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITypeChangeEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITypeChangeEvents_RequestTypeChange(This,changeKind,pTInfoBefore,pStrName,pfCancel)	\
    (This)->lpVtbl -> RequestTypeChange(This,changeKind,pTInfoBefore,pStrName,pfCancel)

#define ITypeChangeEvents_AfterTypeChange(This,changeKind,pTInfoAfter,pStrName)	\
    (This)->lpVtbl -> AfterTypeChange(This,changeKind,pTInfoAfter,pStrName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall ITypeChangeEvents_RequestTypeChange_Proxy( 
    ITypeChangeEvents  * This,
    /* [in] */ CHANGEKIND changeKind,
    /* [in] */ ITypeInfo  *pTInfoBefore,
    /* [in] */ LPOLESTR pStrName,
    /* [out] */ int  *pfCancel);


void __stdcall ITypeChangeEvents_RequestTypeChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ITypeChangeEvents_AfterTypeChange_Proxy( 
    ITypeChangeEvents  * This,
    /* [in] */ CHANGEKIND changeKind,
    /* [in] */ ITypeInfo  *pTInfoAfter,
    /* [in] */ LPOLESTR pStrName);


void __stdcall ITypeChangeEvents_AfterTypeChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __ITypeChangeEvents_INTERFACE_DEFINED__ */


#ifndef __IErrorInfo_INTERFACE_DEFINED__
#define __IErrorInfo_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IErrorInfo
 * at Sat Jul 13 21:56:52 1996
 * using MIDL 3.00.39
 ****************************************/
/* [local][unique][uuid][object] */ 


typedef /* [unique] */ IErrorInfo  *LPERRORINFO;


EXTERN_C const IID IID_IErrorInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IErrorInfo : public IUnknown
    {
    public:
        virtual HRESULT __stdcall GetGUID( 
            /* [out] */ GUID  *pGUID) = 0;
        
        virtual HRESULT __stdcall GetSource( 
            /* [out] */ BSTR  *pBstrSource) = 0;
        
        virtual HRESULT __stdcall GetDescription( 
            /* [out] */ BSTR  *pBstrDescription) = 0;
        
        virtual HRESULT __stdcall GetHelpFile( 
            /* [out] */ BSTR  *pBstrHelpFile) = 0;
        
        virtual HRESULT __stdcall GetHelpContext( 
            /* [out] */ unsigned long  *pdwHelpContext) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IErrorInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IErrorInfo  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IErrorInfo  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IErrorInfo  * This);
        
        HRESULT ( __stdcall  *GetGUID )( 
            IErrorInfo  * This,
            /* [out] */ GUID  *pGUID);
        
        HRESULT ( __stdcall  *GetSource )( 
            IErrorInfo  * This,
            /* [out] */ BSTR  *pBstrSource);
        
        HRESULT ( __stdcall  *GetDescription )( 
            IErrorInfo  * This,
            /* [out] */ BSTR  *pBstrDescription);
        
        HRESULT ( __stdcall  *GetHelpFile )( 
            IErrorInfo  * This,
            /* [out] */ BSTR  *pBstrHelpFile);
        
        HRESULT ( __stdcall  *GetHelpContext )( 
            IErrorInfo  * This,
            /* [out] */ unsigned long  *pdwHelpContext);
        
        END_INTERFACE
    } IErrorInfoVtbl;

    interface IErrorInfo
    {
        CONST_VTBL struct IErrorInfoVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IErrorInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IErrorInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IErrorInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IErrorInfo_GetGUID(This,pGUID)	\
    (This)->lpVtbl -> GetGUID(This,pGUID)

#define IErrorInfo_GetSource(This,pBstrSource)	\
    (This)->lpVtbl -> GetSource(This,pBstrSource)

#define IErrorInfo_GetDescription(This,pBstrDescription)	\
    (This)->lpVtbl -> GetDescription(This,pBstrDescription)

#define IErrorInfo_GetHelpFile(This,pBstrHelpFile)	\
    (This)->lpVtbl -> GetHelpFile(This,pBstrHelpFile)

#define IErrorInfo_GetHelpContext(This,pdwHelpContext)	\
    (This)->lpVtbl -> GetHelpContext(This,pdwHelpContext)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IErrorInfo_GetGUID_Proxy( 
    IErrorInfo  * This,
    /* [out] */ GUID  *pGUID);


void __stdcall IErrorInfo_GetGUID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IErrorInfo_GetSource_Proxy( 
    IErrorInfo  * This,
    /* [out] */ BSTR  *pBstrSource);


void __stdcall IErrorInfo_GetSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IErrorInfo_GetDescription_Proxy( 
    IErrorInfo  * This,
    /* [out] */ BSTR  *pBstrDescription);


void __stdcall IErrorInfo_GetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IErrorInfo_GetHelpFile_Proxy( 
    IErrorInfo  * This,
    /* [out] */ BSTR  *pBstrHelpFile);


void __stdcall IErrorInfo_GetHelpFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IErrorInfo_GetHelpContext_Proxy( 
    IErrorInfo  * This,
    /* [out] */ unsigned long  *pdwHelpContext);


void __stdcall IErrorInfo_GetHelpContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IErrorInfo_INTERFACE_DEFINED__ */


#ifndef __ICreateErrorInfo_INTERFACE_DEFINED__
#define __ICreateErrorInfo_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ICreateErrorInfo
 * at Sat Jul 13 21:56:52 1996
 * using MIDL 3.00.39
 ****************************************/
/* [local][unique][uuid][object] */ 


typedef /* [unique] */ ICreateErrorInfo  *LPCREATEERRORINFO;


EXTERN_C const IID IID_ICreateErrorInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ICreateErrorInfo : public IUnknown
    {
    public:
        virtual HRESULT __stdcall SetGUID( 
            /* [in] */ REFGUID rguid) = 0;
        
        virtual HRESULT __stdcall SetSource( 
            /* [in] */ LPOLESTR szSource) = 0;
        
        virtual HRESULT __stdcall SetDescription( 
            /* [in] */ LPOLESTR szDescription) = 0;
        
        virtual HRESULT __stdcall SetHelpFile( 
            /* [in] */ LPOLESTR szHelpFile) = 0;
        
        virtual HRESULT __stdcall SetHelpContext( 
            /* [in] */ unsigned long dwHelpContext) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICreateErrorInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            ICreateErrorInfo  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            ICreateErrorInfo  * This);
        
        unsigned long ( __stdcall  *Release )( 
            ICreateErrorInfo  * This);
        
        HRESULT ( __stdcall  *SetGUID )( 
            ICreateErrorInfo  * This,
            /* [in] */ REFGUID rguid);
        
        HRESULT ( __stdcall  *SetSource )( 
            ICreateErrorInfo  * This,
            /* [in] */ LPOLESTR szSource);
        
        HRESULT ( __stdcall  *SetDescription )( 
            ICreateErrorInfo  * This,
            /* [in] */ LPOLESTR szDescription);
        
        HRESULT ( __stdcall  *SetHelpFile )( 
            ICreateErrorInfo  * This,
            /* [in] */ LPOLESTR szHelpFile);
        
        HRESULT ( __stdcall  *SetHelpContext )( 
            ICreateErrorInfo  * This,
            /* [in] */ unsigned long dwHelpContext);
        
        END_INTERFACE
    } ICreateErrorInfoVtbl;

    interface ICreateErrorInfo
    {
        CONST_VTBL struct ICreateErrorInfoVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICreateErrorInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICreateErrorInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICreateErrorInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICreateErrorInfo_SetGUID(This,rguid)	\
    (This)->lpVtbl -> SetGUID(This,rguid)

#define ICreateErrorInfo_SetSource(This,szSource)	\
    (This)->lpVtbl -> SetSource(This,szSource)

#define ICreateErrorInfo_SetDescription(This,szDescription)	\
    (This)->lpVtbl -> SetDescription(This,szDescription)

#define ICreateErrorInfo_SetHelpFile(This,szHelpFile)	\
    (This)->lpVtbl -> SetHelpFile(This,szHelpFile)

#define ICreateErrorInfo_SetHelpContext(This,dwHelpContext)	\
    (This)->lpVtbl -> SetHelpContext(This,dwHelpContext)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall ICreateErrorInfo_SetGUID_Proxy( 
    ICreateErrorInfo  * This,
    /* [in] */ REFGUID rguid);


void __stdcall ICreateErrorInfo_SetGUID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateErrorInfo_SetSource_Proxy( 
    ICreateErrorInfo  * This,
    /* [in] */ LPOLESTR szSource);


void __stdcall ICreateErrorInfo_SetSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateErrorInfo_SetDescription_Proxy( 
    ICreateErrorInfo  * This,
    /* [in] */ LPOLESTR szDescription);


void __stdcall ICreateErrorInfo_SetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateErrorInfo_SetHelpFile_Proxy( 
    ICreateErrorInfo  * This,
    /* [in] */ LPOLESTR szHelpFile);


void __stdcall ICreateErrorInfo_SetHelpFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICreateErrorInfo_SetHelpContext_Proxy( 
    ICreateErrorInfo  * This,
    /* [in] */ unsigned long dwHelpContext);


void __stdcall ICreateErrorInfo_SetHelpContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __ICreateErrorInfo_INTERFACE_DEFINED__ */


#ifndef __ISupportErrorInfo_INTERFACE_DEFINED__
#define __ISupportErrorInfo_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ISupportErrorInfo
 * at Sat Jul 13 21:56:52 1996
 * using MIDL 3.00.39
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ ISupportErrorInfo  *LPSUPPORTERRORINFO;


EXTERN_C const IID IID_ISupportErrorInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ISupportErrorInfo : public IUnknown
    {
    public:
        virtual HRESULT __stdcall InterfaceSupportsErrorInfo( 
            /* [in] */ REFIID riid) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISupportErrorInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            ISupportErrorInfo  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            ISupportErrorInfo  * This);
        
        unsigned long ( __stdcall  *Release )( 
            ISupportErrorInfo  * This);
        
        HRESULT ( __stdcall  *InterfaceSupportsErrorInfo )( 
            ISupportErrorInfo  * This,
            /* [in] */ REFIID riid);
        
        END_INTERFACE
    } ISupportErrorInfoVtbl;

    interface ISupportErrorInfo
    {
        CONST_VTBL struct ISupportErrorInfoVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISupportErrorInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISupportErrorInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISupportErrorInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISupportErrorInfo_InterfaceSupportsErrorInfo(This,riid)	\
    (This)->lpVtbl -> InterfaceSupportsErrorInfo(This,riid)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall ISupportErrorInfo_InterfaceSupportsErrorInfo_Proxy( 
    ISupportErrorInfo  * This,
    /* [in] */ REFIID riid);


void __stdcall ISupportErrorInfo_InterfaceSupportsErrorInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __ISupportErrorInfo_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __stdcall  BSTR_UserSize(     unsigned long  *, unsigned long            , BSTR  * ); 
unsigned char  * __stdcall  BSTR_UserMarshal(  unsigned long  *, unsigned char  *, BSTR  * ); 
unsigned char  * __stdcall  BSTR_UserUnmarshal(unsigned long  *, unsigned char  *, BSTR  * ); 
void                      __stdcall  BSTR_UserFree(     unsigned long  *, BSTR  * ); 

unsigned long             __stdcall  CLEANLOCALSTORAGE_UserSize(     unsigned long  *, unsigned long            , CLEANLOCALSTORAGE  * ); 
unsigned char  * __stdcall  CLEANLOCALSTORAGE_UserMarshal(  unsigned long  *, unsigned char  *, CLEANLOCALSTORAGE  * ); 
unsigned char  * __stdcall  CLEANLOCALSTORAGE_UserUnmarshal(unsigned long  *, unsigned char  *, CLEANLOCALSTORAGE  * ); 
void                      __stdcall  CLEANLOCALSTORAGE_UserFree(     unsigned long  *, CLEANLOCALSTORAGE  * ); 

unsigned long             __stdcall  VARIANT_UserSize(     unsigned long  *, unsigned long            , VARIANT  * ); 
unsigned char  * __stdcall  VARIANT_UserMarshal(  unsigned long  *, unsigned char  *, VARIANT  * ); 
unsigned char  * __stdcall  VARIANT_UserUnmarshal(unsigned long  *, unsigned char  *, VARIANT  * ); 
void                      __stdcall  VARIANT_UserFree(     unsigned long  *, VARIANT  * ); 

/* [local] */ HRESULT __stdcall IDispatch_Invoke_Proxy( 
    IDispatch  * This,
    /* [in] */ DISPID dispIdMember,
    /* [in] */ REFIID riid,
    /* [in] */ LCID lcid,
    /* [in] */ WORD wFlags,
    /* [out][in] */ DISPPARAMS  *pDispParams,
    /* [out] */ VARIANT  *pVarResult,
    /* [out] */ EXCEPINFO  *pExcepInfo,
    /* [out] */ unsigned  *puArgErr);


/* [call_as] */ HRESULT __stdcall IDispatch_Invoke_Stub( 
    IDispatch  * This,
    /* [in] */ DISPID dispIdMember,
    /* [in] */ REFIID riid,
    /* [in] */ LCID lcid,
    /* [in] */ unsigned long dwFlags,
    /* [in] */ DISPPARAMS  *pDispParams,
    /* [out] */ VARIANT  *pVarResult,
    /* [out] */ EXCEPINFO  *pExcepInfo,
    /* [out] */ unsigned  *pArgErr,
    /* [in] */ unsigned cVarRef,
    /* [size_is][in] */ unsigned  *rgVarRefIdx,
    /* [size_is][out][in] */ VARIANTARG  *rgVarRef);

/* [local] */ HRESULT __stdcall IEnumVARIANT_Next_Proxy( 
    IEnumVARIANT  * This,
    /* [in] */ unsigned long celt,
    /* [length_is][size_is][out] */ VARIANT  *rgVar,
    /* [out] */ unsigned long  *pCeltFetched);


/* [call_as] */ HRESULT __stdcall IEnumVARIANT_Next_Stub( 
    IEnumVARIANT  * This,
    /* [in] */ unsigned long celt,
    /* [length_is][size_is][out] */ VARIANT  *rgVar,
    /* [out] */ unsigned long  *pCeltFetched);

/* [local] */ HRESULT __stdcall ITypeComp_Bind_Proxy( 
    ITypeComp  * This,
    /* [in] */ LPOLESTR szName,
    /* [in] */ unsigned long lHashVal,
    /* [in] */ WORD wFlags,
    /* [out] */ ITypeInfo  * *ppTInfo,
    /* [out] */ DESCKIND  *pDescKind,
    /* [out] */ BINDPTR  *pBindPtr);


/* [call_as] */ HRESULT __stdcall ITypeComp_Bind_Stub( 
    ITypeComp  * This,
    /* [in] */ LPOLESTR szName,
    /* [in] */ unsigned long lHashVal,
    /* [in] */ WORD wFlags,
    /* [out] */ ITypeInfo  * *ppTInfo,
    /* [out] */ DESCKIND  *pDescKind,
    /* [out] */ LPFUNCDESC  *ppFuncDesc,
    /* [out] */ LPVARDESC  *ppVarDesc,
    /* [out] */ ITypeComp  * *ppTypeComp,
    /* [out] */ CLEANLOCALSTORAGE  *pDummy);

/* [local] */ HRESULT __stdcall ITypeComp_BindType_Proxy( 
    ITypeComp  * This,
    /* [in] */ LPOLESTR szName,
    /* [in] */ unsigned long lHashVal,
    /* [out] */ ITypeInfo  * *ppTInfo,
    /* [out] */ ITypeComp  * *ppTComp);


/* [call_as] */ HRESULT __stdcall ITypeComp_BindType_Stub( 
    ITypeComp  * This,
    /* [in] */ LPOLESTR szName,
    /* [in] */ unsigned long lHashVal,
    /* [out] */ ITypeInfo  * *ppTInfo);

/* [local] */ HRESULT __stdcall ITypeInfo_GetTypeAttr_Proxy( 
    ITypeInfo  * This,
    /* [out] */ TYPEATTR  * *ppTypeAttr);


/* [call_as] */ HRESULT __stdcall ITypeInfo_GetTypeAttr_Stub( 
    ITypeInfo  * This,
    /* [out] */ LPTYPEATTR  *ppTypeAttr,
    /* [out] */ CLEANLOCALSTORAGE  *pDummy);

/* [local] */ HRESULT __stdcall ITypeInfo_GetFuncDesc_Proxy( 
    ITypeInfo  * This,
    /* [in] */ unsigned index,
    /* [out] */ FUNCDESC  * *ppFuncDesc);


/* [call_as] */ HRESULT __stdcall ITypeInfo_GetFuncDesc_Stub( 
    ITypeInfo  * This,
    /* [in] */ unsigned index,
    /* [out] */ LPFUNCDESC  *ppFuncDesc,
    /* [out] */ CLEANLOCALSTORAGE  *pDummy);

/* [local] */ HRESULT __stdcall ITypeInfo_GetVarDesc_Proxy( 
    ITypeInfo  * This,
    /* [in] */ unsigned index,
    /* [out] */ VARDESC  * *ppVarDesc);


/* [call_as] */ HRESULT __stdcall ITypeInfo_GetVarDesc_Stub( 
    ITypeInfo  * This,
    /* [in] */ unsigned index,
    /* [out] */ LPVARDESC  *ppVarDesc,
    /* [out] */ CLEANLOCALSTORAGE  *pDummy);

/* [local] */ HRESULT __stdcall ITypeInfo_GetNames_Proxy( 
    ITypeInfo  * This,
    /* [in] */ MEMBERID memid,
    /* [length_is][size_is][out] */ BSTR  *rgBstrNames,
    /* [in] */ unsigned cMaxNames,
    /* [out] */ unsigned  *pcNames);


/* [call_as] */ HRESULT __stdcall ITypeInfo_GetNames_Stub( 
    ITypeInfo  * This,
    /* [in] */ MEMBERID memid,
    /* [length_is][size_is][out] */ BSTR  *rgBstrNames,
    /* [in] */ unsigned cMaxNames,
    /* [out] */ unsigned  *pcNames);

/* [local] */ HRESULT __stdcall ITypeInfo_Invoke_Proxy( 
    ITypeInfo  * This,
    /* [in] */ void* pvInstance,
    /* [in] */ MEMBERID memid,
    /* [in] */ WORD wFlags,
    /* [out][in] */ DISPPARAMS  *pDispParams,
    /* [out] */ VARIANT  *pVarResult,
    /* [out] */ EXCEPINFO  *pExcepInfo,
    /* [out] */ unsigned  *puArgErr);


/* [call_as] */ HRESULT __stdcall ITypeInfo_Invoke_Stub( 
    ITypeInfo  * This,
    /* [in] */ IUnknown  *pIUnk,
    /* [in] */ MEMBERID memid,
    /* [in] */ unsigned long dwFlags,
    /* [in] */ DISPPARAMS  *pDispParams,
    /* [out] */ VARIANT  *pVarResult,
    /* [out] */ EXCEPINFO  *pExcepInfo,
    /* [out] */ unsigned  *pArgErr,
    /* [in] */ unsigned cVarRef,
    /* [size_is][in] */ unsigned  *rgVarRefIdx,
    /* [size_is][out][in] */ VARIANTARG  *rgVarRef);

/* [local] */ HRESULT __stdcall ITypeInfo_GetDocumentation_Proxy( 
    ITypeInfo  * This,
    /* [in] */ MEMBERID memid,
    /* [out] */ BSTR  *pBstrName,
    /* [out] */ BSTR  *pBstrDocString,
    /* [out] */ unsigned long  *pdwHelpContext,
    /* [out] */ BSTR  *pBstrHelpFile);


/* [call_as] */ HRESULT __stdcall ITypeInfo_GetDocumentation_Stub( 
    ITypeInfo  * This,
    /* [in] */ MEMBERID memid,
    /* [in] */ unsigned long refPtrFlags,
    /* [out] */ BSTR  *pBstrName,
    /* [out] */ BSTR  *pBstrDocString,
    /* [out] */ unsigned long  *pdwHelpContext,
    /* [out] */ BSTR  *pBstrHelpFile);

/* [local] */ HRESULT __stdcall ITypeInfo_GetDllEntry_Proxy( 
    ITypeInfo  * This,
    /* [in] */ MEMBERID memid,
    /* [in] */ INVOKEKIND invKind,
    /* [out] */ BSTR  *pBstrDllName,
    /* [out] */ BSTR  *pBstrName,
    /* [out] */ WORD  *pwOrdinal);


/* [call_as] */ HRESULT __stdcall ITypeInfo_GetDllEntry_Stub( 
    ITypeInfo  * This,
    /* [in] */ MEMBERID memid,
    /* [in] */ INVOKEKIND invKind,
    /* [in] */ unsigned long refPtrFlags,
    /* [out] */ BSTR  *pBstrDllName,
    /* [out] */ BSTR  *pBstrName,
    /* [out] */ WORD  *pwOrdinal);

/* [local] */ HRESULT __stdcall ITypeInfo_AddressOfMember_Proxy( 
    ITypeInfo  * This,
    /* [in] */ MEMBERID memid,
    /* [in] */ INVOKEKIND invKind,
    /* [out] */ void*  *ppv);


/* [nocode][call_as] */ HRESULT __stdcall ITypeInfo_AddressOfMember_Stub( 
    ITypeInfo  * This);

/* [local] */ HRESULT __stdcall ITypeInfo_CreateInstance_Proxy( 
    ITypeInfo  * This,
    /* [in] */ IUnknown  *pUnkOuter,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ void*  *ppvObj);


/* [call_as] */ HRESULT __stdcall ITypeInfo_CreateInstance_Stub( 
    ITypeInfo  * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown  * *ppvObj);

/* [local] */ HRESULT __stdcall ITypeInfo_GetContainingTypeLib_Proxy( 
    ITypeInfo  * This,
    /* [out] */ ITypeLib  * *ppTLib,
    /* [out] */ unsigned  *pIndex);


/* [call_as] */ HRESULT __stdcall ITypeInfo_GetContainingTypeLib_Stub( 
    ITypeInfo  * This,
    /* [out] */ ITypeLib  * *ppTLib,
    /* [out] */ unsigned  *pIndex);

/* [local] */ void __stdcall ITypeInfo_ReleaseTypeAttr_Proxy( 
    ITypeInfo  * This,
    /* [in] */ TYPEATTR  *pTypeAttr);


/* [nocode][call_as] */ HRESULT __stdcall ITypeInfo_ReleaseTypeAttr_Stub( 
    ITypeInfo  * This);

/* [local] */ void __stdcall ITypeInfo_ReleaseFuncDesc_Proxy( 
    ITypeInfo  * This,
    /* [in] */ FUNCDESC  *pFuncDesc);


/* [nocode][call_as] */ HRESULT __stdcall ITypeInfo_ReleaseFuncDesc_Stub( 
    ITypeInfo  * This);

/* [local] */ void __stdcall ITypeInfo_ReleaseVarDesc_Proxy( 
    ITypeInfo  * This,
    /* [in] */ VARDESC  *pVarDesc);


/* [nocode][call_as] */ HRESULT __stdcall ITypeInfo_ReleaseVarDesc_Stub( 
    ITypeInfo  * This);

/* [local] */ HRESULT __stdcall ITypeInfo2_GetDocumentation2_Proxy( 
    ITypeInfo2  * This,
    /* [in] */ MEMBERID memid,
    /* [in] */ LCID lcid,
    /* [out] */ BSTR  *pbstrHelpString,
    /* [out] */ unsigned long  *pdwHelpStringContext,
    /* [out] */ BSTR  *pbstrHelpStringDll);


/* [call_as] */ HRESULT __stdcall ITypeInfo2_GetDocumentation2_Stub( 
    ITypeInfo2  * This,
    /* [in] */ MEMBERID memid,
    /* [in] */ LCID lcid,
    /* [in] */ unsigned long refPtrFlags,
    /* [out] */ BSTR  *pbstrHelpString,
    /* [out] */ unsigned long  *pdwHelpStringContext,
    /* [out] */ BSTR  *pbstrHelpStringDll);

/* [local] */ unsigned __stdcall ITypeLib_GetTypeInfoCount_Proxy( 
    ITypeLib  * This);


/* [call_as] */ HRESULT __stdcall ITypeLib_GetTypeInfoCount_Stub( 
    ITypeLib  * This,
    /* [out] */ unsigned  *pcTInfo);

/* [local] */ HRESULT __stdcall ITypeLib_GetLibAttr_Proxy( 
    ITypeLib  * This,
    /* [out] */ TLIBATTR  * *ppTLibAttr);


/* [call_as] */ HRESULT __stdcall ITypeLib_GetLibAttr_Stub( 
    ITypeLib  * This,
    /* [out] */ LPTLIBATTR  *ppTLibAttr,
    /* [out] */ CLEANLOCALSTORAGE  *pDummy);

/* [local] */ HRESULT __stdcall ITypeLib_GetDocumentation_Proxy( 
    ITypeLib  * This,
    /* [in] */ int index,
    /* [out] */ BSTR  *pBstrName,
    /* [out] */ BSTR  *pBstrDocString,
    /* [out] */ unsigned long  *pdwHelpContext,
    /* [out] */ BSTR  *pBstrHelpFile);


/* [call_as] */ HRESULT __stdcall ITypeLib_GetDocumentation_Stub( 
    ITypeLib  * This,
    /* [in] */ int index,
    /* [in] */ unsigned long refPtrFlags,
    /* [out] */ BSTR  *pBstrName,
    /* [out] */ BSTR  *pBstrDocString,
    /* [out] */ unsigned long  *pdwHelpContext,
    /* [out] */ BSTR  *pBstrHelpFile);

/* [local] */ HRESULT __stdcall ITypeLib_IsName_Proxy( 
    ITypeLib  * This,
    /* [out][in] */ LPOLESTR szNameBuf,
    /* [in] */ unsigned long lHashVal,
    /* [out] */ BOOL  *pfName);


/* [call_as] */ HRESULT __stdcall ITypeLib_IsName_Stub( 
    ITypeLib  * This,
    /* [in] */ LPOLESTR szNameBuf,
    /* [in] */ unsigned long lHashVal,
    /* [out] */ BOOL  *pfName,
    /* [out] */ BSTR  *pBstrLibName);

/* [local] */ HRESULT __stdcall ITypeLib_FindName_Proxy( 
    ITypeLib  * This,
    /* [out][in] */ LPOLESTR szNameBuf,
    /* [in] */ unsigned long lHashVal,
    /* [length_is][size_is][out] */ ITypeInfo  * *ppTInfo,
    /* [length_is][size_is][out] */ MEMBERID  *rgMemId,
    /* [out][in] */ unsigned short  *pcFound);


/* [call_as] */ HRESULT __stdcall ITypeLib_FindName_Stub( 
    ITypeLib  * This,
    /* [in] */ LPOLESTR szNameBuf,
    /* [in] */ unsigned long lHashVal,
    /* [length_is][size_is][out] */ ITypeInfo  * *ppTInfo,
    /* [length_is][size_is][out] */ MEMBERID  *rgMemId,
    /* [out][in] */ unsigned short  *pcFound,
    /* [out] */ BSTR  *pBstrLibName);

/* [local] */ void __stdcall ITypeLib_ReleaseTLibAttr_Proxy( 
    ITypeLib  * This,
    /* [in] */ TLIBATTR  *pTLibAttr);


/* [nocode][call_as] */ HRESULT __stdcall ITypeLib_ReleaseTLibAttr_Stub( 
    ITypeLib  * This);

/* [local] */ HRESULT __stdcall ITypeLib2_GetLibStatistics_Proxy( 
    ITypeLib2  * This,
    /* [out] */ unsigned long  *pcUniqueNames,
    /* [out] */ unsigned long  *pcchUniqueNames);


/* [call_as] */ HRESULT __stdcall ITypeLib2_GetLibStatistics_Stub( 
    ITypeLib2  * This,
    /* [out] */ unsigned long  *pcUniqueNames,
    /* [out] */ unsigned long  *pcchUniqueNames);

/* [local] */ HRESULT __stdcall ITypeLib2_GetDocumentation2_Proxy( 
    ITypeLib2  * This,
    /* [in] */ int index,
    /* [in] */ LCID lcid,
    /* [out] */ BSTR  *pbstrHelpString,
    /* [out] */ unsigned long  *pdwHelpStringContext,
    /* [out] */ BSTR  *pbstrHelpStringDll);


/* [call_as] */ HRESULT __stdcall ITypeLib2_GetDocumentation2_Stub( 
    ITypeLib2  * This,
    /* [in] */ int index,
    /* [in] */ LCID lcid,
    /* [in] */ unsigned long refPtrFlags,
    /* [out] */ BSTR  *pbstrHelpString,
    /* [out] */ unsigned long  *pdwHelpStringContext,
    /* [out] */ BSTR  *pbstrHelpStringDll);



/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
