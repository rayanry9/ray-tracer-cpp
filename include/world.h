#ifndef RayTracerWorld
#define RayTracerWorld

#include <vector>

#include "camera.h"
#include "ray.h"

class World {
 private:
  std::vector<Camera> cameraList;
  std::vector<Object> meshList;
  std::vector<Object> lightList;
  std::vector<Ray> rayList;
};

#endif  // !RayTracerWorld
