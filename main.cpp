#include <iostream>

#include "Zoo.h"

using namespace std;

void menuAgregarHabitat(Zoo* zoologico);
void menuZoo(Zoo* zoologico);

void menuZoo(Zoo* zoologico){
    int op;
    do{
        cout << "EL ZOOLOGICO MARAVILLA" << endl;
        cout << "1. Agrega un habitat." << endl;
        cout << "2. Agregar animal." << endl;
        cout << "3. Entra a un habitat (Ver o editar animales)." << endl;
        cout << "4. Acciones animales." << endl;
        cout << "0. Salir del zoologico." << endl;
        cout << "Ingrese la opcion: \n";
        cin >> op;

        switch(op){
            case 1:
                menuAgregarHabitat(zoologico);
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
}









int main() {
    Zoo zoologicoMaravilla;

    menuZoo(&zoologicoMaravilla);

    std::cout << "Hello, World!" << std::endl;

    return 0;
}
