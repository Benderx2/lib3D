#include "mesh.h"

mesh* mesh_create(unsigned int n) {
	mesh* ptr = calloc(1, sizeof(mesh));
	ptr->v = calloc(n, sizeof(vec3));
	ptr->n = n;
	return ptr;
}

int mesh_add(mesh* ptr, unsigned int id, double x, double y, double z) {
	if(id < ptr->n) {
		ptr->v[id].x = x;
		ptr->v[id].y = y;
		ptr->v[id].z = z;
	} else {
		return -1; 
	}
	return 0;
}

int mesh_addvec3(mesh* ptr, unsigned int id, vec3* vector) {
	return mesh_add(ptr, id, vector->x, vector->y, vector->z);
}
vec3* mesh_vecptr(mesh* ptr, unsigned int id) {
	if(id < ptr->n) {
		return &ptr->v[id];
	}
	return NULL;
}
void mesh_property(mesh* ptr, vec3* pos, vec3* rot) {
	ptr->pos.x = pos->x;
	ptr->pos.y = pos->y;
	ptr->pos.z = pos->z;
	
	ptr->rot.x = rot->x;
	ptr->rot.y = rot->y;
	ptr->rot.z = rot->z;
}