/*
 gENERADOReSTADO.h - Descripción de la librería
Creada por IT10, 09-2016
Lanzado bajo licencia --- 
*/
#ifndef GeneradorEstado_h
#define GeneradorEstado_h

#include "Arduino.h"
class GeneradorEstado {
  public:
   GeneradorEstado();
   void begin();
   //responde estado de humedad ambiente
   String responsHumedadA();
   //responde estado de temperatura ambiente
   String responsTemperaturA();
   //responde stado de humedad de tierra
   String responsHumedadT();
   //responde estado de CO2
   String responsCo2();
   //responde estado de lumenes de luz
   String responsLumen();
   //genera indicador de estado mediante un led rgb
   void responsRGB(int);
   //Pregunta 1 (Hola Eva)--> reponde hola
   String responsHola();
 
  
   
};
#endif
