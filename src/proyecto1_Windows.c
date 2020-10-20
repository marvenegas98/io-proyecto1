#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>


int fibo(int n){
    if (n <= 1) 
        return n; 
    return fibo(n - 1) + fibo(n - 2); 
}


int main(){

	long iteraciones = 1000000; /* Cambiar para aumentar las iteraciones. */
	float tiempoSyscalls, tiempoFuncion, time1, time2;
	struct timeval part_time1, part_time2;


	gettimeofday(&part_time1, NULL);
	time1 = (part_time1.tv_sec * 1000000 + part_time1.tv_usec) * 1000;

	for (int i = 0; i < iteraciones; i++) getpid();

  gettimeofday(&part_time2 ,NULL);
  time2 = (part_time2.tv_sec * 1000000 + part_time2.tv_usec) * 1000;

  tiempoSyscalls = (time2 - time1)/(iteraciones * 1.0);


  gettimeofday(&part_time1,NULL);
  time1 = (part_time1.tv_sec * 1000000 + part_time1.tv_usec) * 1000;

  for (int i = 0; i < iteraciones; i++) fibo(2);


  gettimeofday(&part_time2,NULL);
  time2 = (part_time2.tv_sec * 1000000 + part_time2.tv_usec) * 1000;

  tiempoFuncion = (time2 - time1)/(iteraciones * 1.0);
 

	printf("----Comparación de Tiempos----\n");
	printf("\n");
    printf("Tiempo de la función fibonacci: %f\n", tiempoFuncion);
    printf("Tiempo del Syscall: %f\n", tiempoSyscalls);

  return 0;
}
