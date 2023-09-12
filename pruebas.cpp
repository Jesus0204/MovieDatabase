#include <iostream>
#include "movies.h"

using namespace std;

int main(){

    // Creas la base de datos vacía con el arreglo movies[]
    Movie_Database Yeesus_movies;

    // Agrega las 3 películas al arreglo
    Yeesus_movies.agrega_movies();

    cout << "Antes de ordenar" << endl;

    // Imprime películas antes de ordenar
    Yeesus_movies.print_movies();

    // Llama el selection sort para ordenarlo con review
    Yeesus_movies.sort_num(5);

    cout << "Despues de ordenar;" << endl;

    // Imprime el arreglo despues de ordenar
    Yeesus_movies.print_movies();

}