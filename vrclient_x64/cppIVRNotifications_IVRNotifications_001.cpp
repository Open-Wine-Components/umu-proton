/* This file is auto-generated, do not edit. */
#include "unix_private.h"

#if 0
#pragma makedep unix
#endif

NTSTATUS IVRNotifications_IVRNotifications_001_GetErrorString( void *args )
{
    struct IVRNotifications_IVRNotifications_001_GetErrorString_params *params = (struct IVRNotifications_IVRNotifications_001_GetErrorString_params *)args;
    struct u_IVRNotifications_IVRNotifications_001 *iface = (struct u_IVRNotifications_IVRNotifications_001 *)params->u_iface;
    params->_ret = iface->GetErrorString( params->error, params->pchBuffer, params->unBufferSize );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRNotifications_IVRNotifications_001_GetErrorString( void *args )
{
    struct wow64_IVRNotifications_IVRNotifications_001_GetErrorString_params *params = (struct wow64_IVRNotifications_IVRNotifications_001_GetErrorString_params *)args;
    struct u_IVRNotifications_IVRNotifications_001 *iface = (struct u_IVRNotifications_IVRNotifications_001 *)params->u_iface;
    params->_ret = iface->GetErrorString( params->error, params->pchBuffer, params->unBufferSize );
    return 0;
}
#endif

NTSTATUS IVRNotifications_IVRNotifications_001_CreateNotification( void *args )
{
    struct IVRNotifications_IVRNotifications_001_CreateNotification_params *params = (struct IVRNotifications_IVRNotifications_001_CreateNotification_params *)args;
    struct u_IVRNotifications_IVRNotifications_001 *iface = (struct u_IVRNotifications_IVRNotifications_001 *)params->u_iface;
    u_NotificationBitmap u_photo;
    if (params->photo) u_photo = *params->photo;
    params->_ret = iface->CreateNotification( params->ulOverlayHandle, params->ulUserValue, params->strType, params->strText, params->strCategory, params->photo ? &u_photo : nullptr, params->notificationId );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRNotifications_IVRNotifications_001_CreateNotification( void *args )
{
    struct wow64_IVRNotifications_IVRNotifications_001_CreateNotification_params *params = (struct wow64_IVRNotifications_IVRNotifications_001_CreateNotification_params *)args;
    struct u_IVRNotifications_IVRNotifications_001 *iface = (struct u_IVRNotifications_IVRNotifications_001 *)params->u_iface;
    u_NotificationBitmap u_photo;
    if (params->photo) u_photo = *params->photo;
    params->_ret = iface->CreateNotification( params->ulOverlayHandle, params->ulUserValue, params->strType, params->strText, params->strCategory, params->photo ? &u_photo : nullptr, params->notificationId );
    return 0;
}
#endif

NTSTATUS IVRNotifications_IVRNotifications_001_DismissNotification( void *args )
{
    struct IVRNotifications_IVRNotifications_001_DismissNotification_params *params = (struct IVRNotifications_IVRNotifications_001_DismissNotification_params *)args;
    struct u_IVRNotifications_IVRNotifications_001 *iface = (struct u_IVRNotifications_IVRNotifications_001 *)params->u_iface;
    params->_ret = iface->DismissNotification( params->notificationId );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRNotifications_IVRNotifications_001_DismissNotification( void *args )
{
    struct wow64_IVRNotifications_IVRNotifications_001_DismissNotification_params *params = (struct wow64_IVRNotifications_IVRNotifications_001_DismissNotification_params *)args;
    struct u_IVRNotifications_IVRNotifications_001 *iface = (struct u_IVRNotifications_IVRNotifications_001 *)params->u_iface;
    params->_ret = iface->DismissNotification( params->notificationId );
    return 0;
}
#endif

