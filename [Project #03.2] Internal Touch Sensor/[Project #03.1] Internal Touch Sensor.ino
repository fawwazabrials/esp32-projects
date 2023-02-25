/*
  ESP32 Internal Touch Sensor Test
  Made by Fawwaz Abrial Saffa

  Reference Article: https://medium.com/@fawwazabrials/door-opener-detection-system-project-3-esp32-internal-sensors-588a7132f481
*/

// Set GPIO pin used
#define TOUCH_PIN 4

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println(touchRead(TOUCH_PIN)); // Print sensor readings
  /*
    EXPLANATION : 
      touchRead(uint8_t pin) is the function used for reading the 
      pin where the sensor is being used from
   */

  delay(100);
}