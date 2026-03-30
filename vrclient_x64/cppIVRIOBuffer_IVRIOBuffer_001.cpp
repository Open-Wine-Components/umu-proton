/* This file is auto-generated, do not edit. */
#include "unix_private.h"

#if 0
#pragma makedep unix
#endif

NTSTATUS IVRIOBuffer_IVRIOBuffer_001_Open( void *args )
{
    struct IVRIOBuffer_IVRIOBuffer_001_Open_params *params = (struct IVRIOBuffer_IVRIOBuffer_001_Open_params *)args;
    struct u_IVRIOBuffer_IVRIOBuffer_001 *iface = (struct u_IVRIOBuffer_IVRIOBuffer_001 *)params->u_iface;
    params->_ret = iface->Open( params->pchPath, params->mode, params->unElementSize, params->unElements, params->pulBuffer );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRIOBuffer_IVRIOBuffer_001_Open( void *args )
{
    struct wow64_IVRIOBuffer_IVRIOBuffer_001_Open_params *params = (struct wow64_IVRIOBuffer_IVRIOBuffer_001_Open_params *)args;
    struct u_IVRIOBuffer_IVRIOBuffer_001 *iface = (struct u_IVRIOBuffer_IVRIOBuffer_001 *)params->u_iface;
    params->_ret = iface->Open( params->pchPath, params->mode, params->unElementSize, params->unElements, params->pulBuffer );
    return 0;
}
#endif

NTSTATUS IVRIOBuffer_IVRIOBuffer_001_Close( void *args )
{
    struct IVRIOBuffer_IVRIOBuffer_001_Close_params *params = (struct IVRIOBuffer_IVRIOBuffer_001_Close_params *)args;
    struct u_IVRIOBuffer_IVRIOBuffer_001 *iface = (struct u_IVRIOBuffer_IVRIOBuffer_001 *)params->u_iface;
    params->_ret = iface->Close( params->ulBuffer );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRIOBuffer_IVRIOBuffer_001_Close( void *args )
{
    struct wow64_IVRIOBuffer_IVRIOBuffer_001_Close_params *params = (struct wow64_IVRIOBuffer_IVRIOBuffer_001_Close_params *)args;
    struct u_IVRIOBuffer_IVRIOBuffer_001 *iface = (struct u_IVRIOBuffer_IVRIOBuffer_001 *)params->u_iface;
    params->_ret = iface->Close( params->ulBuffer );
    return 0;
}
#endif

NTSTATUS IVRIOBuffer_IVRIOBuffer_001_Read( void *args )
{
    struct IVRIOBuffer_IVRIOBuffer_001_Read_params *params = (struct IVRIOBuffer_IVRIOBuffer_001_Read_params *)args;
    struct u_IVRIOBuffer_IVRIOBuffer_001 *iface = (struct u_IVRIOBuffer_IVRIOBuffer_001 *)params->u_iface;
    params->_ret = iface->Read( params->ulBuffer, params->pDst, params->unBytes, params->punRead );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRIOBuffer_IVRIOBuffer_001_Read( void *args )
{
    struct wow64_IVRIOBuffer_IVRIOBuffer_001_Read_params *params = (struct wow64_IVRIOBuffer_IVRIOBuffer_001_Read_params *)args;
    struct u_IVRIOBuffer_IVRIOBuffer_001 *iface = (struct u_IVRIOBuffer_IVRIOBuffer_001 *)params->u_iface;
    params->_ret = iface->Read( params->ulBuffer, params->pDst, params->unBytes, params->punRead );
    return 0;
}
#endif

NTSTATUS IVRIOBuffer_IVRIOBuffer_001_Write( void *args )
{
    struct IVRIOBuffer_IVRIOBuffer_001_Write_params *params = (struct IVRIOBuffer_IVRIOBuffer_001_Write_params *)args;
    struct u_IVRIOBuffer_IVRIOBuffer_001 *iface = (struct u_IVRIOBuffer_IVRIOBuffer_001 *)params->u_iface;
    params->_ret = iface->Write( params->ulBuffer, params->pSrc, params->unBytes );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRIOBuffer_IVRIOBuffer_001_Write( void *args )
{
    struct wow64_IVRIOBuffer_IVRIOBuffer_001_Write_params *params = (struct wow64_IVRIOBuffer_IVRIOBuffer_001_Write_params *)args;
    struct u_IVRIOBuffer_IVRIOBuffer_001 *iface = (struct u_IVRIOBuffer_IVRIOBuffer_001 *)params->u_iface;
    params->_ret = iface->Write( params->ulBuffer, params->pSrc, params->unBytes );
    return 0;
}
#endif

NTSTATUS IVRIOBuffer_IVRIOBuffer_001_PropertyContainer( void *args )
{
    struct IVRIOBuffer_IVRIOBuffer_001_PropertyContainer_params *params = (struct IVRIOBuffer_IVRIOBuffer_001_PropertyContainer_params *)args;
    struct u_IVRIOBuffer_IVRIOBuffer_001 *iface = (struct u_IVRIOBuffer_IVRIOBuffer_001 *)params->u_iface;
    params->_ret = iface->PropertyContainer( params->ulBuffer );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRIOBuffer_IVRIOBuffer_001_PropertyContainer( void *args )
{
    struct wow64_IVRIOBuffer_IVRIOBuffer_001_PropertyContainer_params *params = (struct wow64_IVRIOBuffer_IVRIOBuffer_001_PropertyContainer_params *)args;
    struct u_IVRIOBuffer_IVRIOBuffer_001 *iface = (struct u_IVRIOBuffer_IVRIOBuffer_001 *)params->u_iface;
    params->_ret = iface->PropertyContainer( params->ulBuffer );
    return 0;
}
#endif

