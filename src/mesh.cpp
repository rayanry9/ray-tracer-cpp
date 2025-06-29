#include "mesh.h"

#include "color.h"
#include "object.h"
#include "vector3.h"

Mesh::Mesh(const Vector3& pos, const Color& col) : Object{pos}, color{col} {};
const Color& Mesh::getColor() const { return color; }

bool operator==(const Mesh& m1, const Mesh& m2) {
  return (m1.getPosition() == m2.getPosition() && m1.color == m2.color);
};
