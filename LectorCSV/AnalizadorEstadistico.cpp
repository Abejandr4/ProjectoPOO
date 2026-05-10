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
    cout << "limpiando memoria..." << endl;
}

ifstream AnalizadorEstadistico::leerArchivo(){
    ifstream archivo;

    archivo.open(nombreArchivo);

    if (archivo.fail()) {
        cerr << "No se pudo abrir " << nombreArchivo << endl;
    }
    return archivo;

}

void AnalizadorEstadistico::guardarDatos() {

}

void AnalizadorEstadistico::imprimirDatos() {
    ifstream archivo = leerArchivo();

    while (archivo.peek()!=EOF) { //EOF = end of file
        string datos;

        getline(archivo, datos, ','); //las lineas del arch las separamos en datos cada ','

        cout << datos << endl;

    }
}

void AnalizadorEstadistico::ordenarDatos() {

}
double AnalizadorEstadistico::calcularMaximo(){
    ifstream archivo = leerArchivo();



    return 0;
}

double AnalizadorEstadistico::calcularMinimo(){
    ifstream archivo = leerArchivo();
    return 0;
}
double AnalizadorEstadistico::calcularPromedio(){
    ifstream archivo = leerArchivo();
    return 0;
}
double AnalizadorEstadistico::calcularModa(){
    return 0;
}
double AnalizadorEstadistico::calcularMediana(){
    ifstream archivo = leerArchivo();
    return 0;
}

void AnalizadorEstadistico::mostrarHistograma(){
    ifstream archivo = leerArchivo();
}

void AnalizadorEstadistico::guardarResultados(string reporte){
    ifstream archivo = leerArchivo();

}
