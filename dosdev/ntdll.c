#include "precompiled_header.h"
#include "nt.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

NTSTATUS
NTAPI
NtCreateSymbolicLinkObject(
    OUT PHANDLE Handle,
    IN ACCESS_MASK DesiredAccess,
    IN POBJECT_ATTRIBUTES ObjectAttributes,
    IN PUNICODE_STRING DestinationName
    )
{
    UNREFERENCED_PARAMETER(Handle);
    UNREFERENCED_PARAMETER(DesiredAccess);
    UNREFERENCED_PARAMETER(ObjectAttributes);
    UNREFERENCED_PARAMETER(DestinationName);
    return 0;
}

NTSTATUS
NTAPI
NtClose(
    HANDLE Handle
    )
{
    UNREFERENCED_PARAMETER(Handle);
    return 0;
}
