#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void solution(int rank, int row, int col, double **AtAAtB, double *X);
int elimination(int row, int col, double **AtAAtB);
void print(int row, int col, double **AtAAtB, double *AtB);
void plot(int row, int col, double **A, double *X, double *B);

int main()
{
    freopen("data/input.txt", "r", stdin);
    // printf("Enter the dimensions of Matrix :\n");
    int row, col;
    row = 6;
    col = 2;

    int i, j, k;

    double **A;
    A = (double **)calloc(row, sizeof(double));
    for (i = 0; i < row; i++)
    {
        A[i] = (double *)calloc(col, sizeof(double));
    }

    double *B;
    B = (double *)calloc(row, sizeof(double));

    double **At;
    At = (double **)calloc(col, sizeof(double));
    for (i = 0; i < col; i++)
    {
        At[i] = (double *)calloc(row, sizeof(double));
    }

    double **AtA;
    AtA = (double **)calloc(col, sizeof(double));
    for (i = 0; i < col; i++)
    {
        AtA[i] = (double *)calloc(col, sizeof(double));
    }

    double *AtB;
    AtB = (double *)calloc(col, sizeof(double));

    double **AtAAtB;
    AtAAtB = (double **)calloc(col, sizeof(double));
    for (i = 0; i < col; i++)
    {
        AtAAtB[i] = (double *)calloc(col + 1, sizeof(double));
    }

    double *X;
    X = (double *)calloc(col - 1, sizeof(double));

    //Define A
    for (i = 0; i < row; i++)
    {
        scanf("%lf", &A[i][0]);
        scanf("%lf", &B[i]);
        A[i][1] = 1;
        //A[i][2] = A[i][1] * A[i][1];
    }

    //Define At
    for (i = 0; i < row; i++)
    {
        At[0][i] = A[i][0];
        At[1][i] = A[i][1];
        //At[2][i] = A[i][2];
    }

    //Define AtA
    for (i = 0; i < col; i++)
    {
        for (j = 0; j < col; j++)
        {
            for (k = 0; k < row; k++)
            {
                AtA[i][j] += At[i][k] * A[k][j];
            }
        }
    }

    //Define AtB
    for (i = 0; i < col; i++)
    {
        for (k = 0; k < row; k++)
        {
            AtB[i] += At[i][k] * B[k];
        }
    }

    //Define AtAAtB
    for (i = 0; i < col; i++)
    {
        for (k = 0; k < col; k++)
        {
            AtAAtB[i][k] = AtA[i][k];
        }

        AtAAtB[i][col] = AtB[i];
    }

    printf("\nMatrix  A:\n");
    print(row, col, A, AtB);
    printf("\nMatrix  B:\n");
    print(row, 1, AtAAtB, B);
    printf("\nMatrix  At:\n");
    print(col, row, At, AtB);
    printf("\nMatrix  AtA:\n");
    print(col, col, AtA, AtB);
    printf("\nMatrix  AtB:\n");
    print(col, 1, AtAAtB, AtB);
    printf("\nMatrix  AtAAtB:\n");
    print(col, col + 1, AtAAtB, AtB);

    int rank = elimination(col, col + 1, AtAAtB);

    // Call the solution function to find the solution of matrix :
    solution(rank, col, col + 1, AtAAtB, X);
    plot(row, col, A, X, B);

    return 0;
}

/*
19 3
160	68
155	78
143	56
162	70
170	72
175	78
167	68
163	54
156	43
172	71
180	65
159	59
169	63
157	62
161	90
171	45
181	62
177	57
140	80

*/