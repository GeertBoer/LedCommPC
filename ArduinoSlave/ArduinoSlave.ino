#include "FastLED.h"

#define NUM_LEDS 75
#define DATA_PIN 3

/*
#define STARTCHAR 197
#define ENDCHAR 165*/

#define STARTCHAR '#'
#define ENDCHAR '%'

CRGB leds[NUM_LEDS];

uint8_t number = 0;
uint8_t redVal = 0;
uint8_t greenVal = 0;
uint8_t blueVal = 0;

void setup() {
  Serial.begin(115200);
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
}

void loop() {
  if (Serial.available() >= 7)
  {
    GetMessage();
  }

}

void GetMessage()
{
  if (Serial.read() != STARTCHAR)
  {
    return;
  }

  switch (Serial.read())
  {
    case '1':
      number = Serial.read();
      redVal = Serial.read();
      greenVal = Serial.read();
      blueVal = Serial.read();
      leds[number] = CRGB(redVal, greenVal, blueVal);
      break;
    case '2':
      FastLED.show();
      break;
    case '3':
      Serial.print("numleds: ");
      Serial.println(NUM_LEDS);
      break;
    case '4':
      Serial.println("Got message!");
      break;
    default:
      Serial.println("Err invalid control message");
      break;
  }
}

void BeginListener()
{
  //todo
}

