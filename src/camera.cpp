#include "camera.h"

#include <cmath>
#include <iostream>
#include <numbers>
#include <vector>

#include "color.h"
#include "object.h"
#include "ray.h"
#include "vector3.h"
#include "world.h"

Camera::Camera(const Vector3& pos, const Vector3& dir, const Vector3& left,
               const double ar, const int width, const double f)
    : Object{pos},
      direction(dir.normalise()),
      aspectRatio{ar},
      imageWidth{width},
      imageHeight{int(width / ar)},
      pixels{ulong(width), std::vector<Color>(imageHeight)},
      fov{f},
      viewportTopLeft(pos + dir.normalise() +
                      (left.normalise() * (double(imageWidth) / imageHeight) *
                       std::tan(std::numbers::pi * fov / 360)) +
                      (left.cross(dir).normalise() *
                       std::tan(std::numbers::pi * fov / 360))),
      viewportDeltaDown(-left.cross(dir).normalise() * 2.0 *
                        std::tan(std::numbers::pi * fov / 360) / imageHeight),
      viewportDeltaRight(-left.normalise() * 2.0 *
                         (double(imageWidth) / imageHeight) *
                         std::tan(std::numbers::pi * fov / 360) / imageWidth) {
  std::clog << viewportTopLeft << " " << viewportDeltaDown << ' '
            << viewportDeltaRight << '\n'
            << imageWidth << ' ' << imageHeight << '\n'
            << std::tan(std::numbers::pi * fov / 360) << '\n';
};

void Camera::castRays(const World& world) {
  std::clog << viewportDeltaDown * imageHeight << ' '
            << viewportDeltaRight * imageWidth << '\n';
  for (int j = 0; j < imageHeight; j++) {
    for (int i = 0; i < imageWidth; i++) {
      pixels[i][j] = Ray{this->getPosition(),
                         viewportTopLeft + viewportDeltaRight * i +
                             viewportDeltaDown * j - this->getPosition(),
                         Color{0, 0, 139} * (1 - double(j) / imageHeight) +
                             Color{173, 216, 230} * (double(j) / imageHeight)}
                         .cast(world)
                         .getColor();
    }
  }
}

void Camera::printImage() const {
  std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";
  for (int j = 0; j < imageHeight; j++) {
    for (int i = 0; i < imageWidth; i++) {
      std::cout << pixels[i][j];
    }
  }
}
