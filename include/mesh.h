#pragma once

#include "color.h"
#include "object.h"
#include "ray.h"
#include "vector3.h"

class Mesh : public Object {
 private:
  const Color color;

 public:
  Mesh(const Vector3& pos = Vector3{}, const Color& col = Color{});

  const Color& getColor() const;
  virtual bool doesRayIntersect(const Ray& ray) const = 0;
};
