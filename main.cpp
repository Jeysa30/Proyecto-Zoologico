#include <iostream>

#include "Zoo.h"

using namespace std;

void menuAgregarHabitat(Zoo* zoologico);
void menuZoo(Zoo* zoologico);
void menuAgregarAnimal(Habitat* habitatAgregar, int id);

void menuZoo(Zoo* zoologico){
    int op, idAnimal = 1;
    do{
        vector<Habitat*> habitatsVector = zoologico->getVector();
        cout << "EL ZOOLOGICO MARAVILLA" << endl;
        cout << "1. Agrega un habitat." << endl;
        cout << "2. Agregar animal." << endl;
        cout << "3. Entra a un habitat (Ver o editar animales)." << endl;
        cout << "4. Acciones animales." << endl;
        cout << "5. Ver informacion del zoológico" << endl;
        cout << "0. Salir del zoologico." << endl;
        cout << "Ingrese la opcion: \n";
        cin >> op;

        switch(op){
            case 1:
                menuAgregarHabitat(zoologico);
                break;
            case 2:
                if(habitatsVector.empty()){
                    cout << "No puede agregar animales aun, no hay ningun habitat en la que puedan vivir" << endl;
                }
                else{
                    vector<Habitat*>::iterator itVector;
                    int posicionHabitat = 1;
                    cout << "Los habitats disponibles para el animal son:\n";
                    for (itVector = habitatsVector.begin(); itVector != habitatsVector.end(); ++itVector){
                        cout << posicionHabitat << ". " << (*itVector)->getTipoHabitat() << endl;
                    }
                    cout << "Seleccione el numero del habitat donde va a vivir el animal: ";
                    cin >> posicionHabitat;
                    menuAgregarAnimal(zoologico->getVector()[posicionHabitat - 1], idAnimal);
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
            default:
                break;
        }

    }while(op != 0);
}

void menuAgregarHabitat(Zoo* zoologico){
    string tipoHabitat;

    cout << "Ingrese el tipo de habitat que va a crear: ";
    cin.ignore();
    getline(cin, tipoHabitat, '\n');

    Habitat* habitat = new Habitat(tipoHabitat);
    zoologico->agregarHabitat(habitat);
    cout << "Nueva habitat añadida al zoologico" << endl;
}

void menuAgregarAnimal(Habitat* habitatAgregar, int id){

    string nombre;
    int edad, estadoSalud, tipoAnimal;

    cout << "Ingrese el nombre del animal que va a agregar: ";
    cin >> nombre;
    cout << "Ingrese la edad del animal: ";
    cin >> edad;
    cout << "Ingrese el estado de salud actual del animal(del 1 al 10): ";
    cin >> estadoSalud;

    Animal* nuevoAnimal = new Animal(nombre, id, edad, estadoSalud);
    habitatAgregar->agregarAnimal(nuevoAnimal);
    cout << "El animal " << nuevoAnimal->getNombre() << " fue llevado a su nueva habitat " << habitatAgregar->getTipoHabitat() <<endl;
}








int main() {
    Zoo zoologicoMaravilla;

    menuZoo(&zoologicoMaravilla);

    std::cout << "Hello, World!" << std::endl;

    return 0;
}
