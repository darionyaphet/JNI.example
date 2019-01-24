#include <jni.h>
#include <iostream>
#include <string>
#include "org_darion_yaphet_examples_TestJNIString.h"

JNIEXPORT jstring JNICALL Java_org_darion_yaphet_examples_TestJNIString_sayHello(JNIEnv *env, jobject thisObj, jstring inJNIStr) {
  // Step 1: Convert the JNI String (jstring) into C-String (char*)
   const char *inCStr = env->GetStringUTFChars(inJNIStr, NULL);
   if (NULL == inCStr) return NULL;

   // Step 2: Perform its intended operations
   std::cout << "In C++, the received string is: " << inCStr << std::endl;
   env->ReleaseStringUTFChars(inJNIStr, inCStr);  // release resources

   // Prompt user for a C++ string
   std::string outCppStr;
   std::cout << "Enter a String: ";
   std:: cin >> outCppStr;

   // Step 3: Convert the C++ string to C-string, then to JNI String (jstring) and return
   return env->NewStringUTF(outCppStr.c_str());
}
