/*
ReconVoz.cpp -Descripción cpp
Creada por IT10, 09-2016
Lanzado bajo licencia---
*/

#include "Arduino.h"
#include "ReconVoz.h"
ReconVoz::ReconVoz(){
 
}
void ReconVoz::begin()
{}
int ReconVoz::generateQuestion(String estado){
    int a = 0;
    if(estado=="*Hola Eva*"){
      a=1;
    }else{
      if(estado=="*Cómo estás*"){
      a=2;
      }else{
        if((estado=="*Cómo estás de humedad*")||(estado=="*como estas de humedad*")){
        a=3;
        }else{
          if(estado=="*como estas de temperatura y humedad*"){
             a=4;
          }else{
            if(estado=="*como estas de sol*"){
              a=5;
            }else{
              if(estado=="*indica tu estado*"){
                a=6;
              }else{
                  a=-1;
              }}}}}}
  
  return a;
}


