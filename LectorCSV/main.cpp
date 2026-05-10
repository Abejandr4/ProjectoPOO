#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "AnalizadorEstadistico.h"
#include "AnalizadorEstadisticoString.h"

using namespace std;

int main() {

    try {
        cout << "--- Iniciando Analizador de Datos ---" << endl;

        AnalizadorEstadistico analf("data\\waterQuality.csv");
        analf.leerArchivo();

        cout << "\nDatos Numericos:" << endl;
        analf.ordenarDatos();
        analf.calcularMaximo();
        analf.calcularMinimo();
        analf.calcularModa();
        cout << "Promedio: " << analf.calcularPromedio() << endl;

        AnalizadorEstadisticoString analfi("data\\globalAirPollutionDataset.csv");

        cout << "\nDatos de string:" << endl;

        analfi.leerArchivo();
        analfi.ordenarDatos();
        analfi.calcularMaximo();
        analfi.calcularMinimo();

        analf.guardarResultados("reporte_final.txt");
        cout << "\nResultados guardados exitosamente." << endl;

    } catch (const exception& e) {
        cerr << "Errora: " << e.what() << endl;
        return 0;
    }

    return 0;


}