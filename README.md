# Movie Database
Este proyecto tiene por lo mientras dos objetos, uno llamado Movie, con atributos de películas, como su nombre, duración y reviews y el otro llamado MovieDatabase. Ese tiene una lista doblemente ligada implementada con list de C++ de películas y un contador (para tener control interno). Los métodos de Movie solo son los constructores y getters, mientras que los de Movie_Database tiene dos sorts (uno para números y otro para textos, un método para imprimir sus datos y otros métodos auxiliares para ayudar con el sort o facilidad. 

## Datos de una película:
El objeto de Movie tiene los siguientes atributos, que también son los datos de la película:
1. Nombre.
2. Duración.
3. Director.
4. Review.
5. Year (año).

## Consideraciones
El programa se compila y corre con g++. Adicionalmente, el programa (aplicación) se encuentra en main.cpp, mientras que lo que hace pruebas.cpp es ver si los algoritmos y métodos funcionan correctamente. 

## SICT0301: Evalúa los componentes
### Análisis de complejidad para algoritmo de ordenamiento
Ahora, para el análisis de complejidad un selection sort tiende a ser O(n^2) ya que tiene dos ciclos (uno anidado). Esto puede ser cierto para el de sort_num, ya que solo tiene a dos ciclos, pero el que compara a los textos, es más bien O(n^2 * k) ya que se agregó otro ciclo para comparar si las letras son iguales. Esto es porque se agregó otro ciclo, peor este ciclo solo corre si las letras de dos palabras son diferentes, entonces si se tiene una lista de 1000 elementos, los dos primeros ciclos si correrían 1000 veces, pero este último correría mientras las letras de las palabras sean iguales (que no debe de pasar 20), por lo que no es suficientemente influyente para ser otra n. Entonces el sort númerico es O(n^2) y el de texto es O(n^2 * k). 

### Análisis de complejidad de estructura de datos 
Insertion: O(1) porque siempre uso pushback, y no tiene que iterar la lista.  

Busqueda: O(n/2), ya que en el peor de los casos dependiendo de donde inicie la busqueda, tengo que iterar por la mitad de la lista.   

Impresión: O(n), ya que no importa de donde empiezo, tengo que iterar toda la lista para imprimir todos los elementos.

## SICT0302: Toma decisiones
### Selección de algoritmo de ordenamiento
Para este problema decidí usar un selection sort, para poder organizar las películas con cualquier filtro, ya se númerico o por alfabeto. El selection funciona bastante bien, ya que aunque no sea el más rápido, con este es bastante fácil comparar números o letras dentro de un objeto (ya que se tienen que usar getters para obtener y comparar cada elemento). En cuánto al texto, es poco probable que se repitan letras, donde lo más común es que solo sea la primera igual, sin embargo, adapté el selection sort para que lo ordene letra por letra. Las funciones de ordenamiento se encuentran en movies.h en las líneas 228 y 263.

### Selección de estructura de datos
Para este problema uso una lista doblemente ligada (también llamada list en c++). Esta lista me es muy útil, ya que después de ordenar los elementos, los puedo desplegar por orden ascendiente (que empezaría por el head de la lista) o por orden descendiente (que empezaría por el tail de la lista). Tener acceso al final de la lista ayuda mucho a tener está funcionalidad de una forma más fácil. La lista doblemente ligada también da mucha flexibilidad al buscar un elemento, ya que igual puedo aprovechar empezar al final no principio dependiendo del valor buscado. Esta flexibilidad es por lo que decidí usar una lista doblemente ligada Actualmente las funciones se encuentran en movies.h donde para agregar película (línea 131) y para imprimir dependiendo de lo que quiera el usuario (línea 308).

## SICT0303: Implementa acciones científicas
### Consulta de información de estructura

### Lectura de archivos para cargar datos correctamente
Las películas están cargadas en un archivo llamado Movie_Database.csv, donde al llamar el constructor de MovieDatabase, see registran y agregan a la lista todas las películas. Por lo tanto, aunque la insersión de la estructura de datos sea O(1), como tengo que iterar por todas las líneas del archivo (n), aparte de iterar por cada elemento de cada línea (5 elementos por línea), por lo que el análisis asíntotico de la lectura del archivo sería de O(n * 5). 
