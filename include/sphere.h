#pragma once

#include "color.h"
#include "mesh.h"
#include "vector3.h"

class Sphere : public Mesh {
 private:
  const double radius;

 public:
  Sphere(const Vector3& pos = Vector3{}, const Color& col = Color{},
         const double& rad = 1.0);

  bool doesRayIntersect(const Ray& ray) const override;
  const double& getRadius() const;
};
