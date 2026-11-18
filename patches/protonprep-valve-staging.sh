#!/bin/bash

# patch functions
apply_patch() {
    local patch_path="$1"
    patch -Np1 < "$patch_path"
}

apply_all_in_dir() {
    local dir="$1"
    for patch in "$dir"/*.patch; do
        apply_patch "$patch"
    done
}

### (1) PREP SECTION ###

    pushd dxvk
    git reset --hard HEAD
    git clean -xdf
    popd

    pushd vkd3d-proton
    git reset --hard HEAD
    git clean -xdf
    popd

    pushd dxvk-nvapi
    git reset --hard HEAD
    git clean -xdf
    popd

    pushd openvr
    git reset --hard HEAD
    git clean -xdf
    echo "OPENVR: do not assume MSVC when _WIN32 is defined (clang build fix)"
    apply_patch "../patches/openvr/openvr-no-msvc-assumption.patch"
    popd

    pushd gstreamer
    git reset --hard HEAD
    git clean -xdf
    echo "GSTREAMER: fix for unclosable invisible wayland opengl windows in taskbar"
    apply_all_in_dir "../patches/gstreamer/"
    popd

    pushd protonfixes
    git reset --hard HEAD
    git clean -xdf
    popd

    pushd wineopenxr
    git checkout .
    git clean -xdf
    echo "WINEOPENXR: patch wineopenxr so it can be built as part of wine and used outside of steam"
    apply_all_in_dir "../patches/wineopenxr/"
    popd

### END PREP SECTION ###

    git checkout steam_helper
    git checkout umu_helper

    # Ubisoft games stayed "Running" in Steam after quitting: https://github.com/ValveSoftware/Proton/pull/10356
    echo "STEAM_HELPER: close Ubisoft Connect after the game exits"
    apply_all_in_dir "patches/steam_helper"

    git checkout -- piper/CMakeLists.txt

    echo "PIPER: take the prebuilt onnxruntime from NuGet, the GitHub release downloads are gone"
    apply_all_in_dir "patches/piper"

    git checkout -- \
        lsteamclient/unix_private.h \
        lsteamclient/unixlib.cpp

    echo "LSTEAMCLIENT: build with clang and libc++"
    apply_all_in_dir "patches/lsteamclient"

    git checkout -- \
        vrclient_x64/json_converter.cpp \
        vrclient_x64/unix_private.h

    echo "VRCLIENT: build with clang and libc++"
    apply_all_in_dir "patches/vrclient"

### (2) WINE PATCHING ###

    pushd wine
    git reset --hard HEAD
    git clean -xdf

### (2-1) PROBLEMATIC COMMIT REVERT SECTION ###

# Bring back configure files. Staging uses them to regenerate fresh ones
# https://github.com/ValveSoftware/wine/commit/e813ca5771658b00875924ab88d525322e50d39f

    git revert --no-commit e813ca5771658b00875924ab88d525322e50d39f

### END PROBLEMATIC COMMIT REVERT SECTION ###

    echo "WINE: -WINEOPENXR- copy files into wine"
    mkdir -p dlls/wineopenxr
    cp -R ../wineopenxr/* dlls/wineopenxr/

### (2-4) GAME PATCH SECTION ###

    echo "WINE: -GAME FIXES- assetto corsa hud fix"
    apply_patch "../patches/game-patches/assettocorsa-hud.patch"

    echo "WINE: -GAME FIXES- add file search workaround hack for Phantasy Star Online 2 (WINE_NO_OPEN_FILE_SEARCH)"
    apply_patch "../patches/game-patches/pso2_hack.patch"

    echo "WINE: -GAME FIXES- add set current directory workaround for Vanguard Saga of Heroes"
    apply_patch "../patches/game-patches/vgsoh.patch"

    echo "WINE: -GAME FIXES- add xinput support to Dragon Age Inquisition"
    apply_patch "../patches/game-patches/dai_xinput.patch"

    echo "WINE: -GAME FIXES- add fixes for star citizen"
    apply_patch "../patches/game-patches/silence-starcitizen-unsupported-os.patch"
    apply_patch "../patches/game-patches/eac_60101_timeout.patch"

### END GAME PATCH SECTION ###

### (2-5) WINE HOTFIX/BACKPORT SECTION ###

    # Valve bleeding-edge wine fixups needed by 32-bit wineopenxr and by OpenXR outside of steam,
    # not yet in the proton_11.0 wine branch
    echo "WINE: -BACKPORT- winevulkan: pass vkGetInstanceProcAddr to the OpenXR device creation callback"
    apply_patch "../patches/wine-hotfixes/upstream/winevulkan-pass-vkGetInstanceProcAddr-to-device-callback.patch"

    echo "WINE: -BACKPORT- win32u: avoid a crash when __WINE_OPENXR_VK_DEVICE_EXTENSIONS is not set"
    apply_patch "../patches/wine-hotfixes/upstream/win32u-avoid-crash-without-openxr-device-extensions-env.patch"

    echo "WINE: -BACKPORT- wine.inf: add the OpenXR ActiveRuntime registry entry for 32-bit applications"
    apply_patch "../patches/wine-hotfixes/upstream/wine.inf-add-wow6432-openxr-active-runtime.patch"


    # upstream wine commits from Valve's bleeding-edge wine that the Le Mans Ultimate patches build on,
    # not yet in the proton_11.0 wine branch
    echo "WINE: -BACKPORT- d2d1: sprite batch object methods and DrawSpriteBatch() command list recording"
    apply_patch "../patches/wine-hotfixes/upstream/d2d1-allow-null-value-in-effect-SetInput.patch"
    apply_patch "../patches/wine-hotfixes/upstream/d2d1-tests-add-sprite-batch-tests.patch"
    apply_patch "../patches/wine-hotfixes/upstream/d2d1-implement-sprite-batch-object-methods.patch"
    apply_patch "../patches/wine-hotfixes/upstream/d2d1-implement-DrawSpriteBatch-command-list-recording.patch"

    echo "WINE: -BACKPORT- bcrypt: handle prepended secret buffers in BCryptDeriveKey() for KDF_HASH"
    apply_patch "../patches/wine-hotfixes/upstream/bcrypt-handle-prepended-secret-buffers-for-KDF_HASH.patch"

### END WINE HOTFIX/BACKPORT SECTION ###

### (2-6) WINE PENDING UPSTREAM SECTION ###

    # https://github.com/Frogging-Family/wine-tkg-git/commit/ca0daac62037be72ae5dd7bf87c705c989eba2cb
    echo "WINE: -PENDING- unity crash hotfix"
    apply_patch "../patches/wine-hotfixes/pending/unity_crash_hotfix.patch"

    # https://bugs.winehq.org/show_bug.cgi?id=58476
    echo "WINE: -PENDING- RegGetValueW dwFlags hotfix (R.E.A.L VR mod)"
    apply_patch "../patches/wine-hotfixes/pending/registry_RRF_RT_REG_SZ-RRF_RT_REG_EXPAND_SZ.patch"

    # https://github.com/ValveSoftware/wine/pull/205
    # https://github.com/ValveSoftware/Proton/issues/4625
    echo "WINE: -PENDING- Add WINE_DISABLE_SFN option. (Yakuza 5 cutscenes fix)"
    apply_patch "../patches/wine-hotfixes/pending/ntdll_add_wine_disable_sfn.patch"

    echo "WINE: -PENDING- ncrypt: NCryptDecrypt implementation (PSN Login for Ghost of Tsushima)"
    apply_patch "../patches/wine-hotfixes/pending/NCryptDecrypt_implementation.patch"

    # https://github.com/StephenCWills/wine/commits/akiba/
    # https://github.com/ValveSoftware/Proton/issues/651#issuecomment-3564552601
    echo "WINE: -PENDING- add akibas trip undead & undressed patches"
    apply_patch "../patches/wine-hotfixes/pending/akibastrip-video-voice.patch"

    # Separate OpenXR steam reliance
    # https://github.com/GloriousEggroll/proton-ge-custom/issues/214
    echo "WINE: -PENDING- add OpenXR patches"
    apply_patch "../patches/wine-hotfixes/pending/0001-decouple-wineopenxr-from-steamvr-and-integrate-it-in.patch"

    # https://github.com/GloriousEggroll/proton-ge-custom/issues/852
    echo "WINE: -PENDING- winewayland: advertise the OpenVR/OpenXR Vulkan device pseudo-extensions like winex11"
    apply_patch "../patches/wine-hotfixes/pending/winewayland-advertise-openvr-openxr-device-extensions.patch"

    # Le Mans Ultimate
    # https://github.com/GloriousEggroll/proton-ge-custom/issues/777
    # https://github.com/GloriousEggroll/proton-ge-custom/issues/944
    echo "WINE: -PENDING- Register Direct2D Tint effect properties for Le Mans Ultimate"
    apply_patch "../patches/wine-hotfixes/pending/d2d1-register-tint-effect.patch"

    echo "WINE: -PENDING- Render Direct2D sprites, Tint output and layers for Le Mans Ultimate"
    apply_patch "../patches/wine-hotfixes/pending/d2d1-render-bitmap-sprites-tint-and-layers.patch"

    echo "WINE: -PENDING- Isolate Direct2D target clips for Le Mans Ultimate text rendering"
    apply_patch "../patches/wine-hotfixes/pending/d2d1-isolate-target-clip-stacks.patch"

    echo "WINE: -PENDING- Le Mans Ultimate VR loads a .cur cursor through D3DX"
    apply_patch "../patches/wine-hotfixes/pending/d3dx-cur-ico-loading-for-le-mans-ultimate.patch"
    apply_patch "../patches/wine-hotfixes/pending/d3dx-cur-ico-bounds-and-cursor-alpha-for-le-mans-ultimate.patch"

    echo "WINE: -PENDING- Le Mans Ultimate online key derivation and wheel reconnection"
    apply_patch "../patches/wine-hotfixes/pending/bcrypt-kdf-secret-append-for-le-mans-ultimate.patch"
    apply_patch "../patches/wine-hotfixes/pending/dinput-find-hotplugged-devices-for-le-mans-ultimate.patch"

### END WINE PENDING UPSTREAM SECTION ###


### (2-7) PROTON-GE ADDITIONAL CUSTOM PATCHES ###
    # https://steamcommunity.com/app/2074920/discussions/0/604168604057160448/
    echo "WINE: --CUSTOM-- add WINE_HOSTBLOCK envvar to allow working around some problematic anticheats (notably eac)"
    apply_patch "../patches/proton/wine_host_block_envvar.patch"

    echo "WINE: RUN AUTOCONF TOOLS/MAKE_REQUESTS"
    autoreconf -f
    ./tools/make_requests

    popd



### END PROTON-GE ADDITIONAL CUSTOM PATCHES ###
### END WINE PATCHING ###

