#include "SolveSquare.h"

int main () {
    const unsigned long NUM_TESTS = 10 * 1000000;

    if (run_test (NUM_TESTS) == -1)
        return EXIT_FAILURE;

    double a = 0, b = 0, c = 0;
    show_result (a, b, c);

    return EXIT_SUCCESS;
}
