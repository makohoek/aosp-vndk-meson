# SPDX-License-Identifier: CC0-1.0

project('vndk_meson_demo', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3'])

libbase_deps = dependency('libbase', required : true)
libui_deps = dependency('libui', required : true)
libcutils_deps = dependency('libcutils', required : true)
libutils_deps = dependency('libutils', required : true)
libhardware_deps = dependency('libhardware', required : true)
libsystem_deps = dependency('libsystem', required : true)
libmedia_deps = dependency('libmedia', required : true)

android_deps = ([
    libbase_deps,
    libui_deps,
    libcutils_deps,
    libutils_deps,
    libhardware_deps,
    libsystem_deps,
    libmedia_deps,
])

exe = executable('vndk_meson', 'main.cpp',
  install : true,
  dependencies : android_deps)

test('basic', exe)
