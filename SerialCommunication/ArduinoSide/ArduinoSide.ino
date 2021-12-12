/*#include <SoftwareSerial.h>

  void sendFloat(float f){
  byte * b = (byte *) &f;
  Serial.print("f:");
  Serial.write(b[0]);
  Serial.write(b[1]);
  Serial.write(b[2]);
  Serial.write(b[3]);
  //Serial.print(68); //Send nonsense.. Else serial drops offline??
  Serial.flush();
  return;
  }

  SoftwareSerial espSerial(5, 6); //Pin comunicazione seriale RX,TX
  String str;
  void setup(){
  Serial.begin(115200);
  //espSerial.begin(115200);
  delay(2000);
  }
  void loop()
  {
  float temp = analogRead(A0); //Thermistor
  float lux = analogRead(A1); //Photoresistor
  float water = analogRead(A2); //WaterLevel
  float soilHum = analogRead(A3); // SoilHum

  /*Serial.print("TEMP: ");
  Serial.print(temp);
  Serial.print("---"); //terminatore di stringa, non confonde con -
  Serial.print(" LUX: ");
  Serial.print(lux);
  Serial.println("---");
  Serial.print(" WATER: ");
  Serial.print(water);
  Serial.println("---");
  Serial.print(" SOILHUM: ");
  Serial.print(soilHum);
  Serial.println("---");*/
//TEMP--LUX--WATER--SOILHUM
//str =String("_")+String(temp)+String("_")+String(lux)+String("_")+String(water)+String("_")+String(soilHum);
//espSerial.println(str);
/*
  Cast string to char*


  //char* cString = (char*) malloc(sizeof(char)*(str.length() + 1));
  //str.toCharArray(cString, str.length() + 1);
  /*Serial.println(temp);
  delay(1000);
  Serial.println(lux);
  delay(1000);
  Serial.println(water);
  delay(1000);
  Serial.println(soilHum);
  delay(1000);

  sendFloat(temp);
  delay(10000);
  sendFloat(lux);
  delay(10000);
  sendFloat(water);
  delay(10000);
  sendFloat(soilHum);
  delay(10000);


  delay(15000);
  }*/


//float val = 1.234;


 
 
#include "SoftwareSerial.h"

SoftwareSerial Lux(7,8); // rx , tx
SoftwareSerial Water(2,3) ; // rx , tx 
SoftwareSerial SoilHum(4,5); // rx , tx


void setup() {
  Serial.begin(115200);
  Lux.begin(115200);
  Water.begin(115200);
  SoilHum.begin(115200);
}

void loop() {




  float temp = analogRead(A0); //Thermistor
  Serial.write((byte*)&temp, 4);
  delay(3000);
  float lux = analogRead(A1); //Photoresistor
  Lux.write((byte*)&lux, 4);
  delay(3000);
  float water = analogRead(A2); //WaterLevel
  Water.write((byte*)&water, 4);
  delay(3000);
  float soilHum = analogRead(A3); // SoilHum
  SoilHum.write((byte*)&soilHum, 4);
  delay(3000);

}
