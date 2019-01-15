int led7 = D7;

int changeIntensity(String param);

void setup(){
  pinMode(led7, OUTPUT);
  Particle.function("changeIntensity", changeIntensity);
  Serial.begin(9600);
}

void loop(){}

int changeIntensity(String param){
  int ledIntensity = param.toInt();
  if (0 <= ledIntensity <= 255){
    analogWrite(led7, ledIntensity);
  }
  Serial.println(ledIntensity);
}
