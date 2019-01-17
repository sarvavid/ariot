int tempPin = A0;
int photoPin = A1;

int tempVal;
int photoVal;

void setup() {
    Particle.variable("getVal", &photoVal, INT);
    Particle.variable("getTemp", &tempVal, INT);
}

void loop() {
    //getting the voltage reading from the temperature sensor
    float reading = analogRead(tempPin);  
    
    // converting that reading to voltage, for 3.3v arduino use 3.3
    float voltage = reading * 5;
    voltage /= 1024; 
    
    // now print out the temperature
    int temperatureC = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset
                                               //to degrees ((voltage - 500mV) times 100)

    // now convert to Fahrenheit
    tempVal = ((temperatureC * 9 / 5) + 32)/10 - 25;
    
    photoVal = analogRead(photoPin);
    
    delay(100);
}
