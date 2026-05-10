//
// Created by cra38 on 5/10/2026.
//

#ifndef LECTORCSV_ANALIZADORESTADISTICOSTRING_H
#define LECTORCSV_ANALIZADORESTADISTICOSTRING_H

#include "AnalizadorEstadistico.h"
#include "DatoString.h"

#include <vector>

class AnalizadorEstadisticoString : public AnalizadorEstadistico {

private:
    vector<DatoString*> datos;
    public:
    AnalizadorEstadisticoString(string nombreArchivo);

    void ordenarDatos() override;
    void calcularMaximo() override;
    void calcularMinimo() override;

    void calcularModa() override;

    ~AnalizadorEstadisticoString();
};


#endif //LECTORCSV_ANALIZADORESTADISTICOSTRING_H