#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>

/* Funciones para comprar. */
void vacia(){

}

int retorno(){
  return(10);
}


int main(){

  long iteraciones = 1000000; /* Cambiar para aumentar las iteraciones. */
  float syscall_time, funcall_time, time1, time2;
  struct timeval part_time1, part_time2;


  gettimeofday(&part_time1, NULL);
  time1 = (part_time1.tv_sec * 1000000 + part_time1.tv_usec) * 1000;

  for (int i = 0; i < iteraciones; i++){
    getpid();
  }

  gettimeofday(&part_time2 ,NULL);
  time2 = (part_time2.tv_sec * 1000000 + part_time2.tv_usec) * 1000;

  syscall_time = (time2 - time1)/(iteraciones * 1.0);


  gettimeofday(&part_time1,NULL);
  time1 = (part_time1.tv_sec * 1000000 + part_time1.tv_usec) * 1000;

  for (int i = 0; i < iteraciones; i++){
    retorno();
  }

  gettimeofday(&part_time2,NULL);
  time2 = (part_time2.tv_sec * 1000000 + part_time2.tv_usec) * 1000;

  funcall_time = (time2 - time1)/(iteraciones * 1.0);
 

  printf("System Call : %f\n", syscall_time);
  printf("Llamada a funcion : %f\n", funcall_time);

  return 0;
}
