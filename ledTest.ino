int led7 = D7;

int changeIntensity(String param);

void setup() {
  pinMode(led7, OUTPUT);
  Particle.function("changeIntensity", changeIntensity);
  digitalWrite(led7, LOW);
}

void loop() {}

int changeIntensity(String param){
  int ledIntensity = param.toInt();
  if (0 <= ledIntensity <= 255){
    digitalWrite(led7, ledIntensity);
  }
}
