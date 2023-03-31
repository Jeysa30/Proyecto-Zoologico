//
// Created by jeysa nahara on 31/03/2023.
//

#ifndef PROYECTO_ZOOLOGICO_HABITAT_H
#define PROYECTO_ZOOLOGICO_HABITAT_H
#include <iostream>
#include <unordered_map>

using namespace std;


class Habitat {
private:
    string tipoHabitat;
    unordered_map<int, Animal*> animales;
    int cantAnimales;

public:
    Habitat(string tipoHabitat);

};


#endif //PROYECTO_ZOOLOGICO_HABITAT_H
