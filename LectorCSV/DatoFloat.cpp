//
// Created by cra38 on 5/09/2026.
//

#include "DatoFloat.h"

DatoFloat::DatoFloat(float valor) : Dato("float") {
    this->valor = valor;

}

float DatoFloat::getValor() {
    return valor;
}