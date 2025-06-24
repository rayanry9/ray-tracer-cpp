#include "sphere.h"

#include <cmath>
#include <optional>
#include <tuple>

#include "color.h"
#include "mesh.h"
#include "ray.h"
#include "vector3.h"

Sphere::Sphere(const Vector3& pos, const Color& col, const double& rad)
    : Mesh(pos, col), radius{rad} {};

const double& Sphere::getRadius() const { return radius; }

std::optional<std::tuple<Vector3, Vector3>> Sphere::rayIntersection(
    const Ray& ray) const {
  const Vector3& co = this->getPosition();
  const Vector3& o = ray.getPosition();
  const Vector3& d = ray.getDirection();

  const Vector3 oc = o - co;

  const double a = d.dot(d);
  const double b = 2.0 * oc.dot(d);
  const double c = oc.dot(oc) - std::pow(this->getRadius(), 2);

  double discriminant = b * b - 4 * a * c;

  if (discriminant > 0) {
    discriminant = std::sqrt(discriminant);
    const double t1 = (-b + discriminant) / (2 * a);
    const double t2 = (-b - discriminant) / (2 * a);

    if (t1 <= 0 || t2 <= 0) {
      return std::nullopt;
    }

    if (t1 < t2) {
      return std::make_tuple((o + d * t1), (o + d * t1 - co).normalise());
    } else {
      return std::make_tuple((o + d * t2), (o + d * t2 - co).normalise());
    }
  } else {
    return std::nullopt;
  }
}
