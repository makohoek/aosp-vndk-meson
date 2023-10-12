# AOSP system programming using VNDK, meson and NDK

This is an example project on how to use meson to cross-compile an aarch64 binary
that uses VNDK-only libraries, such as `libui`.

## Overview

The following projects are involved:
- **NDK**: provides the cross-compiler toolchains such as `aarch64-linux-android33-clang++`
- **VNDK**: provides vendor-only libraries such as `libui` and such. These are *not* part of Android NDK
- **Meson**: as a build system

## Pre-requisite

1. Install my custom version of meson:
https://github.com/makohoek/meson/tree/nostdlib%2B%2B

Do to a bug in meson, we cannot override the standard C++ library. See:
https://github.com/mesonbuild/meson/pull/12361

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

Building will automatically fetch the VNDK as a subproject and link against the required VNDK libraries.

## Install instructions
```
adb root
adb remount
adb push build-aarch64-linux-android/vndk_meson /vendor/bin
```

Then on board, test with:
```
adb shell
# vndk_meson
Hello from cpp
```
