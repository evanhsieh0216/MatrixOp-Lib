#include "matrix_op.h"
#include <stdio.h>
#include <math.h>
#define EPSILON 1e-6f

//Basic
void matrix_add(float A[SIZE][SIZE], float B[SIZE][SIZE], float Result[SIZE][SIZE])
{
  for(int i = 0; i < SIZE; i++)
    {
      for(int j = 0; j < SIZE; j++)
        {
          Result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void matrix_subtract(float A[SIZE][SIZE], float B[SIZE][SIZE], float Result[SIZE][SIZE])
{
  for(int i = 0; i < SIZE; i++)
    {
      for(int j = 0; j < SIZE; j++)
        {
          Result[i][j] = A[i][j] - B[i][j];
        }
    }
}

void matrix_element_multiply(float A[SIZE][SIZE], float B[SIZE][SIZE], float Result[SIZE][SIZE])
{
  for(int i = 0; i < SIZE; i++)
    {
      for(int j = 0; j < SIZE; j++)
        {
          Result[i][j] = A[i][j] * B[i][j];
        }
    }
}

//Linear
void matrix_multiply(float A[SIZE][SIZE], float B[SIZE][SIZE], float Result[SIZE][SIZE])
{
  for(int i = 0; i < SIZE; i++)
    {
      for(int j = 0; j < SIZE; j++)
        {
          Result[i][j] = 0.0f;

          for(int k = 0; k < SIZE; k++)
            {
              Result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void matrix_transpose(float A[SIZE][SIZE], float Result[SIZE][SIZE])
{
  for(int i = 0; i < SIZE; i++)
    {
      for(int j = 0; j < SIZE; j++)
        {
          Result[j][i] = A[i][j];
        }
    }  
}

//Advanced
float matrix_determinant(float A[SIZE][SIZE])
{
  float term1 = A[0][0] * A[1][1] * A[2][2];
  float term2 = A[0][1] * A[1][2] * A[2][0];
  float term3 = A[0][2] * A[1][0] * A[2][1];

  float positive_sum = term1 + term2 + term3;

  float term4 = A[0][2] * A[1][1] * A[2][0];
  float term5 = A[0][0] * A[1][2] * A[2][1];
  float term6 = A[0][1] * A[1][0] * A[2][2];

  float negative_sum = term4 + term5 + term6;

  return positive_sum - negative_sum;
}

void matrix_adjoint(float A[SIZE][SIZE], float Result[SIZE][SIZE])
{
  float CofactorMatrix[SIZE][SIZE];

  for(int i = 0; i < SIZE; i++)
    {
      for(int j = 0; j < SIZE; j++)
        {
          float minor_val;

          if (i == 0 && j == 0) 
            {
                minor_val = A[1][1] * A[2][2] - A[1][2] * A[2][1];
            }
          else if (i == 0 && j == 1) 
            {
                minor_val = A[1][0] * A[2][2] - A[1][2] * A[2][0];
            }
          else if (i == 0 && j == 2) 
            {
                minor_val = A[1][0] * A[2][1] - A[1][1] * A[2][0];
            }
          else if (i == 1 && j == 0) 
            {
                minor_val = A[0][1] * A[2][2] - A[0][2] * A[2][1];
            }
          else if (i == 1 && j == 1) 
            {
                minor_val = A[0][0] * A[2][2] - A[0][2] * A[2][0];
            }
          else if (i == 1 && j == 2) 
            {
                minor_val = A[0][0] * A[2][1] - A[0][1] * A[2][0];
            }
          else if (i == 2 && j == 0) 
            {
                minor_val = A[0][1] * A[1][2] - A[0][2] * A[1][1];
            }
          else if (i == 2 && j == 1) 
            {
                minor_val = A[0][0] * A[1][2] - A[0][2] * A[1][0];
            }
          else 
            {
                minor_val = A[0][0] * A[1][1] - A[0][1] * A[1][0];
            }
          if ((i + j) % 2 != 0) {
                CofactorMatrix[i][j] = -minor_val;
            } else {
                CofactorMatrix[i][j] = minor_val;
            }
        }
    }  
  for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            Result[i][j] = CofactorMatrix[j][i];
        }
    }
}

//Inverse
int matrix_inverse(float A[SIZE][SIZE], float Result[SIZE][SIZE])
{
   float det = matrix_determinant(A);

  if(fabs(det) < EPSILON) //determinant == 0
  {
    return 0;
  }

  float Adj[SIZE][SIZE];
  matrix_adjoint(A, Adj);

  float inverse_det = 1.0f / det;

  for(int i = 0; i < SIZE; i++)
    {
      for(int j = 0; j < SIZE; j++)
        {
          Result[i][j] = Adj[i][j] * inverse_det;
        }
    }

  return 1;
}

void print_matrix(const char* name, float M[SIZE][SIZE])
{
  printf("Matrix %s:\n", name);
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
      {
        printf("%8.2f ", M[i][j]);
      }
    printf("\n");
  }
  printf("\n");
}

void fill_matrix(float M[SIZE][SIZE], float value) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            M[i][j] = value;
        }
    }
}
