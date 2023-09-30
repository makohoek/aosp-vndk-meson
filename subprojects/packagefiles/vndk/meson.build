# SPDX-License-Identifier: CC0-1.0

project('vndk', 'cpp',
        version : 'vndk-v33')

if host_machine.cpu_family() != 'aarch64'
    error('vndk only supports aarch64 cpu_family')
endif

prebuild_libraries = [
    meson.current_source_dir() / 'arm64/arch-arm64-armv8-a/shared/llndk-stub',
    meson.current_source_dir() / 'arm64/arch-arm64-armv8-a/shared/vndk-sp',
    meson.current_source_dir() / 'arm64/arch-arm64-armv8-a/shared/vndk-core',
]

include_base = 'arm64/include'

cc = meson.get_compiler('cpp')
liblog_dep = declare_dependency(
    dependencies : cc.find_library('log', dirs : prebuild_libraries),
    include_directories : include_directories(include_base / 'system/logging/liblog/include_vndk'))
meson.override_dependency('liblog', liblog_dep)

cutils_dep = declare_dependency(
    dependencies : cc.find_library('cutils', dirs : prebuild_libraries),
    include_directories : include_directories(include_base / 'system/core/libcutils/include_outside_system'))
meson.override_dependency('libcutils', cutils_dep)

libutils_dep = declare_dependency(
    dependencies : cc.find_library('utils', dirs : prebuild_libraries),
    include_directories : include_directories(include_base / 'system/core/libutils/include'))
meson.override_dependency('libutils', libutils_dep)

libhardware_dep = declare_dependency(
    dependencies : cc.find_library('hardware', dirs : prebuild_libraries),
    include_directories : include_directories(include_base / 'hardware/libhardware/include'))
meson.override_dependency('libhardware', libhardware_dep)

libsystem_dep = declare_dependency(
    include_directories : include_directories(include_base / 'system/core/libsystem/include'))
meson.override_dependency('libsystem', libsystem_dep)

libmedia_dep = declare_dependency(
    include_directories : include_directories(include_base / 'system/media/camera/include'))
meson.override_dependency('libmedia', libmedia_dep)

libui_dep = declare_dependency(
    dependencies : cc.find_library('ui', dirs : prebuild_libraries),
    include_directories : include_directories(include_base / 'frameworks/native/libs/ui/include_vndk'))
meson.override_dependency('libui', libui_dep)

deps_cpp = [
  cc.find_library('c++', dirs : prebuild_libraries),
  cc.find_library('c', dirs : prebuild_libraries),
]

vndk_libcpp_dep = declare_dependency(
    dependencies : deps_cpp,
    include_directories : include_directories(include_base / 'external/libcxx/include'))
meson.override_dependency('cpp_stdlib', vndk_libcpp_dep)
