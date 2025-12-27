#include "array_util.h"
#include <stdio.h>

void arr_copy(char *from, char *to, int size)
{
    for (int i = 0; i < size; i++) {
        to[i] = from[i];
    }
}

