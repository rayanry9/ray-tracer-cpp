#ifndef RayTracerRay
#define RayTracerRay

#include "object.h"
#include "vector3.h"

namespace {
const int bounces = 30;
}

class Ray : public Object {
 private:
  Vector3 direction;
};

#endif  // !RayTracerRay
