#include <stdio.h>
#include <stdlib.h>

void uniqueSolution(int rank, int row, int col, double **AtAAtB, double *X)
{
    int i, k;

    //unique solution function is appling backtracking to generate solution of equations :
    for (i = rank - 1; i >= 0; i--)
    {
        if (AtAAtB[i][i] != 0)
            X[i] += (AtAAtB[i][col - 1] / AtAAtB[i][i]);

        k = col - 2;
        while (k > i)
        {
            X[i] += X[k] * AtAAtB[i][k];
            k--;
        }
    }
    printf("\nSolution to Equations is :\n");
    for (i = 0; i < col - 1; i++)
    {
        printf("x%d = %lf\n", i + 1, X[i]);
    }
}
