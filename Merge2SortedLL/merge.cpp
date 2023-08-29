#include <bits/stdc++.h>
using namespace std;
 template <typename T>
 class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };
Node<int> *mergeTwoLists(Node<int> *first, Node<int> *second)
{
    // edge cases
    if (first == NULL)
    {
        return second;
    }
    if (second == NULL)
    {
        return first;
    }
    // first small element pe point karega
    // second large element pe point karega
    if (first->data > second->data)
    {
        swap(first, second);
    }
    Node<int> *newHead = first;
    while (first != NULL && second != NULL)
    {
        Node<int> *temp = NULL;
        while (first != NULL && first->data <= second->data)
        { // manlo bhar nikal gaye to
            temp = first;
            first = first->next;
        }
        // first->data>second->data
        temp->next = second; // jod bhag
        swap(first, second); // first small second large
    }
    return newHead;
}