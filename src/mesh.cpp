#include <iostream>
#include "mesh.h"


// load a simple pyramid mesh
void mesh::loadMesh()
{
	// Create vertices
	verts.push_back(glm::vec3(-1, 0, 1));
	verts.push_back(glm::vec3(1, 0, 1));
	verts.push_back(glm::vec3(1, 0, -1));
	verts.push_back(glm::vec3(-1, 0, -1));
	verts.push_back(glm::vec3(0, 3, 0));

	// Create index triangles
	// base
	tInd.push_back(glm::ivec3(2, 1, 0));
	tInd.push_back(glm::ivec3(3, 2, 0));
	// sides
	tInd.push_back(glm::ivec3(0, 1, 4));
	tInd.push_back(glm::ivec3(1, 2, 4));
	tInd.push_back(glm::ivec3(2, 3, 4));
	tInd.push_back(glm::ivec3(3, 0, 4));
}

void mesh::printStats()
{
	cout << "Number of vertices: " << verts.size() << endl;
	cout << "Number of faces: " << tInd.size() << endl;
	cout << "Mesh size: " << ((verts.size()*sizeof(glm::vec3) + tInd.size()*sizeof(glm::ivec3)) / 1024) << " KB" << endl;
}

// calculate direction of normal face
void mesh::calcNormal()
{
	for (auto tri : tInd)
	{
		glm::vec3 v0 = verts[tri[0]];
		glm::vec3 v1 = verts[tri[1]];
		glm::vec3 v2 = verts[tri[2]];
		// calculate centroid of triangle
		tCentroid.push_back(((float)1.0 / 3) * (v0 + v1 + v2));

		glm::vec3 e1 = v1 - v0;
		glm::vec3 e2 = v2 - v1;
		// calculate normal direction
		tNormal.push_back(glm::cross(e1, e2));
	}
}