// origin: https://www.arduino.cc/en/Tutorial/MasterWriter
// könnte auch interessant sein https://forum.arduino.cc/index.php?topic=442897.15
#include <Wire.h>

int i2cAddress = 8;
int example = 0;

void setup() {
  Wire.begin(i2cAddress);       // join i2c bus
  Wire.onReceive(recByteEvent); // register event
  Wire.onRequest(sendByteEvent);// register event
  pinMode(3, OUTPUT);          // defines onboard led as output
  Serial.begin(9600);
  Serial.write("It works");
}

void loop() {
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void recByteEvent(int howMany) {
  while (1 < Wire.available()) {   // loop through all but the last
    char recByte = Wire.read();    // receive byte as a character
    Serial.print(recByte);         // print the received byte
    if (recByte == 585)        // if the byte is 0000111, turn onboard led on
    {
      digitalWrite(3, HIGH);
    }
    else if (recByte == 00001000)  // if the byte is 0000100, turn onboard led off
    {
      digitalWrite(13, LOW);
    }
    else
    {
      Serial.print("Empfangenes Byte konnte nicht gelesen werden.");
    }
  }
}

void sendByteEvent() {
  Wire.write(example);
}
