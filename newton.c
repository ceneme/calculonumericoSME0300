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

double newton(double x0, double epsilon, FILE* fp, double x_barra)
{
    double xk, ek, parada;

    int k = 0;
    fprintf(fp, "%-10s %-20s %-20s %-20s %s\n", "k", "x_k", "f(x_k)", "f\'(x_k)", "e_k");
    fprintf(fp, "%-10d %-20.8lf %-20.8lf %-20.8lf %.8lf\n", k, x0, f(x0), df(x0), fabs(x0 - x_barra));
    k++;

    do 
    {
        xk = x0 - (f(x0) / df(x0));
        parada = fabs(xk - x0);
        ek = fabs(xk - x_barra);

        fprintf(fp, "%-10d %-20.8lf %-20.8lf %-20.8lf %.8lf\n", k, xk, f(xk), df(xk), ek);

        x0 = xk;
        k++;

    } while (parada >= epsilon * max(1, fabs(xk)) && k < MAXITER);

    return xk;
}

int main(int argc, char *argv[])
{
    FILE* fp = fopen("newton_saida1.txt", "w");

    // intervalo [-1,0]
    newton(-1, 0.000001, fp, -1/sqrt(3));

    // intervalo [0,1]
    fp = fopen("newton_saida2.txt", "w");
    newton(1, 0.000001, fp, 1/sqrt(3));
    
    return EXIT_SUCCESS;
}