#include <jni.h>
#include <string>

#include <libusb.h>
#include "depthai/depthai.hpp"

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_depthaiandroid_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    auto r = libusb_set_option(nullptr, LIBUSB_OPTION_ANDROID_JNIENV, env);

    // Connect to device and start pipeline
    auto device = dai::Device(dai::OpenVINO::VERSION_2021_4, dai::UsbSpeed::HIGH);

    // Create pipeline
    dai::Pipeline pipeline;
    device.startPipeline(pipeline);


    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}