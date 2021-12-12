/*const int NUMSENS = 4;
String sensValue[NUMSENS];
int sensPos = 0; //Posizione nell'array
String data;
String valori;


void setup() {
  // Open serial communications:
  Serial.begin(115200);
}
void loop() { // run over and over
  if (Serial.available()) {
    byte indata[4] = { 0 };
    indata[0] = Serial.read();
    indata[1] = Serial.read();
    indata[2] = Serial.read();
    indata[3] = Serial.read();

    float g;
    memcpy(&g, &indata, sizeof(g));

    Serial.println(g);
  }



  /*while (Serial.available()) {
    character = Serial.read();
    valori.concat(character);
    }*/


  /*char str_array[valori.length()];
    valori.toCharArray(str_array, valori.length());

    data = strtok(str_array, "_");
    while (data != NULL)
    {
    //printf("%s\n", data);
    Serial.println(data);
    sensValue[sensPos] = data;
    sensPos++;
    data = strtok(NULL, "_");
    }
}*/



void setup() 
{
  Serial.begin(115200);
}
void loop() 
{
  if(Serial.available() > 0)
  {
     delay(5);  // wait for all 4 bytes
     byte buf[4];
     byte* bp = buf;
     while (Serial.available()) {
        *bp = Serial.read();
        if (bp - buf < 3) bp++;
     }  
     float received = * (float*)buf;
     Serial.println(received, 3); // printing the result to the serial monitor
  }
  delay(100); // not really required, should be smaller than sender cycle that is set to 3k
}
