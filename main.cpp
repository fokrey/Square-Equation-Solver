#include <stdio.h>
#include <math.h>
#include <assert.h>

const int    INF_ROOTS = -1;
const double EPSILON   =  0.000001;

// All function declaration

int SolveSquare (double, double, double, double*, double*);
int SolveLinear (double, double, double*);
int compare     (double, double);
int isZero      (double);
int isMoreZero  (double);

// End of declaration

int main () {
    printf("#Square Equation Solver\n"
           "#Plese enter coefficients a, b, c:\n");
    double a = 0, b = 0, c = 0;

    if (scanf("%lg %lg %lg", &a, &b, &c) != 3)
        printf ("Failed input! Please enter numbers\n");

    else {
        double x1 = 0, x2 = 0;
        int num_roots = SolveSquare(a, b, c, &x1, &x2);

        switch (num_roots) {
            case 0:
                printf("No solution\n");
                break;
            case 1:
                printf("x = %+lg\n", x1);
                break;
            case 2:
                printf("x1 = %+lg, x2 = %+lg", x1, x2);
                break;
            case INF_ROOTS:
                printf("Infinite number of solution\n");
                return 1;
        }
    }
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
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    if (isZero(a))
        return SolveLinear (b, c, x1);

    /* if (a != 0) */
    double Discr = b * b - 4 * a * c;
    if (Discr == 0) {
        *x1 = *x2 = -b / (2 * a);
        return 1;
    }

    if (isMoreZero (Discr)) {
        *x1 = (-b + sqrt(Discr)) / (2 * a);
        *x2 = (-b - sqrt(Discr)) / (2 * a);
        return 2;
    }
    /* (Discr < 0) */
    printf ("No real roots\n");
    return 0;
}


//---------------------------------------------------------
/** \brief This function solves Linear Equation \f$ ax + b = 0 \f$
    \param [in] a The first  coefficient
    \param [in] b The second coefficient
    \param x1 The pointer to the root
    \return the number of roots */
//---------------------------------------------------------

int SolveLinear (double a, double b, double* x1) {

    assert(isfinite(a));
    assert(isfinite(b));
    assert(x1 != NULL);

    if (isZero (a)) {
        if (isZero (b))
            return INF_ROOTS;
        return 0; /* b != 0 */
    }
    *x1 = -b / a;  /* a != 0 */
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

int compare (double a, double b) {
    assert(isfinite(a));
    assert(isfinite(b));

    if (fabs(a - b) <= EPSILON) /* a == b */
        return 0;
    if (a - b > 2 * EPSILON) /* a > b */
        return 1;
    return -1; /* a < b */
}

//---------------------------------------------------------
/** \brief This function compares the number of double type with zero in epsilon accuracy
    \param a The given number
    \param EPSILON accuracy
    \return 1, if the given number equals zero with said accuracy, 0 if not */
//---------------------------------------------------------

int isZero (double a) {
    assert(isfinite(a));

    if (compare (a, EPSILON) == 0) /* if a == b */
        return 1;
    return 0; /* a != b */
}

//---------------------------------------------------------
/** \brief This function compares the number of double type with zero in epsilon accuracy
    \param a The given number
    \param EPSILON accuracy
    \return 1 if the given number is more zero with said accuracy, 0 if not */
//---------------------------------------------------------

int isMoreZero (double a) {
    assert(isfinite(a));

    if (compare(a, EPSILON) == 1) /* a > EPS */
        return 1;
    return 0;
}

