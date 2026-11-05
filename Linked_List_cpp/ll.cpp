#include "ll.h"
#include <iostream>
using namespace std;


LinkedList::LinkedList() {
    head = nullptr; 
}


LinkedList::~LinkedList() {
    node *current = head;
    while (current != nullptr) {
        node *nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}


LinkedList::node* LinkedList::addNode(node *head, int element) {
    node *newNode = new node();
    newNode->data = element;
    newNode->next = nullptr;

    if (head == nullptr) {
        return newNode;
    }

    node *temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}


LinkedList::node* LinkedList::DeleteNode(node *head) {
    if (head == nullptr) {
        cout << "List is empty, nothing to delete.\n";
        return nullptr;
    }

    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    node *temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
    return head;
}


void LinkedList::display(node *head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}
