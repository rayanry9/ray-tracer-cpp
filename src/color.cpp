#include "color.h"

#include <algorithm>
#include <iostream>
#include <tuple>

Color::Color(const int& r, const int& g, const int& b) : c{r, g, b} {};

Color Color::operator*(double val) {
  return Color{int(c[0] * val) % 256, int(c[1] * val) % 256,
               int(c[2] * val) % 256};
};
Color operator+(const Color& col1, const Color& col2) {
  return Color{(col1.c[0] + col2.c[0]) % 256, (col1.c[1] + col2.c[1]) % 256,
               (col1.c[2] + col2.c[2]) % 256};
};

std::tuple<double, double, double> Color::toHSL() const {
  double r{this->c[0] / 255.0};
  double g{this->c[1] / 255.0};
  double b{this->c[2] / 255.0};

  double min{std::min(std::min(r, g), b)};
  double max{std::max(std::max(r, g), b)};

  double l{(min + max) / 2.0};
  double s{};

  if (l <= 0.5) {
    s = (max - min) / (max + min);
  } else {
    s = (max - min) / (2 - max - min);
  }
  double h{};
  if (max == min) {
    h = 0;
  } else if (max == r) {
    h = (g - b) / (max - min);
  } else if (max == g) {
    h = 2.0 + (b - r) / (max - min);
  } else {
    h = 4.0 + (r - g) / (max - min);
  }
  h *= 60;
  if (h < 0) {
    h += 360;
  }

  return std::make_tuple(h, s, l);
};
Color Color::fromHSL(double h, double s, double l) {
  if (h == 0 || s == 0) {
    return Color{255, 255, 255} * l;
  }

  double temp1{};
  if (l < 0.5) {
    temp1 = l * (1.0 + s);
  } else {
    temp1 = l + s - l * s;
  }

  double temp2{2 * l - temp1};

  h /= 360;

  double r{h + 0.333};
  double g{h};
  double b{h - 0.333};

  if (r < 0) r += 1;
  if (r > 1) r -= 1;

  if (r * 6 < 1) {
    r = temp2 + (temp1 - temp2) * 6 * r;
  } else if (2 * r < 1) {
    r = temp1;
  } else if (3 * r < 2) {
    r = temp2 + (temp1 - temp2) * (0.666 - r) * 6;
  } else {
    r = temp2;
  }

  if (g < 0) g += 1;
  if (g > 1) g -= 1;

  if (g * 6 < 1) {
    g = temp2 + (temp1 - temp2) * 6 * g;
  } else if (2 * g < 1) {
    g = temp1;
  } else if (3 * g < 2) {
    g = temp2 + (temp1 - temp2) * (0.666 - g) * 6;
  } else {
    g = temp2;
  }

  if (b < 0) b += 1;
  if (b > 1) b -= 1;

  if (b * 6 < 1) {
    b = temp2 + (temp1 - temp2) * 6 * b;
  } else if (2 * b < 1) {
    b = temp1;
  } else if (3 * b < 2) {
    b = temp2 + (temp1 - temp2) * (0.666 - b) * 6;
  } else {
    b = temp2;
  }

  return Color{int(r * 255), int(g * 255), int(b * 255)};
};
Color Color::changeLuminance(double l) const {
  double h, s;
  std::tie(h, s, std::ignore) = this->toHSL();

  return Color::fromHSL(h, s, l);
};

std::ostream& operator<<(std::ostream& out, const Color& c) {
  return out << c.c[0] << ' ' << c.c[1] << ' ' << c.c[2] << '\n';
};
