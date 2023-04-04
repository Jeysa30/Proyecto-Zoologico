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
                    //Se llama la funcion infoZoologico porque hace lo mismo que hacia el codigo que teniamos anteriormente
                    zoologico->infoZoologico()->menuAgregarAnimal(idAnimal);
                    idAnimal++;
                }
                break;
            case 3:
                if(habitatsVector.empty()){
                    cout << "No puede entrar en un habitat, no hay ninguna creada hasta el momento" << endl;
                }
                else{

                }
                break;
            case 4:
                if(habitatsVector.empty()){
                    cout << "No puede ejecutar las acciones de los animales porque no hay ningun habitat hasta el momento" << endl;
                }
                else{
                    Animal* animalEncontrado = zoologico->buscarAnimalZoologico();
                    if(animalEncontrado != NULL){
                        animalEncontrado->accionAnimal();
                    }
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
