# AOSP system programming using VNDK, meson and NDK

This is an example project on how to use meson to cross-compile an aarch64 binary
that uses VNDK-only libraries, such as `libui`.

## Overview

The following projects are involved:
- **NDK**: provides the cross-compiler toolchains such as `aarch64-linux-android33-clang++`
    See: https://developer.android.com/ndk/downloads

- **VNDK**: provides vendor-only libraries such as `libui` and such. These are *not* part of Android NDK
    See: https://android.googlesource.com/platform/prebuilts/vndk/v33/

- **Meson**: as a build system
    See: https://mesonbuild.com/

## Pre-requisite

1. Install `meson` version `1.3.0` or higher. This can be done via `pip`
```
pip install meson==1.3.0
```

Note: earlier versions of meson have a bug with overriding the standard C++ library.
See: https://github.com/mesonbuild/meson/pull/12361

2. Download the NDK:
```
wget https://dl.google.com/android/repository/android-ndk-r26b-linux.zip
unzip android-ndk-r26b-linux.zip
mv android-ndk-r26b /mnt/work/aosp/
```

Update `aarch64-linux-android-ndk.txt` to include your own NDK install path:
```ini
[constants]
# TODO: edit these paths for your own locations
ndk = '/mnt/work/aosp/android-ndk-r26b'
```

## Build instructions

```
meson setup --cross-file=aarch64-linux-android-ndk.txt build-aarch64-linux-android
meson compile -C build-aarch64-linux-android
```

For `arm32`, use:

```
meson setup --cross-file=arm-linux-androideabi-ndk.txt build-arm-linux-androideabi
meson compile -C build-arm-linux-androideabi
```

For `x86_64`, use:

```
meson setup --cross-file=x86_64-linux-android-ndk.txt build-x86_64-linux-android
meson compile -C build-x86_64-linux-android
```

Building will automatically fetch the VNDK as a subproject and link against the required VNDK libraries.

## Install instructions
```
adb root
adb remount
# for aarch64
adb push build-aarch64-linux-android/vndk_meson /vendor/bin
# for arm32
adb push build-arm-linux-androideabi/vndk_meson /vendor/bin
# for x86_64
adb push build-x86_64-linux-android/vndk_meson /vendor/bin
```

Then on board, test with:
```
adb shell
# vndk_meson
Hello from cpp
```
