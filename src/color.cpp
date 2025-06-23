#include "color.h"

Color::Color(const int& r, const int& g, const int& b) : c{r, g, b} {};

// Color& Color::operator=(const Color& col) {
//   this->c[0] = col.c[0];
//   this->c[1] = col.c[1];
//   this->c[2] = col.c[2];
//   return *this;
// };

Color Color::operator*(double val) {
  return Color{int(c[0] * val) % 256, int(c[1] * val) % 256,
               int(c[2] * val) % 256};
};
Color operator+(const Color& col1, const Color& col2) {
  return Color{(col1.c[0] + col2.c[0]) % 256, (col1.c[1] + col2.c[1]) % 256,
               (col1.c[2] + col2.c[2]) % 256};
};
std::ostream& operator<<(std::ostream& out, const Color& c) {
  return out << c.c[0] << ' ' << c.c[1] << ' ' << c.c[2] << '\n';
};
