/*
SENSOR.cpp -Descripción cpp
Creada por IT10, 09-2016
Lanzado bajo licencia---
*/

#include "Arduino.h"
#include "Sensor.h"
#include "DHT.h"
#include "MQ135.h"
#include <Wire.h>
//PINES GY-30

  #define sda 4
  #define scl 5

  //PINES MQ135
  #define ANALOGPIN A1    //  Define Analog PIN on Arduino Board
  #define RZERO 206.85    //  Define RZERO Calibration Value
  MQ135 gasSensor = MQ135(ANALOGPIN);

  //PINES RGB
  #define blue 10
  #define green 9
  #define red 8

  //PINES yl 69
  byte humidity_sensor_pin = A0;
  byte humidity_sensor_vcc = 11;

  //GY 30
  int BH1750_address = 0x23; // i2c Addresse
  byte buff[2];

  // PINES DHT11
  #define data 2
  #define DHTTYPE DHT11 // DHT11
  DHT dht(data, DHTTYPE);
Sensor::Sensor(){
  

}


void Sensor::begin()
{
 Wire.begin();
  BH1750_Init(BH1750_address);
 delay(200);
 //Serial.println("Comprobacion sensor DHT11:");
 dht.begin();
 //Serial.println("Comprobacion sensor MQ135:");
 float rzero = gasSensor.getRZero();
 delay(3000);
 //Serial.print("MQ135 RZERO Calibration Value : ");
 //Serial.println(rzero);
 //yl69
 pinMode(humidity_sensor_vcc, OUTPUT);
  digitalWrite(humidity_sensor_vcc, LOW);
}
//----------------Function read MQ135-------------------------//
float Sensor::readgases(){
    float ppm = gasSensor.getPPM();
  delay(1000);
  //Serial.print("CO2 ppm value : ");
  return(ppm);
}


//----------------Function read Humedad -> value int-----------------//
int Sensor::readHumedad(){
  int h = (int) dht.readHumidity();
  int statu = 0;
  if (isnan(h)){
    Serial.println("Fallo leer sensor DHT");
    statu = -1;
  }else{
    statu = h;
  }
  return statu;
}

//------------------Function read Temperatura -> value int-----------------//
int Sensor::readTemperatura(){
  int t = (int) dht.readTemperature();
  int statu = 0;
  if (isnan(t)){
    Serial.println("Fallo leer sensor DHT");
    statu = -1;
  }else{
    statu = t;
  }
  return statu;
}

//---------------Function Turn Off rbg-----------------------//
//1-->Red
//2-->Gren
//3-->Blue
void Sensor::turnonRGB(int estado){
  switch (estado){
    case 1:
      analogWrite(red,255);
      analogWrite(green,0);
      analogWrite(blue,0);
    break;
    case 2:
      analogWrite(red,0);
      analogWrite(green,255);
      analogWrite(blue,0);
    break;
    case 3:
      analogWrite(red,0);
      analogWrite(green,0);
      analogWrite(blue,255);
    break;
  }
}

//------------------GY 30-------------------------------------//
float Sensor::readgy30(){
  float valf=0;

  if(BH1750_Read(BH1750_address)==2){
    
    valf=((buff[0]<<8)|buff[1])/1.2;
    
    /*if(valf<0)Serial.print("> 65535");
    else Serial.print((int)valf,DEC); 
    
    Serial.println(" lx"); */
  }
  delay(1000);
  return valf;
}


//_____________________________________________________________//
void Sensor::BH1750_Init(int address){
  
  Wire.beginTransmission(address);
  Wire.write(0x10); // 1 [lux] aufloesung
  Wire.endTransmission();
}

byte Sensor::BH1750_Read(int address){
  
  byte i=0;
  Wire.beginTransmission(address);
  Wire.requestFrom(address, 2);
  while(Wire.available()){
    buff[i] = Wire.read(); 
    i++;
  }
  Wire.endTransmission();  
  return i;
}


//--------------------------YL69-HUMEDAD------------------------------------//
int Sensor::read_humidity_sensor() {
  digitalWrite(humidity_sensor_vcc, HIGH);
  delay(500);
  int value = analogRead(humidity_sensor_pin);
  digitalWrite(humidity_sensor_vcc, LOW);
  return 1023 - value;
}
//-------------------------------------------------------------

