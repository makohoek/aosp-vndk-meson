/* SPDX-License-Identifier: LGPL-2.1-or-later */
/*
 * Copyright (C) 2023, BayLibre SAS
 *
 * Example using vendor libraries with VNDK, NDK and meson
 */
#include <iostream>
#define LOG_TAG "vndk_meson"
#include <android-base/logging.h>

#include <ui/GraphicBufferAllocator.h>
#include <hardware/camera3.h>
#include <utils/Errors.h>

int main() {
    std::cout << "Hello from cpp" << std::endl;

    LOG(INFO) << "Hello from cpp";

    android::GraphicBufferAllocator &allocator = android::GraphicBufferAllocator::get();

    uint32_t stride = 0;
    buffer_handle_t handle = nullptr;

    int halPixelFormat = HAL_PIXEL_FORMAT_YCbCr_420_888;
    uint32_t usage = GRALLOC_USAGE_SW_READ_OFTEN;

    android::status_t status =
        allocator.allocate(1920, 1080, halPixelFormat, 1 /*layerCount*/, usage,
                           &handle, &stride, "example");

    if (status != android::NO_ERROR) {
        ALOGE("failed buffer allocation: ");
        return 1;
    }

    if (!handle) {
        ALOGE("invalid buffer_handle_t");
        return 1;
    }

    ALOGI("Buffer handle %d error %d", handle->numFds, status);

    return 0;
}
