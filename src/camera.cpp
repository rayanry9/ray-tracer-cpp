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

Camera::Camera(const Vector3& pos, const Vector3& look_at, const Vector3& left,
               const double ar, const int width, const double f)
    : Object{pos},
      direction((look_at - pos).normalise()),
      aspect_ratio{ar},
      image_width{width},
      image_height{int(width / ar)},
      pixels{ulong(width), std::vector<Color>(image_height)},
      fov{f},
      viewport_top_left(
          pos + direction.normalise() +
          (left.normalise() * (double(image_width) / image_height) *
           std::tan(std::numbers::pi * fov / 360)) +
          (left.cross(direction).normalise() *
           std::tan(std::numbers::pi * fov / 360))),
      viewport_delta_down(-left.cross(direction).normalise() * 2.0 *
                          std::tan(std::numbers::pi * fov / 360) /
                          image_height),
      viewport_delta_right(
          -left.normalise() * 2.0 * (double(image_width) / image_height) *
          std::tan(std::numbers::pi * fov / 360) / image_width) {
        // std::clog << viewportTopLeft << " " << viewportDeltaDown << ' '
        //           << viewportDeltaRight << '\n'
        //           << imageWidth << ' ' << imageHeight << '\n'
        //           << std::tan(std::numbers::pi * fov / 360) << '\n';
      };

void Camera::castRays(const World& world) {
  // std::clog << viewportDeltaDown * imageHeight << ' '
  //           << viewportDeltaRight * imageWidth << '\n';
  for (int j = 0; j < image_height; j++) {
    for (int i = 0; i < image_width; i++) {
      pixels[i][j] = Ray{this->getPosition(),
                         viewport_top_left + viewport_delta_right * i +
                             viewport_delta_down * j - this->getPosition(),
                         Color{0, 0, 139} * (1 - double(j) / image_height) +
                             Color{173, 216, 230} * (double(j) / image_height)}
                         .cast(world)
                         .getColor();
    }
  }
}

void Camera::printImage() const {
  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
  for (int j = 0; j < image_height; j++) {
    for (int i = 0; i < image_width; i++) {
      std::cout << pixels[i][j];
    }
  }
}
