#include <Arduino.h>

const int TOUCH_SENSOR_1_PIN = D5;
const int TOUCH_SENSOR_2_PIN = D6;
const int RELAY_PIN = D2;
int currentState = LOW;
unsigned long lastChangeTime = 0; // Time of the last sensor change

void handleSensorChange(int currentSensor)
{
  currentState = !currentState;
  lastChangeTime = millis();
  digitalWrite(LED_BUILTIN, currentState);
  delay(20);
  digitalWrite(RELAY_PIN, currentState);
}


void setup()
{
  pinMode(TOUCH_SENSOR_1_PIN, INPUT);
  pinMode(TOUCH_SENSOR_2_PIN, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(RELAY_PIN, LOW);
}

void loop()
{
  if ((digitalRead(TOUCH_SENSOR_1_PIN) == HIGH || digitalRead(TOUCH_SENSOR_2_PIN) == HIGH) && millis() - lastChangeTime > 3000)
  {
    handleSensorChange(1);
  }
  delay(20);
}

