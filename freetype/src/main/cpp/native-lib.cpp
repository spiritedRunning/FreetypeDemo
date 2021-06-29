#include <jni.h>
#include <string>
#include "Log.h"

#include <ft2build.h>
#include <freetype/freetype.h>

static int error; //this flag is set to true if any error occurs during freetype initialization
static FT_Library library;
static FT_Face fontFace;
static int resolution, glyphMargin;

uint8_t libft_load_file(const char *path) {
    //TODO: To avoid loading ALL glyphs from a particular typeFace, we might
    //let the user provides one or more "character ranges" that we should load

    //TODO: If we have a font face with a HUGE amount of glyphs, maybe it would
    //be better to generate multiple atlas (and a glyph would be found by using
    //its atlas coordinates AND an atlas index)
    if (FT_New_Face(library, path, 0, &fontFace)) {
        LOGE("Error loading font face %s", path);
        error = 2;
        return error;
    }

    //Each character will be rendered in a square of resolution*resolution pixels
    FT_Set_Pixel_Sizes(fontFace, resolution, resolution);

    LOGE("libft_load_file %s face=%p num_glyphs=%d style_name=%s",
         path, fontFace, fontFace->num_glyphs, fontFace->style_name);


    return 0;
}

uint8_t libft_init(int size) {
    if (FT_Init_FreeType(&library)) {
        LOGE("Failed to initialize freetype library");
        error = 1;
        return error;
    }

    LOGE("==========libft_init ok size=%d lib=%p", size, library);

    resolution = size;
    glyphMargin = 0;

    libft_load_file("/sdcard/ttf/SentyWen_slim.ttf");

    return error;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_freetypelib_MainActivity_initFreeType(JNIEnv *env, jobject thiz) {

    libft_init(36);
}

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {

    return JNI_VERSION_1_4;
}

