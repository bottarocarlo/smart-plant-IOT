#include "SoftwareSerial.h"

SoftwareSerial Lux(D7, D8); // rx , tx
SoftwareSerial Water(D2, D3) ; // rx , tx
SoftwareSerial SoilHum(D4, D5); // rx , tx

void setup()
{
  Serial.begin(115200);
  Lux.begin(115200);
  Water.begin(115200);
  SoilHum.begin(115200);

}
void loop()
{
  if (Serial.available() > 0)
  {
    delay(5);  // wait for all 4 bytes
    byte buf[4];
    byte* bp = buf;
    while (Serial.available()) {
      *bp = Serial.read();
      if (bp - buf < 3) bp++;
    }
    float received = * (float*)buf;
    //Serial.print("TEMP --> ");
    //Serial.println(received, 3); // printing the result to the serial monitor
  }
  delay(100); // not really required, should be smaller than sender cycle that is set to 3k
  if (Lux.available() > 0)
  {
    delay(5);  // wait for all 4 bytes
    byte buf[4];
    byte* bp = buf;
    while (Lux.available()) {
      *bp = Lux.read();
      if (bp - buf < 3) bp++;
    }
    float received = * (float*)buf;
    //Serial.print("LUX --> ");
    //Serial.println(received, 3); // printing the result to the serial monitor
  }
  delay(100);
  if (Water.available() > 0)
  {
    delay(5);  // wait for all 4 bytes
    byte buf[4];
    byte* bp = buf;
    while (Water.available()) {
      *bp = Water.read();
      if (bp - buf < 3) bp++;
    }
    float received = * (float*)buf;
    //Serial.print("WATER --> ");
    //Serial.println(received, 3); // printing the result to the serial monitor

    delay(100);
    if (SoilHum.available() > 0)
    {
      delay(5);  // wait for all 4 bytes
      byte buf[4];
      byte* bp = buf;
      while (SoilHum.available()) {
        *bp = SoilHum.read();
        if (bp - buf < 3) bp++;
      }
      float received = * (float*)buf;
      //Serial.print("SOILHUM --> ");
      //Serial.println(received, 3); // printing the result to the serial monitor
    }
  }
}
