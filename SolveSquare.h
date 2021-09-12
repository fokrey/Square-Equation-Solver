#ifndef SOLVESQUARE_SOLVESQUARE_H
#define SOLVESQUARE_SOLVESQUARE_H

#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstdlib>

enum CODE_RETURN {
    INF_ROOTS = -1,
    NO_ROOTS  =  0,
    ONE_ROOT  =  1,
    TWO_ROOTS =  2,
};

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
/** \brief This function shows result of operation
    \param a The first  coefficient
    \param b The second coefficient
    \param c The third  coefficient */
//---------------------------------------------------------
void show_result        (double a, double b, double c);

int  test_solve_square  (double a, double b, double c);
bool random_cases_test  ();
int  partial_cases_test ();
int  run_test           (unsigned long num_tests);

// End of declaration

#endif //SOLVESQUARE_SOLVESQUARE_H
