#ifndef PROYECTO_ZOOLOGICO_ANIMAL_H
#define PROYECTO_ZOOLOGICO_ANIMAL_H
#include <iostream>

#include "Habitat.h"

using namespace std;

/* Clase contenedora Animal:
 * nombre: Cada animal tendrá su respectivo nombre.
 * tipoAlimento: Se pondrá la clase de alimento que consume el animal.
 * id: Cada animal tendrá un número como identificación.
 * edad: Se pondrá o se irá cambiando la edad del animal.
 * tipoAnimal: Al momento de anear el animal se le identificará si es carnívoro, herbívoro ó omnívoro).
 * cantDormir: Se le agregará la cantidad maxima que puede dormir el animal.
 * cantComer: Se le agregará la cantidad en Kg de comida del animal.
 */

class Animal {
private:
    //ATRIBUTOS
    string nombre;
    string tipoAlimento;
    int id;
    int edad;
    int estadoSalud;
    int tipoAnimal;
    int cantDormir;
    int cantComer;

};


#endif //PROYECTO_ZOOLOGICO_ANIMAL_H
