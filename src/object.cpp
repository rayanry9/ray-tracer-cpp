#include "object.h"

#include "vector3.h"

Object::Object(Vector3 pos) : position(pos) {};

const Vector3& Object::getPosition() const { return position; }
void Object::setPosition(const Vector3& pos) { position = pos; }
