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

double bisection(double a, double b, double epsilon, FILE* fp)
{
    if (f(a) * f(b) >= 0)
    {
        printf("Intervalo Invalido\n");
    }

    int k = 0;

    printf("%-10s %-20s %-20s %-20s %-20s %s\n", "k", "a", "b", "x_k", "f(x_k)", "e_k");
    //printf("%-10d %-20.8lf %-20.8lf %-20.8lf %-20.8lf %.8lf\n", k, a, b, (a+b)/2, f((a+b)/2), fabs(a - b));

    double c = a;
    while ((b-a) >= epsilon && k < MAXITER)
    {
        fwrite(&k, sizeof(int), 1, fp);
        c = (a+b)/2;

        if (f(c) == 0.0)
            break;

        else if (f(c)*f(a) < 0)
            b = c;
        else
            a = c;
        
        printf("%-10d %-20.8lf %-20.8lf %-20.8lf %-20.8lf %.8lf\n", k+1, a, b, c, f(c), fabs(a - b));
        k++;
    }
    printf("Raiz aproximada = %.6lf\n", c);
    return c;
}

int main(int argc, char *argv[])
{
    double a = -1;
    double b = 0;
    double epsilon = 0.000001;

    FILE* fp = fopen("bissecao_saida1.txt", "wt");

    bisection(a, b, epsilon, fp);
    a = 0;
    b = 1;
    printf("-------------------------------------------------------------------------------------------------------\n");
    bisection(a, b, epsilon, fp);

    return EXIT_SUCCESS;
}