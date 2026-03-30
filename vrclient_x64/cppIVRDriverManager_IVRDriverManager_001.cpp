/* This file is auto-generated, do not edit. */
#include "unix_private.h"

#if 0
#pragma makedep unix
#endif

NTSTATUS IVRDriverManager_IVRDriverManager_001_GetDriverCount( void *args )
{
    struct IVRDriverManager_IVRDriverManager_001_GetDriverCount_params *params = (struct IVRDriverManager_IVRDriverManager_001_GetDriverCount_params *)args;
    struct u_IVRDriverManager_IVRDriverManager_001 *iface = (struct u_IVRDriverManager_IVRDriverManager_001 *)params->u_iface;
    params->_ret = iface->GetDriverCount(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRDriverManager_IVRDriverManager_001_GetDriverCount( void *args )
{
    struct wow64_IVRDriverManager_IVRDriverManager_001_GetDriverCount_params *params = (struct wow64_IVRDriverManager_IVRDriverManager_001_GetDriverCount_params *)args;
    struct u_IVRDriverManager_IVRDriverManager_001 *iface = (struct u_IVRDriverManager_IVRDriverManager_001 *)params->u_iface;
    params->_ret = iface->GetDriverCount(  );
    return 0;
}
#endif

NTSTATUS IVRDriverManager_IVRDriverManager_001_GetDriverName( void *args )
{
    struct IVRDriverManager_IVRDriverManager_001_GetDriverName_params *params = (struct IVRDriverManager_IVRDriverManager_001_GetDriverName_params *)args;
    struct u_IVRDriverManager_IVRDriverManager_001 *iface = (struct u_IVRDriverManager_IVRDriverManager_001 *)params->u_iface;
    params->_ret = iface->GetDriverName( params->nDriver, params->pchValue, params->unBufferSize );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRDriverManager_IVRDriverManager_001_GetDriverName( void *args )
{
    struct wow64_IVRDriverManager_IVRDriverManager_001_GetDriverName_params *params = (struct wow64_IVRDriverManager_IVRDriverManager_001_GetDriverName_params *)args;
    struct u_IVRDriverManager_IVRDriverManager_001 *iface = (struct u_IVRDriverManager_IVRDriverManager_001 *)params->u_iface;
    params->_ret = iface->GetDriverName( params->nDriver, params->pchValue, params->unBufferSize );
    return 0;
}
#endif

NTSTATUS IVRDriverManager_IVRDriverManager_001_GetDriverHandle( void *args )
{
    struct IVRDriverManager_IVRDriverManager_001_GetDriverHandle_params *params = (struct IVRDriverManager_IVRDriverManager_001_GetDriverHandle_params *)args;
    struct u_IVRDriverManager_IVRDriverManager_001 *iface = (struct u_IVRDriverManager_IVRDriverManager_001 *)params->u_iface;
    params->_ret = iface->GetDriverHandle( params->pchDriverName );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRDriverManager_IVRDriverManager_001_GetDriverHandle( void *args )
{
    struct wow64_IVRDriverManager_IVRDriverManager_001_GetDriverHandle_params *params = (struct wow64_IVRDriverManager_IVRDriverManager_001_GetDriverHandle_params *)args;
    struct u_IVRDriverManager_IVRDriverManager_001 *iface = (struct u_IVRDriverManager_IVRDriverManager_001 *)params->u_iface;
    params->_ret = iface->GetDriverHandle( params->pchDriverName );
    return 0;
}
#endif

NTSTATUS IVRDriverManager_IVRDriverManager_001_IsEnabled( void *args )
{
    struct IVRDriverManager_IVRDriverManager_001_IsEnabled_params *params = (struct IVRDriverManager_IVRDriverManager_001_IsEnabled_params *)args;
    struct u_IVRDriverManager_IVRDriverManager_001 *iface = (struct u_IVRDriverManager_IVRDriverManager_001 *)params->u_iface;
    params->_ret = iface->IsEnabled( params->nDriver );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRDriverManager_IVRDriverManager_001_IsEnabled( void *args )
{
    struct wow64_IVRDriverManager_IVRDriverManager_001_IsEnabled_params *params = (struct wow64_IVRDriverManager_IVRDriverManager_001_IsEnabled_params *)args;
    struct u_IVRDriverManager_IVRDriverManager_001 *iface = (struct u_IVRDriverManager_IVRDriverManager_001 *)params->u_iface;
    params->_ret = iface->IsEnabled( params->nDriver );
    return 0;
}
#endif

