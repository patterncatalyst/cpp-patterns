#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

struct Shape {
  virtual string str() const = 0;
};

struct Circle : Shape {
  float radius;

  Circle() {}

  explicit Circle(const float radius) : radius{radius} {}

  void resize(float factor) { radius *= factor; }

  string str() const override {
    ostringstream oss;
    oss << "A circle of radius " << radius;
    return oss.str();
  }
};

struct Square : Shape {
  float side;

  Square() {}

  explicit Square(const float side) : side{side} {}

  string str() const override {
    ostringstream oss;
    oss << "A square of with side " << side;
    return oss.str();
  }
};

struct ColoredShape : Shape {
  // we are decorating/extending a shape
  Shape &shape;
  // and add a color
  string color;

  ColoredShape(Shape &shape, const string &color) : shape{shape}, color{color} {}

  string str() const override {
    ostringstream oss;
    // shape could be a circle or a square
    oss << shape.str() << " has the color " << color;
    return oss.str();
  }
};

struct TransparentShape : Shape {
  // we are decorating/extending a shape
  Shape &shape;
  // and add transparency.
  uint8_t transparency;

  TransparentShape(Shape &shape, const uint8_t transparency)
      : shape{shape}, transparency{transparency} {}

  string str() const override {
    ostringstream oss;
    // shape could be a circle or a square
    oss << shape.str() << " has " << static_cast<float>(transparency) / 255.f * 100.f
        << "% transparency";
    return oss.str();
  }
};

int main() {
  Circle circle{5};
  cout << circle.str() << endl;

  ColoredShape red_circle{circle, "red"};
  cout << red_circle.str() << endl;

  TransparentShape red_half_visible_circle{red_circle, 128};
  cout << red_half_visible_circle.str() << endl;

  // Oops! Unfortunately this does not work!
  // red_half_visible_circle.resize();

  return 0;
}
