#include <stdio.h>

#define n2  3

float L[3][3];
float U[3][3];

void printMatrix(int n, float A[][n2]) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%f ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void luFactorization(int n, float A[][n2]) {
    int i, j, k;
    

    // Initialize L and U matrices
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                L[i][j] = 1;
            } else {
                L[i][j] = 0;
            }
            U[i][j] = A[i][j];
        }
    }

    // Perform Gaussian elimination
    for (k = 0; k < n - 1; k++) {
        for (i = k + 1; i < n; i++) {
            float factor = U[i][k] / U[k][k];
            L[i][k] = factor;
            for (j = k; j < n; j++) {
                U[i][j] = U[i][j] - factor * U[k][j];
            }
        }
    }

    printf("L matrix:\n");
    printMatrix(n, L);

    printf("U matrix:\n");
    printMatrix(n, U);
}

int main(){
	float A[n2][n2];

	for(int i = 0;i<n2;i++){
		for(int j = 0;j<n2;j++){
			scanf("%f",&A[i][j]);
		}
	}

	float b[n2][1];
	for(int i = 0;i<n2;i++){
		scanf("%f",&b[i][0]);
	}

	for(int i = 0;i<n2;i++){
		printf("%f\n",b[i][0]);
	}
	luFactorization(n2,A);


	float y[n2];
	for(int i = 0;i<n2;i++){
		y[i] = b[0][i];
		printf("Hi , %f\n",y[i]);
		for(int j = 0;j<i;j++){
			y[i] -= L[i][j]*y[j];
		}
	}

	printf("Hello World");

	for(int i = 0;i<n2;i++){
		printf("%f\n",y[i]);
	}

	float x[n2];
	for(int i = n2-1;i>=0;i--){
		x[i] = y[i];
		for(int j = i;j<n2;j++){
			if(i == j){
				continue;
			}
			x[i] -= U[i][j]*x[j]; 
		}
		x[i] /= U[i][i];
	}
	printf("\n\n\n");
	for(int i = 0;i<n2;i++){
		printf("%f\n",x[i]);
	}


	return 0;
}