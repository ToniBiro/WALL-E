

#include "globalVariables.h"
#include "arm_movement.h"
#include "wave.h"


SoftwareSerial SUART(A0, A1);

const int enablePin = 11;
const int in1Pin = 10;
const int in2Pin = 9;
const int btPin0 = A0;
const int btPin1 = A1;

int motorSpeed = 0;
boolean reverse = false;

void setup() {
  
  Serial.begin(9600); // communication with the bluetooth module
  SUART.begin(9600);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(btPin0, INPUT);
  pinMode(btPin1, INPUT);
  rightArm.attach(10);
  rightArm.write(0);
}

void setMotor(int motorSpeed , boolean reverse)
{
  analogWrite(enablePin, motorSpeed );
  digitalWrite(in1Pin, ! reverse);
  digitalWrite(in2Pin, reverse);
}

int command; // default


void loop() {
  if(SUART.available()){
    command = SUART.read();
    Serial.println(command);
    
    digitalWrite(LED_BUILTIN, HIGH);
  }
  if(arms == 0){
    //control the weels
    if (command == 70){
      //setMotor(motorSpeed, reverse);
      Serial.println("fata");
    }
  
    if (command == 66){
      //setMotor(motorSpeed, reverse);
      Serial.println("spate");
    }
    
    if (command == 82){
      //setMotor(motorSpeed, reverse);
      Serial.println("dreapta");
    }
    
    if (command == 76){
      //setMotor(motorSpeed, reverse);
      Serial.println("stanga");
    }
  }
  else{
    //control the arms

    // For the left arm
    if(command == 70){
      move_arm_up(posServoLeftArm);
    }
    if(command == 66){
      move_arm_down(posServoLeftArm);
    }

    // For the right arm
    if(command == 82){
      move_arm_up(posServoRightArm);
    }
    if(command == 76){
      move_arm_down(posServoRightArm);
    }

    // Make Wall-e wave
    //wave with left - aka 0
    if(command == 119){
      wave(0);
    }
    //wave with right - aka 1
    if(command == 117){
      wave(1);
    }
  }

  if(command == 120){
    // the arms have the control
    arms = !arms;
  }

  
}

// default = 83
// dreapta = 82
// stanga = 76
// fata = 70
// spate = 66
// sus+stanga = 71
// jos+stanga = 72
// sus+dreapta = 73
//jos+dreapta = 74
// faruri fata = 119
// faruri spate = 117
