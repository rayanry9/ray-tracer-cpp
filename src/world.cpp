#include "world.h"

#include <functional>
#include <vector>

#include "light.h"
#include "mesh.h"

World::World() : mesh_list{}, light_list{}, camera_list{} {};

const std::vector<std::reference_wrapper<Mesh>>& World::getMeshList() const {
  return mesh_list;
}
const std::vector<std::reference_wrapper<Light>>& World::getLightList() const {
  return light_list;
}
void World::addMesh(Mesh& mesh) { mesh_list.push_back(mesh); }

void World::addLight(Light& light) { light_list.push_back(light); };
