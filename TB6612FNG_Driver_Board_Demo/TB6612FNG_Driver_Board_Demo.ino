

#include "wheel.h"
#include "wheelencoder.h"
#include "linefollowing.h"
#include "ultrasonic.h"
#include "imu.h"
#include "servo.h"
float z_angle = 0;
int flag1 = 0;
void setup() {

  Serial.begin(9600);
  WLsetup();
  WEsetup();
  USsetup();
  LFsetup();
  SOsetup();
  IMsetup();
  delay(1000);
}

void loop() {
  z_angle = IMloop(z_angle);
  if (flag1 == 0) {
    if (z_angle > -175) {
      WLloop(2, 1);
      

    } else {
       //stopping condition
      WLloop(3, 3);
      delay(1000);
      flag1 = 1;
      z_angle = 0;
    }
  }
  if(flag1 == 1){
    if(strstr(LFloop(),"1")){
      WLloop(3,3);
      delay(1000);
      flag1 = 2;
      //stopping condition
      z_angle = 0
    }else{
       WLloop(1,1,1,-z_angle);
    }
 }
 if(flag1 == 2){
    //restain the arm
    USloop()
 }
}
