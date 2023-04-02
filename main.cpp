#include <iostream>

#include "Zoo.h"

using namespace std;

// Parametros de cada función creada
void menuAgregarHabitat(Zoo* zoologico);
void menuZoo(Zoo* zoologico);
void menuAgregarAnimal(Habitat* habitatAgregar, int id);
void infoZoologico(vector<Habitat*> habitatsVector);
void verAnimal(Habitat* verHabitat);

void menuZoo(Zoo* zoologico){
    int op, idAnimal = 1;
    do{
        vector<Habitat*> habitatsVector = zoologico->getVector();
        cout << "\n------EL ZOOLOGICO MARAVILLA------\n" << endl;
        cout << "1. Agrega un habitat." << endl;
        cout << "2. Agregar animal." << endl;
        cout << "3. Entra a un habitat (editar informacion)." << endl;
        cout << "4. Acciones animales." << endl;
        cout << "5. Ver informacion del zoologico." << endl;
        cout << "0. Salir del zoologico.\n" << endl;
        cout << "Ingrese la opcion: ";
        cin >> op;

        switch(op){
            case 1:
                // Se hace el llamado a la función paa agregar un habitat.
                menuAgregarHabitat(zoologico);
                break;
            case 2:
                // Para esta opción evitamos que agregue un animal si por lo menos no hay un habitat creado.
                if(habitatsVector.empty()){ // (Manejo de error).
                    cout << "No puede agregar animales aun, no hay ningun habitat en la que puedan vivir" << endl;
                }

                // Si ya existe por lo menos un habitat se activa esta opción para agregar un animal.
                else{
                    // aquí lo que se hace es mostrar en forma de lista a los habitats disponibles.
                    vector<Habitat*>::iterator itVector;
                    int posicionHabitat;
                    int contadorLista = 1; // Variable para enumerar cada habitat.
                    cout << "\nLos habitats disponibles para el animal son:\n";
                    for (itVector = habitatsVector.begin(); itVector != habitatsVector.end(); ++itVector){
                        cout << contadorLista << ". " << (*itVector)->getTipoHabitat() << endl;
                        ++contadorLista;
                    }
                    // De esta forma, al momento de elegir el habitat aparecería la función para agregar un animal.
                    cout << "Seleccione el numero del habitat donde va a vivir el animal: ";
                    cin >> posicionHabitat;

                    // Se hace el manejo de errores, si entra un número que no se muestra en la lista.
                    while((posicionHabitat < 0) || (posicionHabitat >= contadorLista)){
                        cout << "\nIngreso un numero que no se encuentra en la lista, vuelva a intentarlo: ";
                        cin >> posicionHabitat;
                    }

                    menuAgregarAnimal(zoologico->getVector()[posicionHabitat - 1], idAnimal);
                    // Como el vector esta desde el 1(de manera que empieza en 2), por esto le restamos a la posición -1.
                    idAnimal++;
                }
                break;
            case 3:
                if(habitatsVector.empty()){
                    cout << "No puede agregar animales aun, no hay ningun habitat en la que puedan vivir" << endl;
                }
                else{

                }
                break;
            case 4:
                if(habitatsVector.empty()){
                    cout << "No puede agregar animales aun, no hay ningun habitat en la que puedan vivir" << endl;
                }
                else{

                }
                break;
            case 5:
                if(habitatsVector.empty()){ // Se hace el manejo de error si intenta ver información cuando no hay nada.
                    cout << "No hay ningun habitat ni animal en el zoologico" << endl;
                }
                else{
                    // Se hace el llamado a la función cuando ya tiene por lo menos 1 habitat creado.
                    infoZoologico(habitatsVector);
                }
                break;
            default:
                break;
        }

    }while(op != 0);
}

// Creamos la función para crear un habitat.
void menuAgregarHabitat(Zoo* zoologico){
    string tipoHabitat;

    cout << "Ingrese el tipo de habitat que va a crear: ";
    cin.ignore();
    getline(cin, tipoHabitat, '\n');

    Habitat* habitat = new Habitat(tipoHabitat);
    zoologico->agregarHabitat(habitat);
    cout << "---!Nueva habitat aniadida al zoologico!---" << endl;
}

// Creamos la función para agregar un animal a un habitat existente.
void menuAgregarAnimal(Habitat* habitatAgregar, int id){

    string nombre, especieAnimal;
    int edad, estadoSalud;

    cout << "\nIngrese la especie del animal que va a agregar: " << endl;
    cin >> especieAnimal;
    cout << "\nIngrese el nombre del animal que va a agregar: " << endl;
    cin >> nombre;
    cout << "\nIngrese la edad del animal: " << endl;
    cin >> edad;
    cout << "\nIngrese el estado de salud actual del animal(del 1 al 10): " << endl;
    cin >> estadoSalud;

    Animal* nuevoAnimal = new Animal(nombre, especieAnimal, id, edad, estadoSalud);
    habitatAgregar->agregarAnimal(nuevoAnimal);
    cout << "\nEl animal de nombre " << nuevoAnimal->getNombre() << " fue llevado a su nueva habitat\n" << habitatAgregar->getTipoHabitat() <<endl;
}

// Creamos una función el cual permite ver la información general del zoológico.
void infoZoologico(vector<Habitat*> habitatsVector){
    vector<Habitat *>::iterator itVector;
    int posicionHabitat;
    int contadorLista = 1;

    cout << "\n--INFORMACION DEL ZOOLOGICO--\n" << endl;
    // aquí lo que se hace es mostrar en forma de lista a los habitats que han sido creados.
    for (itVector = habitatsVector.begin(); itVector != habitatsVector.end(); ++itVector) {
        cout << contadorLista << ". " << (*itVector)->getTipoHabitat() << endl;
        ++contadorLista;
    }

    cout << "\nVisita el habitat que deseas mirar la informacion: ";
    cin >> posicionHabitat;

    // Se hace el manejo de errores, si entra un número que no se muestra en la lista.
    while((posicionHabitat < 0) || (posicionHabitat >= contadorLista)){
        cout << "\nIngreso un numero que no se encuentra en la lista, vuelva a intentarlo: ";
        cin >> posicionHabitat;
    }

    verAnimal(habitatsVector[posicionHabitat - 1]);
    // Como el vector esta desde el 1(de manera que empieza en 2), por esto le restamos a la posición -1.

}

// Creamos la función para ver la lista de los animales que hay en cada habitad.
void verAnimal(Habitat* verHabitat){
    map<int, Animal*> mapaAnimal = verHabitat->getAnimales();
    cout << "mapaa= " << mapaAnimal[0] << endl;

    if(mapaAnimal[0] != NULL){
        map<int, Animal*>::iterator itMap;

        for (itMap = mapaAnimal.begin(); itMap != mapaAnimal.end(); ++itMap){
            cout << "El animal " << itMap->second->getEspecieAnimal() << " con id " << itMap->second->getId() << ", se llama " << itMap->second->getNombre();
            cout << " con edad " << itMap->second->getEdad() << endl;
        }
    }
    else{
        cout << "\nEl habitat esta vacio.\n" << endl;
    }
}




int main() {
    Zoo zoologicoMaravilla;

    menuZoo(&zoologicoMaravilla);

    cout << "\n----!Has salido del Zoologico!----" << endl;

    return 0;
}
