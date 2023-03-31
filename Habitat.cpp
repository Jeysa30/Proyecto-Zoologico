#include "Habitat.h"

Habitat::Habitat(string tipoHabitat) {
    this->tipoHabitat = tipoHabitat;
}

string Habitat::getTipoHabitat(){
    return tipoHabitat;
}

void Habitat::setTipoHabitat(string tipoHabitat){
    this->tipoHabitat = tipoHabitat;
}

unordered_map<int, Animal *> Habitat::getAnimales(){
    return animales;
}

int Habitat::getCantAnimales(){
    return cantAnimales;
}

void Habitat::setCantAnimales(int cantAnimales){
    this->cantAnimales = cantAnimales;
}
