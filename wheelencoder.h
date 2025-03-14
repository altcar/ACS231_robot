
// Define the pins used for the encoder
const int encoder1PinA = 30; // green
const int encoder1PinB = 28; // blue
const int encoder2PinA = 30; // green
const int encoder2PinB = 28; // blue

extern void WEsetup()
{
    // Set encoder pins as input with pull-up resistors
    pinMode(encoder1PinA, INPUT_PULLUP);
    pinMode(encoder1PinB, INPUT_PULLUP);
    pinMode(encoder2PinA, INPUT_PULLUP);
    pinMode(encoder2PinB, INPUT_PULLUP);
}

void WEloop()
{

    Serial.print(digitalRead(encoder2PinA));   // MSB = most significant bit
    Serial.print(digitalRead(encoder2PinB));   // LSB = least significant bit)
    Serial.print(digitalRead(encoder1PinA));   // MSB = most significant bit
    Serial.print(digitalRead(encoder1PinB)); // LSB = least significant bit)
    
    Serial.print("   "); // LSB = least significant bit)
}

// // Attach interrupts to the encoder pins
// attachInterrupt(digitalPinToInterrupt(encoder1PinA), updateEncoder, CHANGE);
// attachInterrupt(digitalPinToInterrupt(encoder1PinB), updateEncoder, CHANGE);
// void updateEncoder() {
//   int MSB = digitalRead(encoder1PinA); // MSB = most significant bit
//   int LSB = digitalRead(encoder1PinB); // LSB = least significant bit

//   int encoded = (MSB << 1) | LSB; // Converting the 2 pin value to single number
//   int sum = (lastEncoded << 2) | encoded; // Adding it to the previous encoded value

//   if (sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) encoderPos++;
//   if (sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) encoderPos--;

//   lastEncoded = encoded; // Store this value for next time
// }
