//
// by karlbeecken and leonelbohnet
//
// DS18B20 library: https://github.com/milesburton/Arduino-Temperature-Control-Library
// 1-Wire library: https://github.com/PaulStoffregen/OneWire
// DHT22 library: https://github.com/adafruit/DHT-sensor-library
// Unified sensor library: https://github.com/adafruit/Adafruit_Sensor
#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define FLOATS_SENT 3
#define ONE_WIRE_BUS 2
#define DHTPIN 4
#define DHTTYPE DHT22

int i2cAddress = 8;
int example = 0b10;
int ThermistorPin = 0;
int Vo;
float R1 = 10000;
float logR2, R2, T;
float H;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
float data[FLOATS_SENT];
float T2;
float T_DHT, H_DHT;
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;


void setup() {
  Wire.begin(i2cAddress);         // join i2c bus
  Wire.onReceive(recByteEvent);   // register event
  Wire.onRequest(sendByteEvent);  // register event
  pinMode(LED_BUILTIN, OUTPUT);   // defines onboard led as output
  pinMode(4, OUTPUT);
  Serial.begin(9600);
  data[0] = T;
  data[1] = H;
  data[2] = T2;
  sensors.begin();
  dht.begin();
  Serial.println("Startup done");
}

void loop() {
//  Vo = analogRead(ThermistorPin);
//  R2 = R1 * (1023.0 / (float)Vo - 1.0);
//  logR2 = log(R2);
//  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
//  T = T - 273.15;


  Serial.print("Temperature: ");
  Serial.print(T);
  Serial.println(" C");

  sensors.requestTemperatures();
  T2 = sensors.getTempCByIndex(0);

  updateTempHum();
  Serial.print(T_DHT);
  Serial.print(H_DHT);
  Serial.println("(DHT values)");
  H = H_DHT;
  T = T_DHT;

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
  Wire.write((byte*) &H, FLOATS_SENT*sizeof(float));
}

void updateTempHum()
{
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  T_DHT = event.temperature;
  dht.humidity().getEvent(&event);
  H_DHT = event.relative_humidity;
}
