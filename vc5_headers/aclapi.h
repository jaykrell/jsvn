//+-------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright (C) Microsoft Corporation, 1993-1996.
//
//  File:        aclapi.h
//
//  Contents:    public header file for acl and trusted server access control
//               APIs
//
//--------------------------------------------------------------------
#ifndef __ACCESS_CONTROL_API__
#define __ACCESS_CONTROL_API__

#include <windows.h>
#include <accctrl.h>

#ifdef __cplusplus
extern "C" {
#endif

unsigned long
__stdcall
SetEntriesInAclW( IN  unsigned long               cCountOfExplicitEntries,
                  IN  PEXPLICIT_ACCESS_W  pListOfExplicitEntries,
                  IN  PACL                OldAcl,
                  OUT PACL              * NewAcl);

unsigned long
__stdcall
SetEntriesInAclA( IN  unsigned long               cCountOfExplicitEntries,
                  IN  PEXPLICIT_ACCESS_A  pListOfExplicitEntries,
                  IN  PACL                OldAcl,
                  OUT PACL              * NewAcl);

#ifdef UNICODE
    #define SetEntriesInAcl     SetEntriesInAclW
#else
    #define SetEntriesInAcl     SetEntriesInAclA
#endif


unsigned long
__stdcall
GetExplicitEntriesFromAclW( IN  PACL                  pacl,
                            OUT PULONG                pcCountOfExplicitEntries,
                            OUT PEXPLICIT_ACCESS_W  * pListOfExplicitEntries);

unsigned long
__stdcall
GetExplicitEntriesFromAclA( IN  PACL                  pacl,
                            OUT PULONG                pcCountOfExplicitEntries,
                            OUT PEXPLICIT_ACCESS_A  * pListOfExplicitEntries);

#ifdef UNICODE
    #define GetExplicitEntriesFromAcl       GetExplicitEntriesFromAclW
#else
    #define GetExplicitEntriesFromAcl       GetExplicitEntriesFromAclA
#endif


unsigned long
__stdcall
GetEffectiveRightsFromAclW( IN  PACL          pacl,
                            IN  PTRUSTEE_W    pTrustee,
                            OUT PACCESS_MASK  pAccessRights);

unsigned long
__stdcall
GetEffectiveRightsFromAclA( IN  PACL          pacl,
                            IN  PTRUSTEE_A    pTrustee,
                            OUT PACCESS_MASK  pAccessRights);

#ifdef UNICODE
    #define GetEffectiveRightsFromAcl       GetEffectiveRightsFromAclW
#else
    #define GetEffectiveRightsFromAcl       GetEffectiveRightsFromAclA
#endif


unsigned long
__stdcall
GetAuditedPermissionsFromAclW( IN  PACL          pacl,
                               IN  PTRUSTEE_W    pTrustee,
                               OUT PACCESS_MASK  pSuccessfulAuditedRights,
                               OUT PACCESS_MASK  pFailedAuditRights);

unsigned long
__stdcall
GetAuditedPermissionsFromAclA( IN  PACL          pacl,
                               IN  PTRUSTEE_A    pTrustee,
                               OUT PACCESS_MASK  pSuccessfulAuditedRights,
                               OUT PACCESS_MASK  pFailedAuditRights);

#ifdef UNICODE
    #define GetAuditedPermissionsFromAcl    GetAuditedPermissionsFromAclW
#else
    #define GetAuditedPermissionsFromAcl    GetAuditedPermissionsFromAclA
#endif



unsigned long
__stdcall
GetNamedSecurityInfoW( IN  LPWSTR                 pObjectName,
                       IN  SE_OBJECT_TYPE         ObjectType,
                       IN  SECURITY_INFORMATION   SecurityInfo,
                       OUT PSID                 * ppsidOowner,
                       OUT PSID                 * ppsidGroup,
                       OUT PACL                 * ppDacl,
                       OUT PACL                 * ppSacl,
                       OUT PSECURITY_DESCRIPTOR * ppSecurityDescriptor);

unsigned long
__stdcall
GetNamedSecurityInfoA( IN  LPSTR                  pObjectName,
                       IN  SE_OBJECT_TYPE         ObjectType,
                       IN  SECURITY_INFORMATION   SecurityInfo,
                       OUT PSID                 * ppsidOowner,
                       OUT PSID                 * ppsidGroup,
                       OUT PACL                 * ppDacl,
                       OUT PACL                 * ppSacl,
                       OUT PSECURITY_DESCRIPTOR * ppSecurityDescriptor);

#ifdef UNICODE
    #define GetNamedSecurityInfo        GetNamedSecurityInfoW
#else
    #define GetNamedSecurityInfo        GetNamedSecurityInfoA
#endif


unsigned long
__stdcall
GetSecurityInfo( IN  HANDLE                 handle,
                 IN  SE_OBJECT_TYPE         ObjectType,
                 IN  SECURITY_INFORMATION   SecurityInfo,
                 OUT PSID                 * ppsidOowner,
                 OUT PSID                 * ppsidGroup,
                 OUT PACL                 * ppDacl,
                 OUT PACL                 * ppSacl,
                 OUT PSECURITY_DESCRIPTOR * ppSecurityDescriptor);


unsigned long
__stdcall
SetNamedSecurityInfoW( IN LPWSTR                pObjectName,
                       IN SE_OBJECT_TYPE        ObjectType,
                       IN SECURITY_INFORMATION  SecurityInfo,
                       IN PSID                  psidOowner,
                       IN PSID                  psidGroup,
                       IN PACL                  pDacl,
                       IN PACL                  pSacl);

unsigned long
__stdcall
SetNamedSecurityInfoA( IN LPSTR                 pObjectName,
                       IN SE_OBJECT_TYPE        ObjectType,
                       IN SECURITY_INFORMATION  SecurityInfo,
                       IN PSID                  psidOowner,
                       IN PSID                  psidGroup,
                       IN PACL                  pDacl,
                       IN PACL                  pSacl);

#ifdef UNICODE
    #define SetNamedSecurityInfo        SetNamedSecurityInfoW
#else
    #define SetNamedSecurityInfo        SetNamedSecurityInfoA
#endif


unsigned long
__stdcall
SetSecurityInfo( IN HANDLE                handle,
                 IN SE_OBJECT_TYPE        ObjectType,
                 IN SECURITY_INFORMATION  SecurityInfo,
                 IN PSID                  psidOowner,
                 IN PSID                  psidGroup,
                 IN PACL                  pDacl,
                 IN PACL                  pSacl);


//----------------------------------------------------------------------------
// The following API are provided for trusted servers to use to
// implement access control on their own objects.
//----------------------------------------------------------------------------

unsigned long
__stdcall
BuildSecurityDescriptorW( IN  PTRUSTEE_W              pOwner,
                          IN  PTRUSTEE_W              pGroup,
                          IN  unsigned long                   cCountOfAccessEntries,
                          IN  PEXPLICIT_ACCESS_W      pListOfAccessEntries,
                          IN  unsigned long                   cCountOfAuditEntries,
                          IN  PEXPLICIT_ACCESS_W      pListOfAuditEntries,
                          IN  PSECURITY_DESCRIPTOR    pOldSD,
                          OUT PULONG                  pSizeNewSD,
                          OUT PSECURITY_DESCRIPTOR  * pNewSD);

unsigned long
__stdcall
BuildSecurityDescriptorA( IN  PTRUSTEE_A              pOwner,
                          IN  PTRUSTEE_A              pGroup,
                          IN  unsigned long                   cCountOfAccessEntries,
                          IN  PEXPLICIT_ACCESS_A      pListOfAccessEntries,
                          IN  unsigned long                   cCountOfAuditEntries,
                          IN  PEXPLICIT_ACCESS_A      pListOfAuditEntries,
                          IN  PSECURITY_DESCRIPTOR    pOldSD,
                          OUT PULONG                  pSizeNewSD,
                          OUT PSECURITY_DESCRIPTOR  * pNewSD);


#ifdef UNICODE
    #define BuildSecurityDescriptor     BuildSecurityDescriptorW
#else
    #define BuildSecurityDescriptor     BuildSecurityDescriptorA
#endif


unsigned long
__stdcall
LookupSecurityDescriptorPartsW( OUT PTRUSTEE_W         * pOwner,
                                OUT PTRUSTEE_W         * pGroup,
                                OUT PULONG               cCountOfAccessEntries,
                                OUT PEXPLICIT_ACCESS_W * pListOfAccessEntries,
                                OUT PULONG               cCountOfAuditEntries,
                                OUT PEXPLICIT_ACCESS_W * pListOfAuditEntries,
                                IN  PSECURITY_DESCRIPTOR pSD);

unsigned long
__stdcall
LookupSecurityDescriptorPartsA( OUT PTRUSTEE_A         * pOwner,
                                OUT PTRUSTEE_A         * pGroup,
                                OUT PULONG               cCountOfAccessEntries,
                                OUT PEXPLICIT_ACCESS_A * pListOfAccessEntries,
                                OUT PULONG               cCountOfAuditEntries,
                                OUT PEXPLICIT_ACCESS_A * pListOfAuditEntries,
                                IN  PSECURITY_DESCRIPTOR pSD);

#ifdef UNICODE
    #define LookupSecurityDescriptorParts       LookupSecurityDescriptorPartsW
#else
    #define LookupSecurityDescriptorParts       LookupSecurityDescriptorPartsA
#endif


//----------------------------------------------------------------------------
// The following helper API are provided for building
// access control structures.
//----------------------------------------------------------------------------

void
__stdcall
BuildExplicitAccessWithNameW( IN OUT PEXPLICIT_ACCESS_W  pExplicitAccess,
                              IN     LPWSTR              pTrusteeName,
                              IN     unsigned long               AccessPermissions,
                              IN     ACCESS_MODE         AccessMode,
                              IN     unsigned long               Inheritance);

void
__stdcall
BuildExplicitAccessWithNameA( IN OUT PEXPLICIT_ACCESS_A  pExplicitAccess,
                              IN     LPSTR               pTrusteeName,
                              IN     unsigned long               AccessPermissions,
                              IN     ACCESS_MODE         AccessMode,
                              IN     unsigned long               Inheritance);

#ifdef UNICODE
    #define BuildExplicitAccessWithName     BuildExplicitAccessWithNameW
#else
    #define BuildExplicitAccessWithName     BuildExplicitAccessWithNameA
#endif


void
__stdcall
BuildImpersonateExplicitAccessWithNameW(
    IN OUT PEXPLICIT_ACCESS_W  pExplicitAccess,
    IN     LPWSTR              pTrusteeName,
    IN     PTRUSTEE_W          pTrustee,
    IN     unsigned long               AccessPermissions,
    IN     ACCESS_MODE         AccessMode,
    IN     unsigned long               Inheritance);

void
__stdcall
BuildImpersonateExplicitAccessWithNameA(
    IN OUT PEXPLICIT_ACCESS_A  pExplicitAccess,
    IN     LPSTR               pTrusteeName,
    IN     PTRUSTEE_A          pTrustee,
    IN     unsigned long               AccessPermissions,
    IN     ACCESS_MODE         AccessMode,
    IN     unsigned long               Inheritance);

#ifdef UNICODE
    #define BuildImpersonateExplicitAccessWithName BuildImpersonateExplicitAccessWithNameW
#else
    #define BuildImpersonateExplicitAccessWithName BuildImpersonateExplicitAccessWithNameA
#endif


void
__stdcall
BuildTrusteeWithNameW( IN OUT PTRUSTEE_W  pTrustee,
                       IN     LPWSTR      pName);

void
__stdcall
BuildTrusteeWithNameA( IN OUT PTRUSTEE_A  pTrustee,
                       IN     LPSTR       pName);

#ifdef UNICODE
    #define BuildTrusteeWithName        BuildTrusteeWithNameW
#else
    #define BuildTrusteeWithName        BuildTrusteeWithNameA
#endif


void
__stdcall
BuildImpersonateTrusteeW( IN OUT PTRUSTEE_W  pTrustee,
                          IN     PTRUSTEE_W  pImpersonateTrustee);

void
__stdcall
BuildImpersonateTrusteeA( IN OUT PTRUSTEE_A  pTrustee,
                          IN     PTRUSTEE_A  pImpersonateTrustee);

#ifdef UNICODE
    #define BuildImpersonateTrustee     BuildImpersonateTrusteeW
#else
    #define BuildImpersonateTrustee     BuildImpersonateTrusteeA
#endif


void
__stdcall
BuildTrusteeWithSidW( IN OUT PTRUSTEE_W  pTrustee,
                      IN     PSID        pSid);

void
__stdcall
BuildTrusteeWithSidA( IN OUT PTRUSTEE_A  pTrustee,
                      IN     PSID        pSid);

#ifdef UNICODE
    #define BuildTrusteeWithSid     BuildTrusteeWithSidW
#else
    #define BuildTrusteeWithSid     BuildTrusteeWithSidA
#endif


LPWSTR
__stdcall
GetTrusteeNameW( IN PTRUSTEE_W  pTrustee);

LPSTR
__stdcall
GetTrusteeNameA( IN PTRUSTEE_A  pTrustee);

#ifdef UNICODE
    #define GetTrusteeName     GetTrusteeNameW
#else
    #define GetTrusteeName     GetTrusteeNameA
#endif


TRUSTEE_TYPE
__stdcall
GetTrusteeTypeW( IN PTRUSTEE_W  pTrustee);

TRUSTEE_TYPE
__stdcall
GetTrusteeTypeA( IN PTRUSTEE_A  pTrustee);

#ifdef UNICODE
    #define GetTrusteeType     GetTrusteeTypeW
#else
    #define GetTrusteeType     GetTrusteeTypeA
#endif


TRUSTEE_FORM
__stdcall
GetTrusteeFormW( IN PTRUSTEE_W  pTrustee);

TRUSTEE_FORM
__stdcall
GetTrusteeFormA( IN PTRUSTEE_A  pTrustee);

#ifdef UNICODE
    #define GetTrusteeForm     GetTrusteeFormW
#else
    #define GetTrusteeForm     GetTrusteeFormA
#endif


MULTIPLE_TRUSTEE_OPERATION
__stdcall
GetMultipleTrusteeOperationW( IN PTRUSTEE_W  pTrustee);

MULTIPLE_TRUSTEE_OPERATION
__stdcall
GetMultipleTrusteeOperationA( IN PTRUSTEE_A  pTrustee);

#ifdef UNICODE
    #define GetMultipleTrusteeOperation        GetMultipleTrusteeOperationW
#else
    #define GetMultipleTrusteeOperation        GetMultipleTrusteeOperationA
#endif


PTRUSTEE_W
__stdcall
GetMultipleTrusteeW( IN PTRUSTEE_W  pTrustee);

PTRUSTEE_A
__stdcall
GetMultipleTrusteeA( IN PTRUSTEE_A  pTrustee);

#ifdef UNICODE
    #define GetMultipleTrustee     GetMultipleTrusteeW
#else
    #define GetMultipleTrustee     GetMultipleTrusteeA
#endif


#ifdef __cplusplus
}
#endif
#endif // __ACCESS_CONTROL_API__


#pragma once 
