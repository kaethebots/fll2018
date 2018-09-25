// origin: https://www.arduino.cc/en/Tutorial/MasterWriter
// könnte auch interessant sein https://forum.arduino.cc/index.php?topic=442897.15
#include <Wire.h>

int i2cAddress = 8;

void setup() {
  Wire.begin(i2cAddress);       // join i2c bus
  Wire.onReceive(recByteEvent); // register event
  pinMode(13, OUTPUT);          // defines onboard led as output
  Serial.begin(9600);
}

void loop() {
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void recByteEvent(int howMany) {
  while (1 < Wire.available()) {   // loop through all but the last
    long recByte = Wire.read();    // receive byte as a character
    Serial.print(recByte);         // print the received byte
    if (recByte == 00001111)       // if the byte is 00001111, turn onboard led on
    {
      digitalWrite(13, HIGH);
    }
    else if (recByte == 00001000)  // if the byte is 00001000, turn onboard led off
    {
      digitalWrite(13, LOW);
    }
    else
    {
      Serial.print("Empfangenes Byte konnte nicht gelesen werden. Fehler.");
    }
  }
}
