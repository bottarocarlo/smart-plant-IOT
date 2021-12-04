#include <Photoresistor.h>

#include <Thermistor.h>

#include <GenericSensor.h>


/*
*Test multiplexing manuale
*provo a dare corrente ad un sensore per volta
*e leggerne il valore sul pin A0
*/



  GenericSensor waterLevel(D0);
  GenericSensor soilMoisture(D1);
  Photoresistor photoresistor(D2);
  Thermistor thermistor(D3);

void setup(){
  Serial.begin(115200);
  }

void loop(){

  float d0, d1, d2, d3;
  d0 = d1 = d2 = d3 = 100.00;

  d0 = waterLevel.getValue();
  d1 = soilMoisture.getValue();
  d2 = photoresistor.getLux();
  d3 = thermistor.getTemp();
  delay(50000);

  Serial.print("D0-->"); Serial.println(d0);
  Serial.print("D1-->"); Serial.println(d1);
  Serial.print("D2-->"); Serial.println(d2);
  Serial.print("D3-->"); Serial.println(d3);

  delay(10000);
  }
