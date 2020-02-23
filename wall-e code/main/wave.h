#pragma once
#include "globalVariables.h"

void wave(int arm){
  
  // wave with left arm
  if(arm == 0){
    posServoLeftArm = 90;
    leftArm.write(posServoLeftArm);

    // wave 3 times
    for (int j = 0; j < 3; ++j){

      // move the arm down
      for (int i = 0; i < 60; ++i){
        posServoLeftArm -= 1;
        leftArm.write(posServoLeftArm);
        delay(20);
      }

      // move the arm up
      for (int i = 0; i < 60; ++i){
        posServoLeftArm += 1;
        delay(20);
      }
    }
    playOnceLeft = 0;
  }

  // wave with right arm
  if(arm == 1){
    posServoRightArm = 90;
    rightArm.write(posServoRightArm);
  
  for (int j = 0; j < 3; ++j){

     // move the arm down
      for (int i = 0; i < 60; ++i){
        posServoRightArm += 1;
        rightArm.write(posServoRightArm);
        delay(20);
      }

      // move the arm up
      for (int i = 0; i < 60; ++i){
        posServoRightArm -= 1;
        delay(20);
      }
    }
    playOnceRight = 0;
  }
}
