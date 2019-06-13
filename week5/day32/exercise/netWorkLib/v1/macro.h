#pragma once

#define ERROR_EXIT(msg) \
    do { \
    perror(msg); \
    exit(-1); \
    } while(0)

#define LISTEN_SZ 10

