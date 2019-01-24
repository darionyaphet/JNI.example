#include <jni.h>
//#include <stdio.h>
#include <iostream>
#include "org_darion_yaphet_examples_TestJNIPrimitive.h"

JNIEXPORT jdouble JNICALL Java_org_darion_yaphet_examples_TestJNIPrimitive_average
          (JNIEnv *env, jobject thisObj, jint n1, jint n2) {
   jdouble result;
   std::cout << "In C++, the numbers are " << n1 << " and " << n2 << std::endl;
   result = ((jdouble)n1 + n2) / 2.0;
   // jint is mapped to int, jdouble is mapped to double
   return result;
}

