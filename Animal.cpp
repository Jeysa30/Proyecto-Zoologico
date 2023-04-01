#include "Animal.h"

Animal::Animal(string nombre, int id, int edad, int estadoSalud){
    this->nombre = nombre;
    this->id = id;
    this->edad = edad;
    this->estadoSalud = estadoSalud;
}


string Animal::getNombre(){
    return nombre;
}

void Animal::setNombre(string nombre) {
    this->nombre = nombre;
}

//string Animal::getTipoAlimento(){
//    return tipoAlimento;
//}
//
//void Animal::setTipoAlimento(string tipoAlimento) {
//    this->tipoAlimento = tipoAlimento;
//}

int Animal::getId(){
    return id;
}

void Animal::setId(int id) {
    this->id = id;
}

int Animal::getEdad(){
    return edad;
}

void Animal::setEdad(int edad){
    this->edad = edad;
}

int Animal::getEstadoSalud(){
    return estadoSalud;
}

void Animal::setEstadoSalud(int estadoSalud) {
    this->estadoSalud = estadoSalud;
}

int Animal::getCantDormir(){
    return cantDormir;
}

void Animal::setCantDormir(int cantDormir) {
    this->cantDormir = cantDormir;
}

int Animal::getCantComer(){
    return cantComer;
}

void Animal::setCantComer(int cantComer) {
    this->cantComer = cantComer;
}

bool Animal::getJugar() {
    return this->jugar;
}

void Animal::setJugar(bool Jugar) {
    this->jugar = Jugar;
}
