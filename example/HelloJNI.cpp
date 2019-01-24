#include <jni.h>
//#include <stdio.h>
#include <iostream>
#include "HelloJNI.h"

// Implementation of native method sayHello() of HelloJNI class
JNIEXPORT void JNICALL Java_HelloJNI_sayHello(JNIEnv *env, jobject thisObj) {
  std::cout << "Hello World from C++!" << std::endl;
  return;
}
