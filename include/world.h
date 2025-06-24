#pragma once

#include <functional>
#include <vector>

#include "camera.h"
#include "light.h"

class Mesh;

class World {
 private:
  std::vector<Camera> camera_list;
  std::vector<std::reference_wrapper<Mesh>> mesh_list;
  std::vector<std::reference_wrapper<Light>> light_list;

 public:
  World();
  const std::vector<std::reference_wrapper<Mesh>>& getMeshList() const;
  const std::vector<std::reference_wrapper<Light>>& getLightList() const;
  void addMesh(Mesh& mesh);
  void addLight(Light& light);
};
