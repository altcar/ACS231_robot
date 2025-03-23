const int pinPWMA = 13; 
const int pinAI2 = 12;
const int pinAI1 = 11;      // Pin allocation for AI1
      // Pin allocation for AI2
    // Pin allocation for the PWM pin
const int pinStandBy = 10; // Pin allocation for the standby pin
const int pinBI1 = 9;     // Pin allocation for AI1
const int pinBI2 = 8;     // Pin allocation for AI2
const int pinPWMB = 7;

bool AI1, AI2, BI1, BI2, standBy;
unsigned char pwmValueL = 0, pwmValueR = 0; // PWM value to be written to the output

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

void WLloop(int Left, int Right, int guidance = 0, float theta = 0)
{
      Serial.print(theta);
    switch (Left)
    {
    case 2:
        BI1 = true;
        BI2 = false;
        break;
    case 1: // forward
        BI1 = false;
        BI2 = true;
        break;
    default:
        BI1 = true;
        BI2 = true;
        break;
    }
    switch (Right)
    {
    case 2:
        AI1 = true;
        AI2 = false;
        break;
    case 1: // forward
        AI1 = false;
        AI2 = true;
        break;
    default:
        AI1 = true;
        AI2 = true;
        break;
    }
    // Reverse the Motor

    // Change the speed of the motor 250 max

    // Write the AI1 and AI2 values to the configuration pins
    digitalWrite(pinAI1, AI1);
    digitalWrite(pinAI2, AI2);
    digitalWrite(pinBI1, BI1);
    digitalWrite(pinBI2, BI2);
if(guidance == 1){
    // Define constants for robot and simulation
    const float h = 0.138;   // 1/2 distance between wheels in meters
    const int vMax = 250;   // Maximum PWM signal value (255)
    const float lambda = 1; // Constant for scaling control signal

    // Define vehicle and control constants
    const int v = 150;   // Base velocity for the robot (scaled to 255 for PWM)
    const float K = 1.0; // Proportional gain for error correction

    // Initialize the error signal, control signal, and initial angle
    float e = 0.0; // Error signal (angle deviation)
    float u = 0.0; // Control input

    e = 0 - theta;              // error signal
    u = e * K;                  // control input
    pwmValueL = v - lambda * u; // left velocity//Left motor speed
    pwmValueR = v + lambda * u; // right velocity//Right motor speed
    if (pwmValueL > vMax)
    {
        pwmValueL = vMax;
    }
    if (pwmValueR > vMax)
    {
        pwmValueR = vMax;
    }
    Serial.print(pwmValueL ); Serial.print(" ");
    Serial.print(pwmValueR);
    // Serial.println(u);
}else{
    pwmValueL = 105;
    pwmValueR = 130;
}
    analogWrite(pinPWMA, pwmValueR);
    analogWrite(pinPWMB, pwmValueL);
    // float T = 0.08*0.01; // sampling time
}

// Update the robot's angle based on the difference in wheel velocities
  // theta = theta + ((pwmValueR - pwmValueL) / (2 * h)) * h * 0.01;  // Update theta

// Optional: Print values for debuggin