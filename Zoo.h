//
// Created by jeysa nahara on 31/03/2023.
//

#ifndef PROYECTO_ZOOLOGICO_ZOO_H
#define PROYECTO_ZOOLOGICO_ZOO_H
#include <iostream>
#include <vector>

#include "Habitat.h"


using std::vector;

//creación de la clase Zoológico.
class Zoo {
private:
    vector<Habitat*> vectorHabitats; //creamos el vector para ir guardando los habitats de los animales.

public:
    Zoo() = default;

    vector<Habitat*> getVector();

    void agregarHabitat(Habitat* habitatAgregar);

};


#endif //PROYECTO_ZOOLOGICO_ZOO_H
