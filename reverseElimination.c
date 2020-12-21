#include <stdio.h>
#include <stdlib.h>

void reverseElimination(int row, int col, double **AtAAtB)
{
    int i, j, k;
    double r;

    // reverse function is used to convert the upper triangular matrix to rref form  :
    for (i = row - 1; i > 0; i--)
    {
        if (AtAAtB[i][i] != 0)
        {
            for (j = i - 1; j >= 0; j--)
            {
                if (AtAAtB[i][i] != 0)
                {
                    r = (AtAAtB[j][i] / AtAAtB[i][i]);
                    for (k = col - 1; k >= 0; k--)
                    {
                        AtAAtB[j][k] -= (r * AtAAtB[i][k]);
                    }
                }
            }
        }
    }
}
