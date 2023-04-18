#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k;
    float a[20][20], l[20][20], u[20][20], sum = 0.0;

    printf("Enter the order of matrix: ");
    scanf("%d", &n);

    printf("Enter the elements of matrix\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }

    for (j = 1; j <= n; j++)
    {
        for (i = j; i <= n; i++)
        {
            sum = 0.0;
            for (k = 1; k <= j - 1; k++)
            {
                sum = sum + l[i][k] * u[k][j];
            }
            l[i][j] = a[i][j] - sum;
        }

        for (i = j; i <= n; i++)
        {
            sum = 0.0;
            for (k = 1; k <= j - 1; k++)
            {
                sum = sum + l[j][k] * u[k][i];
            }
            u[j][i] = (a[j][i] - sum) / l[j][j];
        }
    }

    printf("\nL Decomposition:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i >= j)
            {
                printf("%f ", l[i][j]);
            }
            else
            {
                printf("0.0 ");
            }
        }
        printf("\n");
    }

    printf("\nU Decomposition:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i <= j)
            {
                printf("%f ", u[i][j]);
            }
            else
            {
                printf("0.0 ");
            }
        }
        printf("\n");
    }

    return 0;
}