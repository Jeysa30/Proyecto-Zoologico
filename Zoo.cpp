//
// Created by jeysa nahara on 31/03/2023.
//

#include "Zoo.h"


vector<Habitat*> Zoo::getVector() {
    return this->vectorHabitats;
}

void Zoo::agregarHabitat(Habitat* habitatAgregar) {
    this->vectorHabitats.push_back(habitatAgregar);
}

