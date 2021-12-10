void setup() {
  // Open serial communications:
  Serial.begin(115200);
}
void loop() { // run over and over
  if (Serial.available()) {
    String valori = String(Serial.read());
    Serial.println(valori);
  }
  
}
