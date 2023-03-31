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

public:
    Animal() = default; //Constructor por defecto.

    //-----Get y Set de nombre:
    string getNombre();
    void setNombre(string nombre);

    //-----Get y Set de tipoAlimento:
    string getTipoAlimento();
    void setTipoAlimento(string tipoAlimento);

    //-----Get y Set del id:
    int getId();
    void setId(int id);

    //-----Get y Set de edad:
    int getEdad();
    void setEdad(int edad);

    //-----Get y Set de estadoSalud:
    int getEstadoSalud();
    void setEstadoSalud(int estadoSalud);

    //-----Get y Set de tipoAnimal:
    int getTipoAnimal();
    void setTipoAnimal(int tipoAnimal);

    //-----Get y Set de cantDormir:
    int getCantDormir();
    void setCantDormir(int cantDormir);

    //-----Get y Set de cantComer:
    int getCantComer();
    void setCantComer(int cantComer);


};


#endif //PROYECTO_ZOOLOGICO_ANIMAL_H
