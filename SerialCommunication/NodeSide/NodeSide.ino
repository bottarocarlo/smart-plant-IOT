

const int NUMSENS = 4;
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
    valori = String(Serial.read());
    Serial.println(valori);
  }

  char str_array[valori.length()];
  valori.toCharArray(str_array, valori.length());

  data = strtok(str_array, "_");
  while (data != NULL)
  {
    //printf("%s\n", data);
    sensValue[sensPos] = data;
    sensPos++;
    data = strtok(NULL, "_");
  }


}
