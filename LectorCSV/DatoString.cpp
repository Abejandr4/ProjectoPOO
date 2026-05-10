//
// Created by cra38 on 5/10/2026.
//

#include "DatoString.h"

DatoString::DatoString(string valor) : Dato("string") {
    this->valor = valor;
}

string DatoString::getValor() {
    return valor;
}
