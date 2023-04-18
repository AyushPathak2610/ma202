#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k;
    float a[20][20], l[20][20], u[20][20], b[20], y[20], x[20], sum = 0.0;

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

    printf("Enter the elements of b matrix\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%f", &b[i]);
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
            if (i == j)
            {
                u[i][j] = 1;
            }
            else
            {
                sum = 0.0;
                for (k = 1; k <= j - 1; k++)
                {
                    sum = sum + l[j][k] * u[k][i];
                }
                u[j][i] = (a[j][i] - sum) / l[j][j];
            }
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

    for (i = 1; i <= n; i++)
    {
        sum = 0.0;
        for (j = 1; j <= i - 1; j++)
        {
            sum = sum + l[i][j] * y[j];
        }
        y[i] = (b[i] - sum) / l[i][i];
    }

    for (i = n; i >= 1; i--)
    {
        sum = 0.0;
        for (j = i + 1; j <= n; j++)
        {
            sum = sum + u[i][j] * x[j];
        }
        x[i] = (y[i] - sum) / u[i][i];
    }

    printf("\nSolution:\n");
    for (i = 1; i <= n; i++)
    {
        printf("%f ", x[i]);
    }

    return 0;
}