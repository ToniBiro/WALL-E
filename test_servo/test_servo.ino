// test servo on shield
#include <AFMotor.h>
#include <Servo.h>

Servo rightArm;
AF_DCMotor motor1(1);
AF_DCMotor motor4(4);

void setup() {
  rightArm.attach(10);
  motor1.setSpeed(50);
  motor4.setSpeed(255);
}

void loop() {
//  for (int servoPos = 0; servoPos <= 180; servoPos++){
//    rightArm.write(servoPos);
//    delay(5);
//  }
//  for (int servoPos = 180; servoPos >= 0; servoPos--){
//    rightArm.write(servoPos);
//    delay(5);
//  }

  //motor1.run(FORWARD);
  motor4.run(FORWARD);
  
}
