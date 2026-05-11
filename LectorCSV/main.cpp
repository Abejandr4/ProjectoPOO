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
        cout << "  MENU NUMERICO" << endl;
        cout << "========================================" << endl;
        cout << "  1. Imprimir datos" << endl;
        cout << "  2. Ordenar datos" << endl;
        cout << "  3. Calcular maximo" << endl;
        cout << "  4. Calcular minimo" << endl;
        cout << "  5. Calcular promedio" << endl;
        cout << "  6. Calcular moda" << endl;
        cout << "  7. Guardar reporte" << endl;
        cout << "  8. Mostrar histograma" << endl;
        cout << "  0. Volver" << endl;
        cout << "\n  Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "\n========================================" << endl;
                cout << "  Datos" << endl;
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
                cout << "Reporte creado en " << reporte << endl;
                break;
            }
            case 8: {
                analizador.mostrarHistograma(5); //5 filas
                break;
            }
            case 0:
                cout << "\nVolviendo al menu principal" << endl;
                break;
            default:
                cout << "\nOpcion invalida" << endl;
        }
    }
}

int main() {
    int opcion = -1;

    while (opcion != 0) {
        cout << "\n========================================" << endl;
        cout << "  MENU PRINCIPAL" << endl;
        cout << "========================================" << endl;
        cout << "  1. waterQuality.csv         (numerico)" << endl;
        cout << "  2. globalAirPollution.csv   (texto)" << endl;
        cout << "  3. globalAirPollution.csv   (numerico)" << endl;
        cout << "  0. Salir" << endl;
        cout << "\n  Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                AnalizadorEstadistico archivoAgua("data\\waterQuality.csv");
                int columna = 0;
                cout << "Ingresar numero de columna que se quiere leer: ";
                cin >> columna;
                archivoAgua.leerArchivo(columna);
                menuNumerico(archivoAgua, "data\\waterQuality.csv");
                break;
            }
            case 2: {
                AnalizadorEstadisticoString archivoAire("data\\globalAirPollutionDataset.csv");
                int columna = 0;
                cout << "Ingresar numero de columna que se quiere leer (0,1,3,5,7,9,11): ";
                cin >> columna;
                archivoAire.leerArchivo(columna);

                int operacion = -1;
                while (operacion != 0) {
                    cout << "\n========================================" << endl;
                    cout << "  MENU DE TEXTO" << endl;
                    cout << "========================================" << endl;
                    cout << "  1. Ordenar datos" << endl;
                    cout << "  2. Maximo alfabetico" << endl;
                    cout << "  3. Minimo alfabetico" << endl;
                    cout << "  4. Calcular moda" << endl;
                    cout << "  0. Volver" << endl;
                    cout << "\n  Opcion: ";
                    cin >> operacion;

                    switch (operacion) {
                        case 1:
                            archivoAire.ordenarDatos();
                            cout << "\nDatos ordenados exitosamente" << endl;
                            break;
                        case 2:
                            archivoAire.calcularMaximo();
                            break;
                        case 3:
                            archivoAire.calcularMinimo();
                            break;
                        case 4:
                            archivoAire.calcularModa();
                            break;
                        case 0:
                            cout << "\nSaliendo del programa" << endl;
                            break;
                        default:
                            cout << "\nOpcion invalida." << endl;
                    }
                }
                break;
            }
            case 3: {
                AnalizadorEstadistico archivoAire("data\\globalAirPollutionDataset.csv");
                int columna = 0;
                cout << "Ingresar numero de columna que se quiere leer (2,4,6,8,): ";
                cin >> columna;
                archivoAire.leerArchivo(columna);
                menuNumerico(archivoAire, "data\\globalAirPollutionDataset.csv");
                break;
            }
            case 0:
                cout << "\nSaliendo del programa" << endl;
                break;
            default:
                cout << "\nOpcion invalida." << endl;
        }
    }

    return 0;
}