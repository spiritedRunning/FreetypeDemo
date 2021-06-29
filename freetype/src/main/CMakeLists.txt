cmake_minimum_required(VERSION 3.4.1)

include_directories(cpp/freetype-2/10/4/jni/include)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_SOURCE_DIR}/cpp/freetype-2/10/4/lib/${ANDROID_ABI}")

add_library(
             native-lib
             SHARED
            cpp/native-lib.cpp)


target_link_libraries(
                       native-lib
                       freetype
                       log)