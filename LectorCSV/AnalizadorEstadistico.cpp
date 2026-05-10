#include "AnalizadorEstadistico.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <map>
#include <algorithm>
using namespace std;

AnalizadorEstadistico::AnalizadorEstadistico(string nombreArchivo) {
    this->nombreArchivo = nombreArchivo;
}

AnalizadorEstadistico::~AnalizadorEstadistico() {
    cout << "limpiando memoria..." << endl;
    for (auto dato : datos) delete dato; //para cada dato de datos...
}

void AnalizadorEstadistico::leerArchivo(){
    ifstream archivo;

    archivo.open(nombreArchivo);

    if (archivo.fail()) {
        cerr << "No se pudo abrir " << nombreArchivo << endl;
    }

    string linea;
    while (getline(archivo, linea)) {
        try {
            float val = std::stof(linea); // checamos si se convierte a float
            datos.push_back(new DatoFloat(val));
        } catch (...) {
            // checar si se pone algo aqui
        }
    }
    archivo.close();

}

void AnalizadorEstadistico::imprimirDatos() {
    for (auto d : datos) {
        cout << d->getValor() << endl;
    }
}

void AnalizadorEstadistico::ordenarDatos() {
    std::sort(datos.begin(), datos.end(), [](DatoFloat* a, DatoFloat* b) {
        return a->getValor() < b->getValor();
    });
}

void AnalizadorEstadistico::calcularMaximo() {
    if (datos.empty()) {
        cout << "no hay maximo" << endl;
    }
    float max = datos[0]->getValor();
    for (auto d : datos) if (d->getValor() >max) max = d->getValor();
    cout << max << endl;
}

void AnalizadorEstadistico::calcularMinimo() {
    if (datos.empty()) {
        cout << "no hay minimo" << endl;
    }
    float min = datos[0]->getValor();
    for (auto d : datos) if (d->getValor() < min) min = d->getValor();
    cout << min << endl;
}

float AnalizadorEstadistico::calcularPromedio() {
    if (datos.empty()) {
        cout << "no hay promedio" << endl;
        return 0;
    } else {
        float suma = 0;
        for (auto d : datos) suma += d->getValor();
        return suma / datos.size();
    }

}

void AnalizadorEstadistico::calcularModa() { //cehcar si se puede hacer sin map
    if (datos.empty()) return;
    map<float, int> frecuencias;
    for (auto d : datos) frecuencias[d->getValor()]++;

    float moda = datos[0]->getValor();
    int maxFrecuencia = 0;
    for (auto const& [val, frec] : frecuencias) {
        if (frec > maxFrecuencia) {
            maxFrecuencia = frec;
            moda = val;
        }
    }
    cout << "Moda: " << moda << " (aparece " << maxFrecuencia << " veces)" << endl;

}

void AnalizadorEstadistico::guardarResultados(std::string reporte) {
    std::ofstream out(reporte);
    out << "--- Reporte Estadístico Numerico ---\n";
    out << "Archivo: " << nombreArchivo << "\n";
    calcularMaximo();
    calcularMinimo();
    out << "Promedio: " << calcularPromedio() << "\n";
    calcularModa();
    out.close();
}
