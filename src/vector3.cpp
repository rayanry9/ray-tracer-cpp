#include "vector3.h"

#include <cmath>

Vector3::Vector3(double x, double y, double z) : e{x, y, z} {}

double Vector3::x() const { return e[0]; }
double Vector3::y() const { return e[1]; }
double Vector3::z() const { return e[2]; }

Vector3& Vector3::operator+=(const Vector3& v) {
  this->e[0] += v.e[0];
  this->e[1] += v.e[1];
  this->e[2] += v.e[2];
  return *this;
};

Vector3& Vector3::operator-=(const Vector3& v) {
  this->e[0] -= v.e[0];
  this->e[1] -= v.e[1];
  this->e[2] -= v.e[2];
  return *this;
};

Vector3 Vector3::operator-() const { return Vector3{-e[0], -e[1], -e[2]}; };

double Vector3::length() const {
  return std::sqrt((e[0] * e[0]) + (e[1] * e[1]) + (e[2] * e[2]));
}

double Vector3::angle(const Vector3& v) const {
  return std::acos((this->dot(v)) / (this->length() * v.length()));
}

Vector3 Vector3::normalise() const { return *this / this->length(); }

double Vector3::dot(const Vector3& v) const {
  return (e[0] * v.e[0]) + (e[1] * v.e[1]) + (e[2] * v.e[2]);
}

Vector3 Vector3::cross(const Vector3& v) const {
  return Vector3((e[1] * v.e[2]) - (e[2] * v.e[1]),
                 (e[2] * v.e[0]) - (e[0] * v.e[2]),
                 (e[0] * v.e[1]) - (e[1] * v.e[0]));
}

Vector3 operator+(const Vector3& v1, const Vector3& v2) {
  return Vector3{v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]};
}
Vector3 operator+(const Vector3& v1, const double& scalar) {
  return Vector3{v1.e[0] + scalar, v1.e[1] + scalar, v1.e[2] + scalar};
}

Vector3 operator-(const Vector3& v1, const Vector3& v2) {
  return Vector3{v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]};
}
Vector3 operator-(const Vector3& v1, const double& scalar) {
  return Vector3{v1.e[0] - scalar, v1.e[1] - scalar, v1.e[2] - scalar};
}

Vector3 operator*(const Vector3& v1, const double& scalar) {
  return Vector3(v1.e[0] * scalar, v1.e[1] * scalar, v1.e[2] * scalar);
}
Vector3 operator/(const Vector3& v1, const double& scalar) {
  return Vector3(v1.e[0] / scalar, v1.e[1] / scalar, v1.e[2] / scalar);
}

std::ostream& operator<<(std::ostream& out, const Vector3& vec) {
  return out << vec.e[0] << ' ' << vec.e[1] << ' ' << vec.e[2];
};
