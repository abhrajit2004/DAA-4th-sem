#include <stdio.h>
#define INF 99999

void floyd_warshall(int n, int dist[][20])
{
    int i, j, k;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void printResult(int n, int dist[][20])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
            {
                printf("INF ");
            }
            else
            {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    int graph[][20] = {{0, 4, INF, 5, INF},
                       {INF, 0, 1, INF, 6},
                       {2, INF, 0, 3, INF},
                       {INF, INF, 1, 0, 2},
                       {1, INF, INF, 4, 0}};
                       

    floyd_warshall(5, graph);

    printf("The shortest path matrix will be:\n");

    printResult(5, graph);

    return 0;
}