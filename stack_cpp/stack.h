
#ifndef STACK_H
#define STACK_H

class stack {
private:
    int top;
    int size;
    int *arr;

public:
    stack(int size);  
    ~stack();      
    bool isEmpty();   
    bool isFull();
    void push(int element);
    void pop();
    void peek();
    void getTop();
    void display();
};

#endif
