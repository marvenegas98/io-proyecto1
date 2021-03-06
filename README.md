# Proyecto 1 - Principios de Sistemas Operativos

Este proyecto consiste en comparar el costo de correr un syscall vs una llamada a un procedimiento.

Para esto, se construyeron dos programas, uno para Linux y otro para Windows, los cuales obtienen la cantidad de tiempo en milisegundos(mediante la función gettimeofday) que toma la ejecución de una cantidad especifica de iteraciones (1 millón) a la llamada de sistema getpid() y a un procedimiento que implementa Fibonacci. 

Integrantes: 
- Maria Isabel Venegas Berrocal
- Alejandro Centeno Chaves
- Hilary González Abarca

# Ejecución del Proyecto
Se debe correr el programa fuente correspondiente al sistema operativo que se esté usando. 

## Linux
Al compilar un programa en C sin optimización alguna, se añade la bandera O0 al comando. Esto se utiliza dentro de nuestro archivo 'makefile'.
    
Para ejecutar el programa fuente, se navega a la carpeta "Linux" del proyecto y se ejecuta lo siguiente:

    $ make
    $ linux

## Windows
Al compilar un programa en Windows sin optimización alguna, se añade la bandera O0 al comando. Esto se utiliza dentro de nuestro archivo 'makefile 
    
Para ejecutar el programa fuente, se navega a la carpeta "Windows" del proyecto y se ejecuta lo siguiente:

    $ make
    $ windows.exe

Para la compilación de este programa se utilizó el paquete mingw, el cual provee el compilador gcc, y para la ejecución del makefile se utilizó el programa make-3.81


# Resultados Obtenidos

En Linux, los resultados fueron de gran diferencia. El costo de la llamada al sistema por 1 millón de iteraciones fue aproximadamente de 460 milisegundos, mientras que la función fibonacci duró casi 3 milisegundos. 

En Windows, la diferencia no es tan marcada como en Windows, pero siguen durando más las llamadas al sistema que a un procedimiento. 

Por lo tanto, se encuentra que las llamadas al sistema son más costosas que las llamadas a un procedimiento. 

Esto sucede porque una llamada un procedimiento no tiene que dar el control al kernel, porque se ejecuta directamente en el modo de usuario. Al ejecutar una llamada al sistema el programa debe cambiar al modo kernel antes de ejecutar la rutina en código SO, y aquí tiene que establecer de cuál llamada al sistema se trata, y si los parámetros que se están pasando están correctos o no. Por último, cambia de regreso al modo de usuario. 

Estos cambios de modos que trae el ejecutar una llamada al sistema ocupa tiempo, de aquí que conllevan un mayor costo. 
