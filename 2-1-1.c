#include <stdio.h>
#include <math.h>
int main()
{
    int m = 50;
    double nums[50];
    double a = 2.8;
    nums[0] = 0.30;
    for (int i = 1; i < m; i++){
        nums[i] = a * (1.0 - nums[i - 1]) * (nums[i - 1]);
    }
    int count = 0;
    double arr[100];
    int k = 0;
    do
    {
        count = 0;
        double val = a * (1.0 - nums[m - 1 + k]) * nums[m - 1 + k];
        for (int j = m - 1 + k; j > m - 21 + k; j--)
        {
            if (nums[j] != val)
                count++;
        }
        if (count == 20)
        {
            arr[k++] = val;
        }
    } while (count == 20);
    int l = 0;
    while (arr[l] > 0)
    {
        printf("%.10lf ", arr[l]);
        l++;
    }
    return 0;
}
