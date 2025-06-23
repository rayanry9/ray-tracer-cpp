#pragma once

#include <ostream>
class Vector3 {
 private:
  double e[3]{};

 public:
  Vector3(double x = 0.0, double y = 0.0, double z = 0.0);

  double x() const;
  double y() const;
  double z() const;

  Vector3& operator+=(const Vector3& v);

  Vector3& operator-=(const Vector3& v);

  Vector3 operator-() const;

  double length() const;

  double angle(const Vector3& v) const;

  Vector3 normalise() const;

  double dot(const Vector3& v) const;

  Vector3 cross(const Vector3& v) const;

  friend std::ostream& operator<<(std::ostream& out, const Vector3& vec);

  friend Vector3 operator+(const Vector3& v1, const Vector3& v2);
  friend Vector3 operator+(const Vector3& v1, const double& scalar);
  friend Vector3 operator-(const Vector3& v1, const Vector3& v2);
  friend Vector3 operator-(const Vector3& v1, const double& scalar);
  friend Vector3 operator*(const Vector3& v1, const double& scalar);
  friend Vector3 operator/(const Vector3& v1, const double& scalar);
};
