//  Motor Driver with Serial Input

#include "MotorDriver.h"

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  
  /*Configure the motor A to control the wheel at the left side.*/
  /*Configure the motor B to control the wheel at the right side.*/
  motordriver.init();
  motordriver.setSpeed(200,MOTORB);
  motordriver.setSpeed(200,MOTORA);
  
}
 
void loop() {
  
   // print the string when a newline arrives:
  if (stringComplete) {
    Serial.println(inputString);
    
    switch(inputString) {
    case 'forward':
        motordriver.goForward();
    break;
    case 'back':
        motordriver.goBackward();
    break;
    case 'left':
        motordriver.goLeft();
    break;
    case 'right':
        motordriver.goRight();
    break;
    case 'stop':
        motordriver.stop();
    break;
    }
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
  
}
