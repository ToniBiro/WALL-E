# pragma once
// move forword and backword with wall-e
#include "globalVariables.h"

// makes motor "number" move forward
void move_forward(int number){
  if (number == 1){
    motor1.run(FORWARD);
  }

  if(number == 2){
    motor4.run(FORWARD);
  }
}

// makes motor "number" move backward
void move_backward(int number){
  if (number == 1){
    motor1.run(BACKWARD);
  }

  if(number == 2){
    motor4.run(BACKWARD);
  }
}

// stops the motors from moving
void stop_moving(){
  motor1.run(RELEASE);
  motor4.run(RELEASE);
}
