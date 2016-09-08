/*
ReconVoz.cpp -Descripción cpp
Creada por IT10, 09-2016
Lanzado bajo licencia---
*/
#include "Arduino.h"
#include "GeneradorEstado.h"
#include "Sensor.h"

GeneradorEstado::GeneradorEstado(){
 
}
void GeneradorEstado::begin(){

}


String GeneradorEstado::responsHumedadA(){
  Sensor sensor;
  int estatus = sensor.readHumedad();
  if(estatus<40){
    return("Estable");
  }else{
    return("Critico");  
  }
  
 
}
String GeneradorEstado::responsHumedadT(){
  Sensor sensor;
  int estatus = sensor.read_humidity_sensor();
  if(estatus<40){
    return("Estable");
  }else{
    return("Critico");  
  }
}
String GeneradorEstado::responsTemperaturA(){
  Sensor sensor;
  int estatus = sensor.readTemperatura();
  if(estatus<40){
    return("Estable");
  }else{
    return("Critico");  
  }
}
String GeneradorEstado::responsCo2(){
  Sensor sensor;
  int estatus = sensor.readgases();
  if(estatus<40){
    return("Estable");
  }else{
    return("Critico");  
  } 
 }

String GeneradorEstado::responsLumen(){
  Sensor sensor;
  int estatus = sensor.readgy30();
  if(estatus<40){
    return("Estable");
  }else{
    return("Critico");  
  } 
}
 
void GeneradorEstado::responsRGB(int color){
  if(color == 1){
    analogWrite(10,255);
    analogWrite(9,0);
    analogWrite(8,0);
  }
  if(color == 2){
    analogWrite(10,0);
    analogWrite(9,255);
    analogWrite(8,0);
  }
  if(color == 3){
    analogWrite(10,0);
    analogWrite(9,0);
    analogWrite(8,255);
  }
  if(color == 4){
    analogWrite(10,255);
    analogWrite(9,255);
    analogWrite(8,255);
  }
  if(color == 5){
    analogWrite(10,5);
    analogWrite(9,5);
    analogWrite(8,5);
  }
 }
String GeneradorEstado::responsHola(){
    return ("Hola");
 }
 
 
 
 


