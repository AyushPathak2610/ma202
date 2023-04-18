#include <stdio.h>
#include <math.h>


double determinant(double a[3][3]) {
  double det = a[0][0] * ((a[1][1] * a[2][2]) - (a[2][1] * a[1][2])) -
               a[0][1] * (a[1][0] * a[2][2] - a[2][0] * a[1][2]) +
               a[0][2] * (a[1][0] * a[2][1] - a[2][0] * a[1][1]);
  return det;
}

double f(double lambda, double a[3][3]) {
  double b[3][3];
  int i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (i == j) b[i][j] = a[i][j] - lambda;
      else b[i][j] = a[i][j];
    }
  }
  return determinant(b);
}

int main() {
  double a[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  double xl = -2.0, xu = 2.0, xr;
  int i = 0;
  
  while (i < 100) {
    xr = (xl + xu) / 2;
    if (f(xr, a) == 0.0) break;
    else if (f(xr, a) * f(xl, a) < 0) xu = xr;
    else xl = xr;
    i++;
  }
  
  printf("The root of the function is: %.6lf\n", xr);
  
  return 0;
}

