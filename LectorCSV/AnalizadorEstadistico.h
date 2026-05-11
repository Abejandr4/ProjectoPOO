#ifndef ANALIZADORESTADISTICO_H
#define ANALIZADORESTADISTICO_H


#include "DatoFloat.h"
#include <vector>
#include <fstream>
#include <string>
using namespace std;

//este archivo por default trata con datos tipo float, pues son de los tipos que mas se ven en mediciones

class AnalizadorEstadistico {
private:
    string nombreArchivo;
    vector<DatoFloat*> datos; //puntero para optimizar memoria

public:
    AnalizadorEstadistico(string nombreArchivo);

    string getNombreArchivo();

    virtual void leerArchivo(int columna = 0);
    void imprimirDatos();
    void imprimirFila(int fila);
    void imprimirCol(int columna);

    virtual void ordenarDatos();
    virtual void calcularMaximo();
    virtual void calcularMinimo();

    virtual void calcularPromedio();
    virtual void calcularModa();

    void mostrarHistograma(int numeroFilas);


    void guardarResultados(string archivoReporte);

    ~AnalizadorEstadistico();

};

#endif
