/*
 * Proyecto Movie Sorter
 * Jesús Alejandro Cedillo Zertuche
 * A01705442
 * 17/11/2023
 */

/*
 * Para este primer avance, voy a hacer una clase llamada Movie
 * Esta clase va a tener todos los atributos (nombre, duracion, director, etc)
 * Se van a ordenar a las películas en base a lo que se pida ordenar
 */

#include <iostream>
#include "movies.h"

using namespace std;

void prueba_sort_text(){

    // Creas la base de datos vacía con la lista movies para probar los números
    Movie_Database Movies_Prueba;

    // Creas películas con un solo dato de texto para comprobar que el ordenamiento de texto funcione
    // Las películas están en el orden que se agregaron (el siguiente)
    Movie sort_test_num_1 = Movie("Zedillo", 0, "", 0, 0);
    Movies_Prueba.add_movie_prueba(sort_test_num_1);
    Movie sort_test_num_2 = Movie("Cedillo", 0, "", 0, 0);
    Movies_Prueba.add_movie_prueba(sort_test_num_2);
    Movie sort_test_num_3 = Movie("Angel", 0, "", 0, 0);
    Movies_Prueba.add_movie_prueba(sort_test_num_3);
    Movie sort_test_num_4 = Movie("Banquete", 0, "", 0, 0);
    Movies_Prueba.add_movie_prueba(sort_test_num_4);
    Movie sort_test_num_5 = Movie("Mono", 0, "", 0, 0);
    Movies_Prueba.add_movie_prueba(sort_test_num_5);
    Movie sort_test_num_6 = Movie("Banqueta", 0, "", 0, 0);
    Movies_Prueba.add_movie_prueba(sort_test_num_6);
    Movie sort_test_num_7 = Movie("Mano", 0, "", 0, 0);
    Movies_Prueba.add_movie_prueba(sort_test_num_7);
    Movie sort_test_num_8 = Movie("Pan", 0, "", 0, 0);
    Movies_Prueba.add_movie_prueba(sort_test_num_8);

    // Imprimes antes de ordenar
    cout << "\nElementos de texto antes de ordenar: \n";
    Movies_Prueba.print_element(1);

    // Haces que se ordene con la opción 2 ya que es donde se encuentran los datos cargados
    Movies_Prueba.sort_choice(1);

    // Imprimes después de ordenar. Solo se imprimen los números
    cout << "\n\nElementos de texto después de ordenar: \n";
    Movies_Prueba.print_element(1);
}

void prueba_sort_num(){

    // Creas la base de datos vacía con la lista movies para probar los números
    Movie_Database Movies_Prueba;

    // Creas películas con un solo dato númerico para comprobar que el ordenamiento de números funciona
    // Las películas están en el orden que se agregaron (el siguiente)
    Movie sort_test_num_1 = Movie("", 956, "", 0, 0);
    Movies_Prueba.add_movie_prueba(sort_test_num_1);
    Movie sort_test_num_2 = Movie("", 12, "", 0, 0);
    Movies_Prueba.add_movie_prueba(sort_test_num_2);
    Movie sort_test_num_3 = Movie("", 568, "", 0, 0);
    Movies_Prueba.add_movie_prueba(sort_test_num_3);
    Movie sort_test_num_4 = Movie("", 10, "", 0, 0);
    Movies_Prueba.add_movie_prueba(sort_test_num_4);
    Movie sort_test_num_5 = Movie("", 94736292, "", 0, 0);
    Movies_Prueba.add_movie_prueba(sort_test_num_5);
    Movie sort_test_num_6 = Movie("", 1, "", 0, 0);
    Movies_Prueba.add_movie_prueba(sort_test_num_6);
    Movie sort_test_num_7 = Movie("", 2004, "", 0, 0);
    Movies_Prueba.add_movie_prueba(sort_test_num_7);
    Movie sort_test_num_8 = Movie("", 13, "", 0, 0);
    Movies_Prueba.add_movie_prueba(sort_test_num_8);

    // Imprimes antes de ordenar
    cout << "\n\nElementos de número antes de ordenar: \n";
    Movies_Prueba.print_element(2);

    // Haces que se ordene con la opción 2 ya que es donde se encuentran los datos cargados
    Movies_Prueba.sort_choice(2);

    // Imprimes después de ordenar. Solo se imprimen los números
    cout << "\n\nElementos de número después de ordenar: \n";
    Movies_Prueba.print_element(2);

}

int main() {

    // Compruebas que el sort con texto funcione
    prueba_sort_text();

    // Compruebas que el sort con números funcione
    prueba_sort_num();
}