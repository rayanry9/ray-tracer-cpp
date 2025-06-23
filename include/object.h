#pragma once

#include "vector3.h"

class Object {
 private:
  Vector3 position;

 public:
  Object(Vector3 pos = Vector3{});

  const Vector3& getPosition() const;
  void setPosition(const Vector3& pos);
};
