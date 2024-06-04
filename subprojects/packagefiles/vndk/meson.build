# SPDX-License-Identifier: CC0-1.0

project('vndk', 'cpp',
        version : 'vndk-v34')

cpu_family = host_machine.cpu_family()
if cpu_family == 'x86_64'
  cpu = 'x86_64'
  prebuilt_path = cpu / 'arch-x86_64/shared'
elif cpu_family == 'aarch64'
  cpu = 'arm64'
  prebuilt_path = cpu / 'arch-arm64-armv8-a/shared'
elif cpu_family == 'arm'
  cpu = 'arm'
  prebuilt_path = cpu / 'arch-arm-armv7-a-neon/shared'
else
    error('Architecture:  ' + cpu_family + ' not supported')
endif

prebuild_libraries = [
    meson.current_source_dir() / prebuilt_path / 'llndk-stub',
    meson.current_source_dir() / prebuilt_path / 'vndk-sp',
    meson.current_source_dir() / prebuilt_path / 'vndk-core',
]

include_base = cpu / 'include'

cxx = meson.get_compiler('cpp')

libbase_dep = declare_dependency(
    dependencies : cxx.find_library('base', dirs : prebuild_libraries),
    include_directories : include_directories(include_base / 'system/libbase/include'))
meson.override_dependency('libbase', libbase_dep)

liblog_dep = declare_dependency(
    dependencies : cxx.find_library('log', dirs : prebuild_libraries),
    include_directories : include_directories(include_base / 'system/logging/liblog/include_vndk'))
meson.override_dependency('liblog', liblog_dep)

cutils_dep = declare_dependency(
    dependencies : [
        cxx.find_library('cutils', dirs : prebuild_libraries),
        liblog_dep,
    ],
    include_directories : include_directories(include_base / 'system/core/libcutils/include_outside_system'))
meson.override_dependency('libcutils', cutils_dep)

libutils_dep = declare_dependency(
    dependencies : cxx.find_library('utils', dirs : prebuild_libraries),
    include_directories : include_directories(include_base / 'system/core/libutils/include'))
meson.override_dependency('libutils', libutils_dep)

libsystem_dep = declare_dependency(
    include_directories : include_directories(include_base / 'system/core/libsystem/include'))
meson.override_dependency('libsystem', libsystem_dep)

libhardware_dep = declare_dependency(
    dependencies : [
      cxx.find_library('hardware', dirs : prebuild_libraries),
      libsystem_dep,
    ],
    include_directories : include_directories(include_base / 'hardware/libhardware/include'))
meson.override_dependency('libhardware', libhardware_dep)

libmedia_dep = declare_dependency(
    include_directories : include_directories(include_base / 'system/media/camera/include'))
meson.override_dependency('libmedia', libmedia_dep)

libmath_dep = declare_dependency(
    dependencies : cxx.find_library('m', dirs : prebuild_libraries),
    include_directories : include_directories(include_base / 'frameworks/native/libs/math/include'),
)
meson.override_dependency('libmath', libmath_dep)

libui_dep = declare_dependency(
    dependencies : [
        libmath_dep,
        cxx.find_library('ui', dirs : prebuild_libraries),
    ],
    include_directories : [
        include_directories(include_base / 'frameworks/native/libs/ui/include_vndk'),
        include_directories(include_base / 'generated-headers/hardware/interfaces/graphics/common/aidl/android.hardware.graphics.common-V4-ndk-source/gen/include'),
        include_directories(include_base / 'generated-headers/hardware/interfaces/graphics/common/1.2/android.hardware.graphics.common@1.2_genc++_headers/gen/'),
        include_directories(include_base / 'generated-headers/hardware/interfaces/graphics/common/1.1/android.hardware.graphics.common@1.1_genc++_headers/gen/'),
        include_directories(include_base / 'generated-headers/hardware/interfaces/graphics/common/1.0/android.hardware.graphics.common@1.0_genc++_headers/gen/'),
    ])
meson.override_dependency('libui', libui_dep)

vndk_libcpp_dep = declare_dependency(
    dependencies : [
        cxx.find_library('c++', dirs : prebuild_libraries),
        cxx.find_library('c', dirs : prebuild_libraries),
    ],
    include_directories : [
        include_directories(include_base / 'external/libcxx/include'),
        include_directories(include_base / 'external/libcxxabi/include'),
    ])
meson.override_dependency('cpp_stdlib', vndk_libcpp_dep)
