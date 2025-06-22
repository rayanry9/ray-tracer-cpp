#ifndef RayTracerColor
#define RayTracerColor

#include <ostream>
class Color {
 private:
  int c[3]{};

 public:
  Color(const int& r, const int& g, const int& b);

  friend std::ostream& operator<<(std::ostream& out, const Color& c);
};

#endif  // !RayTracerColor
