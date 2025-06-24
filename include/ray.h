#pragma once

#include <optional>

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
  std::optional<Vector3> hit_pos;

 public:
  Ray(const Vector3& pos, const Vector3& dir, const Color& color);

  const Color& getColor() const;
  void setColor(const Color& col);
  Ray& cast(const World& world);
  const Vector3& getDirection() const;

  void setHitPosition(const Vector3& pos);
  bool isPositionFront(const Vector3& pos) const;
};
