#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;
unsigned long last_time;
const float threshold = 175.0; // Angle threshold to detect 180-degree rotation

void IMsetup() {

    Wire.begin();
    mpu.initialize();
    if (!mpu.testConnection()) {
        Serial.println("MPU6050 connection failed!");
        while (1);
    }
    Serial.println("MPU6050 Initialized");
    last_time = millis();
}

float IMloop(float z_angle) {
    int16_t gx, gy, gz;
    mpu.getRotation(&gx, &gy, &gz);

    // Convert raw gyroscope data to degrees per second
    float gZ = gz / 131.0;  // Sensitivity scale factor for 250dps setting
    
    // Calculate time difference
    unsigned long current_time = millis();
    float dt = (current_time - last_time) / 1000.0; // Convert to seconds
    last_time = current_time;

    // Integrate to find angle change
    z_angle += gZ * dt;
Serial.print(z_angle);
    // Normalize angle to keep it within -180 to 180 degrees
    if (z_angle > 180) z_angle -= 360;
    if (z_angle < -180) z_angle += 360;
return z_angle;
}