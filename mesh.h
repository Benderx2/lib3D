#ifndef MESH_H
#define MESH_H

#include "vector.h"

typedef struct {
	unsigned int n; // Number of vertices (0-index)
	vec3 pos, rot; // position and rotation vectors
	vec3* v; // vertices
} mesh;

typedef struct {
	vec3* pos;
	vec3* target;
} camera;

mesh* mesh_create(unsigned int n);

vec3* mesh_vecptr(mesh* ptr, unsigned int id);

int mesh_add(mesh* ptr, unsigned int id, double x, double y, double z);
int mesh_addvec3(mesh* ptr, unsigned int id, vec3* vector);
void mesh_property(mesh* ptr, vec3* pos, vec3* rot);
#endif