#ifndef PROYECTO_ZOOLOGICO_HABITAT_H
#define PROYECTO_ZOOLOGICO_HABITAT_H
#include <iostream>
#include <map>

#include "Animal.h"

using namespace std;

/* Clase contenedora Habitat:
 * tipoHabitat: Donde se irá almacenando el nombre del habitat creado.
 * map: Donde se van guardando cada animal creado al mismo tiempo que su ID.
 * cantAnimales: Aquí se irá almacenando la cantidad de animales que el usuario coloque.
 */

class Habitat {
private:
    //ATRIBUTOS:
    string tipoHabitat;
    map<int, Animal*> animales;
    int cantAnimales;

public:
    Habitat(); //Constructor por defecto.

    Habitat(string tipoHabitat);

    // Los Get y Set del tipoHabitat, donde el usuario colocara el nombre del habitat a crear.
    string getTipoHabitat();
    void setTipoHabitat(string tipoHabitat);

    // Este Get se encarga de recibir el animal que el usuario haya anexado al zoológico.
    map<int, Animal*> getAnimales();

    // Los Get y Set del cantAnimales para ir guardando la cantidad de animales anexados al zoológico.
    void setCantAnimales(int cantAnimales);
    int getCantAnimales();

    //Metodo para agregar animales al mapa
    void agregarAnimal(Animal* nuevoAnimal);

    //Metodo para pedir la informacion del animal.
    void menuAgregarAnimal(int id);

    // Creamos la función para ver la lista de los animales que hay en cada habitad.
    void verAnimal();

};


#endif //PROYECTO_ZOOLOGICO_HABITAT_H
