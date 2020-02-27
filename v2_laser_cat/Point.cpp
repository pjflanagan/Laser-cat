
#ifndef POINT
#define POINT

#include <Arduino.h>

const float MIN_X = 60;
const float MAX_X = 130;
const float MIN_Y = 10;
const float MAX_Y = 140;
const float MIN_DISTANCE = 5;

class Point {
  public:
    Point() {
      x = random(MIN_X + MIN_DISTANCE, MAX_X - MIN_DISTANCE); // this ensures that after we correct for MIN_DISTANCE
      y = random(MIN_Y + MIN_DISTANCE, MAX_Y - MIN_DISTANCE); // we will still not go over the bounds
    }

    Point(float x_in, float y_in) {
      x = x_in;
      y = y_in;
    }

    // changes the values of newPos to meet the min distance requirement
    void validateDelta(Point &newPos) {
      if (abs(newPos.x - x) < MIN_DISTANCE) {
        if (newPos.x > x) {
          newPos.setX(newPos.x + MIN_DISTANCE);
        } else {
          newPos.setX(newPos.x - MIN_DISTANCE);
        }
      }
      if (abs(newPos.y - y) < MIN_DISTANCE) {
        if (newPos.y > y) {
          newPos.setX(newPos.y + MIN_DISTANCE);
        } else {
          newPos.setX(newPos.y - MIN_DISTANCE);
        }
      }
    }

    void set(float x_in, float y_in) {
      x = x_in;
      y = y_in;
    }

    void middle() {
      x = MIN_X + (MAX_X - MIN_X) / 2;
      y = MIN_Y + (MAX_Y - MIN_Y) / 2;
    }

    float x;
    float y;

  protected:

    void setX(float x_in) {
      x = x_in;
    }

    void setY(float y_in) {
      y = y_in;
    }

  private:


};

#endif
