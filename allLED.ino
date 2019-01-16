int RED_PIN = D1;
int GREEN_PIN = D2;
int BLUE_PIN = D3;
int ledPin = D0;

int changeColor(String param);
int changeIntensity(String param);

int color = 0;
int ledIntensity = 0;

void setup() {
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);
    pinMode(ledPin, OUTPUT);
    Particle.function("changeColor", changeColor);
    Particle.function("changeIntensity", changeIntensity);
}

void loop() {
    displayColor(color);
    analogWrite(ledPin, ledIntensity);
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
}

int changeIntensity(String param){
    ledIntensity = param.toInt();
    color = 0;
}
