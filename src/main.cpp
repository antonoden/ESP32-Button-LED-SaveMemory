#include <Arduino.h>

const int buttonPIN = 4;
const int ledPIN = 18;

int ledState = HIGH;
int buttonState = LOW;
int lastButtonState = LOW;

void setup() {
  Serial.begin(115200);

  pinMode(buttonPIN, INPUT);
  pinMode(ledPIN, OUTPUT);

  digitalWrite(ledPIN, ledState);
}

void loop() {
    delay(400);
    int reading = digitalRead(buttonPIN);

    if(reading != buttonState) {
        buttonState = reading;

        if(buttonState == HIGH) { //toggles ledState
            ledState = !ledState;
        }
    }

    if(digitalRead(ledPIN) != ledState) {
        Serial.print("ledState changed ");
        Serial.println(ledState);

        digitalWrite(ledPIN, ledState);
    }
}