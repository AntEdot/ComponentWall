/*
File name: A_main
Description: Runs the program.

Date: Oct 2018
Author: Ante Larsson
For: Scania AB
*/
void setup() {
  initObjects();
  initPins();

  preGame();
}

void loop() {
  tick();
}
