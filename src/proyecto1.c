#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define CALLTIMES 10000

int fibo(int n){
    if (n <= 1) 
        return n; 
    return fibo(n - 1) + fibo(n - 2); 
}

int main(int argc, char const *argv[])
{
    clock_t start, end;
    double tiempoFuncion, tiempoSistema;

    start = clock();
    {
        for (int i = 0; i < CALLTIMES; ++i)
        {
            fibo(2);
        }
    }
    end = clock();
    tiempoFuncion = ((double) (end - start)) / CLOCKS_PER_SEC;

    start = clock();
    {
        for (int i = 0; i < CALLTIMES; ++i)
        {
            getpid();
        }
    }
    end = clock();
    tiempoSistema = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Llamada a la función fibonacci 10000 veces: %f\n", tiempoFuncion);
    printf("Llamada al sistema 10000 veces: %f\n", tiempoSistema);

    return 0;
}

