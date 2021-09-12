#include "SolveSquare.h"

int solve_square (double a, double b, double c, double* x1, double* x2) {
    assert(std::isfinite(a));
    assert(std::isfinite(b));
    assert(std::isfinite(c));

    assert(x1 != nullptr);
    assert(x2 != nullptr);
    assert(x1 != x2);

    if (is_zero(a))
        return solve_linear (b, c, x1);

    // if (a != 0)
    double Discr = b * b - 4 * a * c;
    if (is_zero (Discr)) {
        *x1 = *x2 = -b / (2 * a);
        return ONE_ROOT;
    }

    if (Discr > EPSILON) { // Discr > 0
        double sqrt_D = sqrt (Discr);
        *x1 = (-b + sqrt_D) / (2 * a);
        *x2 = (-b - sqrt_D) / (2 * a);
        return TWO_ROOTS;
    }
    return NO_ROOTS;
}

int solve_linear (double a, double b, double* x1) {

    assert(std::isfinite(a));
    assert(std::isfinite(b));
    assert(x1 != nullptr);

    if (is_zero (a)) {
        if (is_zero (b))
            return INF_ROOTS;
        return NO_ROOTS; // b != 0
    }
    *x1 = (-b / a) + 0; // a != 0
    return ONE_ROOT;
}

bool is_zero (double number) {
    assert(std::isfinite(number));

    return (fabs (number) <= EPSILON);
}

void show_result (double a, double b, double c) {
    printf("#Square Equation Solver\n");

    while (true) {
        printf("#Please enter coefficients a, b, c:\n");

        if (scanf ("%lg %lg %lg", &a, &b, &c) == 3) {
            double x1 = 0, x2 = 0;
            int num_roots = solve_square (a, b, c, &x1, &x2);

            switch (num_roots) {
                case NO_ROOTS:
                    printf ("No solution.\n");
                    break;
                case ONE_ROOT:
                    printf ("x = %-lg\n", x1);
                    break;
                case TWO_ROOTS:
                    printf ("x1 = %-lg, x2 = %-lg\n", x1, x2);
                    break;
                case INF_ROOTS:
                    printf ("Infinite number of solution.\n");
            }

        } else
            printf ("Failed input\n");

        printf ("Do you want to continue? y/n\n");

        while (getchar() != '\n') {;}

        if (getchar() == 'y')
            continue;
        else
            break;
    }
}

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
