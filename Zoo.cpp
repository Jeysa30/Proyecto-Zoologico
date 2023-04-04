#include "Zoo.h"


vector<Habitat*> Zoo::getVector() {
    return this->vectorHabitats;
}

void Zoo::agregarHabitat(Habitat* habitatAgregar) {
    this->vectorHabitats.push_back(habitatAgregar);
}

// Creamos la función para crear un habitat.
void Zoo::menuAgregarHabitat(){
    string tipoHabitat;

    cout << "Ingrese el tipo de habitat que va a crear: ";
    cin.ignore();
    getline(cin, tipoHabitat, '\n');

    Habitat* habitat = new Habitat(tipoHabitat);
    this->agregarHabitat(habitat);
    cout << "\n---!Nueva habitat aniadida al zoologico!---" << endl;
}

// Creamos una función el cual permite ver la información general del zoológico.
Habitat* Zoo::infoZoologico(){
    vector<Habitat *>::iterator itVector;
    int posicionHabitat;
    int contadorLista = 1;

    cout << "\n--INFORMACION DEL ZOOLOGICO--\n" << endl;
    // aquí lo que se hace es mostrar en forma de lista a los habitats que han sido creados.
    for (itVector = this->vectorHabitats.begin(); itVector != this->vectorHabitats.end(); ++itVector) {
        cout << contadorLista << ". " << (*itVector)->getTipoHabitat() << endl;
        ++contadorLista;
    }

    cout << "\nIngrese el numero del habitat: ";
    cin >> posicionHabitat;

    // Se hace el manejo de errores, si entra un número que no se muestra en la lista.
    while((posicionHabitat < 0) || (posicionHabitat >= contadorLista)){
        cout << "\nIngreso un numero que no se encuentra en la lista, vuelva a intentarlo: ";
        cin >> posicionHabitat;
    }
    return this->vectorHabitats[posicionHabitat - 1];
    // Como el vector esta desde el 1(de manera que empieza en 2), por esto le restamos a la posición -1.
}

// Creamos esta funcion para hacer la busquedad del animal que el usuario quiere que haga la accion.
Animal* Zoo::buscarAnimalZoologico(){
    int idAnimal;
    cout << "Ingrese la id del animal: ";
    cin >> idAnimal;

    vector<Habitat *>::iterator itVector;
    for (itVector = this->vectorHabitats.begin(); itVector != this->vectorHabitats.end(); ++itVector){
        map<int, Animal*>::iterator itMap = (*itVector)->getAnimales().begin();
        for (int itM = 0; itM < (*itVector)->getCantAnimales(); ++itMap, itM++){
            if(idAnimal == itMap->second->getId()){
                return itMap->second;
            }
        }
    }
    cout << "El animal con id " << idAnimal << " no se encuentra en el zoolgico" << endl;
    return NULL;
}