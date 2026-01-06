#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head;

struct Node *create(struct Node *ptr)
{
    char ch;
    printf("Enter the value part:");
    scanf("%d", &ptr->data);
    ptr->next = NULL;

    printf("Do you want to continue:");
    scanf(" %c", &ch);

    if (ch == 'y' || ch == 'Y')
    {
        ptr->next = (struct Node *)malloc(sizeof(struct Node));
        ptr->next->prev = ptr;
        ptr = ptr->next;
        create(ptr);
    }
}

void display(struct Node *ptr)
{
    printf("NULL->");
    while (ptr->next != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }

    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->prev;
    }
    printf("NULL");
}

int main()
{
    head = (struct Node *)malloc(sizeof(struct Node));
    head->prev = NULL;
    create(head);
    display(head);
    return 0;
}