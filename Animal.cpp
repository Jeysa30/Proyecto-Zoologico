#include "Animal.h"

Animal::Animal(string nombre,string especieAnimal, int id, int edad, int estadoSalud, int cantDormir, int cantComer){
    this->nombre = nombre;
    this->especieAnimal = especieAnimal;
    this->id = id;
    this->edad = edad;
    this->estadoSalud = estadoSalud;
    this->cantDormir = cantDormir;
    this->cantComer = cantComer;
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
        dietaAnimal.push_back("Carne");
        dietaAnimal.push_back("Pescado");
        dietaAnimal.push_back("Presas");
    }
    else if(tipoDieta == 2){ // Alimento para los herviboros.
        this->dieta = "Herviboro";
        dietaAnimal.push_back("Hierva");
        dietaAnimal.push_back("Frutas");
        dietaAnimal.push_back("Vegetales");
    }
    else{ // Alimento para los omnivoros.
        this->dieta = "Omnivoro";
        dietaAnimal.push_back("Carne");
        dietaAnimal.push_back("Pescado");
        dietaAnimal.push_back("Futas");
    }
    this->setAlimento(dietaAnimal);
}

void Animal::accionAnimal(int id, string accion, int cantAccion){

    if(id == this->id){

        for (int i = 0; i < accion.length(); i++) {
            accion[i] = tolower(accion[i]);
        }

        if(accion.compare("dormir")){

            if(cantAccion <= this->cantDormir){
                cout << "\nEl animal esta durmiendo." << endl;
            }
            else{
                cout << "\nEl animal no puede dormir mas de la cantidad estipulada." << endl;
            }
        }
        else if(accion.compare("comer")){
            string tipoAlimento;

            for (int i = 0; i < tipoAlimento.length(); i++) {
                tipoAlimento[i] = tolower(tipoAlimento[i]);
            }

            if(cantAccion <= this->cantComer){
                cout << "Que alimento vas a darle al animal: " << endl;
                cin >> tipoAlimento;
                vector<Animal*>::iterator itVector;

                for (itVector = this->alimento.begin(); itVector != this->alimento.end(); ++itVector){
                    Animal* pAlimento = *itVector;

                if(tipoAlimento.compare(*itVector)){
                    cout << "\nEl animal esta comiendo." << endl;
                }

            }
            else{
                cout << "\nEl animal no puede dormir mas de la cantidad estipulada." << endl;
            }
        }
        else if(accion.compare("jugar")){

        }
        else{
            cout << "Solo puedes pedirle al animal realizar 3 tipos de acciones." << endl;
        }

    }
    else{
        cout << "\nEste id de animal no existe\n" << endl;
    }
}
