#include "ray.h"

#include <functional>

#include "color.h"
#include "mesh.h"
#include "vector3.h"
#include "world.h"

Ray::Ray(const Vector3& pos, const Vector3& dir, const Color& col)
    : Object{pos}, direction(dir), color{col} {};

const Color& Ray::getColor() const { return color; }

void Ray::setColor(const Color& col) { color = col; };

const Vector3& Ray::getDirection() const { return direction; }

Ray& Ray::cast(const World& world) {
  for (const std::reference_wrapper<Mesh>& mesh : world.getMeshList()) {
    if (mesh.get().doesRayIntersect(*this)) {
      this->setColor(mesh.get().getColor());
    }
  }
  return *this;
}
