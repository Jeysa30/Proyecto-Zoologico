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

// Creamos el metodo para agregar un animal a un habitat existente.
void Habitat::menuAgregarAnimal(int id){
    string nombre, especieAnimal;
    int edad, estadoSalud, cantDormir, tipoDieta, cantComer;

    cout << "\nIngrese el nombre del animal: " << endl;
    cin >> nombre;

    cout << "\nIngrese la especie del animal: " << endl;
    cin >> especieAnimal;

    cout << "\nIngrese la edad del animal: " << endl;
    cin >> edad;
    if(!cin.good()){
        throw invalid_argument("se ingreso un argumento invalido y se espera un numero entero");
    }
    //Manejo de una excepcion, para que la edad maxima sea 150 y no menor a 0.
    comprobacionEntradas(&edad, 150, 1);

    cout << "\nIngrese el estado de salud actual del animal(del 1 al 10): " << endl;
    cin >> estadoSalud;
    if(!cin.good()){
        throw invalid_argument("se ingreso un argumento invalido y se espera un numero entero");
    }
    comprobacionEntradas(&estadoSalud, 10, 1);

    cout << "\nIngrese la cantidad de horas que puede dormir maximo: " << endl;
    cin >> cantDormir;
    if(!cin.good()){
        throw invalid_argument("se ingreso un argumento invalido y se espera un numero entero");
    }
    comprobacionEntradas(&cantDormir, 24, 1);

    cout << "\nIngrese la cantidad(Kg) que puede comer el animal: " << endl;
    cin >> cantComer;
    if(!cin.good()){
        throw invalid_argument("se ingreso un argumento invalido y se espera un numero entero");
    }
    comprobacionEntradas(&cantComer, 50, 1);

    cout << "\nLista de tipo dieta animal:" << endl;
    cout << "\n 1. Carnivoro \n 2. Hervivoro \n 3. omnivoro" << endl;
    cout << "Ingrese el tipo de dieta del animal: " << endl;
    cin >> tipoDieta;
    if(!cin.good()){
        throw invalid_argument("se ingreso un argumento invalido y se espera un numero entero");
    }
    comprobacionEntradas(&tipoDieta, 3, 1);

    //Se crea un animal con los atributos ingresados por el usuario.
    Animal* nuevoAnimal = new Animal(nombre, especieAnimal, id, edad, estadoSalud, cantDormir, cantComer);
    //Se le agrega la alimentacion que va a tener el animal.
    nuevoAnimal->elegirAlimentacion(tipoDieta);
    //Se agrega el animal al habitat correspondiente.
    this->agregarAnimal(nuevoAnimal);
    cout << "\nEl animal de nombre " << nuevoAnimal->getNombre() << " fue llevado a su nueva habitat " << this->getTipoHabitat() <<endl;
}

//Agrega un aminal al mapa de animales.
void Habitat::agregarAnimal(Animal *nuevoAnimal) {
    this->cantAnimales++;
    //agrega el animal al mapa con clave id.
    this->animales.insert(make_pair(nuevoAnimal->getId(), nuevoAnimal));
}

// Creamos el metodo para ver la lista de los animales que hay en cada habitat.
void Habitat::verAnimal(){
    if(this->getAnimales().empty()){
        cout << "\nEl habitat esta vacio.\n" << endl;
    }
    else{
        map<int, Animal*>::iterator itMap = this->getAnimales().begin();
        Animal* animalVer = itMap->second;
        for (int itM = 0; itM < this->cantAnimales; ++itMap, itM++){
            cout << "\nEl animal " << animalVer->getEspecieAnimal() << " con id " << animalVer->getId() << ", se llama " << animalVer->getNombre();
            cout << ", con edad " << animalVer->getEdad() << ", es un animal tipo " << animalVer->getDieta() << endl;
        }
    }
}