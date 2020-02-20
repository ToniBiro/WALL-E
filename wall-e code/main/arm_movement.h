#pragma once
// there are 2 servos that control the arms, the up and down movement

#include "globalVariables.h"


void move_arm_up(int & posServo){

  if(posServo < 90){
    posServo += 1;
    rightArm.write(posServo);
    delay(15);
  }
}

void move_arm_down(int & posServo){
  if(posServo > 0){
    posServo -= 1;
    rightArm.write(posServo);
    delay(15);
  }
}
