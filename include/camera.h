#pragma once

#include <vector>

#include "color.h"
#include "object.h"
#include "vector3.h"

class World;

class Camera : public Object {
 private:
  const double aspectRatio;
  const int imageWidth;
  const int imageHeight;
  const Vector3 direction;
  const double fov;
  const Vector3 viewportTopLeft;
  const Vector3 viewportDeltaRight;
  const Vector3 viewportDeltaDown;

  std::vector<std::vector<Color>> pixels;

 public:
  Camera(const Vector3& pos = Vector3{},
         const Vector3& direction = Vector3{1, 0, 0},
         const Vector3& left = Vector3{0, -1, 0},
         const double aspectRatio = 16.0 / 9, const int imageWidth = 400,
         const double fov = 90);

  void castRays(const World& world);
  void printImage() const;
};
