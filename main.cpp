/*
 * Proyecto Movie Sorter
 * Jesús Alejandro Cedillo Zertuche
 * A01705442
 * 17/11/2023
 */

/*
 * Se va a hacer una clase llamada Movie
 * Esta clase va a tener todos los atributos (nombre, duracion, director, etc)
 * Donde dependiendo de lo que pida el usuario, ordena la lista doblemente ligada
 * Las películas son cargadas de un archivo para el uso más fácil de este
 */

// Biblotecas
#include <iostream>
#include "movies.h"
using namespace std;

// Procedimiento menu
void menu_inicial(){
    /* Imprimir el menu */
    cout << "\nMenu:\n";
    cout << "1. Agregar película a la base de datos.\n";
    cout << "2. Encontrar el nombre de una película.\n";
    cout << "3. Encontrar películas con cierta duración.\n";
    cout << "4. Encontrar películas por director.\n";
    cout << "5. Encontrar películas por reviews.\n";
    cout << "6. Encontrar películas por año. \n";
    cout << "7. Imprimir todas las películas (en el orden que fueron ordenadas al último). \n";
    cout << "8. Generar un archivo con películas ordenadas con cierto criterio (próximamente en otro avance). \n";
    cout << "Cualquier otro número para salir \n\n";
}

// Funcionar auxiliar para solo pedir esto cuando el programa haga ciertas cosas
char print_order(){
    // Le pides al usuario el orden que quiere imprimir las cosas
    cout << endl << "¿Quieres mostrar las películas en orden ascendiente o descendiente?" << endl;
    cout << "Si no se ha ordenado, descendiente imprimiría la película recién agregada hasta llegar a la primera." << endl;
    cout << "Para orden ascendiente escribe 1. Para descendiente escribe 2" << endl << endl;
    char descendiente;
    cout << "Por favor escribe solo 1 u 2. Opción: ";
    // Tomar el input del usuario
    cin >> descendiente;

    return descendiente;
}

int main(){

    cout << "\n¡Bienvenido al Movie Sorter de Yeesus, donde puedes ordenar cualquier película!\n";

    /* Crear el objeto de la base de datos con la lista vacía */
    Movie_Database Movies_Yeesus;

    // Se asgina un valor inicial a opción para que entre al ciclo
    int opcion = 1;

    // Ciclo para que se repita hasta que el usuario eliga opción válida
    while (opcion >= 1 && opcion <= 7){
        // Imprimir el menu
        menu_inicial();

        cout << "Por favor solo escribe números. Opción: ";
        // Tomar el input del usuario
        cin >> opcion;
        
        // En base al input sigue un procedimiento
        switch (opcion){
            // Caso 1 donde el usuario agrega las películas que quiera. Aquí vuelve a pedir el menú
            case 1: {
                Movies_Yeesus.agrega_movie_user();
                break;
            }
            // Caso 2 que se ordena por nombre
            case 2: {
                Movies_Yeesus.sort_choice(1);
                Movies_Yeesus.find_element_menu(1);
                break;
            }
            // Caso 3 que se ordena por duración
            case 3: {
                Movies_Yeesus.sort_choice(2);
                Movies_Yeesus.find_element_menu(2);
                break;
            }
            // Caso 4 que se ordena por director
            case 4: {
                Movies_Yeesus.sort_choice(3);
                Movies_Yeesus.find_element_menu(3);
                break;
            }
            // Caso 5 que se ordena por reviews
            case 5: {
                Movies_Yeesus.sort_choice(4);
                Movies_Yeesus.find_element_menu(4);
                break;
            }
            // Caso 6 que se ordena por año 
            case 6: {
                Movies_Yeesus.sort_choice(5);
                Movies_Yeesus.find_element_menu(5);
                break;
            }
            case 7: {
                char descendiente;
                descendiente = print_order();
                // Imprime las películas para demostrar como fueron ordenadas
                cout << "\nPelículas con el orden actual: \n";
                // Si la opción es dos imprimirla como lo pidió
                if (descendiente == '2'){
                    Movies_Yeesus.print_movies(2);
                }
                // Si no, para no generar error hacerlo por orden ascendiente
                else {
                    Movies_Yeesus.print_movies(1);
                }
                break;
            }
        }
    }

    cout << endl << "Perfecto, gracias por usar el programa!" << endl << endl;
    
    return 0;
}