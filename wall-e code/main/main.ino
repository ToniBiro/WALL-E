#include "globalVariables.h"
#include "arm_movement.h"
#include "wave.h"
#include "wheel_movement.h"
#include "bluetooth.h"

void setup() {
  
  Serial.begin(9600); // communication with the bluetooth module
  SUART.begin(9600);
  pinMode(btPin0, INPUT);
  pinMode(btPin1, INPUT);
  rightArm.attach(10);
  leftArm.attach(9);
  rightArm.write(180);
  leftArm.write(5);
  
  motor1.setSpeed(220);
  motor4.setSpeed(220);
}

void loop() {

  // read the command from the bluetooth module
  read_commands();

  // when the "arms" variable is 0 it means that the control is taken by the wheels
  if(arms == 0){
    //control the wheels
    if (command == upArrow){
      move_forward(1);
      move_forward(2);
    }
  
    if (command == downArrow){
      move_backward(1);
      move_backward(2);
    }

    if(command == backLights || command == frontLights){
      stop_moving();
    }
    
  }
  // when the "arms" variable is 1 it means that the control is taken by the arms
  else{
    
    // first make sure the arm is not waving
    if(playOnceLeft == 1){
      // For the left arm we have the following mapping
      if(command == upArrow){
        move_left_arm_up(posServoLeftArm);
      }
      if(command == downArrow){
        move_left_arm_down(posServoLeftArm);
      }
    }

    if(playOnceRight == 1){
      // For the right arm we have the following mapping
      if(command == rightArrow){
        move_right_arm_up(posServoRightArm);
      }
      if(command == rightArrow){
        move_right_arm_down(posServoRightArm);
      }
    }

    // Make Wall-e wave
    //wave with left - aka 0
    if(command == frontLights && playOnceLeft == 0){
      wave(0);
      playOnceLeft = 1;
    }
    //wave with right - aka 1
    if(command == backLights && playOnceRight == 0){
      playOnceRight = 1;
      wave(1);
    }
  }

  // if the triangle button from the mobile app is pushed
  // the command swiches from the wheels to the arms and viceversa
  if(command == triangle){
    arms = !arms;
  }

  
}
