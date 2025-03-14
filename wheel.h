const int pinAI1 = 9;      // Pin allocation for AI1
const int pinAI2 = 8;      // Pin allocation for AI2
const int pinPWMA = 7;     // Pin allocation for the PWM pin
const int pinStandBy = 10; // Pin allocation for the standby pin
const int pinBI1 = 11;     // Pin allocation for AI1
const int pinBI2 = 12;     // Pin allocation for AI2
const int pinPWMB = 13;

bool AI1, AI2, standBy;
unsigned char pwmValue = 0; // PWM value to be written to the output

extern void WLsetup()
{
    // Assign the digital I/O pin directions
    pinMode(pinAI1, OUTPUT);
    pinMode(pinAI2, OUTPUT);
    pinMode(pinPWMA, OUTPUT);
    pinMode(pinBI1, OUTPUT);
    pinMode(pinBI2, OUTPUT);
    pinMode(pinPWMB, OUTPUT);
    pinMode(pinStandBy, OUTPUT);
    // Drive the standby pin high to enable the output
    standBy = true;
    digitalWrite(pinStandBy, standBy);
}

void WLloop()
{
    // Reverse the Motor
    AI1 = false;
    AI2 = true;

    // Change the speed of the motor
    pwmValue = 250;

    // Write the AI1 and AI2 values to the configuration pins
    digitalWrite(pinAI1, AI1);
    digitalWrite(pinAI2, AI2);
    analogWrite(pinPWMA, pwmValue);
    digitalWrite(pinBI1, AI1);
    digitalWrite(pinBI2, AI2);
    analogWrite(pinPWMB, pwmValue);
}
