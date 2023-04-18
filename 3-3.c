#include <stdio.h>

int determinant(int A[3][3], int lam)
{
    int det = 0;
    det = (A[0][0]-1) * ((A[1][1]-1) * (A[2][2]-1) - A[2][1] * A[1][2]) - A[0][1] * (A[1][0] * (A[2][2]-1) - A[2][0] * A[1][2]) + A[0][2] * (A[1][0] * A[2][1] - A[2][0] * (A[1][1]-1));
    return det;
}

int main()
{   
    int lam=1;
    printf("Enter value of lmabda: \n");
    scanf("%d",&lam);
    int A[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    int det = determinant(A,lam);
    printf("The determinant of the Arix is: %d\n", det);
    return 0;
}