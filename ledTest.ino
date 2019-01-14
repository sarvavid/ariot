int buzzerPin = 7;
int frequency = 50;

int changeIntensity(String param);

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Particle.function("changeIntensity", changeIntensity);
}

void loop() {
  tone(buzzerPin, frequency, 1000);
}

int changeIntensity(String param){
  int n = param.toInt();
  if (0 <= n <= 500){
    frequency = n;
  }
}
