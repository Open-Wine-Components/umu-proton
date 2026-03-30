/* This file is auto-generated, do not edit. */
#include "unix_private.h"

#if 0
#pragma makedep unix
#endif

NTSTATUS IVRExtendedDisplay_IVRExtendedDisplay_001_GetWindowBounds( void *args )
{
    struct IVRExtendedDisplay_IVRExtendedDisplay_001_GetWindowBounds_params *params = (struct IVRExtendedDisplay_IVRExtendedDisplay_001_GetWindowBounds_params *)args;
    struct u_IVRExtendedDisplay_IVRExtendedDisplay_001 *iface = (struct u_IVRExtendedDisplay_IVRExtendedDisplay_001 *)params->u_iface;
    iface->GetWindowBounds( params->pnX, params->pnY, params->pnWidth, params->pnHeight );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRExtendedDisplay_IVRExtendedDisplay_001_GetWindowBounds( void *args )
{
    struct wow64_IVRExtendedDisplay_IVRExtendedDisplay_001_GetWindowBounds_params *params = (struct wow64_IVRExtendedDisplay_IVRExtendedDisplay_001_GetWindowBounds_params *)args;
    struct u_IVRExtendedDisplay_IVRExtendedDisplay_001 *iface = (struct u_IVRExtendedDisplay_IVRExtendedDisplay_001 *)params->u_iface;
    iface->GetWindowBounds( params->pnX, params->pnY, params->pnWidth, params->pnHeight );
    return 0;
}
#endif

NTSTATUS IVRExtendedDisplay_IVRExtendedDisplay_001_GetEyeOutputViewport( void *args )
{
    struct IVRExtendedDisplay_IVRExtendedDisplay_001_GetEyeOutputViewport_params *params = (struct IVRExtendedDisplay_IVRExtendedDisplay_001_GetEyeOutputViewport_params *)args;
    struct u_IVRExtendedDisplay_IVRExtendedDisplay_001 *iface = (struct u_IVRExtendedDisplay_IVRExtendedDisplay_001 *)params->u_iface;
    iface->GetEyeOutputViewport( params->eEye, params->pnX, params->pnY, params->pnWidth, params->pnHeight );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRExtendedDisplay_IVRExtendedDisplay_001_GetEyeOutputViewport( void *args )
{
    struct wow64_IVRExtendedDisplay_IVRExtendedDisplay_001_GetEyeOutputViewport_params *params = (struct wow64_IVRExtendedDisplay_IVRExtendedDisplay_001_GetEyeOutputViewport_params *)args;
    struct u_IVRExtendedDisplay_IVRExtendedDisplay_001 *iface = (struct u_IVRExtendedDisplay_IVRExtendedDisplay_001 *)params->u_iface;
    iface->GetEyeOutputViewport( params->eEye, params->pnX, params->pnY, params->pnWidth, params->pnHeight );
    return 0;
}
#endif

NTSTATUS IVRExtendedDisplay_IVRExtendedDisplay_001_GetDXGIOutputInfo( void *args )
{
    struct IVRExtendedDisplay_IVRExtendedDisplay_001_GetDXGIOutputInfo_params *params = (struct IVRExtendedDisplay_IVRExtendedDisplay_001_GetDXGIOutputInfo_params *)args;
    struct u_IVRExtendedDisplay_IVRExtendedDisplay_001 *iface = (struct u_IVRExtendedDisplay_IVRExtendedDisplay_001 *)params->u_iface;
    iface->GetDXGIOutputInfo( params->pnAdapterIndex, params->pnAdapterOutputIndex );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRExtendedDisplay_IVRExtendedDisplay_001_GetDXGIOutputInfo( void *args )
{
    struct wow64_IVRExtendedDisplay_IVRExtendedDisplay_001_GetDXGIOutputInfo_params *params = (struct wow64_IVRExtendedDisplay_IVRExtendedDisplay_001_GetDXGIOutputInfo_params *)args;
    struct u_IVRExtendedDisplay_IVRExtendedDisplay_001 *iface = (struct u_IVRExtendedDisplay_IVRExtendedDisplay_001 *)params->u_iface;
    iface->GetDXGIOutputInfo( params->pnAdapterIndex, params->pnAdapterOutputIndex );
    return 0;
}
#endif

