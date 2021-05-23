#include <jni.h>
#include <string>
#include <iostream>
using namespace std;
#include <android/log.h>
#include <vector>
#include <memory>


struct Base{
    Base(){
        __android_log_print(ANDROID_LOG_INFO, "ProjectName", "I aasdaaaaaaaaaaam : %d/n");
    }
    ~Base(){
        __android_log_print(ANDROID_LOG_INFO, "ProjectName", "I am :asdddddddddddddddd %d/n");
    }
};


struct Derived:public Base{
    Derived(){
        __android_log_print(ANDROID_LOG_INFO, "ProjectName", "I am :qqqqqqqqqqqqqqqqqqqqqqqqqqqq %d/n");
    }
    ~Derived(){
        __android_log_print(ANDROID_LOG_INFO, "ProjectName", "I am : pooooooooooooppppppppppppp%d/n");
    }
};

extern "C" JNIEXPORT jstring JNICALL
Java_com_vaca_myapplication_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";



    std::vector <int> wert={23, 43, 65, 76};
    wert.push_back(25);
    wert.push_back(16);

    for(auto n:wert){
        __android_log_print(ANDROID_LOG_INFO, "ProjectName", "I am : %d/n", n);
    }




    shared_ptr<Base> p=make_shared<Derived>();



    auto glambda=[](int a,int && b){
        return a<b;
    };

    bool b=glambda(3,4);
    bool d=glambda(4,3);
    __android_log_print(ANDROID_LOG_INFO, "ProjectName", "I am : %d      %d/n", d,b);


    return env->NewStringUTF(hello.c_str());
}