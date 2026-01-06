#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

int isEmpty(struct Node *ptr)
{
    if (head == NULL)
        return 1;
    return 0;
}

int isFull(struct Node *ptr)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    if (new == NULL)
        return 1;
    return 0;
}

void enqueue(struct Node *ptr)
{
    if (isFull(ptr))
        printf("the queue is full!");
    else
    {
        if (head == NULL)
        {
            head = (struct Node *)malloc(sizeof(struct Node));
            printf("Enter the value:");
            scanf("%d", &head->data);
            head->next = NULL;
        }
        else
        {
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = (struct Node *)malloc(sizeof(struct Node));
            printf("Enter the value:");
            scanf("%d", &ptr->next->data);
            ptr->next->next = NULL;
        }
    }
}

void dequeue(struct Node *ptr)
{
    if (isEmpty(ptr))
        printf("The queue is empty!");
    else
    {
        struct Node *loc = ptr;
        head = ptr->next;
        free(loc);
    }
}

void display(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    head = NULL;

    enqueue(head);
    enqueue(head);
    enqueue(head);
    enqueue(head);
    enqueue(head);

    display(head);

    dequeue(head);
    dequeue(head);

    display(head);
}