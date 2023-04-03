#include "Habitat.h"

Habitat::Habitat() {
    this->tipoHabitat = "";
    this->cantAnimales = 0;
}

Habitat::Habitat(string tipoHabitat) {
    this->tipoHabitat = tipoHabitat;
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

// Creamos la función para agregar un animal a un habitat existente.
void Habitat::menuAgregarAnimal(int id){

    string nombre, especieAnimal;
    int edad, estadoSalud, cantDormir, tipoDieta;

    cout << "\nIngrese el nombre del animal: " << endl;
    cin >> nombre;
    cout << "\nIngrese la especie del animal: " << endl;
    cin >> especieAnimal;
    cout << "\nIngrese la edad del animal: " << endl;
    cin >> edad;
    cout << "\nIngrese el estado de salud actual del animal(del 1 al 10): " << endl;
    cin >> estadoSalud;
    cout << "\nIngrese la cantidad de horas que puede dormir maximo: " << endl;
    cin >> cantDormir;

    do {
        cout << "1. Carnivoro \n 2. Hervivoro \n 3. omnivoro" << endl;
        cout << "Ingrese el tipo de dieta del animal: " << endl;
        cin >> tipoDieta;
    }while(tipoDieta <= 0 || tipoDieta > 3);

    Animal* nuevoAnimal = new Animal(nombre, especieAnimal, id, edad, estadoSalud, cantDormir);
    nuevoAnimal->elegirAlimentacion(tipoDieta);
    this->agregarAnimal(nuevoAnimal);
    cout << "\nEl animal de nombre " << nuevoAnimal->getNombre() << " fue llevado a su nueva habitat" << this->getTipoHabitat() <<endl;
}

void Habitat::agregarAnimal(Animal *nuevoAnimal) {
    this->cantAnimales++;
    this->animales.insert(make_pair(nuevoAnimal->getId(), nuevoAnimal));
}

// Creamos la función para ver la lista de los animales que hay en cada habitad.
void Habitat::verAnimal(){
    if(this->getAnimales().empty()){
        cout << "\nEl habitat esta vacio.\n" << endl;
    }
    else{
        map<int, Animal*>::iterator itMap = this->getAnimales().begin();

        for (int itM = 0; itM < this->cantAnimales; ++itMap, itM++){
            cout << "\nEl animal " << itMap->second->getEspecieAnimal() << " con id " << itMap->second->getId() << ", se llama " << itMap->second->getNombre();
            cout << " con edad " << itMap->second->getEdad() << endl;
        }
    }
}

