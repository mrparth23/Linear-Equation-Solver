#include <stdio.h>
#include <stdlib.h>

void swapRows(int a, int b, int row, int col, int **AtAAtB)
{
    //Function is used to Swap two rows of matrix :
    int i;
    int swap;

    for (i = 0; i < col; i++)
    {
        //swaps two rows of matrix :
        swap = AtAAtB[a][i];
        AtAAtB[a][i] = AtAAtB[b][i];
        AtAAtB[b][i] = swap;
    }
}