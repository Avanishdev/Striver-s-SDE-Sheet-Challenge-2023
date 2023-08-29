#include <iostream>
#include <unordered_map>
using namespace std;
class Node
{
public:
    int key;
    int value;
    Node *prev;
    Node *next;
    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
    }
};
class LRUcache
{
public:
    int capacity;
    // head and tail node with dummy values
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    LRUcache(int capacity)
    {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    // hashmap
    unordered_map<int, Node *> mapping;
    // add node function implement
    void addNode(Node *addNode)
    {

        Node *temp = head->next;

        addNode->next = temp;
        addNode->prev = head;

        head->next = addNode;
        temp->prev = addNode;
    }
    // delete node function implement
    void deleteNode(Node *deleteNode)
    {

        Node *deleteNodePrev = deleteNode->prev;
        Node *deleteNodeNext = deleteNode->next;

        deleteNodePrev->next = deleteNodeNext;

        deleteNodeNext->prev = deleteNodePrev;
    }
    // get(key)=>returns value for key
    int get(int key)
    {
        // find for key if exists
        if (mapping.find(key) != mapping.end())
        {
            // exists
            Node *nodeAddress = mapping[key];   // address ko store karalo
            int nodeValue = nodeAddress->value; // value ko store karalo
            // following code is to implement LRU
            // hashmap se delete karo
            mapping.erase(key);
            // linke list se bhi delete karo
            deleteNode(nodeAddress);
            // linked list me new node add karo
            addNode(nodeAddress);
            // hashmap me new entry karo
            mapping[key] = head->next;
            return nodeValue;
        }
        return -1; // not found
    }
    // push(key,value)
    void put(int key, int value)
    {
        // if already exists
        if (mapping.find(key) != mapping.end())
        {
            // exists
            Node *nodeAddress = mapping[key]; // address store karalo

            mapping.erase(key); // hashmap se bhi erase karao

            deleteNode(nodeAddress); // linked list se delete karao
        }
        // if capacity full
        if (mapping.size() == capacity)
        {
            mapping.erase(tail->prev->key); // hashmap se erase karao uski key

            deleteNode(tail->prev); // linked list se delete
        }
        // creating new Node with key and value
        Node *newNode = new Node(key, value);
        // adding new node to linked list
        addNode(newNode);
        // hashmap me add karo
        mapping[key] = head->next;
    }
};
int main()
{
    LRUcache *obj = new LRUcache(3);
    obj->put(1, 10);
    obj->put(3, 15);
    obj->put(2, 2);
    cout << obj->get(3) << endl;
    obj->put(4, 25);
    cout << obj->get(4) << endl;
    // Another way
    //  LRUcache obj(3);
    //  obj.put(1,10);
    return 0;
}