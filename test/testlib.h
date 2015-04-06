#ifndef __TESTLIB_H__
#define __TESTLIB_H__

#include <stdio.h>
#include <string.h>

typedef int bool;
typedef bool (*TestFunction)();

#define true 1
#define false 0
#define yes 1
#define no 0

void start_test(const char* description)
{
    printf("  * %s ", description);
}

#define __TP(x, y) x ## y
#define __TPP(x, y) __TP(x, y)

#define test(description, testfunc) bool __TPP(test_, __COUNTER__) ()\
{\
    start_test(description);\
    {testfunc}\
}


#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define ansi_green(text) ANSI_COLOR_GREEN text ANSI_COLOR_RESET
#define ansi_red(text)   ANSI_COLOR_RED text ANSI_COLOR_RESET

#define init_testfunc(num, array) array[num] = __TPP(test_, num)

bool run_tests(char* suite_name, int num_tests, TestFunction* tests)
{
    printf("Performing %i tests in %s:\n", num_tests, suite_name);

    //TestFunction tests[num_tests];
    //init_testfunc(0, tests);


    bool any_fail = false;
    for (size_t i = 0; i < num_tests; i++) {
        bool result = tests[i]();
        if (result)
        {
            printf(" ... %s", ansi_green("OK"));
        } else {
            printf(" ... %s", ansi_red("FAIL"));
            any_fail = true;
        }
        printf("\n\n");
    }

    return any_fail;
}

#endif /* end of include guard: __TESTLIB_H__ */
