#include <BH1750.h>
#include "Sensor.h"
#include "ReconVoz.h"
#include "GeneradorEstado.h"
BH1750 lightMeter;
Sensor sensor;
ReconVoz reconvoz;
GeneradorEstado generadorestado;
//SERIAL EVENT
char inByte=' ' ;
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
//Definicion de Varialbles de ESTADO
String humedadT;
String humedadA;
String temperatura;
String rgb;
String Co2;
String lumen;

//Arreglo contenedor de estados criticos
String niveles[5];

//TIME PRIORITORIO
int times=0;

//Mensaje de estado
String mensaje;

//Color de estado
int color=1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  sensor.begin();
  reconvoz.begin();
  generadorestado.begin();
  lightMeter.begin();
  inputString.reserve(200);
}

void loop() {
 int estado=0;
  int question=0;
  //if(times==0){
      generadorestado.responsRGB(4);
      humedadT = generadorestado.responsHumedadT();
      humedadA = generadorestado.responsHumedadA();
      temperatura = generadorestado.responsTemperaturA();
      Co2 = generadorestado.responsCo2();
      lumen = generadorestado.responsLumen(lightMeter.readLightLevel());
      niveles[0]=humedadT;
      niveles[1]=humedadA;
      niveles[2]=temperatura;
      niveles[3]=Co2;
      niveles[4]=lumen;
      times=5000; // el sistema se actualiza cada 10 seg
      generadorestado.responsRGB(color);
  //}else{
  //  times--;
    
  //}

  
  //RESEPCION DE DATOS POR BLUETOOTH
  while (Serial.available() > 0) {
    char inByte = Serial.read();
    inputString += inByte;
    delay(2);
  }

  
  if(inputString!=""){
    estado=1;
    mensaje="Tengo ";
    if(niveles[0]=="Critico"){
        mensaje.concat("sed");
    }
    if(niveles[1]=="Critico"){
        mensaje.concat("calor");
    }
    if(niveles[2]=="Critico"){
        mensaje.concat("calor");
    }
    if(niveles[3]=="Critico"){
        mensaje.concat("poco oxigeno");
    }
    if(niveles[4]=="Critico"){
        mensaje.concat(" poca luz ");
    }
    
  }

  
  if(estado==1){
    if(mensaje=="Tengo "){
        mensaje="Esta todo bien";
        color=2;
      }else{
        color=3;
        
      }
    question=reconvoz.generateQuestion(inputString);
    //Serial.println(question);
    if(question==1){
      Serial.println(generadorestado.responsHola());
    }
    if(question==2){
      Serial.println(mensaje);
      
    }
    if(question==3){
      Serial.println("De humedad estoy "+niveles[0]);
    }
    if(question==4){
      mensaje="De temperatura estoy ";
      mensaje.concat(niveles[2]);
      Serial.println(mensaje);
    }
    if(question==5){
      mensaje="De luz estoy  ";
      mensaje.concat(niveles[4]);
      Serial.println(mensaje);
    }
    if(question==6){
      generadorestado.responsRGB(1);
      delay(200);
      generadorestado.responsRGB(color);
    }
    if(question== -1){
      Serial.println("No entiendo la pregunta");
    }
 }


generadorestado.responsRGB(color);

delay(100);
generadorestado.responsRGB(5);
delay(100);
 
inputString="";
  /*
  Serial.print("Humedad relativa: ");

    Serial.println(sensor.readHumedad());

    Serial.print("Temperatura: ");

    Serial.println(sensor.readTemperatura());

    Serial.print("Gases: ");

    Serial.println(sensor.readgases());

    Serial.print("GY 30");
    Serial.println((int)sensor.readgy30());

    Serial.print("Humedad Suelo");
    Serial.println(sensor.read_humidity_sensor());
 */
}
