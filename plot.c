#include <stdio.h>
#include <stdlib.h>

void plot(int row, int col, double **A, double *X, double *B)
{
    int i;
    double x;

    double *Y;
    Y = (double *)calloc(row, sizeof(double));

    for (i = 0; i < row; i++)
    {
        x = A[i][1];
        Y[i] = (X[0] * 1) + (X[1] * x) + (X[2] * x * x);
    }

    x = 185;
    printf("\nFor height 185cm :\n");
    double ans = (X[0] * 1) + (X[1] * x) + (X[2] * x * x);
    printf("y(185) : %lf\n", ans);

    FILE *f = fopen("data/data2.txt", "w");
    fprintf(f, "%lf %lf \n", ans, x);
    fclose(f);

    FILE *fp = fopen("data/data.txt", "w");

    for (i = 0; i < row; i++)
    {
        x = A[i][1];
        fprintf(fp, "%lf %lf \n", x, Y[i]);
    }

    fclose(fp);

    FILE *fp1 = fopen("data/myfile1.gp", "w");
    fprintf(fp1, "set term pngcairo\nset output \"Equation curve.png\"\nset title \"Original Curve\"\nset xlabel \"Heights(cm)\"\nset ylabel \"Weights(kg)\"\nplot '%s' smooth unique with linespoints pt 7 notitle", "data.txt");
    fclose(fp1);

    FILE *fp2 = fopen("data/myfile2.gp", "w");
    fprintf(fp2, "set term pngcairo\nset output \"Original curve.png\"\nset title \"Original Curve\"\nset xlabel \"Heights(cm)\"\nset ylabel \"Weights(kg)\"\nplot '%s' smooth unique with linespoints pt 7 notitle ", "input.txt");
    fclose(fp2);

    FILE *fp3 = fopen("data/myfile3.gp", "w");
    fprintf(fp3, "set term pngcairo\nset output \"New curve.png\"\nset title \"Original Curve\"\nset xlabel \"Heights(cm)\"\nset ylabel \"Weights(kg)\"\nplot '%s' smooth unique with linespoints pt 7 notitle ", "data2.txt");
    fclose(fp3);

    system("cd data && gnuplot -p myfile1.gp && gnuplot -p myfile2.gp && gnuplot -p myfile3.gp");
}

/*
FILE *fp6 = fopen("myfile4.gp","w");
    fprintf(fp6,"set term pngcairo\nset output \"Original curve.png\"\nset title \"Original Curve\"\nset xlabel \"Heights(cm)\"\nset ylabel \"Weights(kg)\"\nplot '%s' smooth unique with linespoints pt 7 notitle","data.dat"); 
    fclose(fp6);

    system("gnuplot -p myfile5.gp && gnuplot -p myfile4.gp && gnuplot -p myfile.gp")

*/