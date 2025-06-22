#include <iostream>
#include <ostream>

int main() {
  const int image_width{256};
  const int image_height{256};

  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

  for (int j = 0; j < image_height; j++) {
    std::clog << "\rScanlines remaining: " << (image_height - j) << ' '
              << std::flush;
    for (int i = 0; i < image_width; i++) {
    }
  }

  std::clog << "\rDone.                 \n";

  return 0;
}
