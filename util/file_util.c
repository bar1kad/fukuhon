#include <stdlib.h>
#include <stdio.h>
#include "file_util.h"

int get_file_size(FILE *file)
{
    fseek(file, 0L, SEEK_END);
    return ftell(file);
}

FILE *open_for_read(const char* path)
{
    FILE *file;
    file = fopen(path, "r");
    if (!file) {
        perror(path);
        exit(1);
    }
    return file;
}

