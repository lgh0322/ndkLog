#include <jni.h>
#include <string>
#include <iostream>
using namespace std;
#include <android/log.h>



extern "C" JNIEXPORT jstring JNICALL
Java_com_vaca_myapplication_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    int n=234;
    __android_log_print(ANDROID_LOG_INFO, "ProjectName", "I am : %d/n", n);
    return env->NewStringUTF(hello.c_str());
}