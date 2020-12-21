#include <stdio.h>
#include <stdlib.h>

void uniqueSolution(int rank, int row, int col, double **AtAAtB, double *X);

void solution(int rank, int row, int col, double **AtAAtB, double *X)
{
    //this function decides whether solution for the equations exist or not, and if exist what is that :
    //unique or infinite :

    int m = row;
    int n = col - 1;

    if (rank == m && rank == n)
    {
        uniqueSolution(rank, row, col, AtAAtB, X);
    }
}
