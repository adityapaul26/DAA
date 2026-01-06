#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int size;
    int *arr;
};

struct Stack *s;

int isFull(struct Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    return 0;
}

int isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    return 0;
}

void push(struct Stack *ptr)
{
    if (isFull(ptr))
        printf("stack overflow!!");
    else
    {
        ptr->top++;
        printf("Enter the value:");
        scanf("%d", &ptr->arr[ptr->top]);
    }
}

void pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
        printf("stack underflow!!");
    else
    {
        ptr->top--;
        printf("The element has been popped.");
    }
}

void display(struct Stack *ptr)
{
    if (ptr->top == -1)
        printf("The stack is empty! nothing to display\n");
    else
        for (int i = 0; i <= ptr->top; i++)
        {
            printf("%d ", ptr->arr[i]);
        }
}

int main()
{
    s = (struct Stack *)malloc(sizeof(sizeof(struct Stack)));
    s->top = -1;
    printf("Enter the size of the stack: ");
    scanf("%d", &s->size);
    s->arr = (int *)malloc(s->size * sizeof(int));
    char ch;
    while (1)
    {
        printf("\na->isempty \nb->isfull \nc->push \nd->pop \ne->display \nf->exit\n");
        printf("Enter your choice:");
        scanf(" %c", &ch);
        switch (ch)
        {
        case 'a':
            if (isEmpty(s))
                printf("The stack is empty\n");
            else
                printf("The stack is not empty\n");
            break;
        case 'b':
            if (isFull(s))
                printf("The stack is full\n");
            else
                printf("The stack is not full\n");
            break;
        case 'c':
            push(s);
            break;
        case 'd':
            pop(s);
            break;
        case 'e':
            display(s);
            break;
        case 'f':
            exit(0);
            break;
        }
    }
}