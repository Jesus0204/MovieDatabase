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
#include <fstream>
#include <sstream>
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

// Clase con la lista de las películas, y algoritmos de ordenamiento junto con una función de print
class Movie_Database {
    // Atributos de la clase
    private: 
        list<Movie> movies;
        void swap(list<Movie>:: iterator i, list<Movie>:: iterator j);
    public: 
        // Constructor por default
        Movie_Database();

        // Métodos de la clase
        void agrega_movie_user();
        void sort_choice(int sort_choice);
        int sort_choice_num(list<Movie>:: iterator elem_pointer, int sort_choice, int letra);
        void sort_num(int sort_choice);
        void sort_text(int sort_choice);
        void print_movies(int asc_desc);
        void print_element(int sort_choice);
};

/**
 * Movie_Database (constructor) lee el archivo, y crea los objetos de dicho archivo
 *
 * genera objetos de tipo Movie y los guarda en movies
 * (lista de objetos) para tener qué ordenar
 * 
 * Usé estas dos ligas de apoyo: 
 * https://www.geeksforgeeks.org/program-to-parse-a-comma-separated-string-in-c/
 * https://iq.opengenus.org/read-and-write-in-csv-in-cpp/.
 * @param None
 * @return
 */
Movie_Database::Movie_Database(){
    // Abrir el archivo
    ifstream file;
    file.open("Movie_Database.csv");

    // Crear la variable para guardar cada línea
    string line;
    // Mientras siga habiendo lineas en el archivo
    while (getline(file, line)) {
        // Sobreescribes al contador para saber cuáles convertir a número por línea
        int count = 0;
        // Declaras las variables donde se guardan los datos
        string name, dir;
        int dur, rev, ye;
        // Crear un stringstream con esa línea
        stringstream ss(line);
        // Mientras siga habiendo string en ese stringstream
        while (ss.good()) {
            // Creas el elemento como string
            string element;
            // Sacas todo hasta que haya una coma y lo guardas en element
            getline(ss, element, ',');
            // Guardas cada elemento en una variable para después crear el objeto
            if (count == 0)
                name = element;
            else if(count == 1) 
                dur = stoi(element);
            else if(count == 2)
                dir = element;
            else if(count == 3)
                rev = stoi(element);
            else if(count == 4)
                ye = stoi(element);
    
            count++;
        }

        movies.push_back(Movie(name, dur, dir, rev, ye));
    }

    // Cierras el archivo
    file.close();
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

    // Agregas la película a la lista ligada
    movies.push_back(Movie(name, dur, dir, rev, ye));
}

/**
 * Cambia los elementos de la lista de acuerdo a los elementos pasados
 * @param list<Movie>:: iterator elem_1 (primer elemento a cambiar)
 * @param list<Movie>:: iterator elem_2 (Segundo elemento a cambiar)
 * @return
 */
void Movie_Database :: swap(list<Movie>:: iterator elem_1, list<Movie>:: iterator elem_2) {
    Movie aux = *elem_1;
    *elem_1 = *elem_2;
    *elem_2 = aux;
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
 * Dependiendo de lo que se quiera ordenar, saca los elementos de la lista
 * @param list<Movie>:: iterator elem_pointer (elememnto que se regresa el dato)
 * @param int sort_choice (caso que se quiere ordenar)
 * @param int letra (letra de la palabra que se está trabajando)
 * @return int - elemento de la lista que se regresa (un número)
 */
int Movie_Database :: sort_choice_num(list<Movie>:: iterator elem_pointer, int sort_choice, int letra){
    if (sort_choice == 1){
        return elem_pointer -> get_nombre()[letra];
    }
    // Opcion 2 para duración
    else if (sort_choice == 2){
        return elem_pointer -> get_duracion();
    }
    else if (sort_choice == 3){
        return elem_pointer -> get_director()[letra];
    }
    // Opción 4 para review
    else if (sort_choice == 4){
        return elem_pointer -> get_review();
    }
    // Opción 5 para year
    else if (sort_choice == 5) {
        return elem_pointer -> get_year();
    }
    // Para evitar el warning
    return 0;
}

/**
 * Hace un selection sort con la lista dependiendo de lo que quieras ordenar
 * @param int sort_choice (Escenario en el que se quiere ordenar)
 * @return
 */
void Movie_Database :: sort_num(int sort_choice){
    // Creas los tres distintos iteradores, donde el primero empieza al principio
    list<Movie>:: iterator i_pointer = movies.begin();
    list<Movie>:: iterator j_pointer;
    list<Movie>:: iterator min_pointer;

    // Recorres la lista hasta el final
    while (i_pointer != movies.end()){
        // Empiezas en el elemento i, ya que lo que está antes ya está ordenado
        min_pointer = i_pointer;

        // Se empieza con el elemento de la lista que no está ordenado.
        j_pointer = i_pointer;
        // Recorres desde ahí hasta el final de la lista
        while (j_pointer != movies.end()){
            // Haces la comparación del elemento que se quedó apuntando min contra el actual de j
            // Si el de min es más grande, se sobrescribe a que ahora apunte al de j
            if (sort_choice_num(min_pointer, sort_choice, 0) > sort_choice_num(j_pointer, sort_choice, 0)){
				min_pointer = j_pointer;
			}
            // Pasas al siguiente elemento
            j_pointer++;
        }
        // Después de encontrarlo, haces el swap
		swap(i_pointer, min_pointer);
        // Pasas al siguiente elemento a ordenar
        i_pointer++;
    }
}

/**
 * Hace un selection sort con la lista pero modificado para texto
 * @param int sort_choice (Escenario en el que se quiere ordenar)
 * @return
 */
void Movie_Database :: sort_text(int sort_choice){
    // Creas los tres distintos iteradores, donde el primero empieza al principio
    list<Movie>:: iterator i_pointer = movies.begin();
    list<Movie>:: iterator j_pointer;
    list<Movie>:: iterator min_pointer;

    // Recorres la lista hasta el final
    while (i_pointer != movies.end()){
        // Empiezas en el elemento i, ya que lo que está antes ya está ordenado
        min_pointer = i_pointer;

        // Se empieza con el elemento de la lista que no está ordenado.
        j_pointer = i_pointer;
        // Recorres desde ahí hasta el final de la lista
        while (j_pointer != movies.end()){

            // Usas un ciclo while que encuentre la primera letra diferente de la palabra. 
            // Solo entra al ciclo cuando min y j no son iguales, ya que si no se cicla el programa
            int count_letra = 0;
            while (sort_choice_num(min_pointer, sort_choice, count_letra) == sort_choice_num(j_pointer, sort_choice, count_letra) && min_pointer != j_pointer){
                count_letra++;
            }

            // Haces la comparación del elemento que se quedó apuntando min contra el actual de j
            // Si el de min es más grande, se sobrescribe a que ahora apunte al de j
            if (sort_choice_num(min_pointer, sort_choice, count_letra) > sort_choice_num(j_pointer, sort_choice, count_letra)){
				min_pointer = j_pointer;
			}
            // Pasas al siguiente elemento
            j_pointer++;
        }
        // Después de encontrarlo, haces el swap
		swap(i_pointer, min_pointer);
        // Pasas al siguiente elemento a ordenar
        i_pointer++;
    }
}

/**
 *
 * Imprime todas las características que hay en cada película que se encuentra 
 * en la lista movies. 
 * @param int asc_desc (1 para empezar al principio y 2 para empezar al final)
 * @return
 */
void Movie_Database :: print_movies(int asc_desc){

    if (asc_desc == 1){
        // Iniciar un iterador al principio de la lista
        list<Movie>:: iterator p = movies.begin();

        // Iniciar un counter para imprimir el número de película
        int i = 0;
        // Recorrer la lista e imprimir valores
        while (p != movies.end()){
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
    else if (asc_desc == 2){
        // Iniciar el iterador al final de la lista
        list<Movie>:: iterator p = movies.end();
        p--;
        // Hacer que apunte a un elemento

        // Iniciar un counter para imprimir el número de película
        int i = 0;
        while (i < movies.size()){
            cout << "\nMovie #" << i + 1 << endl;
            cout << "Nombre: " << p -> get_nombre() << endl;
            cout << "Duración: " << p -> get_duracion() << " min" << endl;
            cout << "Director: " << p -> get_director() << endl;
            cout << "Review: " << p -> get_review() << "%" << endl;
            cout << "Year: " << p -> get_year() << endl << endl;
            p--;
            i++;
        }
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
    list<Movie>:: iterator p = movies.begin();

    // Opcion 1 para el texto
    if (sort_choice == 1){
        while (p != movies.end()){
            cout <<  p -> get_nombre() << " ";
            p++;
        }
    }
    // Opcion 2 para los números
    else if (sort_choice == 2){
        while (p != movies.end()){
            cout <<  p -> get_duracion() << " ";
            p++;
        }
    }
}

#endif