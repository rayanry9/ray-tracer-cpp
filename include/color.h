#pragma once

#include <ostream>
#include <tuple>
class Color {
 private:
  int c[3]{};

 public:
  Color(const int& r = 0, const int& g = 0, const int& b = 0);

  std::tuple<double, double, double> toHSL() const;
  Color changeLuminance(double l) const;
  static Color fromHSL(double h, double s, double l);

  Color operator*(double val);
  friend Color operator+(const Color& col1, const Color& col2);

  friend std::ostream& operator<<(std::ostream& out, const Color& c);
};
