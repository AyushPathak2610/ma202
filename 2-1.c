#include <stdio.h>
#include <math.h>

int main()
{
    double a = 3.99;
    int m = 1000;
    double arr[1001];
    arr[0] = 0.95005;
    // // for (double a = 0; a <= 4; a += 0.2)
    // // {
        for (int i = 1; i <= 1000; i++)
        {
            arr[i] = a * (1 - arr[i - 1]) * arr[i - 1];
        }
        printf("[");
        for (int i = 0; i <= 50; i++)
        {
            
            printf("%lf,", arr[i]);
        }
        printf("]");
        printf("\n");
        printf("[");
        for (int i = 950; i <= 1000; i++)
        {
            
            printf("%lf,", arr[i]);
        }
        printf("]");
    //     printf("\n\n");
    // }

    // arr[0] = 0.9;
    // // for (double a = 0; a <= 4; a += 0.2)
    // // {
    //     for (int i = 1; i <= 100; i++)
    //     {
    //         arr[i] = a * (1 - arr[i - 1]) * arr[i - 1];
    //     }
    //     printf("[");
        
    //     for (int i = 0; i <= 100; i++)
    //     {
    //         printf("%lf,", arr[i]);
    //     }
    //     printf("]");
    //     printf("\n\n");
    // }
    return 0;
}