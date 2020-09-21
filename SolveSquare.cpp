#include "SolveSquare.h"

//---------------------------------------------------------
/** \brief This function solves Square Equation \f$ ax^2 + bx + c = 0 \f$
    \param [in] a  The first coefficient
    \param [in] b  The second coefficient
    \param [in] c  The third coefficient
    \param x1 The pointer to the first root
    \param x2 The pointer to the second root
    \return the number of roots */
//---------------------------------------------------------

int SolveSquare (double a, double b, double c, double* x1, double* x2) {
    assert(std::isfinite(a));
    assert(std::isfinite(b));
    assert(std::isfinite(c));

    assert(x1 != nullptr);
    assert(x2 != nullptr);
    assert(x1 != x2);

    if (isZero(a))
        return SolveLinear (b, c, x1);

    // if (a != 0)
    double Discr = b * b - 4 * a * c;
    if (isZero (Discr)) {
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


//---------------------------------------------------------
/** \brief This function solves Linear Equation \f$ ax + b = 0 \f$
    \param [in] a The first  coefficient
    \param [in] b The second coefficient
    \param x1 The pointer to the root
    \return the number of roots */
//---------------------------------------------------------

int SolveLinear (double a, double b, double* x1) {

    assert(std::isfinite(a));
    assert(std::isfinite(b));
    assert(x1 != nullptr);

    if (isZero (a)) {
        if (isZero (b))
            return INF_ROOTS;
        return 0; // b != 0
    }
    *x1 = -b / a; // a != 0
    return 1;
}

//---------------------------------------------------------
/** \brief This function compares the number of double type with zero in epsilon accuracy
    \param a The given number
    \param EPSILON accuracy
    \return 1, if the given number equals zero with said accuracy, 0 if not */
//---------------------------------------------------------
bool isZero (double number) {
    assert(std::isfinite(number));

    return (fabs (number) <= EPSILON);
}

//---------------------------------------------------------
/** \brief This function shows result of operation
    \param a The first  coefficient
    \param b The second coefficient
    \param c The third  coefficient */
//---------------------------------------------------------

void show_result (double a, double b, double c) {
    printf("#Square Equation Solver\n");
    void Test_SolveSquare ();

    while (true) {
        printf("#Plese enter coefficients a, b, c:\n");

        if (scanf("%lg %lg %lg", &a, &b, &c) == 3) {
            double x1 = 0, x2 = 0;
            int num_roots = SolveSquare(a, b, c, &x1, &x2);

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
            }
        } else
            printf("Failed input\n");
        printf("Do you want to continue? y/n\n");

        char in = '\0';
        scanf("%c", &in);
        if (scanf("%c", &in) == 1) {
            if (in == 'y')
                continue;
            else // in == 'n'
                break;
        }
    }
}

void Test_SolveSquare () {
    double r1 = rand ();
    double r2 = rand ();
    double x1 = r1, x2 = r2;
    if (SolveSquare (0, 0, 0, &x1, &x2) != INF_ROOTS && x1 != r1 && x2 != r2)
        printf ("Test 1 (a = 0, b = 0, c = 0) failed\n");
    else
        printf ("Test 1 OK\n");
    if (SolveSquare (0, 0, 7, &x1, &x2) != NO_ROOTS && x1 != r1 && x2 != r2)
        printf ("Test 2 (a = 0, b = 0, c = 7) failed\n");
    else
        printf ("Test 2 OK\n");
    if (SolveSquare (0, 9, 90, &x1, &x2) != ONE_ROOT && x1 != -10 && x2 != r2)
        printf ("Test 3 (a = 0, b = 9, c = 90) failed\n");
    else
        printf ("Test 3 OK\n");
    if (SolveSquare (7, 8, 9, &x1, &x2) != NO_ROOTS && x1 != r2 && x2 != r2)
        printf ("Test 4 (a = 7, b = 8, c = 9) failed\n");
    else
        printf ("Test 4 OK\n");
    if (SolveSquare (1, -2, 1, &x1, &x2) != ONE_ROOT && x1 != 1 && x2 != r2)
        printf ("Test 5 (a = 1, b = -2, c = 1) failed\n");
    else
        printf ("Test 5 OK\n");
    if (SolveSquare (1, 2, 1, &x1, &x2) != ONE_ROOT && x1 != -1 && x2 != r2)
        printf ("Test 5 (a = 1, b = 2, c = 1) failed\n");
    else
        printf ("Test 5 OK\n");
    if (SolveSquare (1, 0, 0, &x1, &x2) != ONE_ROOT && x1 != 0 && x2 != r2)
        printf ("Test 6 (a = 1, b = 0, c = 0 failed\n");
    else
        printf ("Test 6 OK\n");
    if (SolveSquare (0, 1, 0, &x1, &x2) != ONE_ROOT && x1 != 0 && x2 != r2)
        printf ("Test 7 (a = 0, b = 1, c = 0) failed\n");
    else
        printf ("Test 7 OK\n");
    if (SolveSquare (0, 0, 7, &x1, &x2) != NO_ROOTS && x1 != r1 && x2 != r2)
        printf ("Test 8 (a = 0, b = 0, c = 7) failed\n");
    else
        printf ("Test 8 OK\n");
    if (SolveSquare (1, 0, -9, &x1, &x2) != 2 && x1 != 3 && x2 != -3)
        printf ("Test 9 (a = 1, b = 0, c = -9) failed\n");
    else
        printf ("Test 9 OK\n");

}

void test () {
    double r1 = rand (), r2 = rand ();
    double x1 = r1, x2 = r2;
    double a = rand (), b = rand (), c = rand ();
    int num_roots = SolveSquare (a, b, c, &x1, &x2);
    int check = 0;

    if (num_roots == TWO_ROOTS ) {
        if (isZero (a * x1 * x1 + b * x1 + c) && isZero (a * x2 * x2 + b * x2 + c));
            //printf ("TEST TWO_ROOTS OK\n");
        else
            printf ("TEST TWO_ROOTS (a = %lg, b = %lg, c = %lg) FAILED\n", a, b, c);
    }
    if (num_roots == ONE_ROOT) {
        if (isZero (a * x1 * x1 + b * x1 + c) && x2 == r2);
            //printf ("TEST ONE_ROOT OK");
        else
            printf ("TEST ONE_ROOT (a = %lg, b = %lg, c = %lg) FAILED\n", a, b, c);
    }
    if (num_roots == NO_ROOTS) {
        if (b * b - 4 * a * c < 0 && x1 == r1 && x2 == r2);
            //printf ("TEST NO_ROOTS  OK\n");
        else
            printf ("TEST NO_ROOTS (a = %lg, b = %lg, c = %lg) FAILED\n", a, b, c);
    }
    if (num_roots == INF_ROOTS) {
       for (int i = 0; i < 11; i++) {
           if (isZero(a * rand() * rand() + b * rand() + c))
               check = 1;
           else
               check = 0;
       }
       if (check);
           //printf ("TEST INF_ROOTS OK\n");
       else
           printf ("TEST INF_ROOTS (a = %lg, b = %lg, c = %lg) FAILED\n", a, b, c);
    }

}


