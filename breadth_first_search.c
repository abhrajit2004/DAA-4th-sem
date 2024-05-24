#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size, front, rear;
    int *arr;
};

int isEmpty(struct queue *q)
{
    if (q->front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct queue *q)
{
    if (q->rear == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct queue *q, int data)
{
    if (isFull(q))
    {
        printf("This Queue is full\n");
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = data;
    }
}

int dequeue(struct queue *q)
{

    int a = -1;
    if (isEmpty(q))
    {
        printf("This Queue is empty\n");
    }
    else
    {
        q->front++;
        a = q->arr[q->front];
    }

    return a;
}

int main()
{
    struct queue q;
    q.size = 400;
    q.front = q.rear = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // BFS main logic

    int node;
    int i = 1;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int adj[7][7] = {{0, 1, 1, 1, 0, 0, 0},
                     {1, 0, 1, 0, 0, 0, 0},
                     {1, 1, 0, 1, 1, 0, 0},
                     {1, 0, 1, 0, 1, 0, 0},
                     {0, 0, 1, 1, 0, 1, 1},
                     {0, 0, 0, 0, 1, 0, 0},
                     {0, 0, 0, 0, 1, 0, 0}};

                     
    printf("%d", i);
    visited[i] = 1;
    enqueue(&q, i);

    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if (adj[node][j] == 1 && visited[j] == 0)
            {
                printf("%d", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
    return 0;
}