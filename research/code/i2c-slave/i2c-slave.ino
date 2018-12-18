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
#include <avr/wdt.h>

#define FLOATS_SENT 3
#define ONE_WIRE_BUS 2
#define DHTPIN 4
#define DHTTYPE DHT22

int i2cAddress = 8;
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
  data[0] = T_DHT;
  data[1] = H_DHT;
  data[2] = T2;
  sensors.begin();
  dht.begin();
  wdt_enable(WDTO_8S);
  Serial.println("Startup done");
}

void loop() {

  Serial.print("Temperature: ");
  Serial.print(T2);
  Serial.println(" C");

  sensors.requestTemperatures();
  T2 = sensors.getTempCByIndex(0);

  updateTempHum();
  Serial.print(T_DHT);
  Serial.print("  ");
  Serial.print(H_DHT);
  Serial.print("  ");
  Serial.println("(DHT values)");

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
    if (recByte == 73)        // if the byte is 73, turn onboard led on
    {
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("led on");
    }
    else if (recByte == 74)  // if the byte is 74, turn onboard led off
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
    {
      Serial.println("Empfangenes Byte konnte nicht gelesen werden.");
    }
  }
}

void sendByteEvent() {
  Wire.write((byte*) &H_DHT, FLOATS_SENT*sizeof(float));
  wdt_reset();
}

void updateTempHum()
{
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  T_DHT = event.temperature;
  dht.humidity().getEvent(&event);
  H_DHT = event.relative_humidity;
}
