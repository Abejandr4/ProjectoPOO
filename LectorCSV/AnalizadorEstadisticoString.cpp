//
// Created by cra38 on 5/10/2026.
//

#include "AnalizadorEstadisticoString.h"
#include <iostream>
#include <algorithm>
#include <map>

AnalizadorEstadisticoString::AnalizadorEstadisticoString(string nombreArchivo) 
    : AnalizadorEstadistico(nombreArchivo) {}

AnalizadorEstadisticoString::~AnalizadorEstadisticoString() {
    for (auto d : datos) delete d;
}

// Sobrescribimos la lectura para que guarde strings
void AnalizadorEstadisticoString::ordenarDatos() {
    // Ordenamos por número de letras (longitud) y luego alfabéticamente
    sort(datos.begin(), datos.end(), [](DatoString* a, DatoString* b) {
        if (a->getValor().length() != b->getValor().length())
            return a->getValor().length() < b->getValor().length();
        return a->getValor() < b->getValor();
    });
}

void AnalizadorEstadisticoString::calcularMaximo() {
    if (datos.empty()) return;
    // Maximo alfabético
    string max = datos[0]->getValor();
    for (auto d : datos) if (d->getValor() > max) max = d->getValor();
    cout << "Último alfabéticamente: " << max << endl;
}

void AnalizadorEstadisticoString::calcularMinimo() {
    if (datos.empty()) return;
    string min = datos[0]->getValor();
    for (auto d : datos) if (d->getValor() < min) min = d->getValor();
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

