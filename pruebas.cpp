#include <iostream>
#include "movies.h"

using namespace std;

int main(){

Movie_Database Yeesus_movies;

Yeesus_movies.agrega_movies();

cout << "Antes de ordenar" << endl;

Yeesus_movies.print_movies();

Yeesus_movies.sort_num(4);

cout << "Despues de ordenar;" << endl;

Yeesus_movies.print_movies();

}