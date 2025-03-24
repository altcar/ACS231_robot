// Include the required Wire library for I2C<br>#include <Wire.h>
#include <Wire.h>
#include <Servo.h>

// Timing variables
unsigned long previousMillis = 0;
const long interval = 10;  // Update interval (ms)

// Movement variables
int currentPos = 1100;
int direction = -1;  // -1 = decreasing, 1 = increasing


Servo baseServo;
Servo shoulderServo;
Servo elbowServo;Servo wristServo;

const int basePin = 9;
const int shoulderPin = 10;
const int elbowPin = 11;
const int wristPin = 3;// not used
// Variables to store current positions
int baseMicros = 1500;
int shoulderMicros = 1500;
int elbowMicros = 1500;
int wristMicros = 1500;

//Declare Global variables
float interpVal;

float LuT_1_xElements[] = {600,700, 800, 900, 1000, 1100};
float LuT_1_yElements[] = {2500, 2400, 2330, 2250, 2170, 2000};
// float LuT_1_xElements[] = {600,1100};
// float LuT_1_yElements[] = {2500,  2000};
// initialise  the lookup Table Array size variables
float LuT_1_xSize = 0; // Initialise variable as 0, to be calculated in setup()


// Function prototypes for the lookup Table functions
float LookUpTable1D(float inVal, float elementsArraySize, float xElements[], float yElements[]);
void CheckLuTArrays (float xArraySize, float yArraySize, float xElements[], float yElements[]);




int x = 0;
void setup() {
  // Define the LED pin as Output
  // Start the I2C Bus as Slave on address 9
  Wire.begin(9); 
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
}
void receiveEvent(int bytes) {
  x = Wire.read();    // read one character from the I2C
}
void loop() {
  //If value received is 0 blink LED for 200 ms
  if (x == '1') {

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // Update position
    currentPos += direction;

    // Check boundaries
    // if (currentPos <= 600 || currentPos >= 1100) {
    //   direction *= -1;  // Reverse direction
    // }

    // Constrain position to valid range
    currentPos = constrain(currentPos, 600, 1100);

    // Update servos
    shoulderServo.writeMicroseconds(currentPos);
    int interpVal = LookUpTable1D(currentPos, LuT_1_xSize, LuT_1_xElements, LuT_1_yElements);
    elbowServo.writeMicroseconds(interpVal);
  }
  }
  //If value received is 3 blink LED for 400 ms
  if (x == '0') {
  baseServo.writeMicroseconds(580);
  shoulderServo.writeMicroseconds(2000);
  elbowServo.writeMicroseconds(1500);
  wristServo.writeMicroseconds(wristMicros);
  }
}


float LookUpTable1D (float inVal, float elementsArraySize, float xElements[], float yElements[]) {

  //declare and initialise local variables
  float fraction = 0.0;

  // Scan through the gaps between the elements in the xElement array, and find where the inVal is
  // located. Perform a simple linear interpolation between indexes n and n+1, of xElements
  // and yElements, to calculate the lookup output value relating to the input value

  for (int n = 0; n <= elementsArraySize - 2; n++) {
    if ((inVal >= xElements[n]) && (inVal <= xElements[n + 1])) {
      fraction = (inVal - xElements[n]) / (xElements[n + 1] - xElements[n]);

      // Return the output value and exit the function
      return (fraction * (yElements[n + 1] - yElements[n])) + yElements[n];
    }

  }
  // Return an overflow value of the input value is not within the input range of the xElements array
  return 0xFFFFFFFF;
}

// ----------------------------------------------
// This function performs a simple check on the lookup table arrays to check the data is valid:
// 1. Check the xElements and yElements arrays are the same size
// 2. Chech that the values in the xElements array are increasing with index
//
// If an error is discovered, an error message is displated, and the code is held in an infinite
// loop to block further execution
//
void CheckLuTArrays (float xArraySize, float yArraySize, float xElements[], float yElements[]) {

  // Check for array size missmatch between the xElements and yElements arrays
  // If found display an error message, then block the execution of the remainder
  // of the code
  if (xArraySize != yArraySize) { // check for array size missmatch
    Serial.println();
    Serial.println("Error: Number of elements in xElements array is not equal to the number of");
    Serial.println("elements in the yElements array.");
    Serial.println();
    Serial.println("This program will not execute further, and sit in an infinite loop");
    while (1); // Hold the execution at this point
  }

  //Check that the values in xElements are increasing as the index values increase
  // If not display an error message then block the execution of the remainder of the code
  for (int n = 0; n <= xArraySize - 2; n++) {
    // Scan through the xElement indexes
    if (LuT_1_xElements[n] >= LuT_1_xElements[n + 1]) {
      Serial.println();
      Serial.println("Error: the values in xElements are not all increasing with increasing");
      Serial.println("index values");
      Serial.println();
      Serial.println("This program will not execute further, and sit in an infinite loop");
      while (1); // Hold the execution at this point
    }
  }
}
