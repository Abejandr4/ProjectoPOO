#include "AnalizadorEstadistico.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

AnalizadorEstadistico::AnalizadorEstadistico(string archivo) {
    this->nombreArchivo = archivo;
}

vector<Dato> AnalizadorEstadistico::leerArchivo(){
        vector<vector<string>> registros;

        ifstream archivo(nombreArchivo);

        if (!archivo.is_open()) {
            cerr << "no se pudo cargar: " << nombreArchivo << endl;
        }

        std::string line;
        while (std::getline(archivo, line)) {
            std::vector<std::string> row;
            std::stringstream ss(line);
            std::string cell;

            while (std::getline(ss, cell, ',')) {
                row.push_back(cell);
            }

            registros.push_back(row);
        }

        archivo.close();
        return registros;

}

void AnalizadorEstadistico::ordenarDatos(){
}
double AnalizadorEstadistico::calcularMaximo(){
}
double AnalizadorEstadistico::calcularMinimo(){
}
double AnalizadorEstadistico::calcularPromedio(){
}
double AnalizadorEstadistico::calcularModa(){
}
double AnalizadorEstadistico::calcularMediana(){
}

void AnalizadorEstadistico::mostrarHistograma(){
}

void AnalizadorEstadistico::guardarResultados(string reporte){

}
