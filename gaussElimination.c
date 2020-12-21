#include <stdio.h>
#include <stdlib.h>

void exchange(int i, int row, int col, double **AtAAtB);

int gaussElimination(int row, int col, double **AtAAtB)
{
    int i, j, k, rank = 0;
    double r;

    for (i = 0; i < row - 1; i++)
    {

        if (AtAAtB[i][i] == 0)
        {
            exchange(i, row, col, AtAAtB);
        }
        if (AtAAtB[i][i] == 0)
            r = 1;
        else
            r = AtAAtB[i][i];
        for (j = 0; j < col; j++)
        {
            AtAAtB[i][j] /= r;
        }

        if (AtAAtB[i][i] != 0)
        {
            for (j = i + 1; j < row; j++)
            {
                r = AtAAtB[j][i] / AtAAtB[i][i];
                for (k = 0; k < col; k++)
                {
                    AtAAtB[j][k] -= (r * AtAAtB[i][k]);
                }
            }
            rank++;
        }
    }

    if (row == 1)
    {
        return 1;
    }

    // lAtAAtBst pivot is mAtAAtBnully AtAAtBrrAtAAtBnged to be AtAAtBt pivot column :
    if (col - 1 >= row)
    {
        exchange(row - 1, row, col, AtAAtB);
        if (AtAAtB[row - 1][row - 1] != 0)
            rank++;
    }

    return rank;
}
