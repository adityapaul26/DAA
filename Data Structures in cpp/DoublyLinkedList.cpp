#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;
    Node *prev;
    // null constructor
    Node()
    {
        this->data = {};
        this->next = nullptr;
        this->prev = nullptr;
    }

    // This is using inititalizer lists. More efficient
    // Node() : data{}, next(nullptr) {}

    // constructor
    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
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

// instertion functions

template <typename T>
Node<T> *insertAtHead(Node<T> *head, T data)
{
    if (head == nullptr)
    {
        Node<T> *newNode = new Node<T>(data);
        newNode->next = head;
        return newNode;
    }
    Node<T> *newNode = new Node<T>(data);
    newNode->next = head;
    head->prev = newNode;
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
    newNode->prev = temp;
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
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    return head;
}

// deletion functions
template <typename T>
Node<T> *removeHead(Node<T> *head)
{
    if (head == nullptr)
    {
        cout << "linked list is empty!can't delete" << endl;
        return head;
    }
    if (head->next == nullptr) // Only one node in the list
    {
        delete head;
        return nullptr;
    }
    Node<T> *temp = head->next;
    temp->prev = nullptr;
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
    if (head->next == nullptr) // Only one node in the list
    {
        delete head;
        return nullptr;
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
    if (position > getLength(head))
    {
        cout << "invalid position" << endl;
        return head;
    }
    Node<T> *temp = head;
    if (position == 0)
    {
        head = removeHead(head);
        return head;
    }
    if (position == getLength(head))
    {
        head = removeLast(head);
        return head;
    }
    Node<T> *temp2 = head;
    for (int i = 1; i < position - 1; i++)
        temp = temp->next;
    temp2 = temp->next;
    temp->next = temp2->next;
    temp2->next->prev = temp2->prev;
    delete temp2;
    return head;
}

template <typename T>
Node<T> *display(Node<T> *head)
{
    if (head == nullptr)
        cout << "Empty Linked List!" << endl;
    Node<T> *temp = head;
    cout << "Forewards:";
    while (temp->next != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << " ";
    cout << "nullptr" << endl;

    cout << "Backwards:";
    while (temp->prev != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << temp->data << " ";
    cout << "nullptr" << endl;
}

template <typename T>
Node<T> *reverse(Node<T> *head)
{
    Node<T> *current = head;
    Node<T> *temp = nullptr;
    if (head == nullptr)
    {
        cout << "Empty doubly linked list!" << endl;
        return head;
    }
    while (current)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    return temp->prev;
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
    // display(head);
    head = insertAtMiddle(head, 100, 2);
    // display(head);
    // head = removeHead(head);
    // display(head);
    // head = deletion(head, 5);
    // display(head);
    // cout << getLength(head) << endl;
    head = reverse(head);
    display(head);

    return 0;
}