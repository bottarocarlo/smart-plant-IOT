#ifndef conversion_h
#define conversion_h

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



#endif