#ifndef LL_H
#define LL_H

class LinkedList {
public:
    struct node {
        int data;
        node *next;
    };

private:
    node *head;

public:
    LinkedList();  
    ~LinkedList();      
    node* addNode(node *head, int element);
    node* DeleteNode(node *head);
    void display(node *head);
    
    node* getHead() { return head; }
    void setHead(node* newHead) { head = newHead; }
};

#endif
