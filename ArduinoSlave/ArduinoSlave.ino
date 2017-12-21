#include "FastLED.h"

#define NUM_LEDS 75
#define DATA_PIN 3

/*
  #define STARTCHAR 197
  #define ENDCHAR 165*/

#define STARTCHAR '#'
#define ENDCHAR '%'

CRGB leds[NUM_LEDS];
char buf[8];

uint8_t number = 0;
uint8_t redVal = 0;
uint8_t greenVal = 0;
uint8_t blueVal = 0;

uint16_t delayValue = Serial.read();
uint16_t delayVal2 = Serial.read();

int ledsToProcess = 0;
uint16_t nleds2 = 0;

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
  pinMode(13, OUTPUT);
}

void loop() {
  if ((Serial.available() > 0) && (ledsToProcess <= 0))
  {
    GetMessage();
  }

  if (ledsToProcess && (Serial.available() >= 5))
  {
    Serial.readBytes(buf, 5);
    uint16_t nPixel = buf[0];
    uint16_t nPixel2 = buf[1];
    nPixel |= (nPixel2 << 6);

    for (int i = 0; i <= buf[4]; i++)
    {
      digitalWrite(13, HIGH);
      delay(20);
      digitalWrite(13, LOW);
      delay(20);
    }
    //delay(1000);
    leds[nPixel] = CRGB(buf[2], buf[3], buf[4]);
    ledsToProcess--;
  }
}

void GetMessage()
{
  if (Serial.read() != STARTCHAR)
  {
    return;
  }

  while (!(Serial.available() >= 2)) { } //wait for serial

  switch (Serial.read())
  {
    case '1':
      number = Serial.read();
      redVal = Serial.read();
      greenVal = Serial.read();
      blueVal = Serial.read();
      leds[number] = CRGB(redVal, greenVal, blueVal);

      buf[0] = '#';
      buf[1] = 'A';
      buf[2] = '1';
      buf[3] = '%';

      Serial.write(buf, 4);

      break;
    case '2':
      FastLED.show();
      break;
    case '3':
      Serial.print("numleds: ");
      Serial.println(NUM_LEDS);
      break;
    case '4':
      delayValue = Serial.read();
      delayVal2 = Serial.read();
      delayValue |= (delayVal2 << 8);
      digitalWrite(13, HIGH);
      delay(delayValue);
      digitalWrite(13, LOW);
      break;
    case '5':
      Serial.readBytes(buf, 2);
      ledsToProcess = buf[0];
      nleds2 = buf[1];
      //ledsToProcess |= (nleds2 << 6);
      for (int i = 0; i <= 5; i++)
      {
        digitalWrite(13, HIGH);
        delay(200);
        digitalWrite(13, LOW);
        delay(200);
      }
      Serial.println("ayeee!");
      Serial.println(ledsToProcess);
      break;
    case '6':
      FastLED.clear();
      FastLED.show();
      Serial.println("Clearon");
      break;
    default:
      Serial.println("Err invalid control message");

      break;
  }
}

void BeginListener()
{

}

