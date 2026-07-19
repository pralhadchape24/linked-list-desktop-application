#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <vector>

class LinkedList
{
public:
    LinkedList();
    void insertAtBegin(int value);
    void insertAtEnd(int value);
    void insertAtPos(int value, int pos);

    void deleteAtBegin();
    void deleteAtEnd();
    void deleteAtPos(int pos);

    bool search(int value);
    void clear();

    std::vector<int> getNodes() const;

private:
    struct Node {
        int data;
        Node* next;
        Node(int d) : data(d), next(nullptr) {}
    };

    Node* head;
};

#endif // LINKEDLIST_H

