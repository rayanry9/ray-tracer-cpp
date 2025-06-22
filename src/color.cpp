#include "color.h"

Color::Color(const int& r, const int& g, const int& b) : c{r, g, b} {};

std::ostream& operator<<(std::ostream& out, const Color& c) {
  return out << c.c[0] << ' ' << c.c[1] << ' ' << c.c[2] << '\n';
};
