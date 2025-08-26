#include <iostream>
using namespace std;

template <typename T>

class Node
{
public:
    T data;
    Node *next;
    // null constructor
    Node()
    {
        this->data = {};
        this->next = nullptr;
    }

    // This is using inititalizer lists. More efficient
    // Node() : data{}, next(nullptr) {}

    // constructor
    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

template <typename T>
int getLength(Node<T> *head)
{
    int count = 0;
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

template <typename T>
Node<T> *insertAtHead(Node<T> *head, T data)
{
    Node<T> *newNode = new Node<T>(data);
    newNode->next = head;
    return newNode;
}

template <typename T>
Node<T> *insertAtEnd(Node<T> *head, T data)
{
    if (head == nullptr)
    {
        Node<T> *newNode = new Node<T>(data);
        newNode->next = head;
        return newNode;
    }
    Node<T> *temp = head;
    Node<T> *newNode = new Node<T>(data);
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

template <typename T>
Node<T> *insertAtMiddle(Node<T> *head, T data, int position)
{
    if (position == 0)
    {
        Node<T> *newNode = new Node<T>(data);
        newNode->next = head;
        return newNode;
    }
    if (position > (getLength(head) + 1))
    {
        cout << "invalid position!" << endl;
        return head;
    }
    Node<T> *temp = head;
    Node<T> *newNode = new Node<T>(data);
    for (int i = 0; i < position - 1; i++)
        temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

template <typename T>
Node<T> *display(Node<T> *head)
{
    if (head == nullptr)
        cout << "Empty Linked List!" << endl;
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

template <typename T>
Node<T> *removeHead(Node<T> *head)
{
    if (head == nullptr)
    {
        cout << "linked list is empty!can't delete" << endl;
        return head;
    }
    Node<T> *temp = head->next;
    delete head;
    return temp;
}

template <typename T>
Node<T> *removeLast(Node<T> *head)
{
    if (head == nullptr)
    {
        cout << "linked list is empty!can't delete" << endl;
        return head;
    }
    Node<T> *temp = head;
    while (temp->next->next != nullptr)
        temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
    return head;
}

template <typename T>
Node<T> *deletion(Node<T> *head, int position)
{
    if (head == nullptr)
    {
        cout << "linked list is empty!can't delete" << endl;
        return head;
    }
    Node<T> *temp = head;
    if (position == 0)
    {
        head = removeHead(head);
        return head;
    }
    Node<T> *temp2 = head;
    for (int i = 1; i < position - 1; i++)
        temp = temp->next;
    temp2 = temp->next;
    temp->next = temp->next->next;
    delete temp2;
    return head;
}

int main()
{
    Node<int> *head = nullptr;
    head = insertAtHead(head, 1);
    head = insertAtHead(head, 2);
    head = insertAtHead(head, 3);
    head = insertAtHead(head, 4);
    display(head);
    head = insertAtEnd(head, 0);
    display(head);
    head = insertAtMiddle(head, 100, 3);
    display(head);
    head = removeHead(head);
    display(head);
    head = removeLast(head);
    display(head);
    head = deletion(head, 2);
    display(head);

    return 0;
}
