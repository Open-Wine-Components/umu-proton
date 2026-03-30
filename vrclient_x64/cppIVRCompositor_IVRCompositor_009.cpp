/* This file is auto-generated, do not edit. */
#include "unix_private.h"

#if 0
#pragma makedep unix
#endif

NTSTATUS IVRCompositor_IVRCompositor_009_SetTrackingSpace( void *args )
{
    struct IVRCompositor_IVRCompositor_009_SetTrackingSpace_params *params = (struct IVRCompositor_IVRCompositor_009_SetTrackingSpace_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    iface->SetTrackingSpace( params->eOrigin );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRCompositor_IVRCompositor_009_SetTrackingSpace( void *args )
{
    struct wow64_IVRCompositor_IVRCompositor_009_SetTrackingSpace_params *params = (struct wow64_IVRCompositor_IVRCompositor_009_SetTrackingSpace_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    iface->SetTrackingSpace( params->eOrigin );
    return 0;
}
#endif

NTSTATUS IVRCompositor_IVRCompositor_009_GetTrackingSpace( void *args )
{
    struct IVRCompositor_IVRCompositor_009_GetTrackingSpace_params *params = (struct IVRCompositor_IVRCompositor_009_GetTrackingSpace_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    params->_ret = iface->GetTrackingSpace(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRCompositor_IVRCompositor_009_GetTrackingSpace( void *args )
{
    struct wow64_IVRCompositor_IVRCompositor_009_GetTrackingSpace_params *params = (struct wow64_IVRCompositor_IVRCompositor_009_GetTrackingSpace_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    params->_ret = iface->GetTrackingSpace(  );
    return 0;
}
#endif

NTSTATUS IVRCompositor_IVRCompositor_009_WaitGetPoses( void *args )
{
    struct IVRCompositor_IVRCompositor_009_WaitGetPoses_params *params = (struct IVRCompositor_IVRCompositor_009_WaitGetPoses_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    params->_ret = iface->WaitGetPoses( params->pRenderPoseArray, params->unRenderPoseArrayCount, params->pGamePoseArray, params->unGamePoseArrayCount );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRCompositor_IVRCompositor_009_WaitGetPoses( void *args )
{
    struct wow64_IVRCompositor_IVRCompositor_009_WaitGetPoses_params *params = (struct wow64_IVRCompositor_IVRCompositor_009_WaitGetPoses_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    params->_ret = iface->WaitGetPoses( params->pRenderPoseArray, params->unRenderPoseArrayCount, params->pGamePoseArray, params->unGamePoseArrayCount );
    return 0;
}
#endif

NTSTATUS IVRCompositor_IVRCompositor_009_GetLastPoses( void *args )
{
    struct IVRCompositor_IVRCompositor_009_GetLastPoses_params *params = (struct IVRCompositor_IVRCompositor_009_GetLastPoses_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    params->_ret = iface->GetLastPoses( params->pRenderPoseArray, params->unRenderPoseArrayCount, params->pGamePoseArray, params->unGamePoseArrayCount );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRCompositor_IVRCompositor_009_GetLastPoses( void *args )
{
    struct wow64_IVRCompositor_IVRCompositor_009_GetLastPoses_params *params = (struct wow64_IVRCompositor_IVRCompositor_009_GetLastPoses_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    params->_ret = iface->GetLastPoses( params->pRenderPoseArray, params->unRenderPoseArrayCount, params->pGamePoseArray, params->unGamePoseArrayCount );
    return 0;
}
#endif

NTSTATUS IVRCompositor_IVRCompositor_009_ClearLastSubmittedFrame( void *args )
{
    struct IVRCompositor_IVRCompositor_009_ClearLastSubmittedFrame_params *params = (struct IVRCompositor_IVRCompositor_009_ClearLastSubmittedFrame_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    iface->ClearLastSubmittedFrame(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRCompositor_IVRCompositor_009_ClearLastSubmittedFrame( void *args )
{
    struct wow64_IVRCompositor_IVRCompositor_009_ClearLastSubmittedFrame_params *params = (struct wow64_IVRCompositor_IVRCompositor_009_ClearLastSubmittedFrame_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    iface->ClearLastSubmittedFrame(  );
    return 0;
}
#endif

NTSTATUS IVRCompositor_IVRCompositor_009_PostPresentHandoff( void *args )
{
    struct IVRCompositor_IVRCompositor_009_PostPresentHandoff_params *params = (struct IVRCompositor_IVRCompositor_009_PostPresentHandoff_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    iface->PostPresentHandoff(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRCompositor_IVRCompositor_009_PostPresentHandoff( void *args )
{
    struct wow64_IVRCompositor_IVRCompositor_009_PostPresentHandoff_params *params = (struct wow64_IVRCompositor_IVRCompositor_009_PostPresentHandoff_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    iface->PostPresentHandoff(  );
    return 0;
}
#endif

NTSTATUS IVRCompositor_IVRCompositor_009_GetFrameTiming( void *args )
{
    struct IVRCompositor_IVRCompositor_009_GetFrameTiming_params *params = (struct IVRCompositor_IVRCompositor_009_GetFrameTiming_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    u_Compositor_FrameTiming_0913 u_pTiming;
    if (params->pTiming) u_pTiming = *params->pTiming;
    params->_ret = iface->GetFrameTiming( params->pTiming ? &u_pTiming : nullptr, params->unFramesAgo );
    if (params->pTiming) *params->pTiming = u_pTiming;
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRCompositor_IVRCompositor_009_GetFrameTiming( void *args )
{
    struct wow64_IVRCompositor_IVRCompositor_009_GetFrameTiming_params *params = (struct wow64_IVRCompositor_IVRCompositor_009_GetFrameTiming_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    u_Compositor_FrameTiming_0913 u_pTiming;
    if (params->pTiming) u_pTiming = *params->pTiming;
    params->_ret = iface->GetFrameTiming( params->pTiming ? &u_pTiming : nullptr, params->unFramesAgo );
    if (params->pTiming) *params->pTiming = u_pTiming;
    return 0;
}
#endif

NTSTATUS IVRCompositor_IVRCompositor_009_GetFrameTimeRemaining( void *args )
{
    struct IVRCompositor_IVRCompositor_009_GetFrameTimeRemaining_params *params = (struct IVRCompositor_IVRCompositor_009_GetFrameTimeRemaining_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    params->_ret = iface->GetFrameTimeRemaining(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRCompositor_IVRCompositor_009_GetFrameTimeRemaining( void *args )
{
    struct wow64_IVRCompositor_IVRCompositor_009_GetFrameTimeRemaining_params *params = (struct wow64_IVRCompositor_IVRCompositor_009_GetFrameTimeRemaining_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    params->_ret = iface->GetFrameTimeRemaining(  );
    return 0;
}
#endif

NTSTATUS IVRCompositor_IVRCompositor_009_FadeToColor( void *args )
{
    struct IVRCompositor_IVRCompositor_009_FadeToColor_params *params = (struct IVRCompositor_IVRCompositor_009_FadeToColor_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    iface->FadeToColor( params->fSeconds, params->fRed, params->fGreen, params->fBlue, params->fAlpha, params->bBackground );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRCompositor_IVRCompositor_009_FadeToColor( void *args )
{
    struct wow64_IVRCompositor_IVRCompositor_009_FadeToColor_params *params = (struct wow64_IVRCompositor_IVRCompositor_009_FadeToColor_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    iface->FadeToColor( params->fSeconds, params->fRed, params->fGreen, params->fBlue, params->fAlpha, params->bBackground );
    return 0;
}
#endif

NTSTATUS IVRCompositor_IVRCompositor_009_FadeGrid( void *args )
{
    struct IVRCompositor_IVRCompositor_009_FadeGrid_params *params = (struct IVRCompositor_IVRCompositor_009_FadeGrid_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    iface->FadeGrid( params->fSeconds, params->bFadeIn );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRCompositor_IVRCompositor_009_FadeGrid( void *args )
{
    struct wow64_IVRCompositor_IVRCompositor_009_FadeGrid_params *params = (struct wow64_IVRCompositor_IVRCompositor_009_FadeGrid_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    iface->FadeGrid( params->fSeconds, params->bFadeIn );
    return 0;
}
#endif

NTSTATUS IVRCompositor_IVRCompositor_009_ClearSkyboxOverride( void *args )
{
    struct IVRCompositor_IVRCompositor_009_ClearSkyboxOverride_params *params = (struct IVRCompositor_IVRCompositor_009_ClearSkyboxOverride_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    iface->ClearSkyboxOverride(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRCompositor_IVRCompositor_009_ClearSkyboxOverride( void *args )
{
    struct wow64_IVRCompositor_IVRCompositor_009_ClearSkyboxOverride_params *params = (struct wow64_IVRCompositor_IVRCompositor_009_ClearSkyboxOverride_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    iface->ClearSkyboxOverride(  );
    return 0;
}
#endif

NTSTATUS IVRCompositor_IVRCompositor_009_CompositorBringToFront( void *args )
{
    struct IVRCompositor_IVRCompositor_009_CompositorBringToFront_params *params = (struct IVRCompositor_IVRCompositor_009_CompositorBringToFront_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    iface->CompositorBringToFront(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRCompositor_IVRCompositor_009_CompositorBringToFront( void *args )
{
    struct wow64_IVRCompositor_IVRCompositor_009_CompositorBringToFront_params *params = (struct wow64_IVRCompositor_IVRCompositor_009_CompositorBringToFront_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    iface->CompositorBringToFront(  );
    return 0;
}
#endif

NTSTATUS IVRCompositor_IVRCompositor_009_CompositorGoToBack( void *args )
{
    struct IVRCompositor_IVRCompositor_009_CompositorGoToBack_params *params = (struct IVRCompositor_IVRCompositor_009_CompositorGoToBack_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    iface->CompositorGoToBack(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRCompositor_IVRCompositor_009_CompositorGoToBack( void *args )
{
    struct wow64_IVRCompositor_IVRCompositor_009_CompositorGoToBack_params *params = (struct wow64_IVRCompositor_IVRCompositor_009_CompositorGoToBack_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    iface->CompositorGoToBack(  );
    return 0;
}
#endif

NTSTATUS IVRCompositor_IVRCompositor_009_CompositorQuit( void *args )
{
    struct IVRCompositor_IVRCompositor_009_CompositorQuit_params *params = (struct IVRCompositor_IVRCompositor_009_CompositorQuit_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    iface->CompositorQuit(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRCompositor_IVRCompositor_009_CompositorQuit( void *args )
{
    struct wow64_IVRCompositor_IVRCompositor_009_CompositorQuit_params *params = (struct wow64_IVRCompositor_IVRCompositor_009_CompositorQuit_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    iface->CompositorQuit(  );
    return 0;
}
#endif

NTSTATUS IVRCompositor_IVRCompositor_009_IsFullscreen( void *args )
{
    struct IVRCompositor_IVRCompositor_009_IsFullscreen_params *params = (struct IVRCompositor_IVRCompositor_009_IsFullscreen_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    params->_ret = iface->IsFullscreen(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRCompositor_IVRCompositor_009_IsFullscreen( void *args )
{
    struct wow64_IVRCompositor_IVRCompositor_009_IsFullscreen_params *params = (struct wow64_IVRCompositor_IVRCompositor_009_IsFullscreen_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    params->_ret = iface->IsFullscreen(  );
    return 0;
}
#endif

NTSTATUS IVRCompositor_IVRCompositor_009_GetCurrentSceneFocusProcess( void *args )
{
    struct IVRCompositor_IVRCompositor_009_GetCurrentSceneFocusProcess_params *params = (struct IVRCompositor_IVRCompositor_009_GetCurrentSceneFocusProcess_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    params->_ret = iface->GetCurrentSceneFocusProcess(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRCompositor_IVRCompositor_009_GetCurrentSceneFocusProcess( void *args )
{
    struct wow64_IVRCompositor_IVRCompositor_009_GetCurrentSceneFocusProcess_params *params = (struct wow64_IVRCompositor_IVRCompositor_009_GetCurrentSceneFocusProcess_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    params->_ret = iface->GetCurrentSceneFocusProcess(  );
    return 0;
}
#endif

NTSTATUS IVRCompositor_IVRCompositor_009_GetLastFrameRenderer( void *args )
{
    struct IVRCompositor_IVRCompositor_009_GetLastFrameRenderer_params *params = (struct IVRCompositor_IVRCompositor_009_GetLastFrameRenderer_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    params->_ret = iface->GetLastFrameRenderer(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRCompositor_IVRCompositor_009_GetLastFrameRenderer( void *args )
{
    struct wow64_IVRCompositor_IVRCompositor_009_GetLastFrameRenderer_params *params = (struct wow64_IVRCompositor_IVRCompositor_009_GetLastFrameRenderer_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    params->_ret = iface->GetLastFrameRenderer(  );
    return 0;
}
#endif

NTSTATUS IVRCompositor_IVRCompositor_009_CanRenderScene( void *args )
{
    struct IVRCompositor_IVRCompositor_009_CanRenderScene_params *params = (struct IVRCompositor_IVRCompositor_009_CanRenderScene_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    params->_ret = iface->CanRenderScene(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRCompositor_IVRCompositor_009_CanRenderScene( void *args )
{
    struct wow64_IVRCompositor_IVRCompositor_009_CanRenderScene_params *params = (struct wow64_IVRCompositor_IVRCompositor_009_CanRenderScene_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    params->_ret = iface->CanRenderScene(  );
    return 0;
}
#endif

NTSTATUS IVRCompositor_IVRCompositor_009_ShowMirrorWindow( void *args )
{
    struct IVRCompositor_IVRCompositor_009_ShowMirrorWindow_params *params = (struct IVRCompositor_IVRCompositor_009_ShowMirrorWindow_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    iface->ShowMirrorWindow(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRCompositor_IVRCompositor_009_ShowMirrorWindow( void *args )
{
    struct wow64_IVRCompositor_IVRCompositor_009_ShowMirrorWindow_params *params = (struct wow64_IVRCompositor_IVRCompositor_009_ShowMirrorWindow_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    iface->ShowMirrorWindow(  );
    return 0;
}
#endif

NTSTATUS IVRCompositor_IVRCompositor_009_HideMirrorWindow( void *args )
{
    struct IVRCompositor_IVRCompositor_009_HideMirrorWindow_params *params = (struct IVRCompositor_IVRCompositor_009_HideMirrorWindow_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    iface->HideMirrorWindow(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRCompositor_IVRCompositor_009_HideMirrorWindow( void *args )
{
    struct wow64_IVRCompositor_IVRCompositor_009_HideMirrorWindow_params *params = (struct wow64_IVRCompositor_IVRCompositor_009_HideMirrorWindow_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    iface->HideMirrorWindow(  );
    return 0;
}
#endif

NTSTATUS IVRCompositor_IVRCompositor_009_IsMirrorWindowVisible( void *args )
{
    struct IVRCompositor_IVRCompositor_009_IsMirrorWindowVisible_params *params = (struct IVRCompositor_IVRCompositor_009_IsMirrorWindowVisible_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    params->_ret = iface->IsMirrorWindowVisible(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRCompositor_IVRCompositor_009_IsMirrorWindowVisible( void *args )
{
    struct wow64_IVRCompositor_IVRCompositor_009_IsMirrorWindowVisible_params *params = (struct wow64_IVRCompositor_IVRCompositor_009_IsMirrorWindowVisible_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    params->_ret = iface->IsMirrorWindowVisible(  );
    return 0;
}
#endif

NTSTATUS IVRCompositor_IVRCompositor_009_CompositorDumpImages( void *args )
{
    struct IVRCompositor_IVRCompositor_009_CompositorDumpImages_params *params = (struct IVRCompositor_IVRCompositor_009_CompositorDumpImages_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    iface->CompositorDumpImages(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRCompositor_IVRCompositor_009_CompositorDumpImages( void *args )
{
    struct wow64_IVRCompositor_IVRCompositor_009_CompositorDumpImages_params *params = (struct wow64_IVRCompositor_IVRCompositor_009_CompositorDumpImages_params *)args;
    struct u_IVRCompositor_IVRCompositor_009 *iface = (struct u_IVRCompositor_IVRCompositor_009 *)params->u_iface;
    iface->CompositorDumpImages(  );
    return 0;
}
#endif

