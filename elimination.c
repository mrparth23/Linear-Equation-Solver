#include <stdio.h>
#include <stdlib.h>

int gaussElimination(int row, int col, double **AtAAtB);
void reverseElimination(int row, int col, double **AtAAtB);

int elimination(int row, int col, double **AtAAtB)
{
    int i, j, k, rank = 0;
    double r;

    rank = gaussElimination(row, col, AtAAtB);

    // call to reverse Elimination to generate rref form :
    reverseElimination(row, col, AtAAtB);

    for (i = 0; i < row; i++)
    {
        if (AtAAtB[i][i] == 0)
            r = 1;
        else
            r = AtAAtB[i][i];
        for (j = 0; j < col; j++)
            AtAAtB[i][j] /= r;
    }
    return rank;
}
