/*
 * Proyecto Movie Sorter
 * Jesús Alejandro Cedillo Zertuche
 * A01705442
 * 17/11/2023
 */

/*
 * Archivo que contienes pruebas puras para ver si funciona el código correctamente
 * Como nota, actualmente el Conjuro no se encuentra porque esta corrupto lo que lee
 * Cuando eso se resuelva, se va a modificar las respuestas para incluir la película
 * 
 * La respuesta correcta se sacó ordenando el archivo de excel, y se copió el orden
 */

// Biblotecas
#include <iostream>
#include "movies.h"
using namespace std;

void check_answer(string correct_ans, string test_ans, int count){
    if (correct_ans == test_ans)
        cout << endl << "Test #" << count << " Correct! Success!" << endl;
    else {
        cout << endl << "Test #" << count << " Incorrect! Try again" << endl;
        cout << endl << "Correct answer Test #" << count << ":\n" << correct_ans << endl;
        cout << endl << "Test answer Test #" << count << ":\n" << test_ans << endl;
    }
}

int main(){
    // Creas la base de datos
    Movie_Database pruebas;

    // Variables donde se guardan datos
    string correct_ans;
    string test_ans;
    int count = 1;

    // TEST 1
    cout << "Test #1: Prueba de ordenamiento por duración de película.";

    correct_ans = "[86, 92, 95, 97, 98, 102, 102, 104, 104, 105, 105, 106, 106, 110, 110, 111, 112, 112, 113, 114, "
    "115, 115, 116, 116, 116, 118, 118, 119, 119, 119, 120, 121, 122, 124, 126, 127, 127, 127, 127, 127, 128, 128, "
    "128, 128, 129, 130, 130, 131, 132, 132, 135, 137, 138, 138, 139, 140, 140, 140, 141, 141, 142, 142, 142, 143, "
    "143, 144, 145, 148, 148, 148, 148, 149, 149, 150, 151, 152, 154, 155, 155, 160, 161, 162, 163, 163, 166, 168, "
    "168, 169, 169, 175, 176, 178, 178, 179, 180, 182, 192, 194, 195, 210]";
    pruebas.sort_choice(2);
    test_ans = pruebas.toString_atribute(2);

    check_answer(correct_ans, test_ans, count);
    count++;

    // TEST 2
    cout << endl << "Test #2: Prueba de ordenamiento por año de salida.";

    correct_ans = "[1972, 1977, 1980, 1983, 1991, 1991, 1991, 1993, 1994, 1994, 1995, 1995, 1996, 1997, 1997, " 
    "1998, 1998, 1999, 2000, 2001, 2002, 2002, 2003, 2003, 2003, 2004, 2005, 2006, 2006, 2007, 2007, 2007, 2007, "
    "2008, 2008, 2009, 2009, 2009, 2009, 2010, 2010, 2010, 2011, 2011, 2012, 2012, 2012, 2012, 2012, 2013, 2013, "
    "2013, 2013, 2013, 2014, 2014, 2014, 2014, 2014, 2014, 2015, 2015, 2015, 2016, 2016, 2016, 2016, 2016, 2017, "
    "2017, 2017, 2017, 2018, 2018, 2018, 2019, 2019, 2019, 2020, 2020, 2021, 2021, 2021, 2021, 2021, 2021, 2021, "
    "2022, 2022, 2023, 2023, 2023, 2023, 2023, 2023, 2023, 2023, 2023, 2023, 2023]";
    pruebas.sort_choice(5);
    test_ans = pruebas.toString_atribute(5);

    check_answer(correct_ans, test_ans, count);
    count++;

    // TEST 3
    cout << endl << "Test #3: Prueba de ordenamiento por Review de IMDB.";

    correct_ans = "[54, 58, 58, 59, 59, 61, 61, 62, 63, 63, 64, 64, 65, 66, 66, 67, 68, 69, 70, 70, 71, 71, 71, 71, 71, "
    "71, 71, 72, 72, 72, 72, 73, 73, 73, 73, 73, 73, 74, 74, 74, 74, 75, 75, 75, 76, 76, 76, 76, 76, 76, 77, 77, 77, 77, 77, "
    "78, 78, 78, 78, 78, 78, 78, 79, 79, 79, 79, 79, 80, 80, 80, 80, 81, 81, 82, 82, 83, 83, 84, 84, 84, 85, 85, 85, 86, 86, "
    "86, 86, 86, 87, 87, 88, 88, 88, 88, 89, 90, 90, 90, 92, 93]";
    pruebas.sort_choice(4);
    test_ans = pruebas.toString_atribute(4);

    check_answer(correct_ans, test_ans, count);
    count++;

    // TEST 4
    cout << endl << "Test #4: Prueba de ordenamiento por Director de A-Z";

    correct_ans = "[Aaron Horvath, Alex Kurtznam, Andrew Adamson, Angel Manuel Soto, Anthony & Joe Russo, Anthony & Joe Russo, "
    "Anthony Russo, Bong Joon-ho, Brian DePalma, Bruce A. Evans, Cary Joji Fukunaga, Charles Shyer, Chris McKay, Chris McKay, "
    "Chris Renaud, Christopher McQuarrie, Christopher McQuarrie, Christopher Nolan, Christopher Nolan, Christopher Nolan, Christopher Nolan, "
    "Christopher Nolan, Damien Chazelle, David Fincher, David Fincher, David Fincher, David Fincher, David Fincher, David Fincher, "
    "Dennis Villeneuve, Dexter Fletcher, Dominic Cooke, Doug Liman, Eugenio Derbez, Francis Ford Coppola, Frank Darabont, Garth Jennings, "
    "George Lucas, George Lucas, George Lucas, George Lucas, Gore Verbinski, Gore Verbinski, Gore Verbinski, Greta Gerwig, Guy Ritchie, "
    "Guy Ritchie, J. J. Abrams, J. J. Abrams, James Cameron, James Cameron, James Cameron, James Cameron, James Mangold, James Wan, "
    "Joaquim Dos Santos, John Lee Hancock, Jon Watts, Jonathan Demme, Joss Whedon, Joss Whedon, Louis Leterrier, Matt Reeves, Matthew Vaughn, "
    "Matthew Vaughn, Mel Gibson, Michael Brandt, Michael Spierig, Nancy Meyers, Neill Blomkamp, Neill Blomkamp, Oliver Parker, Patrick Hughes, "
    "Peter Jackson, Peter Jackson, Peter Jackson, Peter Jackson, Peter Jackson, Peter Jackson, Peter Ramsey, Peter Sohn, Phillip Noyce, Pierre Coffin, "
    "Quentin Tarantino, Rian Johnson, Rich Moore, Ridley Scott, Sam Mendes, Sam Mendes, Sam Mendes, Scott Derickson, Shawn Levy, Shawn Levy, "
    "Steven Caple Jr., Steven Spielberg, Steven Spielberg, Steven Spielberg, Tony Scott, Wally Pfister, Zack Snyder]";
    pruebas.sort_choice(3);
    test_ans = pruebas.toString_atribute(3);

    check_answer(correct_ans, test_ans, count);
    count++;

    // TEST 5
    cout << endl << "Test #5: Prueba de ordenamiento por Nombre de película de A-Z";

    correct_ans = "[1917, Avatar, Avatar: The Way of the Water, Avengers, Avengers: Age of Ultron, Avengers: Endgame, Avengers: Infinity War, "
    "Barbie, Blue Beetle, Braveheart, Captain America: Civil War, Cheaper by the Dozen, Deja Vu, Despicable Me, District 9, Doctor Strange, Dune, "
    "Dunkirk, Edge of Tomorrow, Elemental, Fast X, Father of the Bride, Fight Club, Free Guy, Ghosted, Gladiator, Gone Girl, Gran Turismo, "
    "Inception, Indiana Jones and the Dial of Destiny, Instructions not Included, Jack Reacher, Johnny English Reborn, Kingsman: The Secret Service, "
    "La La Land, Lego Batman, Looper, Man of Steel, Minority Report, Mission: Impossible, Mission: Impossible - Fallout, Mr. Brooks, No Time to Die, "
    "Oppenheimer, Parasite, Pirates of the Caribbean: At World's End, Pirates of the Caribbean: Dead Man's Chest, "
    "Pirates of the Caribbean: The Curse of the Black Pearl, Predestination, Pulp Fiction, Salt, Saving Private Ryan, Schindler's List, "
    "Seven, Sherlock Holmes, Shrek II, Sing, Skyfall, Spectre, Spider Man: Across the Spiderverse, Spider Man: Into the Spiderverse, "
    "Spider Man: No Way Home, Star Trek, Star Trek Into the Darkness, Star Wars: A New Hope, Star Wars: Return of the Jedi, Star Wars: Revenge of the Sith, "
    "Star Wars: The Empire Strikes Back, Stardust, Tenet, Terminator 2: Judgement Day, The Batman, The Conjuring, The Courier, The Curious Case of Benjamin Button, "
    "The Dark Knight, The Double, The Game, The Godfather, The Hitman's Bodyguard, The Hobbit: An Unexpected Journey, The Hobbit: The Battle of the Five Armies, "
    "The Hobbit: The Desolation of Smaug, The Little Things, The Lorax, The Lord of the Rings: Fellowship of the Ring, The Lord of the Rings: The Return of the King, "
    "The Lord of the Rings: The Two Towers, The Man from U.N.C.L.E., The Mummy, The Parent Trap, The Shawshank Redemption, The Silence of the Lambs, "
    "The Super Mario Bros Movie, The Tomorrow War, Titanic, Transcendence, Transformers: Rise of the Beast, Zodiac, Zootopia]";
    pruebas.sort_choice(1);
    test_ans = pruebas.toString_atribute(1);

    check_answer(correct_ans, test_ans, count);
    count++;

    // TEST 6
    cout << endl << "Test #6: Prueba de encontrar película por su nombre";

    correct_ans = "¡Elemento encontrado!\n\nMovie #87\nNombre: The Lord of the Rings: The Return of the King\n"
    "Duración: 210 min\nDirector: Peter Jackson\nReview: 90%\nYear: 2003\n\n";
    test_ans = pruebas.find_element_menu(1, "The Lord of the Rings: The Return of the King");

    check_answer(correct_ans, test_ans, count);
    count++;

    // TEST 7
    cout << endl << "Test #7: Prueba errónea de encontrar película por su nombre";

    correct_ans = "\n¡Elemento no encontrado!\n";

    test_ans = pruebas.find_element_menu(1, "Shrek");

    check_answer(correct_ans, test_ans, count);
    count++;

    // TEST 8
    // Ordena por duración, ya que se está buscando por ese atributo
    pruebas.sort_choice(2);
    cout << endl << "Test #8: Prueba de encontrar película por duración (2 películas en frente)";

    correct_ans = "¡Elemento encontrado!\n\nMovie #8\nNombre: Lego Batman\n"
    "Duración: 104 min\nDirector: Chris McKay\nReview: 73%\nYear: 2017\n\n"
    "¡Elemento encontrado!\n\nMovie #9\nNombre: Salt\n"
    "Duración: 104 min\nDirector: Phillip Noyce\nReview: 64%\nYear: 2010\n\n";

    test_ans = pruebas.find_element_menu(2, "104");

    check_answer(correct_ans, test_ans, count);
    count++;

    // TEST 9
    // Ordena por duración, ya que se está buscando por ese atributo
    pruebas.sort_choice(4);
    cout << endl << "Test #9: Prueba de encontrar película por review (2 películas al final)";

    correct_ans = "¡Elemento encontrado!\n\nMovie #90\nNombre: Spider Man: Across the Spiderverse\n"
    "Duración: 140 min\nDirector: Joaquim Dos Santos\nReview: 87%\nYear: 2023\n\n"
    "¡Elemento encontrado!\n\nMovie #89\nNombre: Star Wars: The Empire Strikes Back\n"
    "Duración: 124 min\nDirector: George Lucas\nReview: 87%\nYear: 1980\n\n";

    test_ans = pruebas.find_element_menu(4, "87");

    check_answer(correct_ans, test_ans, count);
    count++;

    // TEST 10
    cout << endl << "Test #10: Prueba de encontrar película y genere stoi error";

    correct_ans = "\nstoi: no conversion\n¡Escribiste una letra para encontrar un valor númerico!\n"
    "Por favor intente de nuevo!\n\n";

    test_ans = pruebas.find_element_menu(2, "Hello");

    check_answer(correct_ans, test_ans, count);
    count++;
}