
#include "plane.h"

#include <cstdlib>
#include <iostream>
#include <optional>
#include <tuple>

#include "color.h"
#include "mesh.h"
#include "vector3.h"

Plane::Plane(const Vector3& pos, const Vector3& up, const Vector3& left,
             Plane::NormDirection norm, double height, double width,
             const Color& col)
    : Mesh{pos, col},
      up{up.normalise()},
      left{left.normalise()},
      normal{norm == Plane::NormDirection::Negative
                 ? up.cross(left).normalise()
                 : left.cross(up).normalise()},
      height{height},
      width{width} {};

std::optional<std::tuple<Vector3, Vector3>> Plane::rayIntersection(
    const Ray& ray) const {
  const Vector3& p = ray.getPosition();
  const Vector3& d = ray.getDirection();
  const double t =
      (this->getPosition().dot(normal) - p.dot(normal)) / d.dot(normal);

  if (t < 0) {
    return std::nullopt;
  }

  const Vector3 intersection = p + d * t;

  const double h = std::abs(intersection.dot(up));
  const double w = std::abs(intersection.dot(left));

  if (h < height && w < width) {
    return std::make_tuple(intersection, normal);
  }
  return std::nullopt;
};
