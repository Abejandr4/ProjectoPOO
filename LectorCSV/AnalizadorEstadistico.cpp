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
    vector<DatoString*> datoString;
    vector<DatoFloat*> datoFloat;

    ifstream archivo = leerArchivo();

    while (archivo.peek()!=EOF) {
        string datos;

        getline(archivo, datos, ',');

        if (typeid(datos).name() == "flaot" ) {
            DatoString entrada = new DatoFloat(datos, "string");
            datoFloat.push_back(entrada);

        } if (typeid(datos).name() == "string" ) {
            Dato entrada = new DatoString(datos, "string");
            datoString.push_back(entrada);
        }
    }
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
    ifstream archivo = leerArchivo();
    int tipoDeDatos = -1;
    int columna = -1;

    cout << "Ordenar datos - OPCIONES " << endl;
    cout << "1. string \n2. flotantes \n3.Salir" << endl;

    do{
    switch (tipoDeDatos){
        case 1:
            cout << "string seleccionados" << endl;
            cout << "ingresar numero de columna: " << endl;
            cin >> columna;


           //ordenar datos alfabeticamente


    }
    }while (tipoDeDatos != 3);

}
double AnalizadorEstadistico::calcularMaximo(){
    ifstream archivo = leerArchivo();

    //maximo de una columna
    //podria ser override
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
