#include <stdio.h>
#include <stdlib.h>
#include "../util/array_util.h"
#include "../test/test_util.h"

MAKE_ASSERT_FUNCTION(char);

void arr_copy_test_literal_initializer()
{

    printf("Running arr_copy_test_literal_initializer\n");
    char from[10] = "1234567890";
    char to[10];

    arr_copy(from, to, sizeof(from));
    
    printf("Validating output: \n");
    for (int i = 0; i < 10; i++) {
        printf("to[i] = %c, from[i] = %c\n", from[i], to[i]);
        test_assert_char(to[i], from[i], "expected: %c, actual: %c\n", "arr_copy_test_literal_initializer FAILED\n");
    }
    printf("arr_copy_test_literal_initializer: PASSED\n\n");
    fflush(stdout);
}

void arr_copy_test_7_chars_arr()
{
    printf("Running arr_copy_test_7_chars_arr\n");
    char from[] = {'F', 'a', 'l', 'l', 'o', 'u', 't'};
    char to[7];

    arr_copy(from, to, sizeof(from));

    printf("Validating output: \n");
    for (int i = 0; i < sizeof(from); i++) {
#if 1
        printf("to[i] = %c, from[i] = %c\n", from[i], to[i]);
#endif
        test_assert_char(to[i], from[i], "expected: %c, actual: %c\n", "arr_copy_test_7_chars_arr FAILED\n");
    }
    printf("arr_copy_test_7_chars_arr: PASSED\n\n");
}

