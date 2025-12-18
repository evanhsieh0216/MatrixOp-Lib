#ifndef MATRIX_OP_H
#define MATRIX_OP_H

#define SIZE 3

//function declare
//Basic
void matrix_add(float A[SIZE][SIZE], float B[SIZE][SIZE], float Result[SIZE][SIZE]);
void matrix_subtract(float A[SIZE][SIZE], float B[SIZE][SIZE], float Result[SIZE][SIZE]);
void matrix_element_multiply(float A[SIZE][SIZE], float B[SIZE][SIZE], float Result[SIZE][SIZE]);

//Linear
void matrix_multiply(float A[SIZE][SIZE], float B[SIZE][SIZE], float Result[SIZE][SIZE]);
void matrix_transpose(float A[SIZE][SIZE], float Result[SIZE][SIZE]);

//Advanced
float matrix_determinant(float A[SIZE][SIZE]);
void matrix_adjoint(float A[SIZE][SIZE], float Result[SIZE][SIZE]);

//Inverse
int matrix_inverse(float A[SIZE][SIZE], float Result[SIZE][SIZE]);

//Support
void print_matrix(const char* name, float M[SIZE][SIZE]);
void fill_matrix(float M[SIZE][SIZE], float value);

#endif
