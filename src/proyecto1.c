#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define contador 20000

clock_t x, y; //x viene siendo el tiempo de partida y y el de llegada

double tiempoFuncion, tiempoSyscalls; //tiempos de la función de los syscalls

int fibo(int n){
    if (n <= 1) 
        return n; 
    return fibo(n - 1) + fibo(n - 2); 
}

int main(int argc, char const *argv[]){

    x = clock();
        for (int i = 0; i < contador; ++i){
            fibo(2);
        }
    y = clock();
    tiempoFuncion = ((double) (y - x)) / CLOCKS_PER_SEC;

    x = clock();
        for (int i = 0; i < contador; ++i){
            getpid();
        }
    y = clock();
    tiempoSyscalls = ((double) (y - x)) / CLOCKS_PER_SEC;
	
	printf("----Comparación de Tiempos----\n");
	printf("\n");
    printf("Función fibonacci ejecutada 20000 veces: %f\n", tiempoFuncion);
    printf("Syscalls ejecutados 20000 veces: %f\n", tiempoSyscalls);

    return 0;
}

