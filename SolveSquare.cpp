#include "SolveSquare.h"

int solve_square (double a, double b, double c, double* x1, double* x2) {
    assert (isfinite(a));
    assert (isfinite(b));
    assert (isfinite(c));

    assert (x1 != nullptr);
    assert (x2 != nullptr);
    assert (x1 != x2);

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

    assert(isfinite(a));
    assert(isfinite(b));
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
    assert(isfinite(number));

    return (fabs (number) <= EPSILON);
}

void input_data (double a, double b, double c) {
    printf("#Square Equation Solver\n");

    while (true) {
        printf("#Please enter coefficients a, b, c:\n");

        if (scanf ("%lg %lg %lg", &a, &b, &c) == 3) {
            double x1 = 0, x2 = 0;
            int num_roots = solve_square (a, b, c, &x1, &x2);

            show_result (num_roots, x1, x2);

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

void show_result (int num_roots, double x1, double x2) {

    switch (num_roots) {
        case NO_ROOTS:
            printf("No solution.\n");
            break;
        case ONE_ROOT:
            printf("x = %-lg\n", x1);
            break;
        case TWO_ROOTS:
            printf("x1 = %-lg, x2 = %-lg\n", x1, x2);
            break;
        case INF_ROOTS:
            printf("Infinite number of solution.\n");
            break;

        default:
            printf("Invalid number of roots!\n");
    }
}

