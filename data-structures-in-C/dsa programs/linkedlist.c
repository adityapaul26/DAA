#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
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
        ptr = ptr->next;
        create(ptr);
    }
}

void deletion(struct Node *ptr, int key)
{
    struct Node *loc;
    while (ptr && ptr->data == key)
    {
        loc = ptr;
        ptr = ptr->next;
        free(loc);
        // head = ptr;
    }

    head = ptr;
    while (ptr && ptr->next != NULL)
    {
        if (ptr->next->data == key)
        {
            loc = ptr->next;
            ptr->next = loc->next;
            free(loc);
        }
        else
            ptr = ptr->next;
    }
}

void display(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}

int main()
{
    head = (struct Node *)malloc(sizeof(struct Node));
    create(head);
    display(head);
    printf("\n");
    deletion(head, 1);
    display(head);
    return 0;
}