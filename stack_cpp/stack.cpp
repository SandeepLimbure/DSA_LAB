#include "stack.h"
#include <iostream>
using namespace std;


stack :: stack(int size) {
    this->size = size;
    this->top = -1;
    this->arr = new int[size]; 
    cout << "stack Initialized successfully." << endl;
}

stack :: ~stack() {
    delete[] arr;
}

bool stack :: isEmpty()
{
    if(top == -1)
    {
        return true;
    }
    return false;
}

bool stack :: isFull()
{
    if(top == size-1)
    {
        return true;
    }
    return false;
}

void stack :: push(int data)
{
    if(isFull())
    {
        cout << "stack is full." << endl;
        return;
    }
    arr[++top] = data;
    cout <<"data added successfully." << endl;
}

void stack :: pop()
{
    if(isEmpty())
    {
        cout << "stack is empty." << endl;
        return;
    }
    int data = arr[top];
    top = top-1;
    cout << "top value "<< data << " is successfully deleted from the stack."<< endl;
}

void stack :: peek()
{
    if(isEmpty())
    {
        cout << "stack is empty." << endl;
        return;
    }
    cout << "top value of the stack :"<< arr[top] << endl;
}

void stack :: getTop()
{

    if(isEmpty())
    {
        cout << "stack is empty." << endl;
        return;
    }
    cout << "top value of the stack :"<< top << endl;
}

void stack :: display()
{
    if(isEmpty())
    {
        cout << "stack is empty." << endl;
        return;
    }
    cout << "The stack elements are : "<< endl; 
    for(int i = 0;i<=top;i++)
    {
        cout << arr[i] << " " << endl;
    }
}
