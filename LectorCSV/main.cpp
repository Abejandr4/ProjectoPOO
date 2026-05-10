#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "AnalizadorEstadistico.h"

using namespace std;

int main() {

    AnalizadorEstadistico archivo1("example.csv");

    auto datos = archivo1.leerArchivo();

    for (const auto& row : datos) {
        for (const auto& cell : row) {
            std::cout << cell << "\t";
        }
        std::cout << std::endl;
    }

    return 0;


    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}