

#ifndef LECTORCSV_COLUMNA_H
#define LECTORCSV_COLUMNA_H

#include "Datos.h"

#include <string>
#include <vector>

#include "DatoFloat.h"
#include "DatoString.h"


class Columna {
private:
    vector<DatoString*> datoString;
    vector<DatoFloat*> datoFloat;

public:
    Columna();
    ~Columna();
};


#endif //LECTORCSV_COLUMNA_H