cmake_minimum_required(VERSION 3.4.1)


include_directories(cpp/include)

set(NATIVE_LIB ${CMAKE_SOURCE_DIR}/jniLibs/${ANDROID_ABI})
#message("NATIVE_LIB = ${CMAKE_SOURCE_DIR}/jniLibs/${ANDROID_ABI}")

# 方式1
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${NATIVE_LIB}")

add_library(
             native-lib
             SHARED
            cpp/native-lib.cpp)

# 方式2
#add_library(freetype SHARED IMPORTED)
#set_target_properties(freetype PROPERTIES IMPORTED_LOCATION ${NATIVE_LIB}/libfreetype.so)

target_link_libraries(
                       native-lib
                       freetype
                       log)