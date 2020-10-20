#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define iteraciones 20000

clock_t x, y; //x viene siendo el tiempo de partida y y el de llegada

double tiempoFuncion, tiempoSyscalls; //tiempos de la función de los syscalls

int fibo(int n){
    if (n <= 1) 
        return n; 
    return fibo(n - 1) + fibo(n - 2); 
}

int main(int argc, char const *argv[]){

    x = clock();
    
        for (int i = 0; i < iteraciones; ++i) fibo(2);
        
    y = clock();
    tiempoFuncion = ((double) (y - x)) / CLOCKS_PER_SEC;

    x = clock();
    
        for (int i = 0; i < iteraciones; ++i) getpid();
        
    y = clock();
    tiempoSyscalls = ((double) (y - x)) / CLOCKS_PER_SEC;
	
	printf("----Comparación de Tiempos----\n");
	printf("\n");
    printf("Tiempo de la función fibonacci: %f\n", tiempoFuncion);
    printf("Tiempo del Syscall: %f\n", tiempoSyscalls);

    return 0;
}

