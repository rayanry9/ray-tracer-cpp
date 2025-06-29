#pragma once

#include <optional>
#include <tuple>

#include "color.h"
#include "object.h"
#include "ray.h"
#include "vector3.h"

class Mesh : public Object {
 private:
  const Color color;

 public:
  Mesh(const Vector3& pos = Vector3{}, const Color& col = Color{});

  friend bool operator==(const Mesh& m1, const Mesh& m2);

  virtual const Color& getColor() const;
  virtual std::optional<std::tuple<Vector3, Vector3>> rayIntersection(
      const Ray& ray) const = 0;
};
