/* This file is auto-generated, do not edit. */
#include "unix_private.h"

NTSTATUS IVRScreenshots_IVRScreenshots_001_RequestScreenshot( void *args )
{
    struct IVRScreenshots_IVRScreenshots_001_RequestScreenshot_params *params = (struct IVRScreenshots_IVRScreenshots_001_RequestScreenshot_params *)args;
    struct u_IVRScreenshots_IVRScreenshots_001 *iface = (struct u_IVRScreenshots_IVRScreenshots_001 *)params->linux_side;
    char *u_pchPreviewFilename = vrclient_dos_to_unix_path( params->pchPreviewFilename );
    char *u_pchVRFilename = vrclient_dos_to_unix_path( params->pchVRFilename );
    params->_ret = (uint32_t)iface->RequestScreenshot( params->pOutScreenshotHandle, params->type, u_pchPreviewFilename, u_pchVRFilename );
    vrclient_free_path( u_pchPreviewFilename );
    vrclient_free_path( u_pchVRFilename );
    return 0;
}

NTSTATUS IVRScreenshots_IVRScreenshots_001_HookScreenshot( void *args )
{
    struct IVRScreenshots_IVRScreenshots_001_HookScreenshot_params *params = (struct IVRScreenshots_IVRScreenshots_001_HookScreenshot_params *)args;
    struct u_IVRScreenshots_IVRScreenshots_001 *iface = (struct u_IVRScreenshots_IVRScreenshots_001 *)params->linux_side;
    params->_ret = (uint32_t)iface->HookScreenshot( params->pSupportedTypes, params->numTypes );
    return 0;
}

NTSTATUS IVRScreenshots_IVRScreenshots_001_GetScreenshotPropertyType( void *args )
{
    struct IVRScreenshots_IVRScreenshots_001_GetScreenshotPropertyType_params *params = (struct IVRScreenshots_IVRScreenshots_001_GetScreenshotPropertyType_params *)args;
    struct u_IVRScreenshots_IVRScreenshots_001 *iface = (struct u_IVRScreenshots_IVRScreenshots_001 *)params->linux_side;
    params->_ret = (uint32_t)iface->GetScreenshotPropertyType( params->screenshotHandle, params->pError );
    return 0;
}

NTSTATUS IVRScreenshots_IVRScreenshots_001_GetScreenshotPropertyFilename( void *args )
{
    struct IVRScreenshots_IVRScreenshots_001_GetScreenshotPropertyFilename_params *params = (struct IVRScreenshots_IVRScreenshots_001_GetScreenshotPropertyFilename_params *)args;
    struct u_IVRScreenshots_IVRScreenshots_001 *iface = (struct u_IVRScreenshots_IVRScreenshots_001 *)params->linux_side;
    params->_ret = (uint32_t)iface->GetScreenshotPropertyFilename( params->screenshotHandle, params->filenameType, params->pchFilename, params->cchFilename, params->pError );
    return 0;
}

NTSTATUS IVRScreenshots_IVRScreenshots_001_UpdateScreenshotProgress( void *args )
{
    struct IVRScreenshots_IVRScreenshots_001_UpdateScreenshotProgress_params *params = (struct IVRScreenshots_IVRScreenshots_001_UpdateScreenshotProgress_params *)args;
    struct u_IVRScreenshots_IVRScreenshots_001 *iface = (struct u_IVRScreenshots_IVRScreenshots_001 *)params->linux_side;
    params->_ret = (uint32_t)iface->UpdateScreenshotProgress( params->screenshotHandle, params->flProgress );
    return 0;
}

NTSTATUS IVRScreenshots_IVRScreenshots_001_TakeStereoScreenshot( void *args )
{
    struct IVRScreenshots_IVRScreenshots_001_TakeStereoScreenshot_params *params = (struct IVRScreenshots_IVRScreenshots_001_TakeStereoScreenshot_params *)args;
    struct u_IVRScreenshots_IVRScreenshots_001 *iface = (struct u_IVRScreenshots_IVRScreenshots_001 *)params->linux_side;
    char *u_pchPreviewFilename = vrclient_dos_to_unix_path( params->pchPreviewFilename );
    char *u_pchVRFilename = vrclient_dos_to_unix_path( params->pchVRFilename );
    params->_ret = (uint32_t)iface->TakeStereoScreenshot( params->pOutScreenshotHandle, u_pchPreviewFilename, u_pchVRFilename );
    vrclient_free_path( u_pchPreviewFilename );
    vrclient_free_path( u_pchVRFilename );
    return 0;
}

NTSTATUS IVRScreenshots_IVRScreenshots_001_SubmitScreenshot( void *args )
{
    struct IVRScreenshots_IVRScreenshots_001_SubmitScreenshot_params *params = (struct IVRScreenshots_IVRScreenshots_001_SubmitScreenshot_params *)args;
    struct u_IVRScreenshots_IVRScreenshots_001 *iface = (struct u_IVRScreenshots_IVRScreenshots_001 *)params->linux_side;
    char *u_pchSourcePreviewFilename = vrclient_dos_to_unix_path( params->pchSourcePreviewFilename );
    char *u_pchSourceVRFilename = vrclient_dos_to_unix_path( params->pchSourceVRFilename );
    params->_ret = (uint32_t)iface->SubmitScreenshot( params->screenshotHandle, params->type, u_pchSourcePreviewFilename, u_pchSourceVRFilename );
    vrclient_free_path( u_pchSourcePreviewFilename );
    vrclient_free_path( u_pchSourceVRFilename );
    return 0;
}

