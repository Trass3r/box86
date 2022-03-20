#define _GNU_SOURCE         /* See feature_test_macros(7) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#include "wrappedlibs.h"

#include "debug.h"
#include "wrapper.h"
#include "bridge.h"
#include "librarian/library_private.h"
#include "x86emu.h"

const char* gstreamer010Name = "libgstreamer-0.10.so.0";
#define LIBNAME gstreamer010

#define PRE_INIT    \
    if(box86_nogtk) \
        return -1;

#define CUSTOM_INIT \
    lib->altmy = strdup("my010_"); \
    lib->priv.w.needed = 1; \
    lib->priv.w.neededlibs = (char**)calloc(lib->priv.w.needed, sizeof(char*)); \
    lib->priv.w.neededlibs[0] = strdup("libglib-2.0.so.0");

#include "wrappedlib_init.h"
