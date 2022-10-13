#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int f, r;
    int *arr;
    int cap;
};
struct queue *build(int cap)
{
    struct queue *q;
    q = (struct queue *)malloc(sizeof(struct queue));
    q->cap = cap;
    q->f = -1;
    q->r = -1;
    q->arr = (int *)malloc(sizeof(int) * cap);
    return q;
}
int isfull(struct queue *q)
{
    if (q->f == q->r + 1 || (q->f == 0 && q->r == q->cap - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isempty(struct queue *q)
{
    if (q->f == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int dequeue(struct queue *q)
{
    int temp;
    temp = q->arr[q->f];
    if (isempty(q))
    {
        printf("Array empty ");
        return 0;
    }
    else if (q->r == q->f)
    {
        q->r = -1;
        q->f = -1;
    }
    else
    {

        q->f = ((q->f) + 1) % q->cap;
    }
    return temp;
}
struct queue *push(struct queue *q, int data)
{
    if (isfull(q))
    {
        printf("Array full");
        return 0;
    }
    else
    {
        if (q->f == -1)
        {
            q->f = 0;
            q->r = 0;
            q->arr[q->r] = data;
        }
        else
        {
            q->r = (q->r + 1) % q->cap;
            q->arr[q->r] = data;
        }
        return q;
    }
}

void pop(struct queue *q1, struct queue *q2, int size)
{
    while (size != 0)
    {
        if (isempty(q1))
        {
            for (int i = 0; i < (size - 1); i++)
            {
                push(q1, dequeue(q2));
            }
            printf("%d ", dequeue(q2));
        }
        else if (isempty(q2))
        {
            for (int i = 0; i < (size - 1); i++)
            {
                push(q2, dequeue(q1));
            }
            printf("%d ", dequeue(q1));
        }
        size--;
    }
}

void traverse(struct queue *q)
{
    int i;
    i = q->f;
    while (i != q->r)
    {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->cap;
    }
    printf("%d ", q->arr[i]);
}

int main()
{
    int n;
    printf("Enter  number of elements ");
    scanf("%d", &n);
    struct queue *q1;
    q1 = (struct queue *)malloc(sizeof(struct queue));
    q1 = build(5);
    struct queue *q2;
    q2 = (struct queue *)malloc(sizeof(struct queue));
    q2 = build(5);
    for (int i = 0; i < n; i++)
    {
        int data;
        printf("Enter data ");
        scanf("%d", &data);
        q1 = push(q1, data);
    }
    pop(q1, q2, 5);
}