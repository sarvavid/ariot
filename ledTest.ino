int buzzerPin = D7;

int changeIntensity(String param);

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Particle.function("changeIntensity", changeIntensity);
  digitalWrite(buzzerPin, HIGH);
}

void loop() {}

int changeIntensity(String param){
  int frequency = param.toInt();
  if (0 <= frequency <= 500){
    tone(buzzerPin, frequency);
  }
}
