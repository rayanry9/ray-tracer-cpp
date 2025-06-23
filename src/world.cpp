#include "world.h"

#include <functional>
#include <vector>

#include "mesh.h"

World::World() : meshList{}, lightList{}, cameraList{} {};

const std::vector<std::reference_wrapper<Mesh>>& World::getMeshList() const {
  return meshList;
}
void World::addMesh(Mesh& mesh) { meshList.push_back(mesh); }
