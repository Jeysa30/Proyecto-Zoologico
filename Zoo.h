#ifndef PROYECTO_ZOOLOGICO_ZOO_H
#define PROYECTO_ZOOLOGICO_ZOO_H
#include "Habitat.h"

using namespace std;

/* Clase contenedora Zoológico.
 * Habitat: creamos el vector para ir guardando los habitats de los animales.
 */

class Zoo {
private:
    //ATRIBUTOS:
    vector<Habitat*> vectorHabitats;

public:
    Zoo() = default; //Constructor por defecto.

    vector<Habitat*> getVector(); //Recibir la información.

    void agregarHabitat(Habitat* habitatAgregar); // Función para ir agregando un nuevo habitat al vector.

    // Funcion para ingresar los datos del habitat.
    void menuAgregarHabitat();

    // Creamos una función el cual permite ver la información general del zoológico. Retorna la dirrecion de memoria del habitat que quiere ver el usuario.
    Habitat* infoZoologico();

    //Metodo para buscar el animal que va a realizar la accion ingresada por el usuario
    Animal* buscarAnimalZoologico();

};

#endif //PROYECTO_ZOOLOGICO_ZOO_H