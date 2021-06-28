//
// Created by Zach on 2021/6/25.
//

#ifndef FREETYPEDEMO_LOG_H
#define FREETYPEDEMO_LOG_H

#include <android/log.h>
#define LOG_TAG "freetype"


#define LOGI(...) \
    ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))
#define LOGW(...) \
    ((void)__android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__))
#define LOGE(...) \
    ((void)__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__))
#define LOGD(...) \
    ((void)__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__))

#endif //FREETYPEDEMO_LOG_H
