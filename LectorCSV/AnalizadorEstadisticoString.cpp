//
// Created by cra38 on 5/10/2026.
//

#include "AnalizadorEstadisticoString.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>
#include <fstream>

AnalizadorEstadisticoString::AnalizadorEstadisticoString(string nombreArchivo) 
    : AnalizadorEstadistico(nombreArchivo) {}

AnalizadorEstadisticoString::~AnalizadorEstadisticoString() {
    for (auto d : datos) delete d;
}


void AnalizadorEstadisticoString::leerArchivo(int columna) {
    ifstream archivo;
    archivo.open(getNombreArchivo());

    if (archivo.fail()) {
        cerr << "No se pudo abrir " << getNombreArchivo() << endl;
        return;
    }

    string linea;
    bool primeraLinea = true;
    while (getline(archivo, linea)) {
        if (primeraLinea) { primeraLinea = false; continue; }
        stringstream ss(linea);
        string celda;
        int col = 0;
        while (getline(ss, celda, ',')) {
            if (col == columna) {
                datos.push_back(new DatoString(celda));
                break;
            }
            col++;
        }
    }
    archivo.close();

}


void AnalizadorEstadisticoString::ordenarDatos() {
    if (datos.empty()) {
        cout << "No hay datos cargados" << endl;
        return;
    }

    sort(datos.begin(), datos.end(), [](DatoString* a, DatoString* b) {
        if (a->getValor().length() != b->getValor().length()) {
            return a->getValor().length() < b->getValor().length();
        }
        return a->getValor() < b->getValor();
    });

    cout << "Primer valor (mas corto): " << datos.front()->getValor() << endl;
    cout << "Ultimo valor (mas largo): " << datos.back()->getValor() << endl;
}

void AnalizadorEstadisticoString::calcularMaximo() {
    if (datos.empty()) return;
    // Maximo alfabético
    string max = datos[0]->getValor();
    for (auto d : datos) {
        if (d->getValor() > max) max = d->getValor();
    }
    cout << "Último alfabéticamente: " << max << endl;
}

void AnalizadorEstadisticoString::calcularMinimo() {
    if (datos.empty()) return;
    string min = datos[0]->getValor();
    for (auto d : datos) {
        if (d->getValor() < min) min = d->getValor();
    }
    cout << "Primero alfabéticamente: " << min << endl;
}

void AnalizadorEstadisticoString::calcularModa() {
    if (datos.empty()) return;
    map<string, int> frec;
    for (auto d : datos) frec[d->getValor()]++;
    
    string moda = "";
    int max = 0;
    for (auto const& [val, f] : frec) {
        if (f > max) { max = f; moda = val; }
    }
    cout << "Moda de texto: " << moda << " (" << max << " veces)" << endl;
}

void AnalizadorEstadisticoString::calcularPromedio() {
    cout << "no se pueden calcular promedios con strings por el momento." << endl;
}
