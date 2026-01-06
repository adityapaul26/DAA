#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void create(struct Node *ptr)
{
    char ch;
    printf("Enter the value:");
    scanf("%d", &ptr->data);
    ptr->next = head;

    printf("do you want to continue:");
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
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = loc->next;
        head = loc->next;
        free(loc);
    }

    while (ptr && ptr->next->next != head)
    {
        if (ptr->next->data == key)
        {
            loc = ptr->next;
            ptr->next = loc->next;
            free(loc);
        }
        else
            ptr = ptr->next;

        if (ptr->next->data == key)
        {
            loc = ptr->next;
            ptr->next = head;
        }
    }
}

void display(struct Node *ptr)
{
    do
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);

    printf("head");
}

int main()
{
    head = (struct Node *)malloc(sizeof(struct Node));
    create(head);
    display(head);
    deletion(head, 1);
    return 0;
}