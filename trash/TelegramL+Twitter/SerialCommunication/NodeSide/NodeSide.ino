#include <SoftwareSerial.h>
const byte numChars = 32;
char receivedChars[numChars];
char tempChars[numChars];        // temporary array for use when parsing

// variables to hold the parsed data
float temp = 0.0;
float lux = 0.0;
float water = 0.0;
float soilHum = 0.0;
boolean newData = false;

SoftwareSerial input(D4, D5); // rx , tx





//============

void setup() {
  Serial.begin(115200);
  input.begin(115200);
  //Serial.println("This demo expects 3 pieces of data - text, an integer and a floating point value");
  //Serial.println("Enter data in this style <HelloWorld, 12, 24.7>  ");
  //Serial.println(valori);
}

//============

void loop() {
  
  recvWithStartEndMarkers();
  if (newData == true) {
    strcpy(tempChars, receivedChars);
    // this temporary copy is necessary to protect the original data
    //   because strtok() used in parseData() replaces the commas with \0
    parseData();
    showParsedData();
    newData = false;
    Serial.println(" ");
    Serial.println(" ");
  }
}

//============

void recvWithStartEndMarkers() {
  static boolean recvInProgress = false;
  static byte ndx = 0;
  char startMarker = '<';
  char endMarker = '>';
  char rc;

  while (input.available() > 0 && newData == false) {
    rc = input.read();

    if (recvInProgress == true) {
      if (rc != endMarker) {
        receivedChars[ndx] = rc;
        ndx++;
        if (ndx >= numChars) {
          ndx = numChars - 1;
        }
      }
      else {
        receivedChars[ndx] = '\0'; // terminate the string
        recvInProgress = false;
        ndx = 0;
        newData = true;
      }
    }

    else if (rc == startMarker) {
      recvInProgress = true;
    }
  }
}

//============

void parseData() {      // split the data into its parts

  char * strtokIndx; // this is used by strtok() as an index

  //strtokIndx = strtok(tempChars,",");      // get the first part - the string
  //strcpy(messageFromPC, strtokIndx); // copy it to messageFromPC

  strtokIndx = strtok(tempChars, ","); // this continues where the previous call left off
  temp = atoi(strtokIndx);     // convert this part to an integer

  strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
  lux = atoi(strtokIndx);     // convert this part to an integer

  strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
  water = atoi(strtokIndx);     // convert this part to an integer

  strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
  soilHum = atoi(strtokIndx);     // convert this part to an integer

  //strtokIndx = strtok(NULL, ",");
  //floatFromPC = atof(strtokIndx);     // convert this part to a float

}

//============

void showParsedData() {
  Serial.print("Temp ");
  Serial.println(temp);
  Serial.print("Lux ");
  Serial.println(lux);
  Serial.print("Water ");
  Serial.println(water);
  Serial.print("SoilHum ");
  Serial.println(soilHum);
}
