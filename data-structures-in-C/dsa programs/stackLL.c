#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top;

int isFull(struct Node *ptr)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
        return 1;
    return 0;
}

int isEmpty(struct Node *ptr)
{
    if (ptr == NULL)
        return 1;
    return 0;
}

void push(struct Node *ptr)
{
    int val;
    printf("Enter the value:");
    scanf("%d", &val);
    if (isFull(ptr))
    {
        printf("Stack overflow!!");
        return;
    }

    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = val;
    new->next = ptr;
    top = new;
}

void pop(struct Node *ptr)
{
    if (isEmpty(ptr))
        printf("Stack Underflow!!");
    else
    {
        struct Node *loc = (struct Node *)malloc(sizeof(struct Node));
        loc = ptr;
        ptr = ptr->next;
        top = ptr;
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
    top = NULL;

    char ch;
    while (1)
    {
        printf("\na->isempty \nb->isfull \nc->push \nd->pop \ne->display \nf->exit\n");
        printf("Enter your choice:");
        scanf(" %c", &ch);
        switch (ch)
        {
        case 'a':
            if (isEmpty(top))
                printf("The stack is empty\n");
            else
                printf("top stack is not empty\n");
            break;
        case 'b':
            if (isFull(top))
                printf("The stack is full\n");
            else
                printf("The stack is not full\n");
            break;
        case 'c':
            push(top);
            break;
        case 'd':
            pop(top);
            break;
        case 'e':
            display(top);
            break;
        case 'f':
            exit(0);
            break;
        }
    }
}