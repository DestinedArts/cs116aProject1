#pragma once

#include <vector>
#include <glm/gtx/intersect.hpp>

using namespace std;

class mesh
{
	public:
		vector<glm::vec3> verts;
		vector<glm::ivec3> tInd;
		vector<glm::vec3> tCentroid;
		vector<glm::vec3> tNormal;

		void loadMesh();
		void printStats();
		void calcNormal();
};
