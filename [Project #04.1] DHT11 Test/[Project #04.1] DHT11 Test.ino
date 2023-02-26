/*
  Temperature and Humidity sensing with DHT11 sensor
  Made by Fawwaz Abrial Saffa

  Reference Article: https://medium.com/@fawwazabrials/a-guide-on-sensors-project-04-esp32-external-sensors-47a45ade46ce
*/

// import the just installed library
#include "DHT.h"

// define the DHT11 sensor using the installed library
#define DHT11_PIN 23
DHT dht(DHT11_PIN, DHT11);

void setup() {
  Serial.begin(115200);

  // start reading from the sensor
  dht.begin();
}

void loop() {
  double h = dht.readHumidity();    // method to read humidity
  double t = dht.readTemperature(); // method to read temperature, default in celcius

  if (isnan(t) | isnan(h)) {
    Serial.println("Failed to read values from sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print("°C Humidity: ");
  Serial.print(h);
  Serial.println("%");

  delay(2000); // delay to give the sensor time for accurate readings
}