#ifndef DATOSTRING_H
#define DATOSTRING_H
#include <string>

using namespace std;

class DatoString: public Dato {
private:
   string tipoPalabra; //nombre propio o comun
   
public:
   Dato(string nombre, string tipo, string tipoPalabra);

   string getNombre();
   string getTipo();

};

#endif
