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

AF_DCMotor motor1(1);
AF_DCMotor motor4(3);

unsigned long move_time = millis();

int playOnceLeft = 0;
int playOnceRight = 0;
