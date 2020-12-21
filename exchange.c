#include <stdio.h>
#include <stdlib.h>

void swapRows(int a, int b, int row, int col, double **AtAAtB);

void exchange(int i, int row, int col, double **AtAAtB)
{

    int j;
    j = i + 1;
    if (AtAAtB[i][i] == 0)
    {
        while (j < row)
        {
            if (AtAAtB[j][i] != 0)
            {
                swapRows(i, j, row, col, AtAAtB);
                return;
            }
            j++;
        }
    }
}
