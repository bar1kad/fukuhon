#include <stdio.h>
#include <stdlib.h>
#include "file_reader.h"

FILE *open_file(const char* path)
{
    FILE *file;
    file = fopen(path, "r");
    if (!file) {
        perror(path);
        exit(1);
    }
    return file;
}

