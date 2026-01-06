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

int main()
{

    return 0;
}