#include "SoftwareSerial.h"
#include "conversion.h"

SoftwareSerial Lux(7, 8); // rx , tx
SoftwareSerial Water(2, 3) ; // rx , tx
SoftwareSerial SoilHum(4, 5); // rx , tx

/*
float TempConversion(float value) {
  float tempK = log(10000.0 * ((1024.0 / value - 1))); //10K is the resistor value!!
  tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK )) * tempK );       //  Temp Kelvin
  float tempC = tempK - 273.15;            // Convert Kelvin to Celcius
  return tempC;
}

float LuxConversion (int value)
{
  double Vout=value*0.0048828125;
  int lux=500/(10*((5-Vout)/Vout));
  return lux;
}
*/


// variables:
float temp = 0;                     // the sensor value

float lux = 0;                     // the sensor value

float water = 0;                     // the sensor value

float soilHum = 0;                    // the sensor value
float sensorMinSoilHum = 1023;        // minimum sensor value
float sensorMaxSoilHum = 0;           // maximum sensor value

void setup() {
  Serial.begin(115200);
  Lux.begin(115200);
  Water.begin(115200);
  SoilHum.begin(115200);

  // turn on LED to signal the start of the calibration period:
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  // calibrate during the first five seconds
  while (millis() < 5000) {
    soilHum = analogRead(A3);

    // record the maximum sensor value
    if (soilHum > sensorMaxSoilHum) {
      sensorMaxSoilHum = soilHum;
    }

    // record the minimum sensor value
    if (soilHum < sensorMinSoilHum) {
      sensorMinSoilHum = soilHum;
    }
  }

  // signal the end of the calibration period
  digitalWrite(LED_BUILTIN, LOW);

}


void loop() {

  float  tempRead = analogRead(A0); //Thermistor
  Serial.print("TEMP ");
  /*temp = constrain(temp, sensorMinTemp, sensorMaxTemp);
    temp = map(temp, sensorMinTemp, sensorMaxTemp, 0, 1023);*/
  temp = TempConversion(tempRead);
  Serial.println(temp);
  //Serial.write((byte*)&temp, 4);
  delay(3000);




  float luxRead = analogRead(A1); //Photoresistor
  //lux = constrain(lux, sensorMinLux, sensorMaxLux);
  //lux = map(lux, sensorMinLux, sensorMaxLux, 0, 1023);
  
  Serial.print("LUX ");
  lux = LuxConversion(luxRead);
  Serial.println(lux);
  //Lux.write((byte*)&lux, 4);
  delay(3000);










  
  water = analogRead(A2); //WaterLevel
  Serial.print("WATER ");
  Serial.println(water);
  //Water.write((byte*)&water, 4);
  delay(3000);










  
  soilHum = analogRead(A3); // SoilHum
  //soilHum = constrain(soilHum, sensorMinSoilHum, sensorMaxSoilHum);
  soilHum = map(soilHum, sensorMinSoilHum, sensorMaxSoilHum, 0, 100);
  Serial.print("SOILHUM ");
  Serial.println(soilHum);
  //SoilHum.write((byte*)&soilHum, 4);
  delay(3000);

}
