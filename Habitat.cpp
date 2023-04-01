#include "Habitat.h"

Habitat::Habitat() {
    this->tipoHabitat = "";
    this->animales[0] = NULL;
    this->cantAnimales = 0;
}

Habitat::Habitat(string tipoHabitat) {
    this->tipoHabitat = tipoHabitat;
    this->animales[1] = NULL;
    this->cantAnimales = 0;
}

string Habitat::getTipoHabitat(){
    return tipoHabitat;
}

void Habitat::setTipoHabitat(string tipoHabitat){
    this->tipoHabitat = tipoHabitat;
}

map<int, Animal*> Habitat::getAnimales(){
    return animales;
}

int Habitat::getCantAnimales(){
    return cantAnimales;
}

void Habitat::setCantAnimales(int cantAnimales){
    this->cantAnimales = cantAnimales;
}

void Habitat::agregarAnimal(Animal *nuevoAnimal) {
    this->animales[nuevoAnimal->getId()] = nuevoAnimal;
}
