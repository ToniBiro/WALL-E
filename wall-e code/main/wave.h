#pragma once
// test servo on shield

#include "globalVariables.h"

void wave(int arm){
  if(arm == 0){ // wave with left arm
    posServoLeftArm = 90;
    leftArm.write(posServoLeftArm);
    for (int j = 0; j < 3; ++j){   
      for (int i = 0; i < 80; ++i){
        posServoLeftArm -= 1;
        leftArm.write(posServoLeftArm);
        delay(20);
      }
      
      for (int i = 0; i < 80; ++i){
        posServoLeftArm += 1;
        delay(20);
      }
    }
    playOnceLeft = 0;
  }
  if(arm == 1){
    posServoRightArm = 90;
    rightArm.write(posServoRightArm);
  
  for (int j = 0; j < 3; ++j){   
      for (int i = 0; i < 60; ++i){
        posServoRightArm -= 1;
        rightArm.write(posServoRightArm);
        delay(20);
      }
      
      for (int i = 0; i < 60; ++i){
        posServoRightArm += 1;
        delay(20);
      }
    }
    playOnceRight = 0;
  }
}
