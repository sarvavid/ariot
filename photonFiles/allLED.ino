// This #include statement was automatically added by the Particle IDE.
#include <FastLED.h>
FASTLED_USING_NAMESPACE

#define LED_COUNT 60
#define LED_PIN D4

struct CRGB leds[LED_COUNT];

int RED_PIN = D1;
int GREEN_PIN = D2;
int BLUE_PIN = D3;
int ledPin = D0;

int changeColor(String param);
int changeIntensity(String param);

int changeColorStrip(String param);

int color = 0;
int ledIntensity = 0;
int hue = 32;

byte idex = 255;
byte meteorLength = 29;

void setup() {
    LEDS.addLeds<WS2812, LED_PIN, GRB>(leds, LED_COUNT);
    LEDS.setBrightness(200);
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);
    pinMode(ledPin, OUTPUT);
    Particle.function("changeColor", changeColor);
    Particle.function("changeIntensity", changeIntensity);
    Particle.function("changeColorStrip", changeColorStrip);
}

void loop() {
    displayColor(color);
    analogWrite(ledPin, ledIntensity);
    allOn(hue);
}

void allOn(int hue){
    if (hue != 0){
        for (int i=0; i <= 59; i++)
        {
            leds[i] = CHSV(hue,200,200);
        }
        FastLED.show();
    }
    else{
        for (int i=0; i <= 59; i++)
        {
            leds[i] = CHSV(0,0,0);
        }
        FastLED.show();
    }
}

void displayColor(int color) {
    int redIntensity;
    int greenIntensity;
    int blueIntensity;
    
    if (color == 0){
        redIntensity = 0;
        greenIntensity = 0;
        blueIntensity = 0;
        
        digitalWrite(RED_PIN, LOW);
        digitalWrite(BLUE_PIN, LOW);
        digitalWrite(GREEN_PIN, LOW);
        
    }
    else if (0 < color && color <= 255)          // zone 1
    {
        redIntensity = 255 - color;    // red goes from on to off
        greenIntensity = color;        // green goes from off to on
        blueIntensity = 0;             // blue is always off
    }
    else if (color <= 511)     // zone 2
    {
        redIntensity = 0;                     // red is always off
        greenIntensity = 255 - (color - 256); // green on to off
        blueIntensity = (color - 256);        // blue off to on
    }
    else // color >= 512       // zone 3
    {
        redIntensity = (color - 512);         // red off to on
        greenIntensity = 0;                   // green is always off
        blueIntensity = 255 - (color - 512);  // blue on to off
    }
    
    if (color != 0){
        analogWrite(RED_PIN, redIntensity);
        analogWrite(BLUE_PIN, blueIntensity);
        analogWrite(GREEN_PIN, greenIntensity);
    }
}

int changeColor(String param){
    color = param.toInt();
    ledIntensity = 0;
    hue = 0;
}

int changeIntensity(String param){
    ledIntensity = param.toInt();
    color = 0;
    hue = 0;
}

int changeColorStrip(String param){
    hue = param.toInt();
    ledIntensity = 0;
    color = 0;
}
