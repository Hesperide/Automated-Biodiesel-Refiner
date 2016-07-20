#include "Timer.h"
  Timer t;
  int clock; // variable to contain the current timerhandler
  int auton=0; //variable that says if the automation is on : 0=off; 1=on
  int time;
  int waitTime_1 = 10;
  int waitTime_2 = 20;
  int waitTime_3 = 10;
  int waitTime_4 = 5;
  int waitWash = 15;
  int nWash = 3;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(9, OUTPUT);
  pinMode(11, INPUT);
  pinMode(10, INPUT);
  pinMode(34, INPUT);
  pinMode(35, INPUT);
  pinMode(7, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(2, INPUT);
  Serial.begin(9600);

}

void automate() {
 //open the methanol valve
 delay(meOHtime);
 //start mixing
 delay(mixingtime);
 //stop mixing
 delay(resttime);
 //open waste valve
 delay(firtswastetime);
 //close waste valve
 //open water valve
 //close valve
 //start mixing
 //close mixing
 //open waste valve
 //close waste valve
 // repeat last 6 commands 3 times for loop
 // DONE !!!!!!
}
// the loop function runs over and over again forever
void loop() {
  //t.update();
  // turn the LED on (HIGH is the voltage level)
  if(digitalRead(11) == HIGH){ //
  digitalWrite(9, HIGH);
   Serial.println("You are in!");
  }
  if(digitalRead(11) == LOW){  // wait for a second
  digitalWrite(9, LOW); 
  Serial.println("You are out!");
  }
  if(digitalRead(10) == HIGH){
    digitalWrite(7, HIGH);
  }
  if(digitalRead(10) == LOW){
    digitalWrite(7, LOW);
  }
  if(digitalRead(35) == HIGH){
    digitalWrite(25, HIGH);
  }
  if(digitalRead(35) == LOW){
    digitalWrite(25, LOW);
  }
  if(digitalRead(34) == HIGH){
    digitalWrite(24, HIGH);
  }
  if(digitalRead(34) == LOW){
    digitalWrite(24, LOW);
  }
//  if (digitalRead(2) == HIGH && auton == 0) {
//    clock = t.every(200,clockEvent);
//    Serial.println("GGGGGGGGGGGGGG!");
//    auton = 1;
//  } else {
//    t.stop(clock);
//    auton = 0;
//    time = 0;
//    digitalWrite(24, LOW);
//    digitalWrite(25, LOW);
//    digitalWrite(9, LOW);
//    digitalWrite(7, LOW);
//  }
    
}

void clockEvent() {
   //event handler for the timer 
  int fifthsec = time;
  if (fifthsec == 0) {
     //start of the process - open mot
     digitalWrite(24, HIGH);
  } else if (fifthsec == waitTime_1/5*1000){
     // close middle valve
     digitalWrite(24, LOW);
     //motor on
     digitalWrite(7, HIGH);
  } else if (fifthsec == waitTime_2/5*1000) {
     //motor off
     digitalWrite(7, LOW);
     //open bottom valve
     digitalWrite(25, HIGH);     
  } else if (fifthsec == waitTime_3/5*1000) {
     //close bottom valve 
     digitalWrite(25, LOW);
     //open top and middle valve
     digitalWrite(9, HIGH);
     digitalWrite(24, HIGH);
  } else if (fifthsec == waitTime_4/5*1000) {
      // close top  and middle valve
      digitalWrite(9, LOW);
      digitalWrite(24, LOW);
      
  }
}
