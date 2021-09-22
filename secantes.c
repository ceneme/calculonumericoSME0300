/*
    Rafael Ceneme 9898610
    Guilherme Pereira Loredo 11885190
    Guilherme Pedro de Oliveira Souza 11801178
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define MAXITER 32

double f(double x)
{
    return (double)( (3*pow(x,5)) - (9*pow(x,4)) + (2*pow(x,3)) - (6*pow(x,2)) - x + 3);
}

double max(double a, double b)
{
    return b > a ? b : a;
}

double secant(double x0, double x1, double epsilon, FILE* fp, double x_barra)
{
    double xk, x_aux, ek, parada;
    int k = 0;
    bool isroot;

    fprintf(fp, "%-10s %-20s %-20s %s\n", "k", "x_k", "f(x_k)", "e_k");
    fprintf(fp, "%-10d %-20.8lf %-20.8lf %.8lf\n", k, x0, f(x0), fabs(x0-x_barra));
    k++;
    fprintf(fp, "%-10d %-20.8lf %-20.8lf %.8lf\n", k, x1, f(x1), fabs(x1-x_barra));
    k++;

    do
    {
        xk = (f(x1)*x0 - f(x0)*x1) / (f(x1) - f(x0));
        ek = fabs(xk-x_barra);
        parada = fabs(xk - x1);

        fprintf(fp, "%-10d %-20.8lf %-20.8lf %.8lf\n", k, xk, f(xk), ek);

        // atualizando o intervalo para proxima iteracao
        x0 = x1;
        x1 = xk;
        k++;
    }
    while(fabs(parada) >= epsilon * max(1, fabs(xk)) && k < MAXITER);

    if (k == MAXITER)
        printf("Maxiter atingido\n");

    return xk;
}

int main(int argc, char *argv[])
{
    FILE* fp = fopen("secantes_saida1.txt", "w");
    double x1, x2, epsilon = 0.000001;
    x1 = 0.0;
    x2 = -1.0;
    
    // intervalo [-1, 0]
    secant(x1, x2, epsilon, fp, -1/sqrt(3));

    fp = fopen("secantes_saida2.txt", "w");
    x1 = 0;
    x2 = 1;

    // intervalo [0,1]
    secant(x1, x2, epsilon, fp, 1/sqrt(3));

    return EXIT_SUCCESS;
}














