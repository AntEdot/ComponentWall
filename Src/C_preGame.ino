/*
File name: C_preGame
Description: Runs the preparation. Give bonus points, run tests or start the game.

Date: Oct 2018
Author: Ante Larsson
For: Scania AB
*/

//Main loop. This is what the preGame does.
void preGame() {                          
  Serial.println(correctString);
  Serial.println(wrongString);

  showNumber(digit_time);                 //Sets the displays to the start time
  wait_for_start();                       //Waits for the start button to be pressed
}

void wait_for_start() {
  while (pre_game_button_check()) {}      //Wait for the start button to be pressed
  startGame();
}

uint8_t pre_game_button_check() {
  if (digitalRead(preButton[0])) {        //Start button. If pressed return 1 and start the game.
    while (digitalRead(preButton[0]));
    return 0;
  }
  if (digitalRead(preButton[1])) {        //Increase button. Give bouns points. Light up green lights.
    delay(10);
    while (digitalRead(preButton[1]));
    greenCount++;
    if (greenCount > 8) {                 //Should not increase beyond 8.
      greenCount = 8;
    }
    greenLight();
    Serial.println(greenCount);
    return 1;
  }
  if (digitalRead(preButton[2])) {        //Decrease button. Remove bouns points. Turn off green lights.
    delay(10);
    while (digitalRead(preButton[2]));
    greenCount--;
    if (greenCount < 0) {                 //Should not dencrease below 0.
      greenCount = 0;
    }
    greenLightOff();
    Serial.println(greenCount);
    return 1;
  }
  if (digitalRead(preButton[3])) {        //Test button. Run tests.
    while (digitalRead(preButton[3]));
    runTests();
    return 1;
  }
}

//Starts the timer
void startGame() {
  Timer1.restart();                             //Restart the timer
  Timer1.attachInterrupt(time_tick, period);    //Attatch time_tick to the timer interupt
  Serial.println("START");
}

void all_lights_off() {
  for (uint8_t i = 0; i < NUM_OF_LIGHTS; i++) {
    digitalWrite(Light[i], HIGH);
  }
}
void all_lights_on() {
  for (uint8_t i = 0; i < NUM_OF_LIGHTS; i++) {
    digitalWrite(Light[i], LOW);
  }
}
