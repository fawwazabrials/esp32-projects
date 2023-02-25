/*
  Door Detection System with ESP32 (no external sensors required)
  Made by Fawwaz Abrial Saffa

  Reference Article: https://medium.com/@fawwazabrials/door-opener-detection-system-project-3-esp32-internal-sensors-588a7132f481
*/

// set pins
const uint8_t BUTTON_PIN = 23;
const uint8_t LED_PIN = 18;
const uint8_t BUZZER_PIN = 19;

// initialize program states
bool systemState;
int hallVal;

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  systemState = false;
  hallVal = 150;
}

void loop() {
  if (digitalRead(BUTTON_PIN) == HIGH) {
    systemState = !systemState;
    digitalWrite(LED_PIN, systemState);

    delay(1000);
  }

  if (systemState) {
    hallVal = hallRead();
    if (!(hallVal >= 200 || hallVal <= 50)) {
      tone(BUZZER_PIN, 659, 5);
    } else noTone(BUZZER_PIN);
  }
}