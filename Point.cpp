
const float MIN_X = 5;
const float MAX_X = 50;
const float MIN_Y = 5;
const float MAX_Y = 35;
const float MIN_DISTANCE = 5;

class Point {
  public:
    Point() {
      // make a random point in the bounds
    }
    
    Point(float x_in, float y_in) {
      x = x_in;
      y = y_in;
    }

    validateDelta(cPoint) {
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

  private:


    int x;
    int y;

};
