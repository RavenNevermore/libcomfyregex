#include "testlib.h"

test("should return NULL, for empty pattern list",
{
    return true;
})


int main(int argc, char const *argv[]) {
    TestFunction tests[1];
    tests[0] = test_0;

    return run_tests("Multi Regex", 1, tests) ? 1 : 0;
}
