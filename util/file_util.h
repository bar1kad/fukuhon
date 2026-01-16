#ifndef FILE_UTIL_H_SENTRY
#define FILE_UTIL_H_SENTRY
#include <stdio.h>

int get_file_size(FILE *file);
    
FILE *open_for_read(const char* path);

#endif

