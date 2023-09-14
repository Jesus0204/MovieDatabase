# Movie Database
Este proyecto tiene por lo mientras dos objetos, uno llamado Movie, con atributos de películas, como su nombre, duración y reviews y el otro llamado MovieDatabase. Ese tiene un arreglo de películas y un contador (para tener control interno). Los métodos de Movie solo son los constructores y getters, mientras que los de Movie_Database tiene dos sorts (uno para números y otro para textos, un método para imprimir sus datos y otros métodos auxiliares para ayudar con el sort o facilidad. 

## Datos de una película:
El objeto de Movie tiene los siguientes atributos, que también son los datos de la película:
1. Nombre.
2. Duración
3. Director
4. Review
5. Year (año)

## Consideraciones
El programa se compila y corre con g++. Adicionalmente, el programa (aplicación) se encuentra en main.cpp, mientras que lo que hace pruebas.cpp es ver si los algoritmos y métodos funcionan correctamente. 

## SICT0301: Evalúa los componentes
Ahora, para el análisis de complejidad un selection sort tiende a ser O(n^2) ya que tiene dos ciclos (uno anidado). Esto puede ser cierto para el de sort_num, ya que solo tiene a dos ciclos, pero el que compara a los textos, podría ser O(n^3) ya que se agregó otro ciclo para comparar si las letras son iguales. Sin embargo, en este programa no estamos comparando y ordenando muchas películas, y de igual forma es muy poco probable que el ciclo corra muchas veces (lo más común es que no corra, o solo corra una sola vez), por lo que también se puede asumir y aproximar que es O(n^2). 

## SICT0302: Toma decisiones
Para este problema decidí usar un selection sort, para poder organizar las películas con cualquier filtro, ya se númerico o por alfabeto. El selection funciona bastante bien, ya que aunque no sea el más rápido, con este es bastante fácil comparar números o letras dentro de un objeto (ya que se tienen que usar getters para obtener y comparar cada elemento). En cuánto al texto, es poco probable que se repitan letras, donde lo más común es que solo sea la primera igual, sin embargo, adapté el selectiion sort para que lo ordene letra por letra. Las funciones de ordenamiento se encuentran en movies.h en las líneas 167 y 192.
