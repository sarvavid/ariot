int led7 = D7;

int changeIntensity(String param);

void setup{
  pinmode(led7, OUTPUT);
  Particle.function("changeIntensity", changeIntensity);
}

void loop{}

int changeIntensity(String param){
  int ledIntensity = param.toInt();
  if (0 <= ledIntensity <= 255){
    analogWrite(led, brightness);
  }
}
