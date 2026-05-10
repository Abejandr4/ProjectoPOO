#include "AnalizadorEstadistico.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

AnalizadorEstadistico::AnalizadorEstadistico(string nombreArchivo) {
    this->nombreArchivo = nombreArchivo;
}

AnalizadorEstadistico::~AnalizadorEstadistico() {
    cout << "fin" << endl;
}

ifstream AnalizadorEstadistico::leerArchivo(){
    ifstream archivo;

    archivo.open(nombreArchivo);

    if (archivo.fail()) {
        cerr << "No se pudo abrir " << nombreArchivo << endl;
    }
    return archivo;

}

void AnalizadorEstadistico::imprimirDatos() {
    ifstream archivo = leerArchivo();

    while (archivo.peek()!=EOF) { //EOF = end of file
        string datos;

        getline(archivo, datos, ','); //las lineas del arch las separamos en datos cada ','

        cout << datos << endl;

    }
}

void AnalizadorEstadistico::ordenarDatos(){

}
double AnalizadorEstadistico::calcularMaximo(){
    return 0;
}

double AnalizadorEstadistico::calcularMinimo(){
    return 0;
}
double AnalizadorEstadistico::calcularPromedio(){
    return 0;
}
double AnalizadorEstadistico::calcularModa(){
    return 0;
}
double AnalizadorEstadistico::calcularMediana(){
    return 0;
}

void AnalizadorEstadistico::mostrarHistograma(){
}

void AnalizadorEstadistico::guardarResultados(string reporte){

}
