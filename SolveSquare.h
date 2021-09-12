#ifndef SOLVESQUARE_SOLVESQUARE_H
#define SOLVESQUARE_SOLVESQUARE_H

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

//---------------------------------------------------------
/** \brief Enumerated type CODE_RETURN is used to define the number of roots of the equation
 * CODE_RETURN equals -1 if the equation has an infinite number of roots */
//---------------------------------------------------------

enum CODE_RETURN {
    INF_ROOTS = -1,
    NO_ROOTS  =  0,
    ONE_ROOT  =  1,
    TWO_ROOTS =  2,
};

//---------------------------------------------------------
/** \brief Constant EPSILON defines epsilon neighborhood of zero
 * Numbers belonging to this neighborhood are considered to be zero */
//---------------------------------------------------------

const double EPSILON = 1e-6;

// All function declaration
//---------------------------------------------------------
/** \brief This function solves Square Equation \f$ ax^2 + bx + c = 0 \f$
    \param [in] a  The first coefficient
    \param [in] b  The second coefficient
    \param [in] c  The third coefficient
    \param x1 The pointer to the first root
    \param x2 The pointer to the second root
    \return the number of roots */
//---------------------------------------------------------
int  solve_square       (double a, double b, double c, double *x1, double *x2);

//---------------------------------------------------------
/** \brief This function solves Linear Equation \f$ ax + b = 0 \f$
    \param [in] a The first  coefficient
    \param [in] b The second coefficient
    \param x1 The pointer to the root
    \return the number of roots */
//---------------------------------------------------------
int  solve_linear       (double a, double b, double *x1);

//---------------------------------------------------------
/** \brief This function compares the number of double type with zero in epsilon accuracy
    \param a The given number
    \param EPSILON accuracy
    \return 1, if the given number equals zero with said accuracy, 0 if not */
//---------------------------------------------------------
bool is_zero            (double number);

//---------------------------------------------------------
/** \brief This function accepts input data
    \param a The first  coefficient
    \param b The second coefficient
    \param c The third  coefficient */
//---------------------------------------------------------
void input_data         (double a, double b, double c);

//---------------------------------------------------------
/** \brief This function shows result of operation
    \param num_roots The number of roots of the equation
    \param x1 The first root
    \param x1 The second root */
//---------------------------------------------------------
void show_result        (int num_roots, double x1, double x2);

int  test_solve_square  (double a, double b, double c);
bool random_cases_test  ();
int  partial_cases_test ();
int  run_test           (unsigned long num_tests);

// End of declaration

#endif //SOLVESQUARE_SOLVESQUARE_H
