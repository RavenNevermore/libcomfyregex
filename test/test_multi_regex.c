#include "testlib.h"

#include "multi_regex.h"

#include <string.h>

test("should return NULL, for empty pattern list",
{
    MultiRegex expressions = {
        .size = 0
    };

    char* source = "This is a test string.";

    char* result = multi_regex_replace(&expressions, source, strlen(source));

    return NULL == result;
})


int main(int argc, char const *argv[]) {
    TestFunction tests[1];
    tests[0] = test_0;

    return run_tests("Multi Regex", 1, tests) ? 1 : 0;
}
