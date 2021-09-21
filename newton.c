/*
    Rafael Ceneme 9898610
    Guilherme Pereira Loredo 11885190
    Guilherme Pedro de Oliveira Souza 11801178
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAXITER 64

double f(double x)
{
    return (double)( (3*pow(x,5)) - (9*pow(x,4)) + (2*pow(x,3)) - (6*pow(x,2)) - x + 3);
}

double df(double x)
{
    return (double)( (15*pow(x,4)) - (36*pow(x,3)) + (6*pow(x,2)) - (12*x) - 1);
}

double max(double a, double b)
{
    return b > a ? b : a;
}

double newton(double x0, double epsilon, FILE* fp)
{
    double xk, ek;

    int k = 0;
    fprintf(fp, "%-10s %-20s %-20s %-20s %s\n", "k", "x_k", "f(x_k)", "f\'(x_k)", "e_k");
    fprintf(fp, "%-10d %-20.8lf %-20.8lf %-20.8lf %.8lf\n", k+1, x0, f(x0), df(x0), fabs(x0 - x0));
    k++;

    do 
    {
        xk = x0 - (f(x0) / df(x0));
        ek = fabs(xk - x0);

        fprintf(fp, "%-10d %-20.8lf %-20.8lf %-20.8lf %.8lf\n", k+1, xk, f(xk), df(xk), ek);

        x0 = xk;
        k++;

    } while (ek >= epsilon * max(1, fabs(xk)) && k < MAXITER);

    return xk;
}

int main(int argc, char *argv[])
{
    FILE* fp = fopen("newton_saida1.txt", "w");

    // intervalo [-1,0]
    newton(-1, 0.000001, fp);

    // intervalo [0,1]
    fp = fopen("newton_saida2.txt", "w");
    newton(1, 0.000001, fp);
    
    return EXIT_SUCCESS;
}