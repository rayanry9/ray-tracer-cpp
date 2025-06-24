#pragma once

#include <optional>
#include <tuple>

#include "color.h"
#include "mesh.h"
#include "vector3.h"

class Sphere : public Mesh {
 private:
  const double radius;

 public:
  Sphere(const Vector3& pos = Vector3{}, const Color& col = Color{},
         const double& rad = 1.0);

  std::optional<std::tuple<Vector3, Vector3>> rayIntersection(
      const Ray& ray) const override;
  const double& getRadius() const;
};
