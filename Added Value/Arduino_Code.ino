#include <Servo.h>

// naming my servo
Servo myservo;

// naming the input pins 
// input is coming from the PYNQ board
int floor0 = 8;
int floor1 = 9;
int floor2 = 10;

// floor tracker, the cars starting 
// pos is on floor 0
int current;

// Logic for helper methods to move the car from floor to floor
// attach the servo to pin 13
// I set 100 to be my 'stopped' point
// so for a x > 100 the car moves up
// and for x < 100 the car moves down
// the delay is used to allow the car to reach its desired floor
// once the desired floor is reached, detach
// the servo from the pin to stop its movement 
// this process is repeated each time a button is pressed

void floor0to2(){
myservo.attach(13);
myservo.write(190);
delay(9810);
myservo.detach();

}

void floor2to0(){
myservo.attach(13);
myservo.write(85);
delay(9100);
myservo.detach();
}

void floor0to1(){
myservo.attach(13);
myservo.write(180);
delay(4990);
myservo.detach();
}

void floor1to2(){
myservo.attach(13);
myservo.write(190);
delay(4800);
myservo.detach();
}

void floor2to1(){
myservo.attach(13);
myservo.write(85);
delay(4490);
myservo.detach();
}

void floor1to0(){
myservo.attach(13);
myservo.write(85);
delay(4590);
myservo.detach();
}

//========================================== setup
void setup() {
pinMode(13, OUTPUT);
Serial.begin(9400);
while(!Serial){
  ;
}
}

//========================================== loop
void loop() {
Serial.println(current);
//===========================
// move to floor 0
//===========================
// when floor0 is high go through the switch process
if(digitalRead(floor0) == 1){
  
   // wait 1.5 seconds to simulate the elevator 
   // doors opening/closing
   delay(1500);

   // logic for the switch:
   // if we want the car to go to floor 0:
   // and were on floor 0, do nothing.
   // and were on floor 1, call floor1to0.
   // and were on floor 2, call floor2to0.
   switch(current){
    case 0:
            break;
    case 1:
            floor1to0();
            current = 0;
            break;
    case 2:
            floor2to0();
            current = 0;
            break;
    default:
            break;
          
   }
}
//===========================
// move to floor 1
//===========================
// logic from the first floor is repeated 
if(digitalRead(floor1) == 1){
  
   delay(1500);
   
   switch(current){
    case 0:
            floor0to1();
            current = 1;
            break;
    case 1:
            break;
    case 2:
            floor2to1();
            current = 1;
            break;
    default:
            break;
   }
}
//===========================
// call to floor 2
//===========================
// logic from the first floor is repeated 
if(digitalRead(floor2) == 1){

  delay(1500);
  
   switch(current){
    case 0:
            floor0to2();
            current = 2;
            break;
    case 1:
            floor1to2();
            current = 2;
            break;
    case 2:
            break;
    default:
            break;
          
   }
}
}// end loop
