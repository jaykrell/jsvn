/*++

Copyright (c) 1992-1996 Microsoft Corporation

Module Name:

    rpcnsi.h

Abstract:

    This file contains the types and function definitions to use the
    Name Service Independent APIs.

--*/

#ifndef __RPCNSI_H__
#define __RPCNSI_H__

typedef void  * RPC_NS_HANDLE;

#define RPC_C_NS_SYNTAX_DEFAULT 0
#define RPC_C_NS_SYNTAX_DCE 3

#define RPC_C_PROFILE_DEFAULT_ELT 0
#define RPC_C_PROFILE_ALL_ELT 1
#define RPC_C_PROFILE_MATCH_BY_IF 2
#define RPC_C_PROFILE_MATCH_BY_MBR 3
#define RPC_C_PROFILE_MATCH_BY_BOTH 4

#define RPC_C_NS_DEFAULT_EXP_AGE -1

/* Server APIs */

RPC_STATUS __stdcall
RpcNsBindingExportA(
    IN unsigned long EntryNameSyntax OPTIONAL,
    IN unsigned char  * EntryName,
    IN RPC_IF_HANDLE IfSpec OPTIONAL,
    IN RPC_BINDING_VECTOR  * BindingVec OPTIONAL,
    IN UUID_VECTOR  * ObjectUuidVec OPTIONAL
    );


RPC_STATUS __stdcall
RpcNsBindingUnexportA(
    IN unsigned long EntryNameSyntax OPTIONAL,
    IN unsigned char  * EntryName,
    IN RPC_IF_HANDLE IfSpec OPTIONAL,
    IN UUID_VECTOR  * ObjectUuidVec OPTIONAL
    );

#ifdef RPC_UNICODE_SUPPORTED

RPC_STATUS __stdcall
RpcNsBindingExportW(
    IN unsigned long EntryNameSyntax OPTIONAL,
    IN unsigned short  * EntryName,
    IN RPC_IF_HANDLE IfSpec OPTIONAL,
    IN RPC_BINDING_VECTOR  * BindingVec OPTIONAL,
    IN UUID_VECTOR  * ObjectUuidVec OPTIONAL
    );

RPC_STATUS __stdcall
RpcNsBindingUnexportW(
    IN unsigned long EntryNameSyntax OPTIONAL,
    IN unsigned short  * EntryName,
    IN RPC_IF_HANDLE IfSpec OPTIONAL,
    IN UUID_VECTOR  * ObjectUuidVec OPTIONAL
    );

#endif

/* Client APIs */

RPC_STATUS __stdcall
RpcNsBindingLookupBeginA(
    IN unsigned long EntryNameSyntax OPTIONAL,
    IN unsigned char  * EntryName OPTIONAL,
    IN RPC_IF_HANDLE IfSpec OPTIONAL,
    IN UUID  * ObjUuid OPTIONAL,
    IN unsigned long BindingMaxCount OPTIONAL,
    OUT RPC_NS_HANDLE  * LookupContext
    );

#ifdef RPC_UNICODE_SUPPORTED

RPC_STATUS __stdcall
RpcNsBindingLookupBeginW(
    IN unsigned long EntryNameSyntax OPTIONAL,
    IN unsigned short  * EntryName OPTIONAL,
    IN RPC_IF_HANDLE IfSpec OPTIONAL,
    IN UUID  * ObjUuid OPTIONAL,
    IN unsigned long BindingMaxCount OPTIONAL,
    OUT RPC_NS_HANDLE  * LookupContext
    );
#endif

RPC_STATUS __stdcall
RpcNsBindingLookupNext(
    IN  RPC_NS_HANDLE LookupContext,
    OUT RPC_BINDING_VECTOR  *  * BindingVec
    );

RPC_STATUS __stdcall
RpcNsBindingLookupDone(
    IN OUT RPC_NS_HANDLE  * LookupContext
    );

/* Group APIs */

RPC_STATUS __stdcall
RpcNsGroupDeleteA(
    IN unsigned long GroupNameSyntax OPTIONAL,
    IN unsigned char  * GroupName
    );

RPC_STATUS __stdcall
RpcNsGroupMbrAddA(
    IN unsigned long GroupNameSyntax OPTIONAL,
    IN unsigned char  * GroupName,
    IN unsigned long MemberNameSyntax OPTIONAL,
    IN unsigned char  * MemberName
    );

RPC_STATUS __stdcall
RpcNsGroupMbrRemoveA(
    IN unsigned long GroupNameSyntax OPTIONAL,
    IN unsigned char  * GroupName,
    IN unsigned long MemberNameSyntax OPTIONAL,
    IN unsigned char  * MemberName
    );

RPC_STATUS __stdcall
RpcNsGroupMbrInqBeginA(
    IN unsigned long GroupNameSyntax OPTIONAL,
    IN unsigned char  * GroupName,
    IN unsigned long MemberNameSyntax OPTIONAL,
    OUT RPC_NS_HANDLE  * InquiryContext
    );

RPC_STATUS __stdcall
RpcNsGroupMbrInqNextA(
    IN  RPC_NS_HANDLE InquiryContext,
    OUT unsigned char  *  * MemberName
    );

#ifdef RPC_UNICODE_SUPPORTED

RPC_STATUS __stdcall
RpcNsGroupDeleteW(
    IN unsigned long GroupNameSyntax OPTIONAL,
    IN unsigned short  * GroupName
    );

RPC_STATUS __stdcall
RpcNsGroupMbrAddW(
    IN unsigned long GroupNameSyntax OPTIONAL,
    IN unsigned short  * GroupName,
    IN unsigned long MemberNameSyntax OPTIONAL,
    IN unsigned short  * MemberName
    );

RPC_STATUS __stdcall
RpcNsGroupMbrRemoveW(
    IN unsigned long GroupNameSyntax OPTIONAL,
    IN unsigned short  * GroupName,
    IN unsigned long MemberNameSyntax OPTIONAL,
    IN unsigned short  * MemberName
    );

RPC_STATUS __stdcall
RpcNsGroupMbrInqBeginW(
    IN unsigned long GroupNameSyntax OPTIONAL,
    IN unsigned short  * GroupName,
    IN unsigned long MemberNameSyntax OPTIONAL,
    OUT RPC_NS_HANDLE  * InquiryContext
    );

RPC_STATUS __stdcall
RpcNsGroupMbrInqNextW(
    IN  RPC_NS_HANDLE InquiryContext,
    OUT unsigned short  *  * MemberName
    );

#endif

RPC_STATUS __stdcall
RpcNsGroupMbrInqDone(
    IN OUT RPC_NS_HANDLE  * InquiryContext
    );

/* Profile APIs */

RPC_STATUS __stdcall
RpcNsProfileDeleteA(
    IN unsigned long ProfileNameSyntax OPTIONAL,
    IN unsigned char  * ProfileName
    );

RPC_STATUS __stdcall
RpcNsProfileEltAddA(
    IN unsigned long ProfileNameSyntax OPTIONAL,
    IN unsigned char  * ProfileName,
    IN RPC_IF_ID  * IfId OPTIONAL,
    IN unsigned long MemberNameSyntax OPTIONAL,
    IN unsigned char  * MemberName,
    IN unsigned long Priority,
    IN unsigned char  * Annotation OPTIONAL
    );

RPC_STATUS __stdcall
RpcNsProfileEltRemoveA(
    IN unsigned long ProfileNameSyntax OPTIONAL,
    IN unsigned char  * ProfileName,
    IN RPC_IF_ID  * IfId OPTIONAL,
    IN unsigned long MemberNameSyntax OPTIONAL,
    IN unsigned char  * MemberName
    );

RPC_STATUS __stdcall
RpcNsProfileEltInqBeginA(
    IN unsigned long ProfileNameSyntax OPTIONAL,
    IN unsigned char  * ProfileName,
    IN unsigned long InquiryType,
    IN RPC_IF_ID  * IfId OPTIONAL,
    IN unsigned long VersOption,
    IN unsigned long MemberNameSyntax OPTIONAL,
    IN unsigned char  * MemberName OPTIONAL,
    OUT RPC_NS_HANDLE  * InquiryContext
    );

RPC_STATUS __stdcall
RpcNsProfileEltInqNextA(
    IN RPC_NS_HANDLE InquiryContext,
    OUT RPC_IF_ID  * IfId,
    OUT unsigned char  *  * MemberName,
    OUT unsigned long  * Priority,
    OUT unsigned char  *  * Annotation
    );

#ifdef RPC_UNICODE_SUPPORTED

RPC_STATUS __stdcall
RpcNsProfileDeleteW(
    IN unsigned long ProfileNameSyntax OPTIONAL,
    IN unsigned short  * ProfileName
    );

RPC_STATUS __stdcall
RpcNsProfileEltAddW(
    IN unsigned long ProfileNameSyntax OPTIONAL,
    IN unsigned short  * ProfileName,
    IN RPC_IF_ID  * IfId OPTIONAL,
    IN unsigned long MemberNameSyntax OPTIONAL,
    IN unsigned short  * MemberName,
    IN unsigned long Priority,
    IN unsigned short  * Annotation OPTIONAL
    );

RPC_STATUS __stdcall
RpcNsProfileEltRemoveW(
    IN unsigned long ProfileNameSyntax OPTIONAL,
    IN unsigned short  * ProfileName,
    IN RPC_IF_ID  * IfId OPTIONAL,
    IN unsigned long MemberNameSyntax OPTIONAL,
    IN unsigned short  * MemberName
    );

RPC_STATUS __stdcall
RpcNsProfileEltInqBeginW(
    IN unsigned long ProfileNameSyntax OPTIONAL,
    IN unsigned short  * ProfileName,
    IN unsigned long InquiryType,
    IN RPC_IF_ID  * IfId OPTIONAL,
    IN unsigned long VersOption,
    IN unsigned long MemberNameSyntax OPTIONAL,
    IN unsigned short  * MemberName OPTIONAL,
    OUT RPC_NS_HANDLE  * InquiryContext
    );

RPC_STATUS __stdcall
RpcNsProfileEltInqNextW(
    IN RPC_NS_HANDLE InquiryContext,
    OUT RPC_IF_ID  * IfId,
    OUT unsigned short  *  * MemberName,
    OUT unsigned long  * Priority,
    OUT unsigned short  *  * Annotation
    );

#endif

RPC_STATUS __stdcall
RpcNsProfileEltInqDone(
    IN OUT RPC_NS_HANDLE  * InquiryContext
    );

/* Entry object APIs */

RPC_STATUS __stdcall
RpcNsEntryObjectInqBeginA(
    IN unsigned long EntryNameSyntax OPTIONAL,
    IN unsigned char  * EntryName,
    OUT RPC_NS_HANDLE  * InquiryContext
    );

#ifdef RPC_UNICODE_SUPPORTED

RPC_STATUS __stdcall
RpcNsEntryObjectInqBeginW(
    IN unsigned long EntryNameSyntax OPTIONAL,
    IN unsigned short  * EntryName,
    OUT RPC_NS_HANDLE  * InquiryContext
    );

#endif

RPC_STATUS __stdcall
RpcNsEntryObjectInqNext(
    IN  RPC_NS_HANDLE InquiryContext,
    OUT UUID  * ObjUuid
    );

RPC_STATUS __stdcall
RpcNsEntryObjectInqDone(
    IN OUT RPC_NS_HANDLE  * InquiryContext
    );

/* Management and MISC APIs */

RPC_STATUS __stdcall
RpcNsEntryExpandNameA(
    IN unsigned long EntryNameSyntax OPTIONAL,
    IN unsigned char  * EntryName,
    OUT unsigned char  *  * ExpandedName
    );

RPC_STATUS __stdcall
RpcNsMgmtBindingUnexportA(
    IN unsigned long EntryNameSyntax OPTIONAL,
    IN unsigned char  * EntryName,
    IN RPC_IF_ID  * IfId OPTIONAL,
    IN unsigned long VersOption,
    IN UUID_VECTOR  * ObjectUuidVec OPTIONAL
    );

RPC_STATUS __stdcall
RpcNsMgmtEntryCreateA(
    IN unsigned long EntryNameSyntax OPTIONAL,
    IN unsigned char  * EntryName
    );

RPC_STATUS __stdcall
RpcNsMgmtEntryDeleteA(
    IN unsigned long EntryNameSyntax OPTIONAL,
    IN unsigned char  * EntryName
    );

RPC_STATUS __stdcall
RpcNsMgmtEntryInqIfIdsA(
    IN unsigned long EntryNameSyntax OPTIONAL,
    IN unsigned char  * EntryName,
    OUT RPC_IF_ID_VECTOR  *  * IfIdVec
    );

RPC_STATUS __stdcall
RpcNsMgmtHandleSetExpAge(
    IN RPC_NS_HANDLE NsHandle,
    IN unsigned long ExpirationAge
    );

RPC_STATUS __stdcall
RpcNsMgmtInqExpAge(
    OUT unsigned long  * ExpirationAge
    );

RPC_STATUS __stdcall
RpcNsMgmtSetExpAge(
    IN unsigned long ExpirationAge
    );

#ifdef RPC_UNICODE_SUPPORTED

RPC_STATUS __stdcall
RpcNsEntryExpandNameW(
    IN unsigned long EntryNameSyntax OPTIONAL,
    IN unsigned short  * EntryName,
    OUT unsigned short  *  * ExpandedName
    );

RPC_STATUS __stdcall
RpcNsMgmtBindingUnexportW(
    IN unsigned long EntryNameSyntax OPTIONAL,
    IN unsigned short  * EntryName,
    IN RPC_IF_ID  * IfId OPTIONAL,
    IN unsigned long VersOption,
    IN UUID_VECTOR  * ObjectUuidVec OPTIONAL
    );

RPC_STATUS __stdcall
RpcNsMgmtEntryCreateW(
    IN unsigned long EntryNameSyntax OPTIONAL,
    IN unsigned short  * EntryName
    );

RPC_STATUS __stdcall
RpcNsMgmtEntryDeleteW(
    IN unsigned long EntryNameSyntax OPTIONAL,
    IN unsigned short  * EntryName
    );

RPC_STATUS __stdcall
RpcNsMgmtEntryInqIfIdsW(
    IN unsigned long EntryNameSyntax OPTIONAL,
    IN unsigned short  * EntryName,
    OUT RPC_IF_ID_VECTOR  *  * IfIdVec
    );

#endif

/* Client API's implemented in wrappers. */

RPC_STATUS __stdcall
RpcNsBindingImportBeginA(
    IN unsigned long EntryNameSyntax OPTIONAL,
    IN unsigned char  * EntryName OPTIONAL,
    IN RPC_IF_HANDLE IfSpec OPTIONAL,
    IN UUID  * ObjUuid OPTIONAL,
    OUT RPC_NS_HANDLE  * ImportContext
    );

#ifdef RPC_UNICODE_SUPPORTED

RPC_STATUS __stdcall
RpcNsBindingImportBeginW(
    IN unsigned long EntryNameSyntax OPTIONAL,
    IN unsigned short  * EntryName OPTIONAL,
    IN RPC_IF_HANDLE IfSpec OPTIONAL,
    IN UUID  * ObjUuid OPTIONAL,
    OUT RPC_NS_HANDLE  * ImportContext
    );

#endif

RPC_STATUS __stdcall
RpcNsBindingImportNext(
    IN RPC_NS_HANDLE ImportContext,
    OUT RPC_BINDING_HANDLE   * Binding
    );

RPC_STATUS __stdcall
RpcNsBindingImportDone(
    IN OUT RPC_NS_HANDLE  * ImportContext
    );

RPC_STATUS __stdcall
RpcNsBindingSelect(
    IN OUT RPC_BINDING_VECTOR  * BindingVec,
    OUT RPC_BINDING_HANDLE   * Binding
    );

#ifdef UNICODE

#define RpcNsBindingLookupBegin RpcNsBindingLookupBeginW
#define RpcNsBindingImportBegin RpcNsBindingImportBeginW
#define RpcNsBindingExport RpcNsBindingExportW
#define RpcNsBindingUnexport RpcNsBindingUnexportW
#define RpcNsGroupDelete RpcNsGroupDeleteW
#define RpcNsGroupMbrAdd RpcNsGroupMbrAddW
#define RpcNsGroupMbrRemove RpcNsGroupMbrRemoveW
#define RpcNsGroupMbrInqBegin RpcNsGroupMbrInqBeginW
#define RpcNsGroupMbrInqNext RpcNsGroupMbrInqNextW
#define RpcNsEntryExpandName RpcNsEntryExpandNameW
#define RpcNsEntryObjectInqBegin RpcNsEntryObjectInqBeginW
#define RpcNsMgmtBindingUnexport RpcNsMgmtBindingUnexportW
#define RpcNsMgmtEntryCreate RpcNsMgmtEntryCreateW
#define RpcNsMgmtEntryDelete RpcNsMgmtEntryDeleteW
#define RpcNsMgmtEntryInqIfIds RpcNsMgmtEntryInqIfIdsW
#define RpcNsProfileDelete RpcNsProfileDeleteW
#define RpcNsProfileEltAdd RpcNsProfileEltAddW
#define RpcNsProfileEltRemove RpcNsProfileEltRemoveW
#define RpcNsProfileEltInqBegin RpcNsProfileEltInqBeginW
#define RpcNsProfileEltInqNext RpcNsProfileEltInqNextW

#else

#define RpcNsBindingLookupBegin RpcNsBindingLookupBeginA
#define RpcNsBindingImportBegin RpcNsBindingImportBeginA
#define RpcNsBindingExport RpcNsBindingExportA
#define RpcNsBindingUnexport RpcNsBindingUnexportA
#define RpcNsGroupDelete RpcNsGroupDeleteA
#define RpcNsGroupMbrAdd RpcNsGroupMbrAddA
#define RpcNsGroupMbrRemove RpcNsGroupMbrRemoveA
#define RpcNsGroupMbrInqBegin RpcNsGroupMbrInqBeginA
#define RpcNsGroupMbrInqNext RpcNsGroupMbrInqNextA
#define RpcNsEntryExpandName RpcNsEntryExpandNameA
#define RpcNsEntryObjectInqBegin RpcNsEntryObjectInqBeginA
#define RpcNsMgmtBindingUnexport RpcNsMgmtBindingUnexportA
#define RpcNsMgmtEntryCreate RpcNsMgmtEntryCreateA
#define RpcNsMgmtEntryDelete RpcNsMgmtEntryDeleteA
#define RpcNsMgmtEntryInqIfIds RpcNsMgmtEntryInqIfIdsA
#define RpcNsProfileDelete RpcNsProfileDeleteA
#define RpcNsProfileEltAdd RpcNsProfileEltAddA
#define RpcNsProfileEltRemove RpcNsProfileEltRemoveA
#define RpcNsProfileEltInqBegin RpcNsProfileEltInqBeginA
#define RpcNsProfileEltInqNext RpcNsProfileEltInqNextA

#endif /* UNICODE */

#endif /* __RPCNSI_H__ */
#pragma once 
