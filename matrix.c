#include "matrix.h"

matrix4* mat_create(int property) {
	matrix4* mx = calloc(sizeof(matrix4), 1);
	switch(property) {
		case NULL_MATRIX:
			break;
		case IDENTITY_MATRIX:
			mx->data[0][0] = 1;
			mx->data[1][1] = 1;
			mx->data[2][2] = 1;
			mx->data[3][3] = 1;
			break;
		default:
			break;
	}
	return mx;
}
matrix4* mat_dup(matrix4* mx) {
	matrix4* mdup = mat_create(NULL_MATRIX);
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			mdup->data[i][j] = mx->data[i][j]; 
		}
	}
	return mdup;
}
void mat_fill(matrix4* mx, 
				double i11, double i12, double i13, double i14,
				double i21, double i22, double i23, double i24,
				double i31, double i32, double i33, double i34,
				double i41, double i42, double i43, double i44) {
	
	mx->data[0][0] = i11;
	mx->data[0][1] = i12; 
	mx->data[0][2] = i13;
	mx->data[0][3] = i14;
	
	mx->data[1][0] = i21;
	mx->data[1][1] = i22;
	mx->data[1][2] = i23;
	mx->data[1][3] = i24;
	
	mx->data[2][0] = i31;
	mx->data[2][1] = i32;
	mx->data[2][2] = i33;
	mx->data[2][3] = i34;
	
	mx->data[3][0] = i41;
	mx->data[3][1] = i42;
	mx->data[3][2] = i43;
	mx->data[3][3] = i44;
	 
}
void mat_recp(matrix4* mx) {
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			mx->data[i][j] = 1/mx->data[i][j];
		}
	}
}
void mat_not(matrix4* mx) {
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			mx->data[i][j] = -mx->data[i][j];
		}
	}
}
matrix4* mat_add(matrix4* m1, matrix4* m2) {
	matrix4* result = mat_create(NULL_MATRIX);
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			result->data[i][j] = m1->data[i][j] + m2->data[i][j];
		}
	}
	return result;
}
matrix4* mat_multiply(matrix4* m1, matrix4* m2) {
	matrix4* result = mat_create(NULL_MATRIX);
	result->data[0][0] = m1->data[0][0] * m2->data[0][0] + m1->data[0][1] * m2->data[1][0] + m1->data[0][2] * m2->data[2][0] + m1->data[0][3] * m2->data[3][0]; 
	result->data[0][1] = m1->data[0][0] * m2->data[0][1] + m1->data[0][1] * m2->data[1][1] + m1->data[0][2] * m2->data[2][1] + m1->data[0][3] * m2->data[3][1]; 
	result->data[0][2] = m1->data[0][0] * m2->data[0][2] + m1->data[0][1] * m2->data[1][2] + m1->data[0][2] * m2->data[2][2] + m1->data[0][3] * m2->data[3][2]; 
	result->data[0][3] = m1->data[0][0] * m2->data[0][3] + m1->data[0][1] * m2->data[1][3] + m1->data[0][2] * m2->data[2][3] + m1->data[0][3] * m2->data[3][3]; 
	result->data[1][0] = m1->data[1][0] * m2->data[0][0] + m1->data[1][1] * m2->data[1][0] + m1->data[1][2] * m2->data[2][0] + m1->data[1][3] * m2->data[3][0]; 
	result->data[1][1] = m1->data[1][0] * m2->data[0][1] + m1->data[1][1] * m2->data[1][1] + m1->data[1][2] * m2->data[2][1] + m1->data[1][3] * m2->data[3][1]; 
	result->data[1][2] = m1->data[1][0] * m2->data[0][2] + m1->data[1][1] * m2->data[1][2] + m1->data[1][2] * m2->data[2][2] + m1->data[1][3] * m2->data[3][2]; 
	result->data[1][3] = m1->data[1][0] * m2->data[0][3] + m1->data[1][1] * m2->data[1][3] + m1->data[1][2] * m2->data[2][3] + m1->data[1][3] * m2->data[3][3]; 
	result->data[2][0] = m1->data[2][0] * m2->data[0][0] + m1->data[2][1] * m2->data[1][0] + m1->data[2][2] * m2->data[2][0] + m1->data[2][3] * m2->data[3][0]; 
	result->data[2][1] = m1->data[2][0] * m2->data[0][1] + m1->data[2][1] * m2->data[1][1] + m1->data[2][2] * m2->data[2][1] + m1->data[2][3] * m2->data[3][1]; 
	result->data[2][2] = m1->data[2][0] * m2->data[0][2] + m1->data[2][1] * m2->data[1][2] + m1->data[2][2] * m2->data[2][2] + m1->data[2][3] * m2->data[3][2]; 
	result->data[2][3] = m1->data[2][0] * m2->data[0][3] + m1->data[2][1] * m2->data[1][3] + m1->data[2][2] * m2->data[2][3] + m1->data[2][3] * m2->data[3][3]; 
	result->data[3][0] = m1->data[3][0] * m2->data[0][0] + m1->data[3][1] * m2->data[1][0] + m1->data[3][2] * m2->data[2][0] + m1->data[3][3] * m2->data[3][0]; 
	result->data[3][1] = m1->data[3][0] * m2->data[0][1] + m1->data[3][1] * m2->data[1][1] + m1->data[3][2] * m2->data[2][1] + m1->data[3][3] * m2->data[3][1]; 
	result->data[3][2] = m1->data[3][0] * m2->data[0][2] + m1->data[3][1] * m2->data[1][2] + m1->data[3][2] * m2->data[2][2] + m1->data[3][3] * m2->data[3][2]; 
	result->data[3][3] = m1->data[3][0] * m2->data[0][3] + m1->data[3][1] * m2->data[1][3] + m1->data[3][2] * m2->data[2][3] + m1->data[3][3] * m2->data[3][3]; 
	return result;
}
void mat_print(matrix4* mx) {
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			printf("%f\t", mx->data[i][j]);
		}
		printf("\n");
	}
}
matrix4* mat_perspectiveFOV_RH(double fov, double aspect, double znear, double zfar) {
	double yScale = 1.0f / tan(fov/2);
	double q = zfar / (zfar - znear);
	matrix4* result = mat_create(NULL_MATRIX);
	result->data[0][0] = yScale / aspect;
	result->data[1][1] = yScale;
	result->data[2][2] = q;
	result->data[2][3] = -1.0f;
	result->data[3][2] = q * znear;
	return result;
}

matrix4* mat_translation(double x, double y, double z) {
	matrix4* result = mat_create(IDENTITY_MATRIX);
	result->data[3][0] = x;
	result->data[3][1] = y;
	result->data[3][2] = z;
	return result;
}
