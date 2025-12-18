#include <stdio.h>
#include "matrix_op.h"

int main()
{
  //Testing matrices 
  float A[SIZE][SIZE]= {{1.0f, 2.0f, 3.0f}, {0.0f, 1.0f, 4.0f}, {5.0f, 6.0f, 0.0f}};
  float B[SIZE][SIZE]= {{7.0f, 8.0f, 9.0f}, {4.0f, 5.0f, 6.0f}, {1.0f, 2.0f, 3.0f}};
  float Result[SIZE][SIZE];

  printf("--- Matrix Operations Test ---\n\n");

  //Testing add
  matrix_add(A, B, Result);
  print_matrix("Addition (A + B)", Result);

  //Testing substract
  matrix_subtract(A, B, Result);
  print_matrix("Subtraction (A - B)", Result);
  
  //Testing element multiply
  matrix_element_multiply(A, B, Result);
  print_matrix("Element-wise Multiply (A .* B)", Result);
  
  //Testing multiply
  matrix_multiply(A, B, Result);
  print_matrix("Matrix Multiplication (A * B)", Result);
  
  //Testing transpose
  matrix_transpose(A, Result);
  print_matrix("Transpose (A^T)", Result);
  
  //Testing determinant
  float det = matrix_determinant(A);
  printf("Determinant of A: %.2f (Expected: 1.00)\n\n", det);
  
  //Testing adjoint
  matrix_adjoint(A, Result);
  print_matrix("Adjoint Matrix of A", Result);
  
  //Testing inverse
  if (matrix_inverse(A, Result)) 
    {
        print_matrix("Inverse of A", Result);
    } else 
      {
        printf("Matrix A is singular, no inverse exists.\n");
      }
  return 0;
}

