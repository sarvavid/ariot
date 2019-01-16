/*
 Stepper Motor Control - speed control

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.
 A potentiometer is connected to analog input 0.

 The motor will rotate in a clockwise direction. The higher the potentiometer value,
 the faster the motor speed. Because setSpeed() sets the delay between steps,
 you may notice the motor is less responsive to changes in the sensor value at
 low speeds.

 Created 30 Nov. 2009
 Modified 28 Oct 2010
 by Tom Igoe

 */

#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor
int angSpeed = 9;

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 5, 6, 9, 10);


void setup() {
  Serial.begin (9600);
  Serial.print (9);
  myStepper.setSpeed(angSpeed/2/PI*60);
  
}

void loop() {
  // map it to a range from 0 to 100:
  // set the motor speed:
    Serial.println(20);
    
    // step 1/100 of a revolution:
    myStepper.step(stepsPerRevolution);
    Serial.println(100);
  
}
