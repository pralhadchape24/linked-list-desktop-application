#include "linkedlist.h"

LinkedList::LinkedList() : head(nullptr) {}

void LinkedList::insertAtBegin(int value)
{
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void LinkedList::insertAtEnd(int value)
{
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void LinkedList::insertAtPos(int value, int pos)
{
    if (pos <= 1) {
        insertAtBegin(value);
        return;
    }

    Node* newNode = new Node(value);
    Node* temp = head;

    for (int i = 1; temp && i < pos - 1; i++)
        temp = temp->next;

    if (!temp) { // insert at end
        insertAtEnd(value);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void LinkedList::deleteAtBegin()
{
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void LinkedList::deleteAtEnd()
{
    if (!head) return;

    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next)
        temp = temp->next;

    delete temp->next;
    temp->next = nullptr;
}

void LinkedList::deleteAtPos(int pos)
{
    if (pos <= 1) {
        deleteAtBegin();
        return;
    }

    if (!head) return;

    Node* temp = head;
    for (int i = 1; temp->next && i < pos - 1; i++)
        temp = temp->next;

    if (!temp->next) return;

    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
}

bool LinkedList::search(int value)
{
    Node* temp = head;
    while (temp) {
        if (temp->data == value)
            return true;
        temp = temp->next;
    }
    return false;
}

void LinkedList::clear()
{
    while (head)
        deleteAtBegin();
}

std::vector<int> LinkedList::getNodes() const
{
    std::vector<int> nodes;
    Node* temp = head;

    while (temp) {
        nodes.push_back(temp->data);
        temp = temp->next;
    }
    return nodes;
}
