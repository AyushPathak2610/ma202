#include <math.h>
#include <stdio.h>

int main() {
  double A[2][2] = {{0, 1}, {1, 0}};
  double lambda1, lambda2, norm1, norm2;
  double v1[2], v2[2], dot_product;
  int i, j;

  // Find eigenvalues
  lambda1 = sqrt(2);
  lambda2 = -sqrt(2);

  // Find eigenvectors
  v1[0] = v2[1] = 1;
  v1[1] = v2[0] = lambda1 / lambda2;

  // Normalize eigenvectors
  norm1 = sqrt(pow(v1[0], 2) + pow(v1[1], 2));
  norm2 = sqrt(pow(v2[0], 2) + pow(v2[1], 2));
  for (i = 0; i < 2; i++) {
    v1[i] /= norm1;
    v2[i] /= norm2;
  }

  // Print eigenvalues and eigenvectors
  printf("Eigenvalue 1: %f\n", lambda1);
  printf("Eigenvector 1: [%f, %f]\n", v1[0], v1[1]);
  printf("Eigenvalue 2: %f\n", lambda2);
  printf("Eigenvector 2: [%f, %f]\n", v2[0], v2[1]);
  // Check if eigenvectors are orthogonal
  dot_product = 0;
  for (i = 0; i < 2; i++) {
    dot_product += v1[i] * v2[i];
  }
  if (dot_product == 0) {
    printf("The eigenvectors are orthogonal.\n");
  } else {
    printf("The eigenvectors are not orthogonal.\n");
  }
  return 0;
}
