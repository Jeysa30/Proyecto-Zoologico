#include "Animal.h"

Animal::Animal(string nombre,string especieAnimal, int id, int edad, int estadoSalud, int cantDormir, int cantComer){
    this->nombre = nombre;
    this->especieAnimal = especieAnimal;
    this->id = id;
    this->edad = edad;
    this->estadoSalud = estadoSalud;
    this->cantDormir = cantDormir;
    this->cantDormirTemporal = cantDormir;
    this->cantComer = cantComer;
    this->cantComerTemporal = cantComer;
    this->jugar = false;
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

int Animal::getCantDormirTemporal(){
    return cantDormirTemporal;
}

void Animal::setCantDormirTemporal(int cantDormirTemporal) {
    this->cantDormirTemporal = cantDormirTemporal;
}

int Animal::getCantComerTemporal(){
    return cantComerTemporal;
}

void Animal::setCantComerTemporal(int cantComerTemporal) {
    this->cantComerTemporal = cantComerTemporal;
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

string Animal::getDieta(){
    return dieta;
}

void Animal::setDieta(string dieta) {
    this->dieta = dieta;
}

// Creación de la función para elegir el tipo de alimentacion del animal.
void Animal::elegirAlimentacion(int tipoDieta){
    vector<string> dietaAnimal;
    if(tipoDieta == 1){ // Alimento para los carnivoros
        this->dieta = "Carnivoro";
        dietaAnimal.push_back("carne");
        dietaAnimal.push_back("pescado");
        dietaAnimal.push_back("presas");
    }
    else if(tipoDieta == 2){ // Alimento para los herviboros.
        this->dieta = "Herviboro";
        dietaAnimal.push_back("hierva");
        dietaAnimal.push_back("frutas");
        dietaAnimal.push_back("vegetales");
    }
    else{ // Alimento para los omnivoros.
        this->dieta = "Omnivoro";
        dietaAnimal.push_back("carne");
        dietaAnimal.push_back("pescado");
        dietaAnimal.push_back("futas");
        dietaAnimal.push_back("verduras");
    }
    this->setAlimento(dietaAnimal);
}

void Animal::accionAnimal(){
    int cantAccion = 0;
    string accion;

    while(cantAccion != -777) {
        cout << "Ingresa el nombre de la accion que quieres que realice " << this->nombre << ": ";
        cin >> accion;
        for (int i = 0; i < accion.length(); i++) {
            accion[i] = tolower(accion[i]);
        }
        if (accion.compare("dormir") == 0) {
            this->dormirAccion(&cantAccion);
        }
        else if (accion.compare("comer") == 0) {
            this->comerAccion(&cantAccion);
        }
        else if (accion.compare("jugar") == 0) {
            this->jugarAccion(&cantAccion);
        }
        else {
            cout << "Solo puedes pedirle al animal realizar 3 tipos de acciones (Comer, dormir, jugar)." << endl;
        }
    }
}

void Animal::dormirAccion(int* cantAccion){
    cout << "Ingrese la cantidad de horas que va a dormir " << this->nombre << ": ";
    cin >> *cantAccion;
    if (this->cantDormirTemporal - *cantAccion >= 0) {
        this->cantDormirTemporal -= *cantAccion;
        cout << "El animal con id " << this->id << " y nombre " << this->nombre << " durmio " << *cantAccion
             << " horas de las " << this->cantDormir << " disponibles, le quedan " << this->cantDormirTemporal
             << " horas para dormir en el dia" << endl;
        *cantAccion = -777;
    }
    else {
        cout << "El animal con id " << this->id << " y nombre " << this->nombre << " no puede dormir "
             << *cantAccion << " horas en este momento, solo le quedan " << this->cantDormirTemporal
             << " horas para dormir hoy" << endl;
    }
}

void Animal::comerAccion(int* cantAccion){
    string alimentarAnimal;
    cout << "\nTenga en cuenta que " << this->nombre << " es " << this->dieta << endl;
    cout << "Ingrese el alimento que se le va a dar a " << this->nombre << ": ";
    cin >> alimentarAnimal;
    for (int i = 0; i < alimentarAnimal.length(); i++) {
        alimentarAnimal[i] = tolower(alimentarAnimal[i]);
    }
    for(int i = 0; i < this->alimento.size(); i++){
        if(alimentarAnimal.compare(this->alimento[i]) == 0){
            cout << "Ingrese la cantidad de alimento que le va a dar a " << this->nombre << ": ";
            cin >> *cantAccion;
            if (this->cantComerTemporal - *cantAccion >= 0) {
                this->cantComerTemporal -= *cantAccion;
                cout << "El animal con id " << this->id << " y nombre " << this->nombre << " comio " << *cantAccion
                     << " kilogramos de " << alimentarAnimal << ", le quedan por comer " << this->cantComerTemporal
                     << " kilogramos en el dia" << endl;
                *cantAccion = -777;
            }
            else {
                cout << "El animal con id " << this->id << " y nombre " << this->nombre << " no puede comer "
                     << *cantAccion << " kilogramos en este momento, solo le quedan " << this->cantComerTemporal
                     << " kilogramos para comer hoy" << endl;
            }
            break;
        }
        if(i + 1 == this->alimento.size()){
            cout << alimentarAnimal
            << " no se encuentra dentro de la posible dieta de " << this->nombre
            << ", si crees que deberia estar en la dieta agregalo en la opcion 3 del menu." << endl;
        }
    }
}

void Animal::jugarAccion(int* cantAccion){
    if(this->jugar == false){
        cout << "\nEl animal con id " << this->id << " y nombre " << this->nombre << " acaba de jugar." << endl;
        this->jugar = true;
        *cantAccion = -777;
    }
    else{
        cout << "\nEl animal con id " << this->id << " y nombre " << this->nombre << " ya jugo una vez en el dia, no puede volver a hacerlo." << endl;
    }
}

