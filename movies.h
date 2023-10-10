/*
 * Proyecto Movie Sorter
 * Jesús Alejandro Cedillo Zertuche
 * A01705442
 * 17/11/2023
 */

/*
 * Para este primer avance, voy a hacer una clase llamada Movie
 * Esta clase va a tener todos los atributos (nombre, duracion, director, etc)
 * Y en este primer avance voy a ordenar a las películas en base a lo que se pida ordenar
 */

// Librerías
#ifndef MOVIES_H
#define MOVIES_H
#include <list>
#include <iostream>

using namespace std;

// Clase movie que tiene los datos de la película, junto con sus constructores y getters
class Movie {
    // Atributos de la clase
    private: 
        string nombre;
        int duracion;
        string director;
        int review;
        int year;
    public: 
        // Constructores
        Movie(): nombre(""), director(""), duracion(0.0), review(0.0), year(0){};
        Movie(string nom, int dur, string direct, int rev, int ye): nombre(nom), duracion(dur), director(direct), review(rev), year(ye){};

        // Métodos de la clase
        string get_nombre();
        int get_duracion();
        string get_director();
        int get_review();
        int get_year();
};

/**
 * getter nombre
 * @return string: nombre de la película
 */
string Movie :: get_nombre(){
    return nombre;
}

/**
 * getter duración
 * @return int: duración en minutos de la película
 */
int Movie :: get_duracion(){
    return duracion;
}

/**
 * getter director
 * @return string: director de la película
 */
string Movie :: get_director(){
    return director;
}

/**
 * getter review
 * @return int: review (en % de 100) de la película
 */
int Movie :: get_review(){
    return review;
}

/**
 * getter year
 * @return int: año en el que se filmó la película
 */
int Movie :: get_year(){
    return year;
}

// Clase con el arreglo de las películas, y algoritmos de ordenamiento junto con una función de print
class Movie_Database {
    // Atributos de la clase
    private: 
        Movie movies[100];
        list<Movie> movie_list;
        int movies_size;
        void swap_num(int i, int j);
    public: 
        // Constructor por default
        Movie_Database(): movies_size(0){};

        // Métodos de la clase
        void agrega_movies();
        void agrega_movie_user();
        void add_movie_prueba(Movie prueba);
        void sort_choice(int sort_choice);
        int sort_choice_num(int min, int sort_choice, int letra);
        void sort_num(int sort_choice);
        void sort_text(int sort_choice);
        void print_movies();
        void print_element(int sort_choice);
};

/**
 * agrega_movies genera objetos en movies[]
 *
 * genera objetos de tipo Movie y los guarda en movies[] 
 * (arreglo de objetos) para tener qué ordenar
 * @param None
 * @return
 */
void Movie_Database :: agrega_movies(){
    movies[movies_size] = Movie("The Conjuring", 112, "James Wan", 86, 2013);
    movies_size++;
    movies[movies_size] = Movie("Star Wars: Revenge of the Sith", 140, "George Lucas", 100, 2005);
    movies_size++;
    movies[movies_size] = Movie("Oppenheimer", 180, "Christopher Nolan", 93, 2023);
    movies_size++;
    movies[movies_size] = Movie("Shrek II", 105, "Andrew Adamson", 95, 2004);
    movies_size++;
    movies[movies_size] = Movie("Avengers", 143, "Joss Whedon", 90, 2012);
    movies_size++;

    movie_list.push_back(Movie("The Conjuring", 112, "James Wan", 86, 2013));
    movie_list.push_back(Movie("Star Wars: Revenge of the Sith", 140, "George Lucas", 100, 2005));
    movie_list.push_back(Movie("Oppenheimer", 180, "Christopher Nolan", 93, 2023));
    movie_list.push_back(Movie("Shrek II", 105, "Andrew Adamson", 95, 2004));
    movie_list.push_back(Movie("Avengers", 143, "Joss Whedon", 90, 2012));
}

/**
 * agrega_movies_user agrega la película de la elección del usuario a la base de datos
 *
 * @param None
 * @return
 */
void Movie_Database :: agrega_movie_user(){
    // Declaras las variables donde se guardan los datos
    string name, dir;
    int dur, rev, ye;

    cout << "\nPor favor escribe el nombre de la película: ";
    // Se agrega el getline para que el input pueda tener espacio y no se cicle
    getline(cin.ignore(100, '\n'), name);

    cout << "\nPor favor escribe la duración de la película en minutos (num): ";
    cin >> dur;

    cout << "\nPor favor escribe el director de la película: ";
    getline(cin.ignore(100, '\n'), dir);

    cout << "\nPor favor escribe el review de la película en '%' del 1 al 100: ";
    cin >> rev;

    cout << "\nPor favor escribe el año que la película salió (num): ";
    cin >> ye;

    // Creas la película y la agregas al database
    movies[movies_size] = Movie(name, dur, dir, rev, ye);
    movies_size++;

    // Agregas la película a la lista ligada
    movie_list.push_back(Movie(name, dur, dir, rev, ye));
}

/**
 * add_movie_Prueba agrega la película que se creó afuera al arreglo con agregación
 * Esta función solo se usa en pruebas, para mayor facilidad en donde se llena un solo dato
 *
 * @param Movie Le pasas la "Película" para que la agregue a la lista
 * @return
 */
void Movie_Database :: add_movie_prueba(Movie Prueba){
    movies[movies_size] = Prueba;
    movies_size++;

    movie_list.push_back(Prueba);
}

/**
 * Cambia los elementos en el arreglo de acuerdo a sus indices
 * @param int num_1 (primer indice a cambiar)
 * @param int num_2 (Segundo indice a cambiar)
 * @return
 */
void Movie_Database :: swap_num(int num_1, int num_2) {
    Movie aux = movies[num_1];
	movies[num_1] = movies[num_2];
	movies[num_2] = aux;
}

/**
 * La función que decide cuál de los dos algoritmos de ordenamiento usa (texto o número)
 * @param int sort_choice (caso que se quiere ordenar)
 * @return
 */
void Movie_Database :: sort_choice(int sort_choice) {
    if (sort_choice == 1 || sort_choice == 3){ 
        sort_text(sort_choice);
    }
    else if (sort_choice == 2 || sort_choice == 4 || sort_choice == 5) {
        sort_num(sort_choice);
    }
}

/**
 * Dependiendo de lo que se quiera ordenar, saca los elementos del arreglo
 * @param int num (indice a buscar)
 * @param int sort_choice (caso que se quiere ordenar)
 * @param int letra (letra de la palabra que se está trabajando)
 * @return int - elemento del arreglo que se regresa (un número)
 */
int Movie_Database :: sort_choice_num(int num, int sort_choice, int letra){
    if (sort_choice == 1){
        return movies[num].get_nombre()[letra];
    }
    // Opcion 2 para duración
    else if (sort_choice == 2){
        return movies[num].get_duracion();
    }
    else if (sort_choice == 3){
        return movies[num].get_director()[letra];
    }
    // Opción 4 para review
    else if (sort_choice == 4){
        return movies[num].get_review();
    }
    // Opción 5 para year
    else if (sort_choice == 5) {
        return movies[num].get_year();
    }
    // Para evitar el warning
    return 0;
}

/**
 * Hace un selection sort con el arreglo dependiendo de lo que quieras ordenar
 * @param int sort_choice (Escenario en el que se quiere ordenar)
 * @return
 */
void Movie_Database :: sort_num(int sort_choice){
    int min;

	// Como se ordena en orden, este se ordena de más chico al más grande
	// Como hace el swap con el más chico, al final de una iteración ese indice ya está ordenado
	for(int i = 0; i < movies_size; i++){
		// Empiezas en el indice i, ya que lo que está antes ya está ordenado
		min = i;
		// Buscas el elemento más chico, de todo el arreglo. 
		// Se empieza con el índice del arreglo que no está ordenado. Esto lo tiene el otro ciclo
		for(int j = i; j < movies_size; j++){
			if (sort_choice_num(min, sort_choice, 0) > sort_choice_num(j, sort_choice, 0)){
				min = j;
			}
		}
		// Después de encontrarlo, haces el swap
		swap_num(i, min);
	}
}

/**
 * Hace un selection sort con el arreglo pero modificado para texto
 * @param int sort_choice (Escenario en el que se quiere ordenar)
 * @return
 */
void Movie_Database :: sort_text(int sort_choice){
    int min;

	// Como se ordena en orden, este se ordena de más chico al más grande
	// Como hace el swap con el más chico, al final de una iteración ese indice ya está ordenado
	for(int i = 0; i < movies_size; i++){
		// Empiezas en el indice i, ya que lo que está antes ya está ordenado
		min = i;
		// Buscas el elemento más chico, de todo el arreglo. 
		// Se empieza con el índice del arreglo que no está ordenado. Esto lo tiene el otro ciclo
		for(int j = i; j < movies_size; j++){
            // Usas un ciclo for que encuentre la primera letra diferente de la palabra. 
            // Solo entra al ciclo cuando min y j no son iguales, ya que si no se cicla el programa
            int count_letra = 0;
            for (int letra = 0; sort_choice_num(min, sort_choice, letra) == sort_choice_num(j, sort_choice, letra) && min != j; letra++){ 
                count_letra++;
            }

            // Ya que encontro la primera letra diferente, haces la comparación para el min
            if (sort_choice_num(min, sort_choice, count_letra) > sort_choice_num(j, sort_choice, count_letra)){
                min = j;
            }
		}
		// Después de encontrarlo, haces el swap
		swap_num(i, min);
	}
}

/**
 *
 * Imprime todas las características que hay en cada película que se encuentra 
 * en la lista movies[]. 
 * @param None
 * @return
 */
void Movie_Database :: print_movies(){
    // Iniciar un iterador al principio de la lista
    list<Movie>:: iterator p = movie_list.begin();

    // Iniciar un counter para imprimir el número de película
    int i = 0;
    while (p != movie_list.end()){
        cout << "\nMovie #" << i + 1 << endl;
        cout << "Nombre: " << p -> get_nombre() << endl;
        cout << "Duración: " << p -> get_duracion() << " min" << endl;
        cout << "Director: " << p -> get_director() << endl;
        cout << "Review: " << p -> get_review() << "%" << endl;
        cout << "Year: " << p -> get_year() << endl << endl;
        p++;
        i++;
    }
}

/**
 * Imprime un solo atributo. La función se usa para pruebas entonces
 * solo se usa con el nombre para comparar el texto, y duración para números
 * @param int sort_choice (caso que se quiere ordenar)
 * @return 
 */
void Movie_Database :: print_element(int sort_choice){
    // Iniciar un iterador al principio de la lista
    list<Movie>:: iterator p = movie_list.begin();

    // Opcion 1 para el texto
    if (sort_choice == 1){
        while (p != movie_list.end()){
            cout <<  p -> get_nombre() << " ";
        }
    }
    // Opcion 2 para los números
    else if (sort_choice == 2){
        while (p != movie_list.end()){
            cout <<  p -> get_duracion() << " ";
        }
    }
}

#endif