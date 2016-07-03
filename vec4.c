#include "vec4.h"

vec4* vec4_rotation(double yaw, double pitch, double roll) {
	double qx, qy, qz, qw; // Quaternion values
	double sin_yaw, cos_yaw, sin_pitch, cos_pitch, sin_roll, cos_roll;
	
	sin_yaw = sin(yaw/2);
	cos_yaw = cos(yaw/2);
	sin_roll = sin(roll/2);
	cos_roll = cos(roll/2);
	sin_pitch = sin(pitch/2);
	cos_pitch = cos(pitch/2);
	
	qx = (cos_yaw * sin_pitch * cos_roll) + (sin_yaw * cos_pitch * sin_roll);
	qy = (sin_yaw * cos_pitch * cos_roll) - (cos_yaw * sin_pitch * sin_roll);
	qz = (cos_yaw * cos_pitch * sin_roll) - (sin_yaw * sin_pitch * cos_roll);
	qw = (cos_yaw * cos_pitch * cos_roll) + (sin_yaw * sin_pitch * sin_roll);
	
	return vec_create(qx, qy, qz, qw, VEC4);
}
matrix4* vec4_rotmatrix(vec4* quaternion) {
	double xx = quaternion->x * quaternion->x;
	double yy = quaternion->y * quaternion->y;
	double zz = quaternion->z * quaternion->z;
	double xy = quaternion->x * quaternion->y;
	double xz = quaternion->x * quaternion->z;
	double xw = quaternion->x * quaternion->w;
	double yz = quaternion->y * quaternion->z;
	double yw = quaternion->y * quaternion->w;
	double zw = quaternion->z * quaternion->w;
	
	matrix4* mx = mat_create(IDENTITY_MATRIX);
	
	mx->data[0][0] = 1.0f - (2.0f * (yy + zz));
	mx->data[0][1] = 2.0f * (xy + zw);
	mx->data[0][2] = 2.0f * (xz - yw);
	
	mx->data[1][0] = 2.0f * (xy - zw);
	mx->data[1][1] = 1.0f - (2.0f * (zz + xx));
	mx->data[1][2] = 2.0f * (yz + xw);
	
	mx->data[2][0] = 2.0f * (xz + yw);
    mx->data[2][1] = 2.0f * (yz - xw);
	mx->data[2][2] = 1.0f - (2.0f * (yy + xx));
	
	return mx;
}
matrix4* mat_rot_yawpitchroll(double yaw, double pitch, double roll) {
	vec4* tmp = vec4_rotation(yaw, pitch, roll);
	matrix4* result = vec4_rotmatrix(tmp);
	free(tmp);
	return result;
}