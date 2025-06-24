#include "light.h"

#include "object.h"

Light::Light(const Vector3& pos, double str) : Object{pos}, strength{str} {};
const double Light::getStrength() const { return strength; };
