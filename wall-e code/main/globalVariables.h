#pragma once

#include<SoftwareSerial.h>
#include <AFMotor.h>
#include <Servo.h>


Servo leftArm;
Servo rightArm;


int posServoRightArm = 0;
int posServoLeftArm = 0;
boolean arms = 1;

boolean waveCheck = 0;
