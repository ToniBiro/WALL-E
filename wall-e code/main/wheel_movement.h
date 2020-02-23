# pragma once
// move forword and backword with wall-e

#include "globalVariables.h"




void move_forward(int number){
  if (number == 1){
    motor1.run(FORWARD);
    move_time = millis();
  }

  if(number == 2){
    motor4.run(FORWARD);
    move_time = millis();
  }

  if(move_time == 2000){
    motor1.run(RELEASE);
    motor4.run(RELEASE);
    
  }

  
}


void move_backward(int number){
  if (number == 1){
    motor1.run(BACKWARD);
    move_time = millis();
  }

  if(number == 2){
    motor4.run(BACKWARD);
    move_time = millis();
  }

  if(move_time == 2000){
    motor1.run(RELEASE);
    motor4.run(RELEASE);
  }
}
