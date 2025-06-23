#pragma once

#include <functional>
#include <vector>

#include "camera.h"

class Mesh;
class Object;

class World {
 private:
  std::vector<Camera> cameraList;
  std::vector<std::reference_wrapper<Mesh>> meshList;
  std::vector<Object> lightList;

 public:
  World();
  const std::vector<std::reference_wrapper<Mesh>>& getMeshList() const;
  void addMesh(Mesh& mesh);
};
