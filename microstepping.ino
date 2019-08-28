
//Set up squeeze stepper

#include <Stepper.h>

const int stepsPerRevolution = 200;

Stepper myStepper (stepsPerRevolution, 3, 4, 5, 6);


//Set up rotation stepper 
// defining pins
  const int stepPin = 7; //pulse
  const int dirPin = 8; //direction
  const int enPin = 9; //enable

void setup() {

  // Squeeze Stepper Speed

  myStepper.setSpeed(25);
  Serial.begin(9600);
  
  
  // set pin as output 
  pinMode(stepPin,OUTPUT);
  pinMode(dirPin,OUTPUT);
  pinMode(enPin,OUTPUT);
  digitalWrite(enPin,LOW);
  
}

void loop() {

  
  // rerun system 20 times

  for (int i=0; i<20; ++i) { 
  
  Serial.println("clockwise");
  myStepper.step(.25*stepsPerRevolution);
  delay(500);

  
  //Enables motor direction motion 
  digitalWrite(dirPin,HIGH);
  //dictates 200 pulse is 1 cycle
  for(int x = 0; x<20; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(6000);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(5);
  }
  delay(500);
}
//raise push bar
Serial.println("counterclockwise");
myStepper.step(-5*stepsPerRevolution);

delay(50000);

}
