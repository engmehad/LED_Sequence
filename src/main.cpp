#include <Arduino.h>

int Leds[] = {7, 8, 9, 10, 11};
int sw = 2;

bool ledsState = false;

unsigned long time = 0;
unsigned long interval = 500;

int index = 0;
int num = 5;

void setup()
{
    pinMode(sw, INPUT_PULLUP);

    for (int i = 0; i < num; i++)
    {
        pinMode(Leds[i], OUTPUT);
        digitalWrite(Leds[i], LOW);
    }
}

void loop()
{
    if (digitalRead(sw) == LOW && !ledsState)
    {
        ledsState = true;
        index = 0;

        for (int i = 0; i < num; i++)
            digitalWrite(Leds[i], LOW);

        time = millis();
    }

    if (ledsState && millis() - time >= interval)
    {
        time = millis();

        // إطفاء جميع الليدات
        for (int i = 0; i < num; i++)
            digitalWrite(Leds[i], LOW);

        // تشغيل الليد الحالي
        digitalWrite(Leds[index], HIGH);

        index++;

        if (index >= num)
        {
            ledsState = false;
            index = 0;
        }
    }
}