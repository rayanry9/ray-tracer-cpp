#include "ray.h"

#include <functional>

#include "color.h"
#include "mesh.h"
#include "vector3.h"
#include "world.h"

Ray::Ray(const Vector3& pos, const Vector3& dir, const Color& col)
    : Object{pos}, color(col), direction(dir) {};

const Color& Ray::getColor() const { return color; }

void Ray::setColor(const Color& col) { color = col; };

const Vector3& Ray::getDirection() const { return direction; }

void Ray::setHitPosition(const Vector3& pos) { hit_pos = pos; };
bool Ray::isPositionFront(const Vector3& pos) const {
  if (hit_pos.has_value()) {
    return (pos - this->getPosition()).length() <
           (hit_pos.value() - this->getPosition()).length();
  } else {
    return true;
  }
};

Ray& Ray::cast(const World& world) {
  for (const std::reference_wrapper<Mesh>& mesh : world.getMeshList()) {
    auto intersection_opt = mesh.get().rayIntersection(*this);

    if (intersection_opt.has_value()) {
      const auto [pos, norm] = intersection_opt.value();

      if (!isPositionFront(pos)) {
        return *this;
      }
      hit_pos = pos;

      double l{0.0};

      for (auto light : world.getLightList()) {
        Ray toLightSource{pos, (light.get().getPosition() - pos).normalise(),
                          mesh.get().getColor()};
        bool isLightRayIntersected{false};
        for (auto subMesh : world.getMeshList()) {
          if (subMesh == mesh) {
            continue;
          }
          if (subMesh.get().rayIntersection(toLightSource).has_value()) {
            isLightRayIntersected = true;
            break;
          }
        }

        if (isLightRayIntersected) {
          l = 0.2;
        } else {
          const double dot_val =
              norm.dot(-(pos - light.get().getPosition()).normalise());
          if (dot_val < 0) {
            l = 0;
          } else {
            l = dot_val;
          }
        }
      }

      this->setColor(mesh.get().getColor().changeLuminance(l));
    }
  }
  return *this;
}
