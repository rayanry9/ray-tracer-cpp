#pragma once

#include "color.h"
#include "object.h"
#include "vector3.h"
#include "world.h"

namespace {
const int bounces = 30;
}

class Ray : public Object {
 private:
  Vector3 direction;
  Color color;

 public:
  Ray(const Vector3& pos, const Vector3& dir, const Color& col = Color{});

  const Color& getColor() const;
  void setColor(const Color& col);
  Ray& cast(const World& world);
  const Vector3& getDirection() const;
};
