#ifndef SOLVESQUARE_SOLVESQUARE_H
#define SOLVESQUARE_SOLVESQUARE_H
#include <cstdio>
#include <cmath>
#include <cassert>

enum CODE_RETURN {
    INF_ROOTS = -1,
    NO_ROOTS  =  0,
    ONE_ROOT,
    TWO_ROOTS,
};
const double EPSILON   =  1e-6;


// All function declaration

int  SolveSquare      (double a, double b, double c, double *x1, double *x2);
int  SolveLinear      (double a, double b, double *x1);
bool isZero           (double number);
void show_result      (double a, double b, double c);
void Test_SolveSquare ();
void test ();

// End of declaration

#endif //SOLVESQUARE_SOLVESQUARE_H
