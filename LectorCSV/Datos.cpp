#include <string>
#include "Datos.h"

#include <iostream>
using namespace std;

Dato::Dato(string tipo) {

    this->tipo = tipo;
}

Dato::~Dato() {
    cout << "limpiando memoria..." << endl;
}

string Dato::getTipo() {
    return tipo;
}
