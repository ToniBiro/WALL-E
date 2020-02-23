#pragma once

#include<SoftwareSerial.h>
#include <AFMotor.h>
#include <Servo.h>

// for the bluetooth module
SoftwareSerial SUART(A0, A1);

const int btPin0 = A0;
const int btPin1 = A1;

int command;

// the 2 servo motors that control the arms
Servo leftArm;
Servo rightArm;

// the position the servo motors are at all time
int posServoRightArm = 0;
int posServoLeftArm = 0;

// variable that is 0 if the wheels are in control or 1 if the arms are in control
boolean arms = 1;

// the 2 dc motors that control the wheels
AF_DCMotor motor1(1);
AF_DCMotor motor4(3);


// check to see if wall-e is waving or not
int playOnceLeft = 0;
int playOnceRight = 0;


// BUTTON READING FOR THE ANDROID APP USED
// the app we used is: 
// if different app is used just change the number of the command here
// default reading = 83

// right-arrow = 82
int rightArrow = 82;
// left-arrow = 76
int leftArrow = 76;
// up-arrow = 70
int upArrow = 70;
// down-arrow = 66
int downArrow = 66;
// up+left = 71
int upLeftArrow = 71;
// down+left = 72
int downLeftArrow = 72;
// up+right = 73
int upRightArrow = 73;
// down+right = 74
int downRightArrow = 74;
// front-lights = 119
int frontLights = 119;
// back-lights = 117
int backLights = 117;
// triangle = 120
int triangle = 120;
