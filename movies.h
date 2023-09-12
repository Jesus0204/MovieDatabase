/*
 * Proyecto Movie Sorter
 * Jesús Alejandro Cedillo Zertuche
 * A01705442
 * 17/11/2023
 */

/*
 * Para este primer avance, voy a hacer una clase llamada Movie
 * Esta clase va a tener todos los atributos (nombre, duracion, director, scare o meter)
 * Y en este primer avance voy a ordenar a las películas en base a lo que se pida ordenar
 */

#ifndef MOVIES_H
#define MOVIES_H
#include <iostream>

using namespace std;

class Movie {
    private: 
        string nombre;
        int duracion;
        string director;
        int review;
        int year;
    public: 
        Movie(): nombre(""), director(""), duracion(0.0), review(0.0), year(0){};
        Movie(string nom, int dur, string direct, int rev, float sca, int ye): nombre(nom), duracion(dur), director(direct), review(rev), year(ye){};
        string get_nombre();
        int get_duracion();
        string get_director();
        int get_review();
        int get_year();
};

string Movie :: get_nombre(){
    return nombre;
}

int Movie :: get_duracion(){
    return duracion;
}

string Movie :: get_director(){
    return director;
}

int Movie :: get_review(){
    return review;
}

int Movie :: get_year(){
    return year;
}


class Movie_Database {
    private: 
        Movie movies[100];
        int num_movie;
    public: 
        Movie_Database(): num_movie(0){};
        void agrega_movies();
        void swap_num(int i, int j);
        int sort_choice_num(int min, int sort_choice);
        void sort_num(int sort_choice);
        void sort_text();
        void print_movies();
};

void Movie_Database :: agrega_movies(){
    movies[num_movie] = Movie("The Conjuring", 112, "James Wan", 86, 3.5, 2013);
    num_movie++;
    movies[num_movie] = Movie("Star Wars: Revenge of the Sith", 140, "George Lucas", 100, 1.0, 2005);
    num_movie++;
    movies[num_movie] = Movie("Oppenheimer", 180, "Christopher Nolan", 93, 2.5, 2023);
    num_movie++;
}

void Movie_Database :: swap_num(int num_1, int num_2) {
    Movie aux = movies[num_1];
	movies[num_1] = movies[num_2];
	movies[num_2] = aux;
}

int Movie_Database :: sort_choice_num(int num, int sort_choice){
    // Opcion 2 para duración
    if (sort_choice == 2){
        return movies[num].get_duracion();
    }
    // Opción 4 para review
    else if (sort_choice == 4){
        return movies[num].get_review();
    }
    // Opción 5 para year
    else if (sort_choice == 5) {
        return movies[num].get_year();
    }
}

// Se usa un selection sort
void Movie_Database :: sort_num(int sort_choice){
    int min;

	// Como se ordena en orden, este se ordena de más chico al más grande
	// Como hace el swap con el más chico, al final de una iteración ese indice ya está ordenado
	for(int i = 0; i < num_movie; i++){
		// Empiezas en el indice i, ya que lo que está antes ya está ordenado
		min = i;
		// Buscas el elemento más chico, de todo el arreglo. 
		// Se empieza con el índice del arreglo que no está ordenado. Esto lo tiene el otro ciclo
		for(int j = i; j < num_movie; j++){
			if (sort_choice_num(min, sort_choice) > sort_choice_num(j, sort_choice)){
				min = j;
			}
		}
		// Después de encontrarlo, haces el swap
		swap_num(i, min);
	}
}

void Movie_Database :: sort_text(){

}

void Movie_Database :: print_movies(){
    for (int i = 0; i < num_movie; i++){
        cout << "Movie #" << i + 1 << endl;
        cout << "Nombre: " << movies[i].get_nombre() << endl;
        cout << "Duración: " << movies[i].get_duracion() << " min" << endl;
        cout << "Director: " << movies[i].get_director() << endl;
        cout << "Review: " << movies[i].get_review() << "%" << endl;
        cout << "Year: " << movies[i].get_year() << endl << endl << endl;
    }
}


#endif