/* This file is auto-generated, do not edit. */
#include <stdarg.h>
#include <stdint.h>

#include "vrclient_private.h"

#include "flatapi.h"

WINE_DEFAULT_DEBUG_CHANNEL(vrclient);

DEFINE_THISCALL_WRAPPER(winIVROverlayView_IVROverlayView_003_AcquireOverlayView, 24)
DEFINE_THISCALL_WRAPPER(winIVROverlayView_IVROverlayView_003_ReleaseOverlayView, 8)
DEFINE_THISCALL_WRAPPER(winIVROverlayView_IVROverlayView_003_PostOverlayEvent, 16)
DEFINE_THISCALL_WRAPPER(winIVROverlayView_IVROverlayView_003_IsViewingPermitted, 12)

uint32_t __thiscall winIVROverlayView_IVROverlayView_003_AcquireOverlayView(struct w_iface *_this, uint64_t ulOverlayHandle, w_VRNativeDevice_t *pNativeDevice, w_VROverlayView_t *pOverlayView, uint32_t unOverlayViewSize)
{
    struct IVROverlayView_IVROverlayView_003_AcquireOverlayView_params params =
    {
        .u_iface = _this->u_iface,
        .ulOverlayHandle = ulOverlayHandle,
        .pNativeDevice = pNativeDevice,
        .pOverlayView = pOverlayView,
        .unOverlayViewSize = unOverlayViewSize,
    };
    TRACE("%p\n", _this);
    VRCLIENT_CALL( IVROverlayView_IVROverlayView_003_AcquireOverlayView, &params );
    return params._ret;
}

uint32_t __thiscall winIVROverlayView_IVROverlayView_003_ReleaseOverlayView(struct w_iface *_this, w_VROverlayView_t *pOverlayView)
{
    struct IVROverlayView_IVROverlayView_003_ReleaseOverlayView_params params =
    {
        .u_iface = _this->u_iface,
        .pOverlayView = pOverlayView,
    };
    TRACE("%p\n", _this);
    VRCLIENT_CALL( IVROverlayView_IVROverlayView_003_ReleaseOverlayView, &params );
    return params._ret;
}

void __thiscall winIVROverlayView_IVROverlayView_003_PostOverlayEvent(struct w_iface *_this, uint64_t ulOverlayHandle, const w_VREvent_t_223 *pvrEvent)
{
    struct IVROverlayView_IVROverlayView_003_PostOverlayEvent_params params =
    {
        .u_iface = _this->u_iface,
        .ulOverlayHandle = ulOverlayHandle,
        .pvrEvent = pvrEvent,
    };
    TRACE("%p\n", _this);
    VRCLIENT_CALL( IVROverlayView_IVROverlayView_003_PostOverlayEvent, &params );
}

int8_t __thiscall winIVROverlayView_IVROverlayView_003_IsViewingPermitted(struct w_iface *_this, uint64_t ulOverlayHandle)
{
    struct IVROverlayView_IVROverlayView_003_IsViewingPermitted_params params =
    {
        .u_iface = _this->u_iface,
        .ulOverlayHandle = ulOverlayHandle,
    };
    TRACE("%p\n", _this);
    VRCLIENT_CALL( IVROverlayView_IVROverlayView_003_IsViewingPermitted, &params );
    return params._ret;
}

extern vtable_ptr winIVROverlayView_IVROverlayView_003_vtable;

DEFINE_RTTI_DATA0(winIVROverlayView_IVROverlayView_003, 0, ".?AVIVROverlayView@@")

__ASM_BLOCK_BEGIN(winIVROverlayView_IVROverlayView_003_vtables)
    __ASM_VTABLE(winIVROverlayView_IVROverlayView_003,
        VTABLE_ADD_FUNC(winIVROverlayView_IVROverlayView_003_AcquireOverlayView)
        VTABLE_ADD_FUNC(winIVROverlayView_IVROverlayView_003_ReleaseOverlayView)
        VTABLE_ADD_FUNC(winIVROverlayView_IVROverlayView_003_PostOverlayEvent)
        VTABLE_ADD_FUNC(winIVROverlayView_IVROverlayView_003_IsViewingPermitted)
    );
__ASM_BLOCK_END

struct w_iface *create_winIVROverlayView_IVROverlayView_003( struct u_iface u_iface )
{
    struct w_iface *r = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(*r));
    TRACE("-> %p\n", r);
    r->vtable = &winIVROverlayView_IVROverlayView_003_vtable;
    r->u_iface = u_iface;
    return r;
}

void destroy_winIVROverlayView_IVROverlayView_003(struct w_iface *object)
{
    TRACE("%p\n", object);
    HeapFree(GetProcessHeap(), 0, object);
}

struct w_iface *create_winIVROverlayView_IVROverlayView_003_FnTable( struct u_iface u_iface )
{
    struct w_iface *r = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(*r));
    struct thunk *thunks = alloc_thunks(4);
    struct thunk **vtable = HeapAlloc(GetProcessHeap(), 0, 4 * sizeof(*vtable));
    int i;

    TRACE("-> %p, vtable %p, thunks %p\n", r, vtable, thunks);
    init_thunk(&thunks[0], r, winIVROverlayView_IVROverlayView_003_AcquireOverlayView, 4, FALSE, FALSE);
    init_thunk(&thunks[1], r, winIVROverlayView_IVROverlayView_003_ReleaseOverlayView, 1, FALSE, FALSE);
    init_thunk(&thunks[2], r, winIVROverlayView_IVROverlayView_003_PostOverlayEvent, 2, FALSE, FALSE);
    init_thunk(&thunks[3], r, winIVROverlayView_IVROverlayView_003_IsViewingPermitted, 1, FALSE, FALSE);
    for (i = 0; i < 4; i++)
        vtable[i] = &thunks[i];
    r->u_iface = u_iface;
    r->vtable = (void *)vtable;
    return r;
}

void destroy_winIVROverlayView_IVROverlayView_003_FnTable(struct w_iface *object)
{
    TRACE("%p\n", object);
    VirtualFree(object->vtable[0], 0, MEM_RELEASE);
    HeapFree(GetProcessHeap(), 0, object->vtable);
    HeapFree(GetProcessHeap(), 0, object);
}

void init_winIVROverlayView_rtti( char *base )
{
#if defined(__x86_64__) || defined(__aarch64__)
    init_winIVROverlayView_IVROverlayView_003_rtti( base );
#endif /* defined(__x86_64__) || defined(__aarch64__) */
}
