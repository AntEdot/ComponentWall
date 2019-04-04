/*
File name: D_Tick
Description: Main game loop. Checks if buttons are pressed and turning on lights.

Date: Oct 2018
Author: Ante Larsson
For: Scania AB
*/
//Main function in tick. Checks buttons and game over.
void tick() {
  startMeas();

  game_button_check();
  game_over_check();

  stopMeas();
}

//Gets called by the timer. AKA it runs once every second.
void time_tick() {              
  digit_time--;
  showNumber(digit_time);

  if (game_over_flag) {
    back_time++;
    display.showNumberDec(back_time);   //Display the Variable value;
  }

  if (digit_time <= 0) {                //Detach this function from the timer when 0 is reached.
    Timer1.detachInterrupt();
  }
}

uint8_t game_button_check() {                       //Checks if a button is pressed.
  uint8_t preLightCount = (greenCount + redCount);

  for (uint8_t i = 0; i < NUM_OF_BUTTONS; i++) {
    if (digitalRead(Button[i])) {
      String tmpStr = "B";
      if (i < 10) {
        tmpStr += "0";
      }
      tmpStr += String(i);
      points(tmpStr);
    }
  }
  return (greenCount + redCount) - preLightCount;
}

void points(String in) {                            //Checks if the pressed button is correct or worng. 
  int correctIndex = correctString.indexOf(in);     //And turn on the appropriate light.
  int wrongIndex = wrongString.indexOf(in);

  if (correctIndex >= 0) {
    correctString.remove(correctIndex, 3);
    Serial.println(correctString);
    greenCount++;
    greenLight();
    Serial.println(greenCount,DEC);
  }
  if (wrongIndex >= 0) {
    wrongString.remove(wrongIndex, 3);
    Serial.println(wrongString);
    redCount++;
    redLight();
    Serial.println(redCount,DEC);
  }
}

void greenLight() {
  if (test) {
    digitalWrite(Light[greenCount + (NUM_OF_LIGHTS / 2)-1], LOW);
  } else {
    digitalWrite(Light[(greenCount + redCount) + (NUM_OF_LIGHTS / 2)-1], LOW);
  }
}

void greenLightOff() {
  if (test) {
    digitalWrite(Light[greenCount + (NUM_OF_LIGHTS / 2)], HIGH);
  } else {
    digitalWrite(Light[(greenCount + redCount) + (NUM_OF_LIGHTS / 2)], HIGH);
  }
}

void redLight() {
  if (test) {
    digitalWrite(Light[redCount-1], LOW);
  } else {
    digitalWrite(Light[(greenCount + redCount)-1], LOW);
  }
}

void game_over_check() {                                                        //Game is over when the time is up or 8 buttons have been pressed.
  if ((greenCount + redCount) >= (NUM_OF_LIGHTS / 2) || (digit_time <= 0)) {
    game_over();
  }
}

void game_over() {
  game_over_flag = 0;
  rest_red();

  Serial.println("GAME OVER");

  while (1);                        //Program gets stuck in this loop. 
}

void rest_red() {                   //If there are on lit lights turn them red when the time is up.
  while ((greenCount + redCount) < (NUM_OF_LIGHTS / 2)) {
    redCount++;
    redLight();
  }
}

void startMeas() {                  //Measure the length of a game tick.
  preMillis = millis() % 0xffff;
}

void stopMeas() {
  long mil = (millis() - preMillis);
  if (mil > highestMillis) {
    Serial.print("Highest Tick time: ");
    Serial.println(mil);
    highestMillis = mil;
  }
}
