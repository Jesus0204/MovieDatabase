/*
 * Proyecto Movie Sorter
 * Jesús Alejandro Cedillo Zertuche
 * A01705442
 * 17/11/2023
 */

/*
 * Para este segundo avance, tengo un archivo csv con 100 películas,
 * que son cargadas a la estructura de datos. Tiene nombre, duración, director
 * review y año en el que salió. Se puede ordenar por todos esos elementos y encontrar en la lista
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
        int elem_return_num_or_letter(list<Movie>:: iterator &elem_pointer, int sort_choice, int letra);
        void sort_num(int sort_choice);
        void sort_text(int sort_choice);
        string toString_movies(int asc_desc);
        string toString_element(list<Movie>:: iterator &elem_pointer, int count);
        string toString_atribute(int atribute_num);
        string find_element_menu(int find_choice, string value);
        bool find_element(list<Movie>:: iterator &elem_pointer, int find_choice, string value);
        string find_element(string value, int find_choice, list<Movie>:: iterator &elem_pointer);
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

    // Le quitas la primera línea del archivo porque está corrupta
    // Esto ocurre no importa que película se encuentre primero
    // Lo que se corrompe es el título (lo que va primero)
    // Lo demás no se corrompe
    // PREGUNTAAAAR Y AVERIGUAR PORQUE
    getline(file, line);

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
int Movie_Database :: elem_return_num_or_letter(list<Movie>:: iterator &elem_pointer, int sort_choice, int letra){
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
            if (elem_return_num_or_letter(min_pointer, sort_choice, 0) > elem_return_num_or_letter(j_pointer, sort_choice, 0)){
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
            while (elem_return_num_or_letter(min_pointer, sort_choice, count_letra) == elem_return_num_or_letter(j_pointer, sort_choice, count_letra) && min_pointer != j_pointer){
                count_letra++;
            }

            // Haces la comparación del elemento que se quedó apuntando min contra el actual de j
            // Si el de min es más grande, se sobrescribe a que ahora apunte al de j
            if (elem_return_num_or_letter(min_pointer, sort_choice, count_letra) > elem_return_num_or_letter(j_pointer, sort_choice, count_letra)){
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
 * @return string - aux (el string con todo lo que contiene la lista)
 */
string Movie_Database :: toString_movies(int asc_desc){
    // Creas el stream para guardar todo
    stringstream aux;

    if (asc_desc == 1){
        // Iniciar un iterador al principio de la lista
        list<Movie>:: iterator p = movies.begin();

        // Iniciar un counter para imprimir el número de película
        int i = 1;
        // Recorrer la lista e imprimir valores
        while (p != movies.end()){
            aux << "\nMovie #" << i << endl;
            aux << "Nombre: " << p -> get_nombre() << endl;
            aux << "Duración: " << p -> get_duracion() << " min" << endl;
            aux << "Director: " << p -> get_director() << endl;
            aux << "Review: " << p -> get_review() << "%" << endl;
            aux << "Year: " << p -> get_year() << endl << endl;
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
        int i = 1;
        while (i <= movies.size()){
            aux << "\nMovie #" << i << endl;
            aux << "Nombre: " << p -> get_nombre() << endl;
            aux << "Duración: " << p -> get_duracion() << " min" << endl;
            aux << "Director: " << p -> get_director() << endl;
            aux << "Review: " << p -> get_review() << "%" << endl;
            aux << "Year: " << p -> get_year() << endl << endl;
            p--;
            i++;
        }
    }

    // Lo regresas
    return aux.str();
}

/**
 * Imprime un elemento de la lista sin tener que iterarla
 * @param list<Movie>:: iterator elem_pointer (apuntador a elemento a imprimir)
 * @param int count (número de película en lista posiblemente ordenada)
 * @return string - aux (el string con todos los elementos de la pelicula)
 */
string Movie_Database :: toString_element(list<Movie>:: iterator &elem_pointer, int count){
    // Creas el stream para guardar todo
    stringstream aux;
    // Imprimes todos los datos del elemento apuntado
    aux << "\nMovie #" << count << endl;
    aux << "Nombre: " << elem_pointer -> get_nombre() << endl;
    aux << "Duración: " << elem_pointer -> get_duracion() << " min" << endl;
    aux << "Director: " << elem_pointer -> get_director() << endl;
    aux << "Review: " << elem_pointer -> get_review() << "%" << endl;
    aux << "Year: " << elem_pointer -> get_year() << endl << endl;

    // Lo regresas
    return aux.str();
}

/**
 * El método toString que imprime solo un atributos para el archivo de pruebas
 * @param int atribute_num (que tipo de atributo se va a regresar)
 * @return string - aux (el string con todos los atributos de lista)
 */
string Movie_Database :: toString_atribute(int atribute_num){
    stringstream aux;
    // Creas esto para el espacio del final
    list<Movie> :: iterator p = movies.begin();
    list<Movie> :: iterator end = movies.end();
    end--;

    aux << "[";
    // Iteras toda la lista
    while (p != movies.end()){
        // Para los valores con texto, como no existe uno que regrese todo el elemento, usas getters
        if (atribute_num == 1)
            aux << p -> get_nombre();
        else if (atribute_num == 3)
            aux << p -> get_director();
        // Para lo demás llamas la función, ya que regresa los valores númericos sin problema
        else 
            aux << elem_return_num_or_letter(p, atribute_num, 0);
        if (p != end){
            aux << ", ";
        }
        p++;
    }

    aux << "]";

    return aux.str();
}

/**
 * La función que manda a llamar las funciones de encontrar un número o un texto
 * @param int find_choice (caso que se quiere encontrar)
 * @param string value (el valor que se quiere buscar)
 * @return string - aux (El string donde se guarda toda la información a regresar)
 */
string Movie_Database :: find_element_menu(int find_choice, string value) {
    stringstream aux;

    // Iniciar un iterador al principio y final de la lista
    // Esto sirve para saber donde empezar a iterar y sacar la mitad del rango
    list<Movie>:: iterator first = movies.begin();
    list<Movie>:: iterator last = movies.end();
    // Hacer que last apunte a un elemento
    last--;

    if (find_choice == 1 || find_choice == 3){
        // Aquí no hago validación porque puede haber películas con título de número (como 1917)
        // Haces el cálculo para saber donde empezar en la lista (donde es más probable que este el elemento)
        char first_char = 'A';
        char last_char = 'Z';
        int size = (first_char + last_char) / 2;

        if (value[0] <= size){
            aux << find_element(value, find_choice, first);
        }
        else if (value[0] > size){
            aux << find_element(value, find_choice, last);
        }
    }
    else if (find_choice == 2 || find_choice == 4 || find_choice == 5) {
        // Intentar Convertir el string de input a número
        int value_num;
        try {
            value_num = stoi(value);
        }
        // Si ve que no se puede hacer imprimir y salir de la función (ya que después genera error)
        catch (invalid_argument const& ex)
        {
            aux << endl << ex.what() << endl << "¡Escribiste una letra para encontrar un valor númerico!" <<'\n';
            aux << "Por favor intente de nuevo!" << endl << endl;
            // Salir de la función para que no genere error
            return aux.str();
        }

        // Sacas el primer y último elemento
        int first_num = elem_return_num_or_letter(first, find_choice, 0);
        int last_num = elem_return_num_or_letter(last, find_choice, 0);
        // Sacas el cálculo de la mitad
        int size = (first_num + last_num) / 2;

        if (value_num <= size){
            aux << find_element(value, find_choice, first);
        }
        else if (value_num > size){
            aux << find_element(value, find_choice, last);
        }
    }

    return aux.str();
}

/**
 * Dependiendo de lo que se quiera ordenar, saca los elementos de la lista
 * @param list<Movie>:: iterator elem_pointer (elemento donde imprime)
 * @param int find_choice (caso que se quiere buscar)
 * @param string value (el valor a buscar)
 * @return
 */
bool Movie_Database :: find_element(list<Movie>:: iterator &elem_pointer, int find_choice, string value){
    // Opcion 1 para nombre
    if (find_choice == 1){
        if (elem_pointer -> get_nombre() == value)
            return true;
    }
    // Opcion 2 para duración
    else if (find_choice == 2){
        // Convertir el string de input a número
        int value_num = stoi(value);
        if (elem_pointer -> get_duracion() == value_num)
            return true;
    }
    // Opcion 3 para director
    else if (find_choice == 3){
        if (elem_pointer -> get_director() == value)
            return true;
    }
    // Opción 4 para review
    else if (find_choice == 4){
        // Convertir el string de input a número
        int value_num = stoi(value);
        if (elem_pointer -> get_review() == value_num)
            return true;
    }
    // Opción 5 para year
    else if (find_choice == 5) {
        // Convertir el string de input a número
        int value_num = stoi(value);
        if (elem_pointer -> get_year() == value_num)
            return true;
    }
    return false;
}

/**
 * Encuentras un elemento que es de tipo texto, iterando en la lista ya sea desde
 * el principio o del final
 * * Se consiguó apoyo de esta liga, donde si no se puede convertir el input a número
 * Saque al usuario de la función para que no genere error
 * https://stackoverflow.com/questions/59457656/exception-handling-with-stoi-function
 * @param string value (el valor a buscar)
 * @param int find_choice (caso que se quiere buscar)
 * @param list<Movie>:: iterator p (Lugar apuntado en donde se empieza iterar (final o principio))
 * @return string - aux (el string que indica si encontro el elemento y sus datos)
 */
string Movie_Database :: find_element(string value, int find_choice, list<Movie>:: iterator &p){
    // Creas el lugar para guardar todo
    stringstream aux;

    // Creas una bandera
    bool found = false;

    if (p == movies.begin()) {

        // Empiezas a iterar la lista completa y el contador
        int count = 1;
        while (p != movies.end()){
            // Si el valor a buscar es igual al que se busca
            if (find_element(p, find_choice, value) == true){
                aux <<"¡Elemento encontrado!" << endl;
                aux << toString_element(p, count);
                found = true;
            }
            // Incrementas el apuntador y el contador
            p++;
            count++;
        }
    }
    else {
        // Emmpiezas el contador y a iterar la lista desde atrás
        int count = movies.size();
        while(count != 0){
            // Si el valor a buscar es igual al que se busca
            if (find_element(p, find_choice, value) == true){
                aux <<"¡Elemento encontrado!" << endl;
                aux << toString_element(p, count);
                found = true;
            }
            // Decrementas el apuntador y el contador
            p--;
            count--;
        }
    }
    
    // Si la bandera se quedó en false todo el tiempo imprimes que no se encontro
    if (found == false){
        // Imprimes que no se encontró el elemento
        aux << endl << "¡Elemento no encontrado!" << endl;
    }
    return aux.str();
}

#endif