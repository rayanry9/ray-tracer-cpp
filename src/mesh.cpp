#include "mesh.h"

#include "color.h"
#include "object.h"
#include "vector3.h"

Mesh::Mesh(const Vector3& pos, const Color& col) : Object{pos}, color{col} {};
const Color& Mesh::getColor() const { return color; }
