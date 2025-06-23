#include "sphere.h"

#include <cmath>
#include <iostream>

#include "color.h"
#include "mesh.h"
#include "ray.h"
#include "vector3.h"

Sphere::Sphere(const Vector3& pos, const Color& col, const double& rad)
    : Mesh(pos, col), radius{rad} {};

const double& Sphere::getRadius() const { return radius; }

bool Sphere::doesRayIntersect(const Ray& ray) const {
  const Vector3& co = this->getPosition();
  const Vector3& o = ray.getPosition();
  const Vector3& d = ray.getDirection();

  const Vector3 oc = co - o;

  const double a = d.dot(d);
  const double b = 2.0 * oc.dot(d);
  const double c = oc.dot(oc) - std::pow(this->getRadius(), 2);

  const double discriminant = b * b - 4 * a * c;

  // std::clog << discriminant << ' ' << oc << ' ' << co << ' ' << o << '\n';

  return discriminant >= 0;
}
