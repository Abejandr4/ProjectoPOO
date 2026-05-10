#ifndef ANALIZADORESTADISTICO_H
#define ANALIZADORESTADISTICO_H


#include "DatoFloat.h"
#include <vector>
#include <fstream>
#include <string>
using namespace std;

//este archivo por default trata con datos tipo float, pues son de los que mas se ven en medicions

class AnalizadorEstadistico {
private:
    string nombreArchivo;
    vector<DatoFloat*> datos; //puntero para optimizar memoria

public:
    AnalizadorEstadistico(string nombreArchivo);

    void leerArchivo();
    void imprimirDatos();

    virtual void ordenarDatos();
    virtual void calcularMaximo();
    virtual void calcularMinimo();

    float calcularPromedio();
    virtual void calcularModa();
    float calcularMediana();

    void mostrarHistograma();


    void guardarResultados(string archivoReporte);

    ~AnalizadorEstadistico();

};

#endif
