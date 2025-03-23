

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
  // SOsetup();
  IMsetup();
  delay(1000);

}

void loop() {
  // Serial.print(flag1);Serial.print(" ");
// WLloop(1,1);

  z_angle = IMloop(z_angle);
  if (flag1 == 0) {
    if (z_angle > -167) {  
      // SOloop2(580, 700, 2000);
      WLloop(2, 1);
    } else {
      //stopping condition, Turn 180 on the spot
      WLloop(3, 3);
      delay(1000);
      flag1 = 1;
      z_angle = 0;
    }
  }

  if (flag1 == 1) {
    if (LFloop().indexOf("1") >= 0) {  // line follower detected a 1 in any sensor, stop
      delay(700);
      WLloop(3, 3);
      delay(1000);
      flag1 = 2;
      //stopping condition
      z_angle = 0;
    } else {
      WLloop(1, 1, 2, -z_angle);
    }
  }

  if (flag1 == 2) {  // turn 90 degrees left, facing the first gate
    if (z_angle > -85) {
      WLloop(2, 1);
    }
   else {
    //stopping condition
    WLloop(3, 3);
    delay(1000);
    flag1 = 3;
    z_angle = 0;
  }
  }
  
  if (flag1 == 3) {  // move forward until the ultrasonic value is above a threshold
    if (USloop() > 23) {
      WLloop(1, 1);
    } else {
      //stopping condition
      WLloop(3, 3);
      delay(1000);
      SOloop();  // pen drawing
        flag1 = 4;
      z_angle = 0;
    }
    }

  //   if (flag1 == 4) {  // step back
  //     WLloop(2, 2);
  //     delay(1000);} else {
  //       //stopping condition
  //       WLloop(3, 3);
  //       delay(1000);
  //       flag1 = 5;
  //       z_angle = 0;
  //     }
  //     }

  //     if (flag1 == 5) {  // turn 90 degrees left, facing the left wall
  //       if (z_angle > -85) {
  //         WLloop(2, 1);
  //      
  //     } else {
  //       //stopping condition
  //       WLloop(3, 3);
  //       delay(1000);
  //       flag1 = 6;
  //       z_angle = 0;
  //     }
  //     }

  //     if (flag1 == 6) {  // move forward until the ultrasonic value is above a threshold, part 2
  //       if (USloop() > 11) {
  //         WLloop(1, 1);
  //       } else {
  //         //stopping condition
  //         WLloop(3, 3);
  //         delay(1000);
  //         // SOloop();  // pen drawing
  //           flag1 = 4;
  //         z_angle = 0;
  //       }
  //     }
  //   }
  }