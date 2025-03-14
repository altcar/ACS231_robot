#include <Servo.h> // import the servo library

Servo S1; // create a servo object

//middle is positive                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
const byte S1pwm = 6; //yellow

// declare variables, for use later:
int P1val; int S1angle;

// initialise the servo and the serial monitor:
void SOsetup() {
  S1.attach(S1pwm);  
}
 
void SOloop() {
  S1.write(1023);//1023 max
  delay(2000);
  
  S1.write(800);
}
