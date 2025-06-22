#ifndef RayTracerCamera
#define RayTracerCamera

#include "object.h"
#include "vector3.h"

class Camera : public Object {
 private:
  const double aspectRatio = 16.0 / 9;
  const int imageWidth = 400;
  const int imageHeight = int(imageWidth / aspectRatio);

 public:
  Camera(const Vector3& pos);
};

#endif  // !RayTracerCamera
