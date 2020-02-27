#ifndef LASER
#define LASER

#include <Arduino.h>
#include <Servo.h>
#include "Point.cpp"

const int LIGHT_PIN = 13;
const int SERVO_MOVE_DELAY = 10;

class Laser {
  public:
    Laser(int x_pin, int y_pin, int light_pin) {
      X_SERVO.attach(x_pin);  // attaches the x servo on pin 9 to the servo object
      Y_SERVO.attach(y_pin);  // attaches the y servo on pin 6 to the servo object
      LIGHT_PIN = light_pin;
      pinMode(LIGHT_PIN, OUTPUT);
    }

    // MOVEMENT

    void moveTo(Point * p, float t) {
      float x_speed = (p->x - pos.x) / t;
      float y_speed = (p->y - pos.y) / t;
      for (float d = 0; d < t; d += 1) {
        pos.x += x_speed;
        pos.y += y_speed;
        X_SERVO.write(pos.x);
        Y_SERVO.write(pos.y);
        delay(SERVO_MOVE_DELAY);
      }
      pos.set(p->x, p->y); // ensure that the current position is the new position
    }

    void curveTo(Point &to, Point &control, float t) {

    }

    void startUpRoutine() {
      // switch on the laser
      digitalWrite (LIGHT_PIN, HIGH);

      // run the length of the border
//      border();

      // then place the servos in the center at the beginning
      Point p = Point();
      p.middle();
      X_SERVO.write(200);
      Y_SERVO.write(250);
    }

  private:

    void border() {
      moveTo(new Point(MIN_X, MIN_Y), 50);
      moveTo(new Point(MIN_X, MAX_Y), 50);
      moveTo(new Point(MAX_X, MAX_Y), 50);
      moveTo(new Point(MAX_X, MIN_Y), 50);
    }

    Servo X_SERVO;
    Servo Y_SERVO;
    int LIGHT_PIN;
    Point pos;

};

#endif
