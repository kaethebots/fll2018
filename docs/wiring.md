# Wiring of Arduino

```
(Arduino) => Device
```
##### LED Stripe:
```
D9  => LED-Stripe red pin
D10 => LED-Stripe green pin
D11 => LED-Stripe blue pin
GND => +12V (common anode)
```

##### DHT22:
```
5V  => 5V
D4  => DATA
GND => GND
```

##### DS18B20
```
5V  => 5V
D2  => DATA
GND => GND
4.7kOhm resistor between DATA and 5V
```
