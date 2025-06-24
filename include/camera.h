#pragma once

#include <vector>

#include "color.h"
#include "object.h"
#include "vector3.h"

class World;

class Camera : public Object {
 private:
  const double aspect_ratio;
  const int image_width;
  const int image_height;
  const Vector3 direction;
  const double fov;
  const Vector3 viewport_top_left;
  const Vector3 viewport_delta_right;
  const Vector3 viewport_delta_down;

  std::vector<std::vector<Color>> pixels;

 public:
  Camera(const Vector3& pos = Vector3{},
         const Vector3& direction = Vector3{1, 0, 0},
         const Vector3& left = Vector3{0, -1, 0},
         const double aspect_ratio = 16.0 / 9, const int image_width = 400,
         const double fov = 90);

  void castRays(const World& world);
  void printImage() const;
};
