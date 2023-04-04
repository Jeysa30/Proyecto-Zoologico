#include "Zoo.h"

using namespace std;

// Prototipos de cada función creada en el main
void menuZoo(Zoo* zoologico);

int main() {
    Zoo zoologicoMaravilla;

    ////Manejo de la exepcion del menu, para que no se pueda ingresar string en las varibles de enteros.
    bool terminado = false;
    int x = 0;
    do {
        try {
            menuZoo(&zoologicoMaravilla);
            terminado = true;
        }
        catch (const invalid_argument error) {
            cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
            //limpieza del buffer, estas funciones con estos parametros logran que al momento de manejar el error
            //en el que se ingresa un string no se haga ningun bucle.
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            terminado = false;
        }
    }
    while(terminado == false);


    cout << "\n----!Has salido del Zoologico!----" << endl;

    return 0;
}

void menuZoo(Zoo* zoologico){
    int op, idAnimal = 1;
    do{
        vector<Habitat*> habitatsVector = zoologico->getVector();
        cout << "\n------EL ZOOLOGICO MARAVILLA------\n" << endl;
        cout << "1. Agrega un habitat." << endl;
        cout << "2. Agregar animal." << endl;
        cout << "3. Modificar alimentacion de un animal." << endl;
        cout << "4. Acciones animales." << endl;
        cout << "5. Ver informacion del zoologico." << endl;
        cout << "0. Salir del zoologico.\n" << endl;
        cout << "Ingrese la opcion: ";
        cin >> op;
        //Entra en la condicion de manejo de errores cuando la entrada por consola es incorrecta.
        if(!cin.good()){
            throw invalid_argument("se ingreso un argumento invalido y se espera un numero entero");
        }

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
                    bool terminado = false;
                    int x = 0;
                    do {
                        //Manejo de entradas.
                        try {
                            //Se llama la funcion infoZoologico porque hace lo mismo que hacia el codigo que teniamos anteriormente
                            zoologico->infoZoologico()->menuAgregarAnimal(idAnimal);
                            idAnimal++;
                            terminado = true;
                        }
                        catch (const invalid_argument error) {
                            cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            terminado = false;
                        }
                    }
                    while(terminado == false);
                }
                break;
            case 3:
                if(habitatsVector.empty()){
                    cout << "No puede modificar los alimentos de los animales porque no hay ningun habitat hasta el momento" << endl;
                }
                else{
                    bool terminado = false;
                    int x = 0;
                    do {
                        //Manejo de entradas.
                        try {
                            Animal* animalEncontrado = zoologico->buscarAnimalZoologico();
                            if(animalEncontrado != NULL){
                                animalEncontrado->modificarAlimentacion();
                            }
                            terminado = true;
                        }
                        catch (const invalid_argument error) {
                            cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            terminado = false;
                        }
                    }
                    while(terminado == false);
                }
                break;
            case 4:
                if(habitatsVector.empty()){
                    cout << "No puede ejecutar las acciones de los animales porque no hay ningun habitat hasta el momento" << endl;
                }
                else{
                    bool terminado = false;
                    int x = 0;
                    do {
                        //Manejo de entradas.
                        try {
                            Animal* animalEncontrado = zoologico->buscarAnimalZoologico();
                            if(animalEncontrado != NULL){
                                animalEncontrado->accionAnimal();
                            }
                            terminado = true;
                        }
                        catch (const invalid_argument error) {
                            cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            terminado = false;
                        }
                    }
                    while(terminado == false);
                }
                break;
            case 5:
                if(habitatsVector.empty()){ // Se hace el manejo de error si intenta ver información cuando no hay nada.
                    cout << "No hay ningun habitat ni animal en el zoologico" << endl;
                }
                else{
                    bool terminado = false;
                    int x = 0;
                    do {
                        //Manejo de entradas.
                        try {
                            // Se hace el llamado a la función cuando ya tiene por lo menos 1 habitat creado.
                            zoologico->infoZoologico()->verAnimal();
                            terminado = true;
                        }
                        catch (const invalid_argument error) {
                            cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            terminado = false;
                        }
                    }
                    while(terminado == false);
                }
                break;
            default:
                break;
        }

    }while(op != 0);
}