int ledPin = A4;

int changeIntensity(String param);

void setup(){
  pinMode(ledPin, OUTPUT);
  Particle.function("changeIntensity", changeIntensity);
  Serial.begin(9600);
}

void loop(){}

int changeIntensity(String param){
  int ledIntensity = param.toInt();
  if (0 <= ledIntensity && ledIntensity <= 255){
    analogWrite(ledPin, ledIntensity);
    Serial.println(ledIntensity);
  }
}
