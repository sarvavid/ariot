int photoPin = A0;
int analogVal;

void setup() {
    Particle.variable("getVal", &analogVal, INT);
}

void loop() {
    analogVal = analogRead(photoPin);
    delay(100);
}