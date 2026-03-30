/* This file is auto-generated, do not edit. */
#include "unix_private.h"

#if 0
#pragma makedep unix
#endif

NTSTATUS IVRNotifications_IVRNotifications_002_CreateNotification( void *args )
{
    struct IVRNotifications_IVRNotifications_002_CreateNotification_params *params = (struct IVRNotifications_IVRNotifications_002_CreateNotification_params *)args;
    struct u_IVRNotifications_IVRNotifications_002 *iface = (struct u_IVRNotifications_IVRNotifications_002 *)params->u_iface;
    u_NotificationBitmap_t u_pImage;
    if (params->pImage) u_pImage = *params->pImage;
    params->_ret = iface->CreateNotification( params->ulOverlayHandle, params->ulUserValue, params->type, params->pchText, params->style, params->pImage ? &u_pImage : nullptr, params->pNotificationId );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRNotifications_IVRNotifications_002_CreateNotification( void *args )
{
    struct wow64_IVRNotifications_IVRNotifications_002_CreateNotification_params *params = (struct wow64_IVRNotifications_IVRNotifications_002_CreateNotification_params *)args;
    struct u_IVRNotifications_IVRNotifications_002 *iface = (struct u_IVRNotifications_IVRNotifications_002 *)params->u_iface;
    u_NotificationBitmap_t u_pImage;
    if (params->pImage) u_pImage = *params->pImage;
    params->_ret = iface->CreateNotification( params->ulOverlayHandle, params->ulUserValue, params->type, params->pchText, params->style, params->pImage ? &u_pImage : nullptr, params->pNotificationId );
    return 0;
}
#endif

NTSTATUS IVRNotifications_IVRNotifications_002_RemoveNotification( void *args )
{
    struct IVRNotifications_IVRNotifications_002_RemoveNotification_params *params = (struct IVRNotifications_IVRNotifications_002_RemoveNotification_params *)args;
    struct u_IVRNotifications_IVRNotifications_002 *iface = (struct u_IVRNotifications_IVRNotifications_002 *)params->u_iface;
    params->_ret = iface->RemoveNotification( params->notificationId );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRNotifications_IVRNotifications_002_RemoveNotification( void *args )
{
    struct wow64_IVRNotifications_IVRNotifications_002_RemoveNotification_params *params = (struct wow64_IVRNotifications_IVRNotifications_002_RemoveNotification_params *)args;
    struct u_IVRNotifications_IVRNotifications_002 *iface = (struct u_IVRNotifications_IVRNotifications_002 *)params->u_iface;
    params->_ret = iface->RemoveNotification( params->notificationId );
    return 0;
}
#endif

