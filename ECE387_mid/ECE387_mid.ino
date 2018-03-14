#include <Servo.h>
Servo myservo;
int cf = 0;

// define 6 pins 3 for checking the current floor
// 3 for moving to the next floor
// myservo.attach(pin)
// myservo.write(100) -- mess with the calabration 
// myservo.detach()



void loop() {
  // call the elevator to the correct floor
  //========================================
  // we want to be on floor 0
  if(pin1 == high){
    // check to see what floor the elevator is currently on
    if(cf == 0){
      // wait for 5 seconds for the elevator to load
    }
    if(cf == 1){
      // we want to lower the elevator one floor
      // set cf to 0
    }
    if(cf == 2){
      // we want to lower the elevator two floors
      // set the cf to 0
    }
    // wait until one of the next pins goes high
    while(pin2 != low || pin3 != low){
      if(one of the floor pins are pushed){
        break;
      }
      }
    // once one goes high do this
    if(pin2){
      // we want the car to go up a floor
      // set cf to 2
    }
    if(pin3){
      // we want the car to go up two floors
      // set cf to 3
    }
    
  }
  

}
