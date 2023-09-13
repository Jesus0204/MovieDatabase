#include <iostream>
#include "movies.h"

using namespace std;

int main(){

    // Creas la base de datos vacía con el arreglo movies[]
    Movie_Database Yeesus_movies;

    // Agrega las 5 películas al arreglo
    Yeesus_movies.agrega_movies();

    cout << "Antes de ordenar" << endl;

    // Imprime películas antes de ordenar
    Yeesus_movies.print_movies();

    // Llama el selection sort para ordenarlo con year
    Yeesus_movies.sort_num(5);

    cout << "Despues de ordenar:" << endl;

    // Imprime el arreglo despues de ordenar
    Yeesus_movies.print_movies();

    // Ahora se hace lo mismo pero con texto (como nombre o directores)

    // Llama el selection sort para ordenarlo por nombre
    Yeesus_movies.sort_text(1);

    cout << "Despues de ordenar por nombre:" << endl;

    Yeesus_movies.print_movies();

}