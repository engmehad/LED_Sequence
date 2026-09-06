
#include <Arduino.h>

int Leds[] = {3,4,5,6,9};
int sw = 2;

bool ledsState = false;

unsigned long time = 0;
unsigned long interval = 500;

int index = 0;
int num = 5;

void clearLeds()
{
    for (int i = 0; i < num; i++) {
        digitalWrite(Leds[i], LOW);
    }
}

void setup()
{
    pinMode(sw, INPUT_PULLUP);

    for (int i = 0; i < num; i++) {
        pinMode(Leds[i], OUTPUT);
        digitalWrite(Leds[i], LOW);
    }
}

void loop()
{
    if (digitalRead(sw) == LOW && !ledsState) {
        ledsState = true;
        index = 0;
        clearLeds();
        time = millis();
    }

    if (ledsState && millis() - time >= interval) {
        time = millis();

        clearLeds();

        digitalWrite(Leds[index], HIGH);
        index++;

        if (index >= num) {
            clearLeds();
            ledsState = false;
            index = 0;
        }
    }
}

