#include <SoftwareSerial.h>

SoftwareSerial espSerial(5, 6); //Pin comunicazione seriale
String str;
void setup(){
Serial.begin(115200);
espSerial.begin(115200);
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
str =String("_")+String(temp)+String("_")+String(lux)+String("_")+String(water)+String("_")+String(soilHum);
espSerial.println(str);
delay(1000);
}
