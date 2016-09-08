 /*
  ReconVoz.h - Descripción de la librería
Creada por IT10, 09-2016
Lanzado bajo licencia --- 
*/
#ifndef ReconVoz_h
#define ReconVoz_h

#include "Arduino.h"
class ReconVoz {
  public:
   ReconVoz();
   void begin();
   //Sensor de MOnoxido de Carbono
   int generateQuestion(String);
   
  
};
#endif
