#include<SoftwareSerial.h>
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
}

void setMotor(int motorSpeed , boolean reverse)
{
  analogWrite(enablePin, motorSpeed );
  digitalWrite(in1Pin, ! reverse);
  digitalWrite(in2Pin, reverse);
}

int comanda; // default
boolean arms = 0;

void loop() {
  if(SUART.available()){
    comanda = SUART.read();
    Serial.println(comanda);
    
    digitalWrite(LED_BUILTIN, HIGH);
  }
  if(arms == 0){
    //control the weels
    if (comanda == 70){
      //setMotor(motorSpeed, reverse);
      Serial.println("fata");
    }
  
    if (comanda == 66){
      //setMotor(motorSpeed, reverse);
      Serial.println("spate");
    }
    
    if (comanda == 82){
      //setMotor(motorSpeed, reverse);
      Serial.println("dreapta");
    }
    
    if (comanda == 76){
      //setMotor(motorSpeed, reverse);
      Serial.println("stanga");
    }
  }
  else{
    //control the arms
  }

  if(comanda == 120){
    // controlul e obtinuta de brate
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
