/*
File name: F_Tests
Description: Runs tests for the I/O.

Date: Oct 2018
Author: Ante Larsson
For: Scania AB
*/
void runTests() {
  test_lights();
  test_digits();
  test_buttons();
}

void test_lights() {
  Serial.print("TEST: Testing lights...");

  for (uint8_t i = 0; i < NUM_OF_LIGHTS / 2; i++) {
    digitalWrite(Light[i], LOW);
    delay(200);
  }
  for (uint8_t i = 0; i < NUM_OF_LIGHTS / 2; i++) {
    digitalWrite(Light[i], HIGH);
    digitalWrite(Light[NUM_OF_LIGHTS / 2 + i], LOW);
    delay(200);
  }

  for (uint8_t i = NUM_OF_LIGHTS / 2; i < NUM_OF_LIGHTS; i++) {
    digitalWrite(Light[i], HIGH);
    delay(200);
  }

  all_lights_on();
  delay(200);
  all_lights_off();
  delay(200);
  all_lights_on();
  delay(200);
  all_lights_off();


  Serial.println("Done.");
}

void test_digits() {
  for (uint8_t i = 0; i < 10; i++) {
    int temp_i = i + i * 10;
    showNumber(temp_i);
    Serial.println(temp_i);
    delay(500);
  }
  showNumber(digit_time);
}

void test_buttons() {
  test = 1;
  String correctString_buffer = correctString;
  String wrongString_buffer = wrongString;

  Serial.println(correctString);
  Serial.println(wrongString);
  Serial.println("TEST: Testing buttons. Press a button.");

  uint8_t bc = 0;
  while (bc < NUM_OF_BUTTONS) {
    if (game_button_check() > 0) {
      bc++;
      Serial.println("TEST: Press another one.");
    }
  }
  Serial.println("TEST: Done.");
  delay(1000);

  all_lights_off();
  greenCount = 0;
  redCount = 0;
  correctString = correctString_buffer;
  wrongString = wrongString_buffer;
  test = 0;
}


