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
    // cout << "limpiando memoria..." << endl;
    for (auto dato : datos) delete dato;
}

string AnalizadorEstadistico::getNombreArchivo() {
    return nombreArchivo;
}

void AnalizadorEstadistico::leerArchivo(int columna){
    ifstream archivo;

    archivo.open(nombreArchivo);

    if (archivo.fail()) {
        cerr << "No se pudo abrir " << nombreArchivo << endl;
        return;
    }

    string linea;
    bool primeraLinea = true;

    while (getline(archivo, linea)) {
        if (primeraLinea) { // saltar encabezado porque tiene las categor[ias
            primeraLinea = false;
            continue;
        }

        stringstream ss(linea);
        string celda;
        int col = 0;
        while (getline(ss, celda, ',')) {
            if (col == columna) {
                try {
                    float val = stof(celda);
                    datos.push_back(new DatoFloat(val));
                } catch (...) {}
                break;
            }
            col++;
        }
    }
    archivo.close();

}

void AnalizadorEstadistico::imprimirDatos() {
    for (auto d : datos) {
        cout << d->getValor() << endl;
    }
}

void AnalizadorEstadistico::imprimirFila(int fila) {
    ifstream archivo;

    archivo.open(nombreArchivo);

    if (!archivo) { cerr << "No se pudo abrir " << nombreArchivo << endl; return; }
    string linea;
    int lineaActual = -1;
    while (getline(archivo, linea)) {
        if (lineaActual == fila) {
            stringstream ss(linea);
            string celda;
            bool primero = true;
            while (getline(ss, celda, ',')) {
                if (!primero) cout << " | ";
                cout << celda;
                primero = false;
            }
            cout << endl;
            break;
        }
        lineaActual++;
    }
    archivo.close();
}

void AnalizadorEstadistico::imprimirCol(int columna) {

    ifstream archivo;

    archivo.open(nombreArchivo);

    if (!archivo) { cerr << "No se pudo abrir " << nombreArchivo << endl; return; }
    string linea;
    bool primeraLinea = true;
    while (getline(archivo, linea)) {
        if (primeraLinea) {
            // Imprime encabezado de la columna
            stringstream ss(linea);
            string celda; int col = 0;
            while (getline(ss, celda, ',')) {
                if (col == columna) { cout << "[" << celda << "]" << endl; break; }
                col++;
            }
            primeraLinea = false;
            continue;
        }
        stringstream ss(linea);
        string celda; int col = 0;
        while (getline(ss, celda, ',')) {
            if (col == columna) { cout << celda << endl; break; }
            col++;
        }
    }
    archivo.close();
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
    cout << "maximo: " << max << endl;
}

void AnalizadorEstadistico::calcularMinimo() {
    if (datos.empty()) {
        cout << "no hay minimo" << endl;
    }
    float min = datos[0]->getValor();
    for (auto d : datos) if (d->getValor() < min) min = d->getValor();
    cout << "minimo: " << min << endl;
}

void AnalizadorEstadistico::calcularPromedio() {
    float promedio = 0;

    if (datos.empty()) {
        cout << "no hay promedio" << endl;

    } else {
        float suma = 0;
        for (auto d : datos) suma += d->getValor();
        promedio =  suma / datos.size();
    }

    cout << "promedio: " << promedio << endl;

}

void AnalizadorEstadistico::calcularModa() { //cehcar si se puede hacer sin map
    if (datos.empty()) return;
    map<float, int> frecuencias;
    for (auto d : datos) frecuencias[d->getValor()]++;

    float moda = datos[0]->getValor();
    int maxFrecuencia = 0;
    for (auto [val, frec] : frecuencias) {
        if (frec > maxFrecuencia) {
            maxFrecuencia = frec;
            moda = val;
        }
    }
    cout << "Moda: " << moda << " (aparece " << maxFrecuencia << " veces)" << endl;

}


void AnalizadorEstadistico::guardarResultados(string reporte) {
    stringstream buffer;

    ofstream out(reporte);
    out << "--- Reporte Estadístico ---\n";
    out << "Archivo: " << nombreArchivo << "\n";

    streambuf* coutOG = cout.rdbuf(); //coutOG = a donde originalmente se dirige el cout

    cout.rdbuf(buffer.rdbuf()); // se manda a memoria temporal

    calcularMaximo();
    calcularMinimo();
    calcularPromedio();
    calcularModa();

    cout.rdbuf(coutOG);

    out << buffer.str();
    cout << buffer.str();

    out.close();
}
