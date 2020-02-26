
#include <Arduino.h>
#include <Servo.h>

const int LIGHT_PIN = 13;
const int SERVO_MOVE_DELAY = 10;

class Laser {
  public:
    Laser(int x_pin, int y_pin, int light_pin) {
      X_SERVO.attach(x_pin);  // attaches the x servo on pin 9 to the servo object
      Y_SERVO.attach(y_pin);  // attaches the y servo on pin 6 to the servo object
      LIGHT_PIN = light_pin;
      pinMode(LIGHT_PIN, OUTPUT);

      startUpRoutine();
    }

  private:

    void startUpRoutine() {
      // switch on the laser
      digitalWrite (LIGHT_PIN, HIGH);

      // run the length of the border
      border();

      // then place the servos in the center at the beginning
      X_SERVO.write(c_x);
      Y_SERVO.write(c_y);
    }

    Servo X_SERVO;
    Servo Y_SERVO;
    int LIGHT_PIN;
    current

};
