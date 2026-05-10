#ifndef ANALIZADORESTADISTICO_H
#define ANALIZADORESTADISTICO_H

#include "Datos.h"
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class AnalizadorEstadistico {
private:
    vector<Dato*> registros;
    string nombreArchivo;

public:
    AnalizadorEstadistico(string nombreArchivo);

    ifstream leerArchivo();
    void imprimirDatos();

    void ordenarDatos();
    double calcularMaximo();
    double calcularMinimo();

    double calcularPromedio();
    double calcularModa();  
    double calcularMediana();  

    void mostrarHistograma();


    void guardarResultados(string archivoReporte);

    ~AnalizadorEstadistico();

};

#endif
