/*
  ESP32 Internal Hall Effect Sensor
  Made by Fawwaz Abrial Saffa

  Reference Article: https://medium.com/@fawwazabrials/door-opener-detection-system-project-3-esp32-internal-sensors-588a7132f481
*/

void setup() {
  Serial.begin(115200);

}

void loop() {
  Serial.println(hallRead());
  /*
    EXPLANATION:
      The function hallRead() is used to read the values 
      that the sensor is getting
  */

  delay(100);
}