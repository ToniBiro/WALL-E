#pragma once

#include "globalVariables.h"

// reads the commands from the bluetooth module
void read_commands(){
  
  if(SUART.available()){
    command = SUART.read();
    Serial.println(command); //check if the connection is ok
  }
}
