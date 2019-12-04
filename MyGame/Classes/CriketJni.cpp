//
// Created by kuboyama on 2019/11/29.
//

#include "CriketJni.h"

#include "ck/ck.h"
#include "ck/config.h"

JNIEXPORT void JNICALL Java_org_cocos2dx_cpp_AppActivity_initCricket(JNIEnv *env, jobject obj, jobject thiz) {
CkConfig config(env, thiz);
CkInit(&config);
}