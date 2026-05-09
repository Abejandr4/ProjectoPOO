#ifndef DATOSTRING_H
#define DATOSTRING_H
#include <string>

using namespace std;

class DatoMedicion: public Dato {
private:
   string unidad;
   
public:
   Dato(string nombre, string tipo);

};

#endif
