#ifndef SOLVESQUARE_SOLVESQUARE_H
#define SOLVESQUARE_SOLVESQUARE_H

#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstdlib>

enum CODE_RETURN {
    INF_ROOTS = -1,
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS,
};
const double EPSILON   = 1e-6;


// All function declaration

int  SolveSquare        (double a, double b, double c, double *x1, double *x2);
int  SolveLinear        (double a, double b, double *x1);
bool isZero             (double number);
void show_result        (double a, double b, double c);
int Test_SolveSquare    (double a, double b, double c);
bool random_cases_test  ();
int  partial_cases_test ();
int  run_test           (unsigned long num_tests);

// End of declaration

#endif //SOLVESQUARE_SOLVESQUARE_H
