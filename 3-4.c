#include <stdio.h>

int main()
{
    int i, j;
    float lambda, det;
    int A[3][3] = {{1, 0, 0},
                   {0, 1, 0},
                   {0, 0, 1}};

    printf("Enter the value of lambda: ");
    scanf("%f", &lambda);

    det = A[0][0] * ((A[1][1] * A[2][2] - A[2][1] * A[1][2]) - lambda * (A[1][1] - lambda) * (A[2][2] - lambda));
    det = det - A[0][1] * (A[1][0] * (A[2][2] - lambda) - A[2][0] * (A[1][2] - lambda));
    det = det + A[0][2] * (A[1][0] * (A[2][1] - lambda) - A[2][0] * (A[1][1] - lambda));

    printf("The determinant of A - lambda * I is: %f\n", det);

    return 0;
}
