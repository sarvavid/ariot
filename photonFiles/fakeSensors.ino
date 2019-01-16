int setPot(String param);
int getTime(String param);

int potVal = 0;
int currTime = 0;

void setup() {
    Particle.function("setPot", setPot);
    Particle.variable("getPot", &potVal, INT);
    Particle.function("getTime", getTime);
}

void loop() {}

int setPot(String param){
    potVal = param.toInt();
}

int getTime(String param){
    currTime = param.toInt();
}