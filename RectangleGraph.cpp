#include <iostream>
#include <string>
#include <vector>
#include "Rectangle.cpp"
#include <graphics.h>

using namespace std;

class RectangleGraph
{
  private:
    std::vector<double> data;

  public:
    RectangleGraph(std::vector<double> d): data(d) {}

    double getSum()
    {
      double sum = 0;

      for(int i = 0; i < data.size(); i++)
      {
        sum += data[i];
      }

      return sum;
    }

    int getMaxIndex()
    {
      double max = data[0];
      int index = 0;
      for(int i = 1; i < data.size(); i++)
      {
        if(max < data[i]) {
          max = data[i];
          index = i;
        }
      }

      return index;
    }

    std::vector<Rectangle> graph(Rectangle baseRect)
    {
      std::vector<Rectangle> rects;

      if (data.size() <= 1)
      {
        rects = {baseRect};
        return rects;
      }

      double percent = data[getMaxIndex()] / getSum();

      if(baseRect.getHeight() < baseRect.getWidth())
      {
        rects = baseRect.splitVert(percent);
      }
      else
      {
        rects = baseRect.splitHorz(percent);
      }

      std::vector<double> newData;
      std::copy(data.begin(), data.end(), back_inserter(newData));
      newData.erase(newData.begin() + getMaxIndex());

      RectangleGraph newGrapher(newData);
      std::vector<Rectangle> newRects = newGrapher.graph(rects[1]);

      std::copy(newRects.begin(), newRects.end(), back_inserter(rects));

      rects.erase(rects.begin() + 1);

      return rects;
    }

    void show(double width, double height)
    {
      int gd = DETECT, gm;
      initgraph(&gd,&gm, NULL);


      std::vector<Rectangle> rects = graph(Rectangle(width, height));

      for(Rectangle rect : rects)
      {
        int left = (int) rect.getX(), top = (int) rect.getY();
        int right = (int) (rect.getX() + rect.getWidth()), bottom = (int) (rect.getY() + rect.getHeight());

        rectangle(left, top, right, bottom);
      }

      getch();
      closegraph();
    }

};

int main()
{
   std::vector<double> data = {10, 50, 20, 100, 5, 200, 500, 420, 1, 234, 23, 65, 87, 10, 90, 300};
   RectangleGraph test(data);

   test.show(479, 639);
}
