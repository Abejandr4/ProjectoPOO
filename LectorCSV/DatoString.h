//
// Created by cra38 on 5/09/2026.
//

#ifndef LECTORCSV_DATOSTRING_H
#define LECTORCSV_DATOSTRING_H

#include "Datos.h"


class DatoString : public Dato {
    private:
    string valor;

    public:
    DatoString(string valor);

    string getValor();
};


#endif //LECTORCSV_DATOSTRING_H