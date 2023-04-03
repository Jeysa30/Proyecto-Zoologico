#include "Animal.h"

Animal::Animal(string nombre,string especieAnimal, int id, int edad, int estadoSalud, int cantDormir){
    this->nombre = nombre;
    this->especieAnimal = especieAnimal;
    this->id = id;
    this->edad = edad;
    this->estadoSalud = estadoSalud;
    this->cantDormir = cantDormir;
    this->jugar = False;
}

string Animal::getNombre(){
    return nombre;
}

void Animal::setNombre(string nombre) {
    this->nombre = nombre;
}

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

vector<string> Animal::getAlimento(){
    return alimento;
}

void Animal::setAlimento(vector<string> alimento) {
    this->alimento = alimento;
}

string Animal::getEspecieAnimal(){
    return especieAnimal;
}

void Animal::setEspecieAnimal(string especieAnimal) {
    this->especieAnimal = especieAnimal;
}

void Animal::elegirAlimentacion(int tipoDieta){
    vector<string> dietaAnimal;
    if(tipoDieta == 1){
        dietaAnimal[0] = "Carne";
        dietaAnimal[1] = "Pescado";
        dietaAnimal[2] = "Presas";
    }
    else if(tipoDieta == 2){
        dietaAnimal[0] = "Hierva";
        dietaAnimal[1] = "Frutas";
        dietaAnimal[2] = "Vegetales";
    }
    else{
        dietaAnimal[0] = "Carne";
        dietaAnimal[1] = "Pescado";
        dietaAnimal[2] = "Futas";
    }
    this->setAlimento(dietaAnimal);
}
