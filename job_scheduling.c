#include <stdio.h>

int main()
{
    int jobs[20];
    int profit[] = {20, 15, 10, 5, 1};
    int deadlines[20];
    int n = sizeof(profit) / sizeof(profit[0]);
    int i, j, p = 0;
    printf("Enter the deadlines which should be in between the indices of profit array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &deadlines[i]);
    }
    for (i = 0; i < n; i++)
    {
        jobs[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = deadlines[i]; j >= 0; j--)
        {
            if (jobs[j] == -1)
            {
                break;
            }
        }
        if (j >= 1)
        {
            jobs[j] = i;
            printf("job%d ", jobs[j]);
            p += profit[i];
        }
    }
    printf("\nThe maximum profit is: %d", p);
    return 0;
}