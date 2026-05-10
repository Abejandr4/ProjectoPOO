//
// Created by cra38 on 2/10/2026.
//

#ifndef LECTORCSV_DATOFLOAT_H
#define LECTORCSV_DATOFLOAT_H

#include "Datos.h"

class DatoFloat : public Dato {
    private:
    float valor;

    public:
    DatoFloat(float valor);

    float getValor();

};


#endif //LECTORCSV_DATOFLOAT_H