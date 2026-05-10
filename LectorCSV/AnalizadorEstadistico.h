#ifndef ANALIZADORESTADISTICO_H
#define ANALIZADORESTADISTICO_H

#include "Datos.h"
#include "DatoString.h"
#include "DatoFloat.h"
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class AnalizadorEstadistico {
private:
    string nombreArchivo;

public:
    AnalizadorEstadistico(string nombreArchivo);

    ifstream leerArchivo();

    void guardarDatos();
    void imprimirDatos();

    virtual void ordenarDatos();
    virtual double calcularMaximo();
    virtual double calcularMinimo();

    double calcularPromedio();
    virtual double calcularModa();
    double calcularMediana();  

    void mostrarHistograma();


    void guardarResultados(string archivoReporte);

    ~AnalizadorEstadistico();

};

#endif
