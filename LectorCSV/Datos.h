#ifndef DATOS_H
#define DATOS_H
#include <string>

using namespace std;

class Dato {
private:
   string tipo;

public:
   Dato(string tipo);
   virtual ~Dato();

   string getTipo();
};

#endif
