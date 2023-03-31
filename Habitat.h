#ifndef PROYECTO_ZOOLOGICO_HABITAT_H
#define PROYECTO_ZOOLOGICO_HABITAT_H
#include <iostream>
#include <unordered_map>

#include "Animal.h"

using namespace std;

/* Clase contenedora Habitat:
 * tipoHabitat: Donde se irá almacenando el nombre del habitat creado.
 * unordered_map(mapa desordenado): Donde se van guardando cada animal creado al mismo tiempo que su ID.
 * cantAnimales: Aquí se irá almacenando la cantidad de animales que el usuario coloque.
 */

class Habitat {
private:
    //ATRIBUTOS:
    string tipoHabitat;
    unordered_map<int, Animal*> animales;
    int cantAnimales;

public:
    Habitat() = default; //Constructor por defecto.

    Habitat(string tipoHabitat);

    // Los Get y Set del tipoHabitat, donde el usuario colocara el nombre del habitat a crear.
    string getTipoHabitat();
    void setTipoHabitat(string tipoHabitat);

    // Este Get se encarga de recibir el animal que el usuario haya anexado al zoológico.
    unordered_map<int, Animal *> getAnimales();

    // Los Get y Set del cantAnimales para ir guardando la cantidad de animales anexados al zoológico.
    void setCantAnimales(int cantAnimales);
    int getCantAnimales();

};


#endif //PROYECTO_ZOOLOGICO_HABITAT_H
