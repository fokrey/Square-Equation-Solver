#include "SolveSquare.h"

int partial_cases_test () {

    int failed_part_cases = 0;

    failed_part_cases += test_solve_square (0, 0, 0);
    failed_part_cases += test_solve_square (0, 0, 7);
    failed_part_cases += test_solve_square (0, 9, 90);
    failed_part_cases += test_solve_square (7, 8, 9);
    failed_part_cases += test_solve_square (1, -2, 1);
    failed_part_cases += test_solve_square (0, 1, 0);
    failed_part_cases += test_solve_square (1, 0, -9);

    return failed_part_cases;

}

bool random_cases_test () {
    return test_solve_square (rand (), rand (), rand ());
}

int test_solve_square (double a, double b, double c) {

    const double poison1 = 577, poison2 = 593;
    double x1 = poison1, x2 = poison2;

    int num_roots = solve_square (a, b, c, &x1, &x2);

    static const size_t test_inf_roots_number = 11;

    switch (num_roots) {
        case TWO_ROOTS:
            if (is_zero (a * x1 * x1 + b * x1 + c) && is_zero (a * x2 * x2 + b * x2 + c))
                return 0; // number of failed tests is 0
            else {
                printf("TEST TWO_ROOTS (a = %lg, b = %lg, c = %lg) FAILED\n", a, b, c);
                return 1; //number of failed tests is 1
            }
        case ONE_ROOT:
            if (is_zero (a * x1 * x1 + b * x1 + c) && (x2 == x1 || x2 == poison2))
                return 0;
            else {
                printf("TEST ONE_ROOT (a = %lg, b = %lg, c = %lg) FAILED\n", a, b, c);
                return 1;
            }

        case NO_ROOTS:
            if ((b * b - 4 * a * c < 0 && x1 == poison1 && x2 == poison2) ||(is_zero(a) && is_zero (b) && !is_zero (c)))
                return 0;
            else {
                printf("TEST NO_ROOTS (a = %lg, b = %lg, c = %lg) FAILED\n", a, b, c);
                return 1;
            }

        case INF_ROOTS:
            for (int i = 0; i < test_inf_roots_number; i++) {
                if (!(is_zero (a * rand () * rand () + b * rand () + c))) {
                    printf("TEST INF_ROOTS (a = %lg, b = %lg, c = %lg) FAILED\n", a, b, c);
                    return 1;
                }
            }
            return 0;

        default: printf ("Invalid number of roots!\n");
            return 1;
    }
}

int run_test (unsigned long num_tests) {

    int failed_part_cases = 0;
    int failed_rand_cases = 0;

    for (int i = 0; i < num_tests; i++)
        failed_rand_cases += random_cases_test ();

    failed_part_cases = partial_cases_test ();

    if (failed_rand_cases == 0 && failed_part_cases == 0) {
        printf ("ALL TESTS PASSED!\n");
        return 0;
    }
    else {
        printf ("ERROR! %d out of %d TESTS FAILED\n", failed_rand_cases + failed_part_cases, num_tests);
        return -1;
    }
}
