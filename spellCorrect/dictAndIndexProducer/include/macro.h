#pragma once

#include <errno.h>

#define ERROR_EXIT(msg) \
    do { \
        perror(msg); \
        exit(-1); \
    } while(0)


