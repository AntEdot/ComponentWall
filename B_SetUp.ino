/*
File name: B_SetUp
Description: Initializes objects and pins.

Date: Oct 2018
Author: Ante Larsson
For: Scania AB
*/

void initObjects() {
  Serial.begin(9600);         //Initialize serial communitaction
  Timer1.initialize(period);  //Initialize TimerOne (A timer will run with a specific period)
  
 
  display.setBrightness(0x0a);  //set the diplay to maximum brightness
  display.showNumberDec(back_time);
}

void initPins() {
  for (uint8_t i = 0; i <= NUM_OF_PRE_BUTTONS; i++) {   //Set pins to inputs and outputs, respectively.
    pinMode(preButton[i], INPUT);
  }
  for (uint8_t i = 0; i <= NUM_OF_BUTTONS; i++) {
    pinMode(Button[i], INPUT);
  }

  for (uint8_t i = 0; i < NUM_OF_LIGHTS; i++) {
    pinMode(Light[i], OUTPUT);
    digitalWrite(Light[i], HIGH);
  }

  pinMode(segmentClock, OUTPUT);
  pinMode(segmentData, OUTPUT);
  pinMode(segmentLatch, OUTPUT);

  digitalWrite(segmentClock, LOW);    //Set to LOW for no operation.
  digitalWrite(segmentData, LOW);
  digitalWrite(segmentLatch, LOW);
}
