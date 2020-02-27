/*
  Forked from: Laser Tower for the CAT - LA FABRIQUE DIY Created 30 Sep 2016 by Lucas Berbesson
  TODO:
    - make it turn on with a button
    - make it run for 5 minutes before turning off
    - make it do a few different random things (shake, flicker, flow through points, just go to a selected point)
*/

#include <Servo.h>
#include "Laser.cpp"

const float MIN_MOVE_TIME = 20;
const float MAX_MOVE_TIME = 50;

Laser laser = Laser(9,6,13);

void setup() {
  laser.startUpRoutine();
    Serial.begin(9600);

}

void toRandom() {
  float move_time = random(MIN_MOVE_TIME, MAX_MOVE_TIME);
  Point * p = new Point();
  laser.moveTo(p, move_time);
}

void path() {

}

void shake() {

}

const int MIN_FLICKS = 8;
const int MAX_FLICKS = 20;
const int MIN_FLICK_TIMEOUT = 30;
const int MAX_FLICK_TIMEOUT = 80;
void flicker() {
  float flick_count = random(MIN_FLICKS, 40);
  bool isOn = true;
  for (float flicks = 0; flicks < flick_count; flicks += 1) {
    int flick_timeout = random(MIN_FLICK_TIMEOUT, MAX_FLICK_TIMEOUT);
    if (isOn) {
      digitalWrite(LIGHT_PIN, LOW);
    } else {
      digitalWrite(LIGHT_PIN, HIGH);
    }
    delay(flick_timeout);
  }
  digitalWrite(LIGHT_PIN, HIGH);  // ensure the laser is on
}

const int MIN_VANISH_TIMEOUT = 500;
const int MAX_VANISH_TIMEOUT = 2000;
void vanish() {
  digitalWrite(LIGHT_PIN, LOW);
  int vanish_timeout = random(MIN_VANISH_TIMEOUT, MAX_VANISH_TIMEOUT);
  digitalWrite(LIGHT_PIN, HIGH);
}

//
// LOOP
//

void loop() {
//  toRandom();
//  delay(500);
}
