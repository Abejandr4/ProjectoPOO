#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "AnalizadorEstadistico.h"

using namespace std;

int main() {

    AnalizadorEstadistico archivo1("C:\\Users\\cra38\\OneDrive\\Desktop\\ProjectoPOO\\LectorCSV\\data\\waterQuality.csv");
    AnalizadorEstadistico archivo2("C:\\Users\\cra38\\OneDrive\\Desktop\\ProjectoPOO\\LectorCSV\\data\\globalAirPollutionDataset.csv"); //checar si se dbee poner path entero

    archivo1.leerArchivo();
    archivo2.leerArchivo();

    archivo1.imprimirDatos();



    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}