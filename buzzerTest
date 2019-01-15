int buzzPin = A4;

int changeIntensity(String param);

void setup(){
  pinMode(buzzPin, OUTPUT);
  Particle.function("changeIntensity", changeIntensity);
  Serial.begin(9600);
}

void loop(){}

int changeIntensity(String param){
  int freq = param.toInt();
  if (0 <= freq && freq <= 500){
    tone(buzzPin, freq);
  }
}
