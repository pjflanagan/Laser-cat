/*
  Forked from: Laser Tower for the CAT - LA FABRIQUE DIY Created 30 Sep 2016 by Lucas Berbesson
  TODO:
    - make it turn on with a button
    - make it run for 5 minutes before turning off
    - make it do a few different random things (shake, flicker, flow through points, just go to a selected point)
*/

#include <Servo.h>

const float MIN_X = 5;
const float MAX_X = 50;
const float MIN_Y = 5;
const float MAX_Y = 35;

const float MINIMAL_MOVEMENT = 5;
const float MIN_MOVE_TIME = 20;
const float MAX_MOVE_TIME = 50;

// find center of square for starting point
float c_x = MIN_X + (MAX_X - MIN_X) / 2;
float c_y = MIN_Y + (MAX_Y - MIN_Y) / 2;

// Instantiating two servos and setting the light pin
Servo X_SERVO;
Servo Y_SERVO;
const int LIGHT_PIN = 13;
const int SERVO_MOVE_DELAY = 10;

//
// SETUP
//

void setup() {
  X_SERVO.attach(9);  // attaches the x servo on pin 9 to the servo object
  Y_SERVO.attach(6);  // attaches the y servo on pin 6 to the servo object
  pinMode (LIGHT_PIN, OUTPUT);
  digitalWrite (LIGHT_PIN, HIGH);  // switch on the laser

  //Place the servos in the center at the beginning
  X_SERVO.write(c_x);
  Y_SERVO.write(c_y);

}

// VALIDATOR

const float MIN_DISTANCE = 5;
void checkMinDistance(float &new_x, float &new_y) {
  if (abs(new_x - c_x) < MIN_DISTANCE) {
    if (new_x > c_x) {
      new_x += MIN_DISTANCE;
    } else {
      new_x -= MIN_DISTANCE;
    }
  }

  if (abs(new_y - c_y) < MIN_DISTANCE) {
    if (new_y > c_y) {
      new_y += MIN_DISTANCE;
    } else {
      new_y -= MIN_DISTANCE;
    }
  }
}

//
// MOVEMENT
//

void to(float x, float y, float t) {
  float x_speed = (x - c_x) / t;
  float y_speed = (y - c_y) / t;
  for (float pos = 0; pos < t; pos += 1) {
    c_x += x_speed;
    c_y += y_speed;
    X_SERVO.write(c_x);
    Y_SERVO.write(c_y);
    delay(SERVO_MOVE_DELAY);
  }
  c_x = x; // ensure that the current position is the new position
  c_y = y;
}

void curve(float x, float y, float x_control, float y_control, float t) {

}

void toRandom() {
  float move_time = random(MIN_MOVE_TIME, MAX_MOVE_TIME);
  float new_x = random(MIN_X + MIN_DISTANCE, MAX_X - MIN_DISTANCE); // this ensures that after we correct for MIN_DISTANCE
  float new_y = random(MIN_Y + MIN_DISTANCE, MAX_Y - MIN_DISTANCE); // we will still not go over the bounds
  checkMinDistance(new_x, new_y);
  to(new_x, new_y, move_time);
}

void path() {

}

void shake() {

}

void border() {
  to(MIN_X, MIN_Y, 50);
  to(MIN_X, MAX_Y, 50);
  to(MAX_X, MAX_Y, 50);
  to(MAX_X, MIN_Y, 50);
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
  toRandom();
  delay(500);
}
