#include <stdio.h>
#include <stdlib.h>

void print(int row, int col, double **AtAAtB, double *AtB)
{
    //Function is used to print a matrix.
    //It print's Matrix in its Augumented Form :
    int i, j;

    if (col == 1)
    {
        for (i = 0; i < row; i++)
        {
            printf("%.1lf\n", AtB[i]);
        }
    }
    else
    {
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < col; j++)
            {
                printf("%.1lf  ", AtAAtB[i][j]);
            }
            printf("\n");
        }
    }
}
