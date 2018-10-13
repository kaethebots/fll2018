//
// by karlbeecken and leonelbohnet
//
// origin: https://www.arduino.cc/en/Tutorial/MasterWriter
// könnte auch interessant sein https://forum.arduino.cc/index.php?topic=442897.15
#include <Wire.h>

#define FLOATS_SENT 2

int i2cAddress = 8;
int example = 0b10;
int ThermistorPin = 0;
int Vo;
float R1 = 10000;
float logR2, R2, T;
float H;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
float data[FLOATS_SENT];



void setup() {
  Wire.begin(i2cAddress);         // join i2c bus
  Wire.onReceive(recByteEvent);   // register event
  Wire.onRequest(sendByteEvent);  // register event
  pinMode(LED_BUILTIN, OUTPUT);   // defines onboard led as output
  pinMode(4, OUTPUT);
  Serial.begin(9600);
  data[0] = T;
  data[1] = H;
  Serial.println("Startup done");
}

void loop() {
  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  T = T - 273.15;

  Serial.print("Temperature: ");
  Serial.print(T);
  Serial.println(" C");

  delay(500);
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
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println("led off");
    }
    else if (recByte == 71)
    {
      digitalWrite(4, HIGH);
    }
    else if (recByte == 72)
    {
      digitalWrite(4, LOW);
    }
    else
    {
      Serial.println("Empfangenes Byte konnte nicht gelesen werden.");
    }
  }
}

void sendByteEvent() {
  Wire.write((byte*) &T, FLOATS_SENT*sizeof(float));
}
