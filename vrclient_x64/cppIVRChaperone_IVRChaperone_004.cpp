/* This file is auto-generated, do not edit. */
#include "unix_private.h"

#if 0
#pragma makedep unix
#endif

NTSTATUS IVRChaperone_IVRChaperone_004_GetCalibrationState( void *args )
{
    struct IVRChaperone_IVRChaperone_004_GetCalibrationState_params *params = (struct IVRChaperone_IVRChaperone_004_GetCalibrationState_params *)args;
    struct u_IVRChaperone_IVRChaperone_004 *iface = (struct u_IVRChaperone_IVRChaperone_004 *)params->u_iface;
    params->_ret = iface->GetCalibrationState(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRChaperone_IVRChaperone_004_GetCalibrationState( void *args )
{
    struct wow64_IVRChaperone_IVRChaperone_004_GetCalibrationState_params *params = (struct wow64_IVRChaperone_IVRChaperone_004_GetCalibrationState_params *)args;
    struct u_IVRChaperone_IVRChaperone_004 *iface = (struct u_IVRChaperone_IVRChaperone_004 *)params->u_iface;
    params->_ret = iface->GetCalibrationState(  );
    return 0;
}
#endif

NTSTATUS IVRChaperone_IVRChaperone_004_GetPlayAreaSize( void *args )
{
    struct IVRChaperone_IVRChaperone_004_GetPlayAreaSize_params *params = (struct IVRChaperone_IVRChaperone_004_GetPlayAreaSize_params *)args;
    struct u_IVRChaperone_IVRChaperone_004 *iface = (struct u_IVRChaperone_IVRChaperone_004 *)params->u_iface;
    params->_ret = iface->GetPlayAreaSize( params->pSizeX, params->pSizeZ );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRChaperone_IVRChaperone_004_GetPlayAreaSize( void *args )
{
    struct wow64_IVRChaperone_IVRChaperone_004_GetPlayAreaSize_params *params = (struct wow64_IVRChaperone_IVRChaperone_004_GetPlayAreaSize_params *)args;
    struct u_IVRChaperone_IVRChaperone_004 *iface = (struct u_IVRChaperone_IVRChaperone_004 *)params->u_iface;
    params->_ret = iface->GetPlayAreaSize( params->pSizeX, params->pSizeZ );
    return 0;
}
#endif

NTSTATUS IVRChaperone_IVRChaperone_004_GetPlayAreaRect( void *args )
{
    struct IVRChaperone_IVRChaperone_004_GetPlayAreaRect_params *params = (struct IVRChaperone_IVRChaperone_004_GetPlayAreaRect_params *)args;
    struct u_IVRChaperone_IVRChaperone_004 *iface = (struct u_IVRChaperone_IVRChaperone_004 *)params->u_iface;
    params->_ret = iface->GetPlayAreaRect( params->rect );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRChaperone_IVRChaperone_004_GetPlayAreaRect( void *args )
{
    struct wow64_IVRChaperone_IVRChaperone_004_GetPlayAreaRect_params *params = (struct wow64_IVRChaperone_IVRChaperone_004_GetPlayAreaRect_params *)args;
    struct u_IVRChaperone_IVRChaperone_004 *iface = (struct u_IVRChaperone_IVRChaperone_004 *)params->u_iface;
    params->_ret = iface->GetPlayAreaRect( params->rect );
    return 0;
}
#endif

NTSTATUS IVRChaperone_IVRChaperone_004_ReloadInfo( void *args )
{
    struct IVRChaperone_IVRChaperone_004_ReloadInfo_params *params = (struct IVRChaperone_IVRChaperone_004_ReloadInfo_params *)args;
    struct u_IVRChaperone_IVRChaperone_004 *iface = (struct u_IVRChaperone_IVRChaperone_004 *)params->u_iface;
    iface->ReloadInfo(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRChaperone_IVRChaperone_004_ReloadInfo( void *args )
{
    struct wow64_IVRChaperone_IVRChaperone_004_ReloadInfo_params *params = (struct wow64_IVRChaperone_IVRChaperone_004_ReloadInfo_params *)args;
    struct u_IVRChaperone_IVRChaperone_004 *iface = (struct u_IVRChaperone_IVRChaperone_004 *)params->u_iface;
    iface->ReloadInfo(  );
    return 0;
}
#endif

NTSTATUS IVRChaperone_IVRChaperone_004_SetSceneColor( void *args )
{
    struct IVRChaperone_IVRChaperone_004_SetSceneColor_params *params = (struct IVRChaperone_IVRChaperone_004_SetSceneColor_params *)args;
    struct u_IVRChaperone_IVRChaperone_004 *iface = (struct u_IVRChaperone_IVRChaperone_004 *)params->u_iface;
    iface->SetSceneColor( params->color );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRChaperone_IVRChaperone_004_SetSceneColor( void *args )
{
    struct wow64_IVRChaperone_IVRChaperone_004_SetSceneColor_params *params = (struct wow64_IVRChaperone_IVRChaperone_004_SetSceneColor_params *)args;
    struct u_IVRChaperone_IVRChaperone_004 *iface = (struct u_IVRChaperone_IVRChaperone_004 *)params->u_iface;
    iface->SetSceneColor( params->color );
    return 0;
}
#endif

NTSTATUS IVRChaperone_IVRChaperone_004_GetBoundsColor( void *args )
{
    struct IVRChaperone_IVRChaperone_004_GetBoundsColor_params *params = (struct IVRChaperone_IVRChaperone_004_GetBoundsColor_params *)args;
    struct u_IVRChaperone_IVRChaperone_004 *iface = (struct u_IVRChaperone_IVRChaperone_004 *)params->u_iface;
    iface->GetBoundsColor( params->pOutputColorArray, params->nNumOutputColors, params->flCollisionBoundsFadeDistance, params->pOutputCameraColor );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRChaperone_IVRChaperone_004_GetBoundsColor( void *args )
{
    struct wow64_IVRChaperone_IVRChaperone_004_GetBoundsColor_params *params = (struct wow64_IVRChaperone_IVRChaperone_004_GetBoundsColor_params *)args;
    struct u_IVRChaperone_IVRChaperone_004 *iface = (struct u_IVRChaperone_IVRChaperone_004 *)params->u_iface;
    iface->GetBoundsColor( params->pOutputColorArray, params->nNumOutputColors, params->flCollisionBoundsFadeDistance, params->pOutputCameraColor );
    return 0;
}
#endif

NTSTATUS IVRChaperone_IVRChaperone_004_AreBoundsVisible( void *args )
{
    struct IVRChaperone_IVRChaperone_004_AreBoundsVisible_params *params = (struct IVRChaperone_IVRChaperone_004_AreBoundsVisible_params *)args;
    struct u_IVRChaperone_IVRChaperone_004 *iface = (struct u_IVRChaperone_IVRChaperone_004 *)params->u_iface;
    params->_ret = iface->AreBoundsVisible(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRChaperone_IVRChaperone_004_AreBoundsVisible( void *args )
{
    struct wow64_IVRChaperone_IVRChaperone_004_AreBoundsVisible_params *params = (struct wow64_IVRChaperone_IVRChaperone_004_AreBoundsVisible_params *)args;
    struct u_IVRChaperone_IVRChaperone_004 *iface = (struct u_IVRChaperone_IVRChaperone_004 *)params->u_iface;
    params->_ret = iface->AreBoundsVisible(  );
    return 0;
}
#endif

NTSTATUS IVRChaperone_IVRChaperone_004_ForceBoundsVisible( void *args )
{
    struct IVRChaperone_IVRChaperone_004_ForceBoundsVisible_params *params = (struct IVRChaperone_IVRChaperone_004_ForceBoundsVisible_params *)args;
    struct u_IVRChaperone_IVRChaperone_004 *iface = (struct u_IVRChaperone_IVRChaperone_004 *)params->u_iface;
    iface->ForceBoundsVisible( params->bForce );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRChaperone_IVRChaperone_004_ForceBoundsVisible( void *args )
{
    struct wow64_IVRChaperone_IVRChaperone_004_ForceBoundsVisible_params *params = (struct wow64_IVRChaperone_IVRChaperone_004_ForceBoundsVisible_params *)args;
    struct u_IVRChaperone_IVRChaperone_004 *iface = (struct u_IVRChaperone_IVRChaperone_004 *)params->u_iface;
    iface->ForceBoundsVisible( params->bForce );
    return 0;
}
#endif

NTSTATUS IVRChaperone_IVRChaperone_004_ResetZeroPose( void *args )
{
    struct IVRChaperone_IVRChaperone_004_ResetZeroPose_params *params = (struct IVRChaperone_IVRChaperone_004_ResetZeroPose_params *)args;
    struct u_IVRChaperone_IVRChaperone_004 *iface = (struct u_IVRChaperone_IVRChaperone_004 *)params->u_iface;
    iface->ResetZeroPose( params->eTrackingUniverseOrigin );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRChaperone_IVRChaperone_004_ResetZeroPose( void *args )
{
    struct wow64_IVRChaperone_IVRChaperone_004_ResetZeroPose_params *params = (struct wow64_IVRChaperone_IVRChaperone_004_ResetZeroPose_params *)args;
    struct u_IVRChaperone_IVRChaperone_004 *iface = (struct u_IVRChaperone_IVRChaperone_004 *)params->u_iface;
    iface->ResetZeroPose( params->eTrackingUniverseOrigin );
    return 0;
}
#endif

