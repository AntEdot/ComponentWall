/*
File name: Scoreboard_V1.1
Description: Header file. Initializes global variables.

Date: Nov 2018
Author: Ante Larsson
For: Scania AB
*/

#include <TimerOne.h>
#include <TM1637Display.h>

#define NUM_OF_PRE_BUTTONS 4
#define NUM_OF_BUTTONS 16
#define NUM_OF_LIGHTS 16

//Button and Light pins
static uint8_t preButton[NUM_OF_PRE_BUTTONS] = {8, 9, 10, 11};
static uint8_t Button[NUM_OF_BUTTONS] = {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15};
static uint8_t Light[NUM_OF_LIGHTS] = {39, 41, 43, 45, 47, 49, 51, 53, 40, 38, 42, 44, 46, 48, 50, 52}; //First half is green second is red

//Digit pins
byte segmentClock = 21;
byte segmentLatch = 20;
byte segmentData = 19;

//Back Display Pins
byte CLK = 15;
byte DIO = 14;

TM1637Display display(CLK, DIO); //Initialize back display

//Points
int redCount = 0;
int greenCount = 0;

//Define buttons
String wrongString = "W:B00B01B02B03B04B05B06B07";
String correctString = "C:B08B09B10B11B12B13B14B15";

//Flags
uint8_t test = 0;
uint8_t game_over_flag = 1;

//Time tick
char digit_time = 90;
uint8_t back_time = 0;
uint32_t period = 1000000; //1sec

//Tick length
long preMillis = 0;
long highestMillis = 0;
