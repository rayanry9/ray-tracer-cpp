#pragma once

#include "color.h"
#include "mesh.h"
#include "vector3.h"

class Plane : public Mesh {
 private:
  const Vector3 up;
  const Vector3 left;
  const Vector3 normal;
  const double height;
  const double width;

 public:
  enum class NormDirection { Positive, Negative };

  Plane(const Vector3& pos, const Vector3& up, const Vector3& left,
        NormDirection normal, double height, double width,
        const Color& color = Color{255, 255, 255});

  std::optional<std::tuple<Vector3, Vector3>> rayIntersection(
      const Ray& ray) const override;
};
