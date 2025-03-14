

#include "wheel.h"
#include "wheelencoder.h"
#include "linefollowing.h"
#include "ultrasonic.h"

#include "servo.h"

void setup()
{

  Serial.begin(9600);
  WLsetup();
  WEsetup();
  USsetup();
  LFsetup();
  SOsetup();
}

void loop()
{
  WLloop();
  WEloop();
  LFloop();
  USloop();
  SOloop();
}
