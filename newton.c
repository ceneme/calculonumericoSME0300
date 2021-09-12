/*
    Rafael Ceneme 9898610
    Guilherme Pereira Loredo 11885190
    Guilherme Pedro de Oliveira Souza 11801178
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAXITER 32

double f(double x)
{
    return (double)( (3*pow(x,5)) - (9*pow(x,4)) + (2*pow(x,3)) - (6*pow(x,2)) - x + 3);
}

double df(double x)
{
    return (double)( (15*pow(x,4)) - (36*pow(x,3)) + (6*pow(x,2)) - (12*x) - 1);
}

double newton(double x, double epsilon, int maxiter)
{
    double x_k = f(x) / df(x);
    
    int k = 0;
    printf("%-10s %-20s %-20s %-20s %s\n", "k", "x_k", "f(x_k)", "f\'(x_k)", "e_k");

    while (fabs(x_k) >= epsilon && k < maxiter)
    {
        x_k = f(x) / df(x);
        x = x - x_k;
        printf("%-10d %-20.8lf %-20.8lf %-20.8lf %.8lf\n", k+1, x, f(x), df(x), fabs(x_k - x));
        k++;
    }

    if (k == maxiter)
        printf("maxiter atingido\n");

    return x;
}

int main(int argc, char *argv[])
{

    printf("Raiz aproximada = %lf\n", newton(1, 0.000001, MAXITER));

    return EXIT_SUCCESS;
}