#include <stdio.h>
#include <stdlib.h>
#include "../util/file_util.h"
#include "test_util.h"

void get_file_size_test()
{
    printf("Running get_file_size_test");
    FILE *file = fopen("./test/test.txt", "r");
    if (!file) {
        perror("test.txt");
        exit(1);
    }
    assert_int(get_file_size(file), 555, "expected: %d, actual: %d\n", "get_file_size_test FAILED");
    printf("get_file_size_test: PASSED\n");
}

int main() {
    get_file_size_test();
}

