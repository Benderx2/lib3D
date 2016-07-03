#ifndef VEC4_H
#define VEC4_H

#include "vector.h"
#include "matrix.h"

vec4* vec4_rotation(double yaw, double pitch, double roll);
matrix4* vec4_rotmatrix(vec4* quaternion);

matrix4* mat_rot_yawpitchroll(double yaw, double pitch, double roll);
#endif