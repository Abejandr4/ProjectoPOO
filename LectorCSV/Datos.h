#ifndef DATOS_H
#define DATOS_H
#include <string>

using namespace std;

class Dato {
private:
   string nombre;
   string tipo;
   
public:
   Dato(string nombre, string tipo);

   string getNombre();
   string getTipo();

};

#endif
