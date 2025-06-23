#include "camera.h"
#include "sphere.h"
#include "vector3.h"
#include "world.h"

int main() {
  Camera cam1{
      Vector3{0, 0, 0}, Vector3{1, 0, 0}, Vector3{0, -1, 0}, 16.0 / 9, 400, 90};
  World world{};
  Sphere s1{Vector3{10, 0, 0}, Color{255, 165, 0}, 4};

  world.addMesh(s1);

  cam1.castRays(world);
  cam1.printImage();
  return 0;
}
