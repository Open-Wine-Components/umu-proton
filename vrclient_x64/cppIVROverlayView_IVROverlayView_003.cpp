/* This file is auto-generated, do not edit. */
#include "unix_private.h"

#if 0
#pragma makedep unix
#endif

NTSTATUS IVROverlayView_IVROverlayView_003_AcquireOverlayView( void *args )
{
    struct IVROverlayView_IVROverlayView_003_AcquireOverlayView_params *params = (struct IVROverlayView_IVROverlayView_003_AcquireOverlayView_params *)args;
    struct u_IVROverlayView_IVROverlayView_003 *iface = (struct u_IVROverlayView_IVROverlayView_003 *)params->u_iface;
    u_VRNativeDevice_t u_pNativeDevice;
    if (params->pNativeDevice) u_pNativeDevice = *params->pNativeDevice;
    u_VROverlayView_t u_pOverlayView;
    if (params->pOverlayView) u_pOverlayView = *params->pOverlayView;
    params->_ret = iface->AcquireOverlayView( params->ulOverlayHandle, params->pNativeDevice ? &u_pNativeDevice : nullptr, params->pOverlayView ? &u_pOverlayView : nullptr, params->unOverlayViewSize );
    if (params->pNativeDevice) *params->pNativeDevice = u_pNativeDevice;
    if (params->pOverlayView) *params->pOverlayView = u_pOverlayView;
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVROverlayView_IVROverlayView_003_AcquireOverlayView( void *args )
{
    struct wow64_IVROverlayView_IVROverlayView_003_AcquireOverlayView_params *params = (struct wow64_IVROverlayView_IVROverlayView_003_AcquireOverlayView_params *)args;
    struct u_IVROverlayView_IVROverlayView_003 *iface = (struct u_IVROverlayView_IVROverlayView_003 *)params->u_iface;
    u_VRNativeDevice_t u_pNativeDevice;
    if (params->pNativeDevice) u_pNativeDevice = *params->pNativeDevice;
    u_VROverlayView_t u_pOverlayView;
    if (params->pOverlayView) u_pOverlayView = *params->pOverlayView;
    params->_ret = iface->AcquireOverlayView( params->ulOverlayHandle, params->pNativeDevice ? &u_pNativeDevice : nullptr, params->pOverlayView ? &u_pOverlayView : nullptr, params->unOverlayViewSize );
    if (params->pNativeDevice) *params->pNativeDevice = u_pNativeDevice;
    if (params->pOverlayView) *params->pOverlayView = u_pOverlayView;
    return 0;
}
#endif

NTSTATUS IVROverlayView_IVROverlayView_003_ReleaseOverlayView( void *args )
{
    struct IVROverlayView_IVROverlayView_003_ReleaseOverlayView_params *params = (struct IVROverlayView_IVROverlayView_003_ReleaseOverlayView_params *)args;
    struct u_IVROverlayView_IVROverlayView_003 *iface = (struct u_IVROverlayView_IVROverlayView_003 *)params->u_iface;
    u_VROverlayView_t u_pOverlayView;
    if (params->pOverlayView) u_pOverlayView = *params->pOverlayView;
    params->_ret = iface->ReleaseOverlayView( params->pOverlayView ? &u_pOverlayView : nullptr );
    if (params->pOverlayView) *params->pOverlayView = u_pOverlayView;
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVROverlayView_IVROverlayView_003_ReleaseOverlayView( void *args )
{
    struct wow64_IVROverlayView_IVROverlayView_003_ReleaseOverlayView_params *params = (struct wow64_IVROverlayView_IVROverlayView_003_ReleaseOverlayView_params *)args;
    struct u_IVROverlayView_IVROverlayView_003 *iface = (struct u_IVROverlayView_IVROverlayView_003 *)params->u_iface;
    u_VROverlayView_t u_pOverlayView;
    if (params->pOverlayView) u_pOverlayView = *params->pOverlayView;
    params->_ret = iface->ReleaseOverlayView( params->pOverlayView ? &u_pOverlayView : nullptr );
    if (params->pOverlayView) *params->pOverlayView = u_pOverlayView;
    return 0;
}
#endif

NTSTATUS IVROverlayView_IVROverlayView_003_PostOverlayEvent( void *args )
{
    struct IVROverlayView_IVROverlayView_003_PostOverlayEvent_params *params = (struct IVROverlayView_IVROverlayView_003_PostOverlayEvent_params *)args;
    struct u_IVROverlayView_IVROverlayView_003 *iface = (struct u_IVROverlayView_IVROverlayView_003 *)params->u_iface;
    u_VREvent_t_223 u_pvrEvent;
    if (params->pvrEvent) u_pvrEvent = *params->pvrEvent;
    iface->PostOverlayEvent( params->ulOverlayHandle, params->pvrEvent ? &u_pvrEvent : nullptr );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVROverlayView_IVROverlayView_003_PostOverlayEvent( void *args )
{
    struct wow64_IVROverlayView_IVROverlayView_003_PostOverlayEvent_params *params = (struct wow64_IVROverlayView_IVROverlayView_003_PostOverlayEvent_params *)args;
    struct u_IVROverlayView_IVROverlayView_003 *iface = (struct u_IVROverlayView_IVROverlayView_003 *)params->u_iface;
    u_VREvent_t_223 u_pvrEvent;
    if (params->pvrEvent) u_pvrEvent = *params->pvrEvent;
    iface->PostOverlayEvent( params->ulOverlayHandle, params->pvrEvent ? &u_pvrEvent : nullptr );
    return 0;
}
#endif

NTSTATUS IVROverlayView_IVROverlayView_003_IsViewingPermitted( void *args )
{
    struct IVROverlayView_IVROverlayView_003_IsViewingPermitted_params *params = (struct IVROverlayView_IVROverlayView_003_IsViewingPermitted_params *)args;
    struct u_IVROverlayView_IVROverlayView_003 *iface = (struct u_IVROverlayView_IVROverlayView_003 *)params->u_iface;
    params->_ret = iface->IsViewingPermitted( params->ulOverlayHandle );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVROverlayView_IVROverlayView_003_IsViewingPermitted( void *args )
{
    struct wow64_IVROverlayView_IVROverlayView_003_IsViewingPermitted_params *params = (struct wow64_IVROverlayView_IVROverlayView_003_IsViewingPermitted_params *)args;
    struct u_IVROverlayView_IVROverlayView_003 *iface = (struct u_IVROverlayView_IVROverlayView_003 *)params->u_iface;
    params->_ret = iface->IsViewingPermitted( params->ulOverlayHandle );
    return 0;
}
#endif

