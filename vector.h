#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <math.h>

#include "wrapper.h"
#include "matrix.h"

#define VEC2 0
#define VEC3 1
#define VEC4 2

typedef struct {
	double x;
	double y;
} vec2;

typedef struct {
	double x;
	double y;
	double z;
} vec3;

typedef struct {
	double x;
	double y;
	double z;
	double w;
} vec4;

vec3 _unitX = { 1.0f, 0.0f, 0.0f };
vec3 _unitY = { 0.0f, 1.0f, 0.0f };
vec3 _unitZ = { 0.0f, 0.0f, 1.0f };

void* vec_create(double x, double y, double z, double w, int type);

double vec_mag(void* vector, int type);

void* vec_not(void* vector, int type);
void* vec_recp(void* vector, int type);

vec2* vec2_add(vec2* v1, vec2* v2);
vec3* vec3_add(vec3* v1, vec3* v2);
vec4* vec4_add(vec4* v1, vec4* v2);

vec2* vec2_sub(vec2* v1, vec2* v2);
vec3* vec3_sub(vec3* v1, vec3* v2);
vec4* vec4_sub(vec4* v1, vec4* v2);

double vec2_dot(vec2* v1, vec2* v2);
double vec3_dot(vec3* v1, vec3* v2);
double vec4_dot(vec4* v1, vec4* v2);

vec3* vec3_cross(vec3* v1, vec3* v2);

void vec_print(void* vector, int type);

vec3* vec3_transcoords(vec3* vector, matrix4* transmat);

vec2* vec3_project(wp_display* disp, vec3* vector, matrix4* transmat);
matrix4* vec3_lookatLH(vec3* eye, vec3* target, vec3* up);

void vec2_draw(wp_display* disp, vec2* vector);

static vec3* vec3_unitX(void) {
	return &_unitX;
}
static vec3* vec3_unitY(void) {
	return &_unitY;
}
static vec3* vec3_unitZ(void) {
	return &_unitZ;
}
#endif