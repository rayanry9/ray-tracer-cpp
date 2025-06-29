
#include "camera.h"
#include "color.h"
#include "light.h"
#include "plane.h"
#include "sphere.h"
#include "vector3.h"
#include "world.h"

int main() {
  Camera cam1{Vector3{30, 30, 5},
              Vector3{15, 0, 0},
              Vector3{-1, 0, 0},
              16.0 / 9,
              400,
              75};
  Camera cam2{Vector3{0, 0, 5},
              Vector3{15, 0, 0},
              Vector3{0, -1, 0},
              16.0 / 9,
              400,
              75};
  World world{};

  Sphere s1{Vector3{15, 0, 0}, Color{255, 165, 0}, 6};
  world.addMesh(s1);

  Plane p1{Vector3{40, 0, -6},
           Vector3{1, 0, 0},
           Vector3{0, -1, 0},
           Plane::NormDirection::Positive,
           400,
           400,
           Color{240, 240, 240}};

  world.addMesh(p1);

  Light l1{Vector3{30, 10, 10}};
  world.addLight(l1);

  // cam1.castRays(world);
  // cam1.printImage();
  cam2.castRays(world);
  cam2.printImage();
  return 0;
}
