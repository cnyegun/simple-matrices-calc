#ifndef math_stuff
#define math_stuff

#include "matrix_struct.h"

struct matrix sumOfTwoMatrices(struct matrix mtx1, struct matrix mtx2)
{
    struct matrix sum;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sum.value[i][j] = mtx1.value[i][j] + mtx2.value[i][j];
        }
    }
    return sum;
}

#endif