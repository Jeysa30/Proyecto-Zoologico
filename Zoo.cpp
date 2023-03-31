#include "Zoo.h"


vector<Habitat*> Zoo::getVector() {
    return this->vectorHabitats;
}

void Zoo::agregarHabitat(Habitat* habitatAgregar) {
    this->vectorHabitats.push_back(habitatAgregar);
}

