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

### END PREP SECTION ###

### (2) WINE PATCHING ###

    pushd wine
    git reset --hard HEAD
    git clean -xdf

### (2-1) PROBLEMATIC COMMIT REVERT SECTION ###

# Bring back configure files. Staging uses them to regenerate fresh ones
# https://github.com/ValveSoftware/wine/commit/e813ca5771658b00875924ab88d525322e50d39f

    git revert --no-commit e813ca5771658b00875924ab88d525322e50d39f

### END PROBLEMATIC COMMIT REVERT SECTION ###
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


    # https://github.com/JacKeTUs/wine/commits/lmu-d2d1-tinkering
    echo "WINE: -GAME FIXES- add le mans ultimate patches"
    apply_patch "../patches/game-patches/lemansultimate-gameinput.patch"

### END GAME PATCH SECTION ###

### (2-5) WINE HOTFIX/BACKPORT SECTION ###

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

    #https://github.com/GloriousEggroll/proton-ge-custom/issues/283
    echo "WINE: -PENDING- quartz: backport to allow clannad videos to work"
    apply_patch "../patches/wine-hotfixes/pending/8848.patch"

    # https://github.com/StephenCWills/wine/commits/akiba/
    # https://github.com/ValveSoftware/Proton/issues/651#issuecomment-3564552601
    echo "WINE: -PENDING- add akibas trip undead & undressed patches"
    apply_patch "../patches/wine-hotfixes/pending/akibastrip-video-voice.patch"

    # Separate OpenXR steam reliance
    # https://github.com/GloriousEggroll/proton-ge-custom/issues/214
    echo "WINE: -PENDING- add OpenXR patches"
    apply_patch "../patches/wine-hotfixes/pending/0001-decouple-wineopenxr-from-steamvr-and-integrate-it-in.patch"

### END WINE PENDING UPSTREAM SECTION ###


### (2-7) PROTON-GE ADDITIONAL CUSTOM PATCHES ###
    echo "WINE: -CUSTOM- Downgrade MESSAGE to TRACE to remove write_watches spam"
    apply_patch "../patches/proton/0001-ntdll-Downgrade-using-kernel-write-watches-from-MESS.patch"

    echo "WINE: -CUSTOM- Fix a crash in ID2D1DeviceContext if no target is set"
    apply_patch "../patches/proton/fix-a-crash-in-ID2D1DeviceContext-if-no-target-is-set.patch"

    # https://steamcommunity.com/app/2074920/discussions/0/604168604057160448/
    echo "WINE: --CUSTOM-- add WINE_HOSTBLOCK envvar to allow working around some problematic anticheats (notably eac)"
    apply_patch "../patches/proton/wine_host_block_envvar.patch"

    echo "WINE: RUN AUTOCONF TOOLS/MAKE_REQUESTS"
    autoreconf -f
    ./tools/make_requests

    popd



### END PROTON-GE ADDITIONAL CUSTOM PATCHES ###
### END WINE PATCHING ###

