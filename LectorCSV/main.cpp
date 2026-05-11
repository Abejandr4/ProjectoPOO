#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "AnalizadorEstadistico.h"
#include "AnalizadorEstadisticoString.h"

using namespace std;

void menuNumerico(AnalizadorEstadistico& analizador, const string& nombreArchivo) {
    int opcion = -1;
    while (opcion != 0) {
        cout << "\n========================================" << endl;
        cout << "  " << "MENU NUMERICO" << endl;
        cout << "========================================" << endl;
        cout << "  1. Imprimir datos" << endl;
        cout << "  2. Ordenar datos" << endl;
        cout << "  3. Calcular maximo" << endl;
        cout << "  4. Calcular minimo" << endl;
        cout << "  5. Calcular promedio" << endl;
        cout << "  6. Calcular moda" << endl;
        cout << "  7. Guardar reporte" << endl;
        cout << "  0. Volver" << endl;
        cout << "\n  Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "\n========================================" << endl;
                cout << "  " << "Datos" << endl;
                cout << "========================================" << endl;
                analizador.imprimirDatos();
                break;
            case 2:
                analizador.ordenarDatos();
                cout << "\nDatos ordenados exitosamente." << endl;
                break;
            case 3:
                cout << "\nMaximo: ";
                analizador.calcularMaximo();
                break;
            case 4:
                cout << "\nMinimo: ";
                analizador.calcularMinimo();
                break;
            case 5:
                analizador.calcularPromedio();
                break;
            case 6:
                analizador.calcularModa();
                break;
            case 7: {
                string reporte;
                cout << "Nombre del archivo de reporte (solo una palabra): ";
                cin >> reporte;
                analizador.guardarResultados(reporte);
                cout << "Reporte guardado en " << reporte << endl;
                break;
            }
            case 0:
                cout << "\nVolviendo al menu principal..." << endl;
                break;
            default:
                cout << "\nOpcion invalida." << endl;
        }
    }
}

int main() {
    const string archivoNumericos = "data\\waterQuality.csv";
    const string archivoStrings   = "data\\globalAirPollutionDataset.csv";

    cout << "Cargando archivos..." << endl;

    AnalizadorEstadistico analf(archivoNumericos);
    analf.leerArchivo(1);

    AnalizadorEstadisticoString analfi(archivoStrings);
    analfi.leerArchivo(1);

    AnalizadorEstadistico anaAQI(archivoStrings);
    anaAQI.leerArchivo(2);

    cout << "Archivos cargados exitosamente." << endl;

    int opcion = -1;
    while (opcion != 0) {

        cout << "  1. waterQuality.csv         (numerico - columna 'target')" << endl;
        cout << "  2. globalAirPollution.csv   (texto    - columna 'City')" << endl;
        cout << "  3. globalAirPollution.csv   (numerico - columna 'AQI Value')" << endl;
        cout << "  0. Salir" << endl;
        cout << "\n  Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                menuNumerico(analf, archivoNumericos);
                break;
            case 2: {
                int subopcion = -1;
                while (subopcion != 0) {
                    cout << "  1. Ordenar datos" << endl;
                    cout << "  2. Maximo alfabetico" << endl;
                    cout << "  3. Minimo alfabetico" << endl;
                    cout << "  4. Calcular moda" << endl;
                    cout << "  0. Volver" << endl;
                    cout << "\n  Opcion: ";
                    cin >> subopcion;

                    switch (subopcion) {
                        case 1:
                            analfi.ordenarDatos();
                            cout << "\nDatos ordenados exitosamente." << endl;
                            break;
                        case 2:
                            analfi.calcularMaximo();
                            break;
                        case 3:
                            analfi.calcularMinimo();
                            break;
                        case 4:
                            analfi.calcularModa();
                            break;
                        case 0:
                            cout << "\nVolviendo al menu principal..." << endl;
                            break;
                        default:
                            cout << "\nOpcion invalida." << endl;
                    }
                }
                break;
            }
            case 3:
                menuNumerico(anaAQI, archivoStrings);
                break;
            case 0:
                cout << "\nSaliendo del programa. Hasta luego!" << endl;
                break;
            default:
                cout << "\nOpcion invalida." << endl;
        }
    }

    return 0;
}