#pragma once

#include "object.h"
#include "vector3.h"
class World;

class Light : public Object {
 private:
  const double strength;

 public:
  Light(const Vector3& pos = Vector3{}, double strength = 1.0);
  const double getStrength() const;
};
