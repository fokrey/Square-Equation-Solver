#include <cstdio>
#include <cmath>
#include <cassert>

enum CODE_RETURN {
    INF_ROOTS = -1,
    NO_ROOTS  =  0,
    ONE_ROOT,
    TWO_ROOTS,
};
const double EPSILON   =  0.000001;

// All function declaration

int SolveSquare  (double a, double b, double c, double *x1, double *x2);
int SolveLinear  (double a, double b, double *x1);
int compare      (double left, double right);
bool isZero      (double number);
int show_result  (double a, double b, double c);
char get_answer  ();

// End of declaration

int main () {
    printf("#Square Equation Solver\n"
           "#Plese enter coefficients a, b, c:\n");
    double a = 0, b = 0, c = 0;

    show_result (a, b, c);
    return 0;
}

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
    if (isZero(Discr)) {
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
/** \brief This function compares two given numbers of double type
//  \param [in] a The first  given number
//  \param [in] b The second given number
//  \param EPSILON accuracy
//  \return 1 if a >  b,
           0 if a == b,
           1 if a <  b */
//---------------------------------------------------------

int compare (double left, double right) {
    assert(std::isfinite(left));
    assert(std::isfinite(right));

    if (fabs(left - right) <= EPSILON) // left == right
        return 0;
    if (left - right  >  EPSILON) // left > right
        return 1;
    return -1; // left < right
}

//---------------------------------------------------------
/** \brief This function compares the number of double type with zero in epsilon accuracy
    \param a The given number
    \param EPSILON accuracy
    \return 1, if the given number equals zero with said accuracy, 0 if not */
//---------------------------------------------------------
bool isZero (double number) {
    assert(std::isfinite(number));

    return compare (number, EPSILON) == 0;
}

int show_result (double a, double b, double c) {

    while (scanf("%lg %lg %lg", &a, &b, &c) == 3) {
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
                return 1;
        }
        printf("Do you want to continue? "
               "Enter new coefficients a, b, c if yes, n if no\n");
    }

    if (get_answer () == 'n')
        return 0;

    if (scanf("%lg %lg %lg", &a, &b, &c) != 3)
        printf ("Failed input!\n");
}

char get_answer () {
    char in = 0;
    scanf ("%c", &in);
    return in;
}


