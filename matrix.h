#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <math.h>

#define NULL_MATRIX 0 // Null matrix - All elements are 0.
#define IDENTITY_MATRIX 1

#define MATRIX_GET(mptr, row, col) mptr->data[row][col]

typedef struct {
	// data[row][col]
	double data[4][4];
} matrix4;

matrix4* mat_create(int property);
matrix4* mat_dup(matrix4* mx);

void mat_fill(matrix4* mx, 
				double i11, double i12, double i13, double i14,
				double i21, double i22, double i23, double i24,
				double i31, double i32, double i33, double i34,
				double i41, double i42, double i43, double i44);

void mat_recp(matrix4* mx);
void mat_not(matrix4* mx);

matrix4* mat_add(matrix4* m1, matrix4* m2);
matrix4* mat_multiply(matrix4* m1, matrix4* m2);

void mat_print(matrix4* mx);

matrix4* mat_perspectiveFOV_RH(double FOV, double aspect, double znear, double zfar);
matrix4* mat_translation(double x, double y, double z);

#endif