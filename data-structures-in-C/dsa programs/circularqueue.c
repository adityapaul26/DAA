#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int size;
    int f;
    int r;
    int *arr;
};

struct Node *q;

void enqueue(struct Node *ptr)
{
    int val;
    printf("ENTER val:");
    scanf("%d", &val);
    if (ptr->f == 0 && ptr->r == ptr->size - 1)
    {
        printf("the queue is full!");
        return;
    }
    else if (ptr->f == -1 && ptr->r == -1)
    {
        ptr->f = ptr->r = 0;
        ptr->arr[ptr->r] = val;
    }
    else if (ptr->r == ptr->size - 1 && ptr->f != 0)
    {
        ptr->r = 0;
        ptr->arr[ptr->r] = val;
    }
    else
    {
        ptr->r++;
        ptr->arr[ptr->r] = val;
    }
}

void dequeue(struct Node *ptr)
{
    if (ptr->f == -1 && ptr->r == -1)
    {
        printf("the queue is empty!!");
    }
    else if (ptr->f == ptr->r)
    {
        ptr->f = -1;
        ptr->r = -1;
    }
    else if (ptr->f == ptr->size - 1)
    {
        ptr->f = 0;
    }
    else
        ptr->f++;
}

void display(struct Node *ptr)
{
    if (ptr->f <= ptr->r)
    {
        for (int i = ptr->f; i <= ptr->r; i++)
        {
            printf("%d ", ptr->arr[i]);
        }
    }
    else
    {
        for (int i = ptr->f; i < ptr->size; i++)
        {
            printf("%d ", ptr->arr[i]);
        }
        for (int i = 0; i < ptr->r; i++)
        {
            printf("%d ", ptr->arr[i]);
        }
    }
}

int main()
{
    q = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the size of the queue:");
    scanf("%d", &q->size);
    q->f = -1;
    q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueue(q);
    enqueue(q);
    enqueue(q);
    enqueue(q);
    enqueue(q);
    enqueue(q);
    display(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    display(q);
}