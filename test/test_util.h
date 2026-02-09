#ifndef TEST_UTIL_H_SENTRY
#define TEST_UTIL_H_SENTRY

#include <stdio.h>
#include <stdlib.h>

#define MAKE_ASSERT_FUNCTION(TYPE) \
void test_assert_ ## TYPE(TYPE expected, TYPE actual, char *format_str, char *message) {\
    if (actual != expected) {\
        fprintf(stderr, format_str, expected, actual);\
        fprintf(stderr, "%s\n", message);\
        exit(1);\
    }\
}

#endif

