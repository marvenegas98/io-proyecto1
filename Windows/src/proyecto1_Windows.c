#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>


int fibo(int n){
    
    return n; 
}

void vacia(){

}

int main(){

	long iteraciones = 1000000; /* Cambiar para aumentar las iteraciones. */
	float tiempoSyscall1, tiempoFuncion1, tiempoFuncion2, time1, time2;
	struct timeval part_time1, part_time2;

/*************************************************************************************/
/*               Medicion de tiempo para syscall getpi()                             */
/*************************************************************************************/

	gettimeofday(&part_time1, NULL);
	time1 = (part_time1.tv_sec * 1000000 + part_time1.tv_usec) * 1000;

	for (int i = 0; i < iteraciones; i++) _getpid();

  	gettimeofday(&part_time2 ,NULL);
  	time2 = (part_time2.tv_sec * 1000000 + part_time2.tv_usec) * 1000;

  	tiempoSyscall1 = (time2 - time1)/(iteraciones * 1.0);


/*************************************************************************************/
/*               Medicion de tiempo para funcion fibonacci                           */
/*************************************************************************************/

  	gettimeofday(&part_time1,NULL);
  	time1 = (part_time1.tv_sec * 1000000 + part_time1.tv_usec) * 1000;

  	for (int i = 0; i < iteraciones; i++) fibo(2);

  	gettimeofday(&part_time2,NULL);
  	time2 = (part_time2.tv_sec * 1000000 + part_time2.tv_usec) * 1000;

  	tiempoFuncion1 = (time2 - time1)/(iteraciones * 1.0);

/*************************************************************************************/
/*               Medicion de tiempo para funcion vacia                               */
/*************************************************************************************/

  	gettimeofday(&part_time1,NULL);
  	time1 = (part_time1.tv_sec * 1000000 + part_time1.tv_usec) * 1000;

  	for (int i = 0; i < iteraciones; i++) vacia();

  	gettimeofday(&part_time2,NULL);
  	time2 = (part_time2.tv_sec * 1000000 + part_time2.tv_usec) * 1000;

  	tiempoFuncion2 = (time2 - time1)/(iteraciones * 1.0);
 

/*************************************************************************************/
/*                           Resultados                                              */
/*************************************************************************************/

	printf("----Comparación de Tiempos----\n");
	printf("\n");
    	printf("Tiempo de la funcion fibonacci de 2: %f\n", tiempoFuncion1);
	//printf("Tiempo de la funcion vacia: %f\n\n", tiempoFuncion2);
    	printf("Tiempo del Syscall getpid: %f\n", tiempoSyscall1);

  	return 0;
}
