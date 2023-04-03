#include <iostream>

#include "Zoo.h"

using namespace std;

// Parametros de cada función creada
void menuZoo(Zoo* zoologico);

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
                zoologico->menuAgregarHabitat();
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
                    habitatsVector[posicionHabitat - 1]->menuAgregarAnimal(idAnimal);
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
                    zoologico->infoZoologico()->verAnimal();
                }
                break;
            default:
                break;
        }

    }while(op != 0);
}

int main() {
    Zoo zoologicoMaravilla;

    menuZoo(&zoologicoMaravilla);

    cout << "\n----!Has salido del Zoologico!----" << endl;

    return 0;
}
