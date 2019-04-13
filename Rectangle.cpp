#include <iostream>
#include <vector>

using namespace std;

class Rectangle
{
  private:
    double width;
    double height;

    // top left corner
    double x;
    double y;

  public:
    Rectangle(): height(0), width(0), x(0), y(0) {}
    Rectangle(double h, double w): height(h), width(w), x(0), y(0) {}
    Rectangle(double h, double w, double x, double y): height(h), width(w), x(x), y(y) {}

    double getWidth() {return width;}
    double getHeight() {return height;}
    double getX() {return x;}
    double getY() {return y;}

    double getArea()
    {
      return height * width;
    }


    std::vector<Rectangle> splitHorz(double percent)
    {
      double newHeight = (getArea() * percent) / width;
      Rectangle rect1(newHeight, width, x, y);
      Rectangle rect2(height - newHeight, width, x, y + newHeight);

      std::vector<Rectangle> rects = {rect1, rect2};
      return rects;
    }

    std::vector<Rectangle> splitVert(double percent)
    {
      double newWidth = (getArea() * percent) / height;
      Rectangle rect1(height, newWidth, x, y);
      Rectangle rect2(height, width - newWidth, x + newWidth, y);

      std::vector<Rectangle> rects = {rect1, rect2};
      return rects;
    }

    std::string toString()
    {
      return "Rect:[height=" + std::to_string(height) + ", width=" + std::to_string(width) + ", x=" + std::to_string(x) + ", y=" + std::to_string(y) + "]";
    }
};
