#include "unix_private.h"

#if 0
#pragma makedep unix
#endif

template< typename Iface, typename Params >
static NTSTATUS IVRRenderModels_LoadRenderModel( Iface *iface, Params *params, bool wow64 )
{
    static std::remove_reference_t< decltype(**params->ppRenderModel) > tag;
    struct render_model *model = params->ppRenderModel ? render_model::from_w( *params->ppRenderModel ) : NULL;
    params->_ret = iface->LoadRenderModel( params->pchRenderModelName, params->ppRenderModel ? &model->u_model( tag ) : nullptr );
    if (params->_ret == 0 && model) model->w_model( tag ) = *model->u_model( tag );
    return 0;
}

template< typename Iface, typename Params >
static NTSTATUS IVRRenderModels_FreeRenderModel( Iface *iface, Params *params, bool wow64 )
{
    static std::remove_reference_t< decltype(*params->pRenderModel) > tag;
    struct render_model *model = params->pRenderModel ? render_model::from_w( params->pRenderModel ) : NULL;
    iface->FreeRenderModel( model->u_model( tag ) );
    return 0;
}

template< typename Iface, typename Params >
static NTSTATUS IVRRenderModels_LoadRenderModel_Async( Iface *iface, Params *params, bool wow64 )
{
    static std::remove_reference_t< decltype(**params->ppRenderModel) > tag;
    struct render_model *model = params->ppRenderModel ? render_model::from_w( *params->ppRenderModel ) : NULL;
    params->_ret = iface->LoadRenderModel_Async( params->pchRenderModelName, params->ppRenderModel ? &model->u_model( tag ) : nullptr );
    if (params->_ret == 0 && model) model->w_model( tag ) = *model->u_model( tag );
    return 0;
}

template< typename Iface, typename Params >
static NTSTATUS IVRRenderModels_LoadTexture( Iface *iface, Params *params, bool wow64 )
{
    static std::remove_reference_t< decltype(**params->ppTexture) > tag;
    struct render_model_texture_map *map = params->ppTexture ? render_model_texture_map::from_w( *params->ppTexture ) : NULL;
    params->_ret = iface->LoadTexture( params->textureId, params->ppTexture ? &map->u_map( tag ) : nullptr );
    if (params->_ret == 0 && map) map->w_map( tag ) = *map->u_map( tag );
    return 0;
}

template< typename Iface, typename Params >
static NTSTATUS IVRRenderModels_FreeTexture( Iface *iface, Params *params, bool wow64 )
{
    static std::remove_reference_t< decltype(*params->pTexture) > tag;
    struct render_model_texture_map *map = params->pTexture ? render_model_texture_map::from_w( params->pTexture ) : NULL;
    iface->FreeTexture( map->u_map( tag ) );
    return 0;
}

template< typename Iface, typename Params >
static NTSTATUS IVRRenderModels_LoadTexture_Async( Iface *iface, Params *params, bool wow64 )
{
    static std::remove_reference_t< decltype(**params->ppTexture) > tag;
    struct render_model_texture_map *map = params->ppTexture ? render_model_texture_map::from_w( *params->ppTexture ) : NULL;
    params->_ret = iface->LoadTexture_Async( params->textureId, params->ppTexture ? &map->u_map( tag ) : nullptr );
    if (params->_ret == 0 && map) map->w_map( tag ) = *map->u_map( tag );
    return 0;
}

VRCLIENT_UNIX_IMPL( IVRRenderModels, 002, FreeRenderModel );
VRCLIENT_UNIX_IMPL( IVRRenderModels, 002, FreeTexture );
VRCLIENT_UNIX_IMPL( IVRRenderModels, 002, LoadRenderModel );
VRCLIENT_UNIX_IMPL( IVRRenderModels, 002, LoadTexture );
VRCLIENT_UNIX_IMPL( IVRRenderModels, 004, FreeRenderModel );
VRCLIENT_UNIX_IMPL( IVRRenderModels, 004, FreeTexture );
VRCLIENT_UNIX_IMPL( IVRRenderModels, 004, LoadRenderModel_Async );
VRCLIENT_UNIX_IMPL( IVRRenderModels, 004, LoadTexture_Async );
VRCLIENT_UNIX_IMPL( IVRRenderModels, 005, FreeRenderModel );
VRCLIENT_UNIX_IMPL( IVRRenderModels, 005, FreeTexture );
VRCLIENT_UNIX_IMPL( IVRRenderModels, 005, LoadRenderModel_Async );
VRCLIENT_UNIX_IMPL( IVRRenderModels, 005, LoadTexture_Async );
VRCLIENT_UNIX_IMPL( IVRRenderModels, 006, FreeRenderModel );
VRCLIENT_UNIX_IMPL( IVRRenderModels, 006, FreeTexture );
VRCLIENT_UNIX_IMPL( IVRRenderModels, 006, LoadRenderModel_Async );
VRCLIENT_UNIX_IMPL( IVRRenderModels, 006, LoadTexture_Async );
