#include <stdio.h>
#include <stdlib.h>
#include "../util/file_util.h"

void assert(int actual, int expected)
{
    if (actual != expected) {
        fprintf(stderr, "expected: %d, actual: %d", expected, actual);
        exit(1);
    }
}

void get_file_size_test()
{
    FILE *file = fopen("./test/test.txt", "r");
    if (!file) {
        perror("test.txt");
        exit(1);
    }
    assert(get_file_size(file), 755);
    printf("get_file_size_test: PASSED");
}

int main() {
    get_file_size_test();
}

