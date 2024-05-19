#include <stdio.h>

int main()
{
    int profit[] = {100, 80, 60, 40, 20};
    int weight[] = {2, 3, 4, 5, 6};
    float x[5];
    int remaining = 20, i, p = 0;
    for (i = 0; i < 5; i++)
    {
        x[i] = 0.0;
    }
    for (i = 0; i < 5; i++)
    {
        if (weight[i] > remaining)
        {
            break;
        }
        x[i] = 1.0;
        remaining -= weight[i];
        p += profit[i];
    }
    if (i <= 5)
    {
        x[i] = (float)remaining / weight[i];
        p += profit[i] * x[i];
    }
    printf("Maximum profit: %d", p);
    return 0;
}