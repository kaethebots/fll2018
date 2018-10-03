// origin: https://www.arduino.cc/en/Tutorial/MasterWriter
// könnte auch interessant sein https://forum.arduino.cc/index.php?topic=442897.15
#include <Wire.h>

int i2cAddress = 8;
int example = 0b10;
int sw01;

void setup() {
  Wire.begin(i2cAddress);         // join i2c bus
  Wire.onReceive(recByteEvent);   // register event
  Wire.onRequest(sendByteEvent);  // register event
  pinMode(LED_BUILTIN, OUTPUT);   // defines onboard led as output
  pinMode(2, INPUT_PULLUP);
  Serial.begin(9600);
  int sw01 = 0;
  Serial.println("Startup done");
}

void loop() {
  int sensorVal = digitalRead(2);
  if (sensorVal == HIGH) {
    int sw01 = 1;
  } else {
    int sw01 = 0;
  }
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void recByteEvent(int howMany) {
  Serial.print(howMany);
  while (0 < Wire.available()) {   // loop through all but the last
    Serial.println(0);
    int recByte = Wire.read();    // receive byte as an integer
    Serial.println(recByte);         // print the received byte
    if (recByte == 73)        // if the byte is 0000111, turn onboard led on
    {
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("led on");
    }
    else if (recByte == 74)  // if the byte is 0000100, turn onboard led off
    {
      digitalWrite(13, LOW);
      Serial.println("led off");
    }
    else
    {
      Serial.println("Empfangenes Byte konnte nicht gelesen werden.");
    }
  }
}

void sendByteEvent() {
  Wire.write(sw01);
}
