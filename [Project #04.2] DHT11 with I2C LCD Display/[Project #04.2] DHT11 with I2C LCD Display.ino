/*
  DHT11 with I2C LCD Display
  Made by Fawwaz Abrial Saffa

  Reference Article: https://medium.com/@fawwazabrials/a-guide-on-sensors-project-04-esp32-external-sensors-47a45ade46ce
*/

// import the just installed library
#include "DHT.h"
#include <LiquidCrystal_I2C.h>

// define the DHT11 sensor using the installed library
#define DHT11_PIN 23
DHT dht(DHT11_PIN, DHT11);
float temperature, humidity;

// define the LCD Display
const int LCD_COLUMNS = 16;
const int LCD_ROWS = 2;
LiquidCrystal_I2C lcd(0x27, LCD_COLUMNS, LCD_ROWS);  

// symbols
byte thermometer[8] = {
	0b00100,
	0b01010,
	0b01010,
	0b01110,
	0b01110,
	0b11111,
	0b11111,
	0b01110
};

byte water[8] = {
	0b00100,
	0b00100,
	0b01010,
	0b01010,
	0b10001,
	0b10001,
	0b10001,
	0b01110
};

byte degree[8] = {
	0b01000,
	0b10100,
	0b01000,
	0b00011,
	0b00100,
	0b00100,
	0b00011,
	0b00000
};

void setup() {
  // start reading from the sensor
  dht.begin();

  // initiate LCD and symbols
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, thermometer);
  lcd.createChar(1, water);
  lcd.createChar(2, degree);
}

void loop() {
  delay(2000);
  lcd.clear();
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();

  lcd.setCursor(0, 0);
  lcd.print("Status: ");
  if (isnan(temperature) & isnan(humidity)) lcd.print("ERROR");
  else {
    lcd.print("OK");
    lcd.setCursor(0, 1);
    lcd.write(0);
    lcd.setCursor(2, 1);
    lcd.print(temperature, 1);
    lcd.setCursor(6, 1);
    lcd.write(2);

    lcd.setCursor(8, 1);
    lcd.write(1);
    lcd.setCursor(10, 1);
    lcd.print(humidity, 1);
    lcd.setCursor(14, 1);
    lcd.print("%");
  }
}
