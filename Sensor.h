 /*
  Sensor.h - Descripción de la librería
Creada por IT10, 09-2016
Lanzado bajo licencia --- 
*/
#ifndef Sensor_h
#define Sensor_h

#include "Arduino.h"
class Sensor {
  public:
   Sensor();
   void begin();
   //Sensor de MOnoxido de Carbono
   float readgases();
   //Sensor de Humedad Ambiente
   int readHumedad();
   //Sensor de temperatura Ambiente
   int readTemperatura();
   //Emisor RGB LED
   void turnonRGB(int);
   //GY 30 SENSOR DE LUZ
   float readgy30();
   //YL69 SENSOR DE Humedad TIerra
   int read_humidity_sensor();
  private:  
  void BH1750_Init(int);
  byte BH1750_Read(int);
   int _variable;
};
#endif
