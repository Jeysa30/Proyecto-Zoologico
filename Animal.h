#ifndef PROYECTO_ZOOLOGICO_ANIMAL_H
#define PROYECTO_ZOOLOGICO_ANIMAL_H
#include <iostream>
#include <vector>

using namespace std;

/* Clase Animal:
 * nombre: Cada animal tendrá su respectivo nombre.
 * especieAnimal: Identificar la especie del animal al agregar.
 * dieta: Se escoge que tipo de dieta es el animal (carnivoro, herviboro ó omnivoro).
 * id: Cada animal tendrá un número como identificación.
 * edad: Se pondrá o se irá cambiando la edad del animal.
 * cantDormir: Se le agregará la cantidad maxima que puede dormir el animal.
 * cantComer: Se le agregará la cantidad en Kg de comida del animal.
 * jugar: Booleano para saber si el animal ya jugo en el día.
 * vector tipo string de alimento: Se pondrá la clase de alimento que consume el animal.
 */

class Animal {
private:
    //ATRIBUTOS
    string nombre;
    string especieAnimal;
    string dieta;
    int id;
    int edad;
    int estadoSalud;
    int cantDormir;
    int cantComer;
    int cantDormirTemporal;
    int cantComerTemporal;
    bool jugar;
    vector<string> alimento;

public:
    Animal() = default; //Constructor por defecto.

    Animal(string nombre,string especieAnimal, int id, int edad, int estadoSalud, int cantDormir, int cantComer);

    //-----Get y Set de nombre:
    string getNombre();
    void setNombre(string nombre);

    //-----Get y Set de especieAnimal:
    string getEspecieAnimal();
    void setEspecieAnimal(string especieAnimal);

    //-----Get y Set de dieta:
    string getDieta();
    void setDieta(string dieta);

    //-----Get y Set del id:
    int getId();
    void setId(int id);

    //-----Get y Set de edad:
    int getEdad();
    void setEdad(int edad);

    //-----Get y Set de estadoSalud:
    int getEstadoSalud();
    void setEstadoSalud(int estadoSalud);

    //-----Get y Set de cantDormir:
    int getCantDormir();
    void setCantDormir(int cantDormir);

    //-----Get y Set de cantComer:
    int getCantComer();
    void setCantComer(int cantComer);

    //-----Get y Set de cantDormirTemporal:
    int getCantDormirTemporal();
    void setCantDormirTemporal(int cantDormirTemporal);

    //-----Get y Set de cantComerTemporal:
    int getCantComerTemporal();
    void setCantComerTemporal(int cantComerTemporal);

    //-----Get y Set del jugar:
    bool getJugar();
    void setJugar(bool Jugar);

    //-----Get y Set del vector tipo alimento
    vector<string> getAlimento();
    void setAlimento(vector<string> alimento);

    //Metodo para agregar el tipo de alimentacion que tendra el animal.
    void elegirAlimentacion(int tipoDieta);

    // Función que permite al usuario que elija que accion debe realizar para el animal.
    void accionAnimal();

    void dormirAccion(int* cantAccion);
    void comerAccion(int* cantAccion);
    void jugarAccion(int* cantAccion);
};


#endif //PROYECTO_ZOOLOGICO_ANIMAL_H
