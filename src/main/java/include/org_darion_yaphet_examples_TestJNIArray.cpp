#include <jni.h>
//#include <stdio.h>
#include <iostream>
#include <string>
#include "org_darion_yaphet_examples_TestJNIArray.h"

JNIEXPORT jstring JNICALL Java_org_darion_yaphet_examples_TestJNIArray_mkString
  (JNIEnv *env, jobject obj, jobjectArray values) {

    jsize length = env->GetArrayLength(values);
    for (int i = 0; i < length; i++) {
      jobject obj = env->GetObjectArrayElement(values, i);
      jclass clazz = env->GetObjectClass(obj);
      jmethodID getClazz    = env->GetMethodID(clazz, "getClass", "()Ljava/lang/Class;");
      jobject   getClazzObj   = env->CallObjectMethod(obj, getClazz);
      jclass    objClazz  = env->GetObjectClass(getClazzObj);
      jmethodID getName = env->GetMethodID(objClazz, "getName", "()Ljava/lang/String;");
      jstring clazz_type = static_cast<jstring>(env->CallObjectMethod(getClazzObj,getName));

      std::string name = std::string(env->GetStringUTFChars(clazz_type, NULL)); 
      if (name.compare("java.lang.Boolean") == 0) {
        jmethodID m = env->GetMethodID(clazz, "booleanValue","()Z");
        bool b_value = env->CallBooleanMethod(obj, m);
        std::cout << "Type : " << name << " Value : " << b_value << std::endl;
      } else if (name.compare("java.lang.Integer") == 0) {
        jmethodID m = env->GetMethodID(clazz, "intValue","()I");
        int i_value = env->CallIntMethod(obj, m);
        std::cout << "Type : " << name << " Value : " << i_value << std::endl;
      } else if (name.compare("java.lang.Long") == 0) {
        jmethodID m = env->GetMethodID(clazz, "longValue","()J");
        long l_value = env->CallLongMethod(obj, m);
        std::cout << "Type : " << name << " Value : " << l_value << std::endl;
      } else if (name.compare("java.lang.Float") == 0) {
        jmethodID m = env->GetMethodID(clazz, "floatValue","()F");
        float f_value = env->CallFloatMethod(obj, m);
        std::cout << "Type : " << name << " Value : " << f_value << std::endl;
      } else if (name.compare("java.lang.Double") == 0) {
        jmethodID m = env->GetMethodID(clazz, "doubleValue","()D");
        double d_value = env->CallDoubleMethod(obj, m);
        std::cout << "Type : " << name << " Value : " << d_value << std::endl;
      } else if (name.compare("java.lang.String") == 0) {
        jmethodID m = env->GetMethodID(clazz, "toString","()Ljava/lang/String;");
        jstring js_value = static_cast<jstring>(env->CallObjectMethod(obj, m));
        std::string s_value = std::string(env->GetStringUTFChars(js_value, NULL));
        std::cout << "Type : " << name << " Value : " << s_value << std::endl;
      } else {
        std::cout << "Type : " << name << std::endl;
      }
    }

    std::string value = "Hello World!";
    return env->NewStringUTF(value.c_str());
}
