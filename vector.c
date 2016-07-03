// Simple vector calculation implementation in C.
#include "vector.h"

vec3 _unitX = { 1.0f, 0.0f, 0.0f };
vec3 _unitY = { 0.0f, 1.0f, 0.0f };
vec3 _unitZ = { 0.0f, 0.0f, 1.0f };

// Create a vector (malloc'd) and return value as void*. Free it yourself.
void* vec_create(double x, double y, double z, double w, int type) {
	vec2* myvec2 = NULL;
	vec3* myvec3 = NULL;
	vec4* myvec4 = NULL;
	switch(type) {
		case VEC2:
			myvec2 = calloc(sizeof(vec2), 1);
			myvec2->x = x;
			myvec2->y = y;
			return (void*)myvec2;
		case VEC3:
			myvec3 = calloc(sizeof(vec3), 1);
			myvec3->x = x;
			myvec3->y = y;
			myvec3->z = z;
			return (void*)myvec3;
		case VEC4:
			myvec4 = calloc(sizeof(vec4), 1);
			myvec4->x = x;
			myvec4->y = y;
			myvec4->z = z;
			myvec4->w = w;
			return (void*)myvec4;
		default:
			return NULL;
	}
}
// Gives the magnitude (length) of a vector.
double vec_mag(void* vector, int type) {
	vec2* myvec2 = NULL;
	vec3* myvec3 = NULL;
	vec4* myvec4 = NULL;
	switch(type) {
		case VEC2:
			myvec2 = (vec2*)vector;
			return sqrt(pow(myvec2->x, 2) + pow(myvec2->y, 2));
		case VEC3:
			myvec3 = (vec3*)vector;
			return sqrt(pow(myvec3->x, 2) + pow(myvec3->y, 2) + pow(myvec3->z, 2));
		case VEC4:
			myvec4 = (vec4*)vector;
			return sqrt(pow(myvec4->x, 2) + pow(myvec4->y, 2) + pow(myvec4->z, 2) + pow(myvec4->w, 2));
		default:
			return -1;
	}
}
// Inverse sign of each component.
void* vec_not(void* vector, int type) {
	vec2* myvec2 = NULL;
	vec3* myvec3 = NULL;
	vec4* myvec4 = NULL;
	double x, y, z, w; 
	switch(type) {
		case VEC2:
			myvec2 = (vec2*)vector;
			x = -myvec2->x;
			y = -myvec2->y;
			z = 0;
			w = 0;
			break;
		case VEC3:
			myvec3 = (vec3*)vector;
			x = -myvec3->x;
			y = -myvec3->y;
			z = -myvec3->z;
			w = 0;
			break;
		case VEC4:
			myvec4 = (vec4*)vector;
			x = -myvec4->x;
			y = -myvec4->y;
			z = -myvec4->z;
			w = -myvec4->w;
			break;
		default:
			return NULL;
	}
	return vec_create(x,y,z,w,type);
}
// Take reciprocal of each component
void* vec_recp(void* vector, int type) {
	vec2* myvec2 = NULL;
	vec3* myvec3 = NULL;
	vec4* myvec4 = NULL;
	double x, y, z, w; 
	switch(type) {
		case VEC2:
			myvec2 = (vec2*)vector;
			x = 1/myvec2->x;
			y = 1/myvec2->y;
			z = 0;
			w = 0;
			break;
		case VEC3:
			myvec3 = (vec3*)vector;
			x = 1/myvec3->x;
			y = 1/myvec3->y;
			z = 1/myvec3->z;
			w = 0;
			break;
		case VEC4:
			myvec4 = (vec4*)vector;
			x = 1/myvec4->x;
			y = 1/myvec4->y;
			z = 1/myvec4->z;
			w = 1/myvec4->w;
			break;
		default:
			return NULL;
	}
	return vec_create(x,y,z,w,type);
}
// Normalise (convert to unit vector).
void* vec_normalise(void* vector, int type) {
	vec2* myvec2 = NULL;
	vec3* myvec3 = NULL;
	vec4* myvec4 = NULL;
	double mag = 1.0f;
	switch(type) {
		case VEC2:
			myvec2 = (vec2*)vector;
			mag = vec_mag(myvec2, VEC2);
			return vec_create(myvec2->x/mag, myvec2->y/mag, 0, 0, VEC2);
		case VEC3:
			myvec3 = (vec3*)vector;
			mag = vec_mag(myvec3, VEC3);
			return vec_create(myvec3->x/mag, myvec3->y/mag, myvec3->z/mag, 0, VEC3);
		case VEC4:
			myvec4 = (vec4*)vector;
			mag = vec_mag(myvec4, VEC4);
			return vec_create(myvec4->x/mag, myvec4->y/mag, myvec4->z/mag, myvec4->w/mag, VEC4);
		default:
			return NULL;
	}
	return NULL;
}
// print vector.
void vec_print(void* vector, int type) {
	vec2* myvec2 = NULL;
	vec3* myvec3 = NULL;
	vec4* myvec4 = NULL;
	switch(type) {
		case VEC2:
			myvec2 = (vec2*)vector;
			printf("vec2: x: %f, y: %f\n", myvec2->x, myvec2->y);
			return;
		case VEC3:
			myvec3 = (vec3*)vector;
			printf("vec3: x: %f, y: %f, z: %f\n", myvec3->x, myvec3->y, myvec3->z);
			return;
		case VEC4:
			myvec4 = (vec4*)vector;
			printf("vec4: x: %f, y: %f, z: %f, w: %f\n", myvec4->x, myvec4->y, myvec4->z, myvec4->w);
			return;
		default:
			return;
	}
}
// Addition and subtraction
vec2* vec2_add(vec2* v1, vec2* v2) {
	return (vec2*)vec_create(v1->x + v2->y, v1->y + v2->y, 0, 0, VEC2);
}
vec3* vec3_add(vec3* v1, vec3* v2) {
	return (vec3*)vec_create(v1->x + v2->x, v1->y + v2->y, v1->z + v2->z, 0, VEC3);
}
vec4* vec4_add(vec4* v1, vec4* v2) {
	return (vec4*)vec_create(v1->x + v2->x, v1->y + v2->y, v1->z + v2->z, v1->w + v2->w, VEC4);
}
vec2* vec2_sub(vec2* v1, vec2* v2) {
	vec2* tx = vec_not(v2, VEC2);
	vec2* vx = vec2_add(v1, tx);
	free(tx);
	return vx;
}
vec3* vec3_sub(vec3* v1, vec3* v2) {
	vec3* tx = vec_not(v2, VEC3);
	vec3* vx = vec3_add(v1, tx);
	free(tx);
	return vx;
}
vec4* vec4_sub(vec4* v1, vec4* v2) {
	vec4* tx = vec_not(v2, VEC4);
	vec4* vx = vec4_add(v1, tx);
	free(tx);
	return vx;
}
// Dot Product
double vec2_dot(vec2* v1, vec2* v2) {
	return (v1->x * v2->x + v1->y * v2->y);
}
double vec3_dot(vec3* v1, vec3* v2) {
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}
double vec4_dot(vec4* v1, vec4* v2) {
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z + v1->w * v2->w);
}
// Vector 3 Cross Product.
vec3* vec3_cross(vec3* v1, vec3* v2) {
	return (vec3*)vec_create(v1->y*v2->z - v1->z*v2->y, v1->z*v2->x - v1->x*v2->z, v1->x*v2->y - v1->y*v2->x, 0,  VEC3);
}
// Multiply a 3D vector with a 4x4 homogenous matrix, hence transforming it.
vec3* vec3_transcoords(vec3* vector, matrix4* transmat) {
	vec4* v4 = vec_create(0, 0, 0, 0, VEC4);
	v4->x = vector->x * transmat->data[0][0] + vector->x * transmat->data[1][0] + vector->x * transmat->data[2][0] + transmat->data[3][0];
	v4->y = vector->y * transmat->data[0][1] + vector->y * transmat->data[1][1] + vector->y * transmat->data[2][1] + transmat->data[3][1];
	v4->z = vector->z * transmat->data[0][2] + vector->z * transmat->data[1][2] + vector->z * transmat->data[2][2] + transmat->data[3][2];
	v4->w = 1.0f / (vector->x * transmat->data[0][3] + vector->y*transmat->data[1][3] + vector->z*transmat->data[2][3] + transmat->data[3][3]);
	return vec_create(v4->x * v4->w, v4->y * v4->w, v4->z * v4->w, 0, VEC3);
}

vec2* vec3_project(wp_display* disp, vec3* vector, matrix4* transmat) {
	vec3* tmp = vec3_transcoords(vector, transmat);
	// translate again from 0,0 at center scrn to top left scrn.
	double x = tmp->x * disp->w + disp->w/2;
	double y = tmp->y * disp->h + disp->h/2;
	free(tmp);
	return vec_create(x, y, 0, 0, VEC2);
}

// create a left handed look at perspective.
matrix4* vec3_lookatLH(vec3* eye, vec3* target, vec3* up) {
	vec3 *xaxis, *yaxis, *zaxis;
	// z = target - eye (Depth)
	zaxis = vec3_sub(target, eye);
	zaxis = vec_normalise(zaxis, VEC3);
	// x = up x z
	xaxis = vec3_cross(up, zaxis);
	vec_normalise(xaxis, VEC3);
	yaxis = vec3_cross(xaxis, zaxis);
	// create the identity matrix first so that we can fill in the data.
	matrix4* result = mat_create(IDENTITY_MATRIX);
	result->data[0][0] = xaxis->x;
	result->data[1][0] = xaxis->y;
	result->data[2][0] = xaxis->z;
	
	result->data[0][1] = yaxis->x;
	result->data[1][1] = yaxis->y;
	result->data[2][1] = yaxis->z;
	
	result->data[0][2] = zaxis->x;
	result->data[1][2] = zaxis->y;
	result->data[2][2] = zaxis->z;
	
	result->data[3][0] = -vec3_dot(xaxis, eye);
	result->data[3][1] = -vec3_dot(yaxis, eye);
	result->data[3][2] = -vec3_dot(zaxis, eye);
}

void vec2_draw(wp_display* disp, vec2* vector) {
	if(vector->x >= 0 && vector->y >= 0 && vector->x < disp->h && vector->y < disp->w) {
		wp_pixel(disp, vector->x, vector->y, 255, 255, 255, 1);
	}
}

