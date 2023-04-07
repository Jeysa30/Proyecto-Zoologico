#include "Animal.h"

Animal::Animal(string nombre,string especieAnimal, int id, int edad, int estadoSalud, int cantDormir, int cantComer){
    this->nombre = nombre;
    this->especieAnimal = especieAnimal;
    this->id = id;
    this->edad = edad;
    this->estadoSalud = estadoSalud;
    this->cantDormir = cantDormir;
    this->cantDormirTemporal = cantDormir;
    this->cantComer = cantComer;
    this->cantComerTemporal = cantComer;
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

int Animal::getCantDormirTemporal(){
    return cantDormirTemporal;
}

void Animal::setCantDormirTemporal(int cantDormirTemporal) {
    this->cantDormirTemporal = cantDormirTemporal;
}

int Animal::getCantComerTemporal(){
    return cantComerTemporal;
}

void Animal::setCantComerTemporal(int cantComerTemporal) {
    this->cantComerTemporal = cantComerTemporal;
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

// Creación del metodo para elegir el tipo de alimentacion del animal.
void Animal::elegirAlimentacion(int tipoDieta){
    if(tipoDieta == 1){ // Alimento para los carnivoros
        this->dieta = "Carnivoro";
        this->alimento.push_back("carne");
        this->alimento.push_back("pescado");
        this->alimento.push_back("presas");
    }
    else if(tipoDieta == 2){ // Alimento para los herviboros.
        this->dieta = "Herbivoro";
        this->alimento.push_back("hierva");
        this->alimento.push_back("frutas");
        this->alimento.push_back("vegetales");
    }
    else{ // Alimento para los omnivoros.
        this->dieta = "Omnivoro";
        this->alimento.push_back("carne");
        this->alimento.push_back("pescado");
        this->alimento.push_back("futas");
        this->alimento.push_back("verduras");
    }
}

// Metodo para que el usuario escoja la accion que va a realizar el animal.
void Animal::accionAnimal(){
    int cantAccion = 0;
    int accionFueEjecutada = -777;
    string accion;

    while(cantAccion != accionFueEjecutada) {
        cout << "\nIngresa el nombre de la accion que quieres que realice " << this->nombre << " (Comer, dormir o jugar): ";
        cin >> accion;
        for (int i = 0; i < accion.length(); i++) {
            accion[i] = tolower(accion[i]);
        }
        if (accion.compare("dormir") == 0) {
            this->dormirAccion(&cantAccion);
        }
        else if (accion.compare("comer") == 0) {
            this->comerAccion(&cantAccion);
        }
        else if (accion.compare("jugar") == 0) {
            this->jugarAccion(&cantAccion);
        }
        else {
            cout << "\nSolo puedes pedirle al animal realizar 3 tipos de acciones (Comer, dormir o jugar).\n" << endl;
        }
    }
}

// Metodo asociado al metodo accionAnimal.
void Animal::dormirAccion(int* cantAccion){
    cout << "\nIngrese la cantidad de horas que va a dormir " << this->nombre << ": ";
    cin >> *cantAccion;
    if(!cin.good()){
        throw invalid_argument("se ingreso un argumento invalido y se espera un numero entero");
    }
    if (this->cantDormirTemporal - *cantAccion >= 0) {
        this->cantDormirTemporal -= *cantAccion;
        cout << "\nEl animal con id " << this->id << " y nombre " << this->nombre << " durmio " << *cantAccion
             << " horas de las " << this->cantDormir << " disponibles, le quedan " << this->cantDormirTemporal
             << " horas para dormir en el dia\n" << endl;
        //Para que se sepa que la accion termino exitosamente.
        *cantAccion = -777;
    }
    else {
        cout << "\nEl animal con id " << this->id << " y nombre " << this->nombre << " no puede dormir "
             << *cantAccion << " horas en este momento, solo le quedan " << this->cantDormirTemporal
             << " horas para dormir hoy\n" << endl;
    }
}

// Metodo asociado al metodo accionAnimal.
void Animal::comerAccion(int* cantAccion){
    string alimentarAnimal;
    cout << "\nTenga en cuenta que " << this->nombre << " es " << this->dieta << endl;
    vector<string>::iterator itComida;
    for (itComida = this->alimento.begin(); itComida != this->alimento.end(); ++itComida) {
        cout << "- " << (*itComida) << endl;
    }
    cout << "\nIngrese el alimento que se le va a dar a " << this->nombre << ": ";
    cin >> alimentarAnimal;

    //Convierte todos los caracteres de una cadena en minusculas.
    for (int i = 0; i < alimentarAnimal.length(); i++) {
        alimentarAnimal[i] = tolower(alimentarAnimal[i]);
    }

    //Recorre el vector de alimentos.
    for(int i = 0; i < this->alimento.size(); i++){
        if(alimentarAnimal.compare(this->alimento[i]) == 0){
            cout << "\nIngrese la cantidad de alimento que le va a dar a " << this->nombre << ": ";
            cin >> *cantAccion;
            if(!cin.good()){
                throw invalid_argument("se ingreso un argumento invalido y se espera un numero entero");
            }

            if (this->cantComerTemporal - *cantAccion >= 0) {
                this->cantComerTemporal -= *cantAccion;
                cout << "\nEl animal con id " << this->id << " y nombre " << this->nombre << " comio " << *cantAccion
                     << " kilogramos de " << alimentarAnimal << ", le quedan por comer " << this->cantComerTemporal
                     << " kilogramos en el dia\n" << endl;
                //Para que se sepa que la accion termino exitosamente.
                *cantAccion = -777;
            }
            else {
                cout << "\nEl animal con id " << this->id << " y nombre " << this->nombre << " no puede comer "
                     << *cantAccion << " kilogramos en este momento, solo le quedan " << this->cantComerTemporal
                     << " kilogramos para comer hoy\n" << endl;
            }
            break;
        }
        //Entra al condicional cuando llega a la ultima iteracion del ciclo y no se encontro el alimento.
        if(i + 1 == this->alimento.size()){
            cout <<"\n"<< alimentarAnimal
            << " no se encuentra dentro de la posible dieta de " << this->nombre
            << ", si crees que deberia estar en la dieta agregalo en la opcion 3 del menu.\n" << endl;
        }
    }
}

// Metodo asociado al metodo accionAnimal.
void Animal::jugarAccion(int* cantAccion){
    if(this->jugar == false){
        cout << "\nEl animal con id " << this->id << " y nombre " << this->nombre << " acaba de jugar.\n" << endl;
        this->jugar = true;
        //Para que se sepa que la accion termino exitosamente.
        *cantAccion = -777;
    }
    else{
        cout << "\nEl animal con id " << this->id << " y nombre ";
        cout << this->nombre << " ya jugo una vez en el dia, no puede volver a hacerlo.\n" << endl;
    }
}

//Metodo para modificar el tipo de alimentacion del animal.
void Animal::modificarAlimentacion(){
    int op;
    cout << "\n1. Eliminar alguna comida." << endl;
    cout << "\n2. agregar una nueva comida." << endl;
    cout << "\nQue modificaciones quieres realizarle a la alimentacion del animal " << this->nombre << ":" << endl;
    cin >> op;
    if(!cin.good()){
        throw invalid_argument("se ingreso un argumento invalido y se espera un numero entero");
    }

    while(op != 1 && op != 2) {
        cout << "\nIngreso un numero que no se encuentra en la lista, vuelva a intentarlo: ";
        cin >> op;
        if(!cin.good()){
            throw invalid_argument("se ingreso un argumento invalido y se espera un numero entero");
        }
    }

    if(op == 1){
        eliminarAlimento();
    }
    else if(op == 2){
        agregarAlimento();
    }

}

//Metodo de la opcion 1 para eliminar de la lista un alimento del animal.
void Animal::eliminarAlimento(){
    int eliminar;
    int contador = 1;
    int contadorFinal = 1;

    cout << "\nEsta es la lista de los alimentos:\n" << endl;
    vector<string>::iterator itComida;
    for (itComida = this->alimento.begin(); itComida != this->alimento.end(); ++itComida) {
        cout << contador << ". " << (*itComida) << endl;
        ++contador;
    }

    cout << "\nDigita el alimento a eliminar: ";
    cin >> eliminar;
    if(!cin.good()){
        throw invalid_argument("se ingreso un argumento invalido y se espera un numero entero");
    }

    while((eliminar < 0) || (eliminar >= contador)){
        cout << "\nIngreso un numero que no se encuentra en la lista, vuelva a intentarlo: ";
        cin >> eliminar;
        if(!cin.good()){
            throw invalid_argument("se ingreso un argumento invalido y se espera un numero entero");
        }
    }
    //Elimina un elemento de un vector dada una posicion.
    alimento.erase(alimento.begin() + (eliminar-1));
    cout << "\nEl alimento se elimino correctamente." << endl;

    cout << "\nLa lista de los alimentos quedo asi:\n" << endl;
    for (itComida = this->alimento.begin(); itComida != this->alimento.end(); ++itComida) {
        cout << contadorFinal << ". " << (*itComida) << endl;
        ++contadorFinal;
    }
}

//Metodo de la opcion 2 para agregar a la lista un alimento del animal.
void Animal::agregarAlimento(){
    string agregar;
    int contador = 1;
    int contadorFinal = 1;

    cout << "\nEsta es la lista de los alimentos:\n" << endl;
    vector<string>::iterator itComida;
    for (itComida = this->alimento.begin(); itComida != this->alimento.end(); ++itComida) {
        cout << contador << ". " << (*itComida) << endl;
        ++contador;
    }

    cout << "\n\nLista de alimentos que se pueden agregar a la dieta del animal" << endl;
    if(this->dieta == "Carnivoro"){
        agregar = this->alimentoCarnivoro();
    }
    else if(this->dieta == "Herbivoro"){
        agregar = this->alimentoHerbivoro();
    }
    else if(this->dieta == "Omnivoro"){
        agregar = this->alimentoOmnivoro();
    }

    alimento.push_back(agregar);
    cout << "\nEl alimento se agrego correctamente." << endl;

    cout << "\nLa lista de los alimentos quedo asi:\n" << endl;
    for (itComida = this->alimento.begin(); itComida != this->alimento.end(); ++itComida) {
        cout << contadorFinal << ". " << (*itComida) << endl;
        ++contadorFinal;
    }
}

// Metodo para agregar alimentos posibles del tipo de dieta Carnivoro.
string Animal::alimentoCarnivoro(){
    int agregar;
    map<int, string> carnivoro;
    map<int, string>::iterator itMap;
    carnivoro[1] = "aves";
    carnivoro[2] = "insectos";
    carnivoro[3] = "huevos";
    carnivoro[4] = "gusanos";

    for(itMap = carnivoro.begin(); itMap != carnivoro.end(); itMap++){
        cout << itMap->first << ". " << itMap->second << endl;
    }

    cout << "\nEscribe el numero del alimento a agregar: ";
    cin >> agregar;
    if(!cin.good()){
        throw invalid_argument("se ingreso un argumento invalido y se espera un numero entero");
    }

    return carnivoro[agregar];
}

// Metodo para agregar alimentos posibles del tipo de dieta herbivoro.
string Animal::alimentoHerbivoro(){
    int agregar;
    map<int, string> herbivoro;
    map<int, string>::iterator itMap;
    herbivoro[1] = "hojas";
    herbivoro[2] = "raices";
    herbivoro[3] = "flores";
    herbivoro[4] = "nectar";
    herbivoro[5] = "polen";
    herbivoro[6] = "corteza";

    for(itMap = herbivoro.begin(); itMap != herbivoro.end(); itMap++){
        cout << itMap->first << ". " << itMap->second << endl;
    }

    cout << "\nEscribe el numero del alimento a agregar: ";
    cin >> agregar;
    if(!cin.good()){
        throw invalid_argument("se ingreso un argumento invalido y se espera un numero entero");
    }

    return herbivoro[agregar];
}

// Metodo para agregar alimentos posibles del tipo de dieta omnivoro.
string Animal::alimentoOmnivoro() {
    int agregar;
    map<int, string> omnivoro;
    map<int, string>::iterator itMap;
    omnivoro[1] = "aves";
    omnivoro[2] = "insectos";
    omnivoro[3] = "huevos";
    omnivoro[4] = "gusanos";
    omnivoro[5] = "hojas";
    omnivoro[6] = "raices";
    omnivoro[7] = "flores";
    omnivoro[8] = "nectar";
    omnivoro[9] = "polen";
    omnivoro[10] = "corteza";
    omnivoro[11] = "miel";

    for(itMap = omnivoro.begin(); itMap != omnivoro.end(); itMap++){
        cout << itMap->first << ". " << itMap->second << endl;
    }

    cout << "\nEscribe el numero del alimento a agregar: ";
    cin >> agregar;
    if(!cin.good()){
        throw invalid_argument("se ingreso un argumento invalido y se espera un numero entero");
    }

    return omnivoro[agregar];
}