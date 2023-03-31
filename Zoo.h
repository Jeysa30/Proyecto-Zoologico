#ifndef PROYECTO_ZOOLOGICO_ZOO_H
#define PROYECTO_ZOOLOGICO_ZOO_H
#include <iostream>
#include <vector>

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

};


#endif //PROYECTO_ZOOLOGICO_ZOO_H
