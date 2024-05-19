#include <stdio.h>

void Maxmin(int arr[], int *max, int *min, int l, int h)
{
    int max1, min1;
    if (l == h)
    {
        *max = *min = arr[l];
    }
    else if (l == h - 1)
    {
        if (arr[l] < arr[h])
        {
            *max = arr[h];
            *min = arr[l];
        }
        else
        {
            *max = arr[l];
            *min = arr[h];
        }
    }
    else
    {
        int mid = (l + h) / 2;
        Maxmin(arr, max, min, l, mid);
        Maxmin(arr, &max1, &min1, mid + 1, h);
        if (*max < max1)
        {
            *max = max1;
        }
        if (*min > min1)
        {
            *min = min1;
        }
    }
}
int main()
{
    int arr[20], n, i, max, min;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    Maxmin(arr, &max, &min, 0, n - 1);
    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);
    return 0;
}