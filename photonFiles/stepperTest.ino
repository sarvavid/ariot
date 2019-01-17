#include <Stepper.h>

const int stepsPerRevolution = 200;

int angSpeed = 9;

Stepper myStepper(stepsPerRevolution, D0, D1, D2, D3);

void setup() {
  myStepper.setSpeed(angSpeed/2/3.1415*60);
  
}

void loop() {
    myStepper.step(stepsPerRevolution);
}
