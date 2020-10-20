# Proyecto 1 - Principios de Sistemas Operativos

Este proyecto consiste en comparar el costo de correr un syscall vs una llamada a un procedimiento.

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
Al compilar un programa en Windows sin optimización alguna, se ..
    
Para ejecutar el programa fuente, se navega a la carpeta "Windows" del proyecto y se ejecuta lo siguiente:



# Resultados Obtenidos

Se obtuvo que las llamadas al sistema son bastante más costosas que una llamada a un procedimiento.

Esto sucede porque una llamada un procedimiento no tiene que dar el control al kernel, porque se ejecuta directamente en el modo de usuario. Al ejecutar una llamada al sistema el programa debe cambiar al modo kernel antes de ejecutar la rutina en código SO, y aquí tiene que establecer de cuál llamada al sistema se trata, y si los parámetros que se están pasando están correctos o no. Por último, cambia de regreso al modo de usuario. 

Estos cambios de modos que trae el ejecutar una llamada al sistema ocupa tiempo, de aquí que conllevan un mayor costo. 
