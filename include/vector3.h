#ifndef RayTracerVector3
#define RayTracerVector3

class Vector3 {
 private:
  double e[3]{};

 public:
  Vector3(double x = 0.0, double y = 0.0, double z = 0.0);

  const double& x() const;
  const double& y() const;
  const double& z() const;

  Vector3& operator+=(const Vector3& v);

  Vector3& operator-=(const Vector3& v);

  double length() const;

  double angle(const Vector3& v) const;

  Vector3 normalise() const;

  double dot(const Vector3& v) const;

  Vector3 cross(const Vector3& v) const;

  friend Vector3 operator+(const Vector3& v1, const Vector3& v2);
  friend Vector3 operator+(const Vector3& v1, const double& scalar);
  friend Vector3 operator-(const Vector3& v1, const Vector3& v2);
  friend Vector3 operator-(const Vector3& v1, const double& scalar);
  friend Vector3 operator*(const Vector3& v1, const double& scalar);
  friend Vector3 operator/(const Vector3& v1, const double& scalar);
};

#endif  // RayTracerVector3
