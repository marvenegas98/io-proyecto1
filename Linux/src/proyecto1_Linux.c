#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <sys/time.h>
#define iteraciones 1000000

double tiempoFuncion, tiempoVacia, tiempoSyscall; //tiempos de la función de los syscalls
struct timeval tiempoF, tiempoS,tiempoV, tiempoX;

long obtener_nanosegundos(struct timeval t){  
    long a = t.tv_sec*1000000 + t.tv_usec;
    a *=1000;
    return a; 
}

int fibo(int n){
    if (n <= 1) 
        return n; 
    return fibo(n - 1) + fibo(n - 2); 
}
void vacia(){
}

int main(int argc, char const *argv[]){
   
    int res;

/*************************************************************************************/
/*               Medicion de tiempo para funcion fibonacci                              */
/*************************************************************************************/

    gettimeofday(&tiempoF,NULL); 
    
    for (int i = 0; i < iteraciones; ++i) ;
    
    gettimeofday(&tiempoS,NULL);

    tiempoFuncion = (obtener_nanosegundos(tiempoS) - obtener_nanosegundos(tiempoF))/(iteraciones*1.0);    

/*************************************************************************************/
/*               Medicion de tiempo para funcion vacia                               */
/*************************************************************************************/
    gettimeofday(&tiempoV,NULL);
    
    for (int i = 0; i < iteraciones; ++i) vacia();
    
    gettimeofday(&tiempoX,NULL); 

    tiempoVacia = (obtener_nanosegundos(tiempoX) - obtener_nanosegundos(tiempoV))/(iteraciones*1.0);    

/*************************************************************************************/
/*               Medicion de tiempo para funcion getpid                             */
/*************************************************************************************/
    
    gettimeofday(&tiempoS,NULL);
    
    for (int i = 0; i < iteraciones; ++i) getpid();
    
    gettimeofday(&tiempoF,NULL);

    tiempoSyscall = (obtener_nanosegundos(tiempoF) - obtener_nanosegundos(tiempoS))/(iteraciones*1.0);  

	
    printf("----Comparación de Tiempos----\n");
    printf("\n");
    printf("Tiempo de la función fibonacci: %f\n", tiempoFuncion);
    printf("Tiempo de la función vacia: %f\n", tiempoVacia);
    printf("Tiempo del Syscall: %f\n", tiempoSyscall);

    return 0;
}

