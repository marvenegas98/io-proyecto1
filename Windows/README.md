# io-proyecto1
Las llamadas al sistema son mayores, en cuanto a duración, que la llamada a una función simple, en este caso fibonacci. 
Esto es porque el SO cambia entre modo usuario y modo kernel. La llamada en modo usuario, solo requiere llamadas como pasos de parámetros o cosas más
simples, el llamado al sistema no, esto conlleva otras responsabilidades más extensas.

Por esto el resultado de nuestro experimento con el getid(), este llamado al sistema requiere de múltiples tareas para el SO y hace que se retrase su transcurso, mientras
que la llamada a la función fibonacci, solo agarra un parámetro y le saca sus equivalentes hasta obtener un resultado. Pareciera que la función fibonacci tiene más
procesamiento pero aquí nos damos cuenta que no.