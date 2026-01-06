#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};

struct Queue *q;

int isEmpty(struct Queue *ptr)
{
    if (ptr->f == -1 && ptr->r == -1)
        return 1;
    return 0;
}

int isFull(struct Queue *ptr)
{
    if (ptr->r == ptr->size - 1)
        return 1;
    return 0;
}

void enqueue(struct Queue *ptr)
{
    if (isFull(ptr))
        printf("The queue is full!");
    else
    {

        if (ptr->f == -1)
            ptr->f = 0;
        // ptr->r++;
        printf("Enter the value:");
        scanf("%d", &ptr->arr[++ptr->r]);
    }
}

void dequeue(struct Queue *ptr)
{
    if (isEmpty(ptr))
        printf("the queue is empty!");
    else
    {
        ptr->f++;
    }
}

void display(struct Queue *ptr)
{
    for (int i = ptr->f; i <= ptr->r; i++)
    {
        printf("%d ", ptr->arr[i]);
    }
}

int main()
{
    q = (struct Queue *)malloc(sizeof(struct Queue));
    q->f = -1;
    q->r = -1;
    q->arr = (int *)malloc(100 * sizeof(int));
    enqueue(q);
    enqueue(q);
    enqueue(q);
    enqueue(q);
    display(q);
    dequeue(q);
    dequeue(q);
    printf("\n");
    display(q);
}