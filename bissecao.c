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

double max(double a, double b)
{
    return b > a ? b : a;
}

double bisection(double a, double b, double epsilon, FILE* fp, double x_barra)
{
    int k = 0;
    double x0 = a;
    double ek, xk, f_xk, parada;

    fprintf(fp, "%-10s %-20s %-20s %-20s %-20s %s\n", "k", "a", "b", "x_k", "f(x_k)", "e_k");

    if (f(a)*f(b) < 0)
    {
        do 
        {
            xk = (a + b) / 2;
            ek = fabs(xk-x_barra);
            parada = fabs(xk-x0);
            f_xk = f(xk);

            fprintf(fp, "%-10d %-20.8lf %-20.8lf %-20.8lf %-20.8lf %.8lf\n", k+1, a, b, xk, f_xk, ek);

            if (f_xk == 0)
                return xk;

            else if (f(a)*f_xk < 0)
                b = xk;
            else 
                a = xk;

            x0 = xk;
            k++;
        }
        while (fabs(parada) >= epsilon * max(1, fabs(xk)) && k < MAXITER);
    }
}

int main(int argc, char *argv[])
{
    // intervalo [-1,0]
    double a = -1;
    double b = 0;
    double epsilon = 0.000001;
    FILE* fp = fopen("bissecao_saida1.txt", "w");
    
    bisection(a, b, epsilon, fp, -1/sqrt(3));

    // intervalo [0,1]
    a = 0;
    b = 1;
    fp = fopen("bissecao_saida2.txt", "w");
    
    bisection(a, b, epsilon, fp, 1/sqrt(3));

    return EXIT_SUCCESS;
}