#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
    int choice, data, size;

    cout << "Enter the initial size of the stack: ";
    cin >> size;
    stack mystack(size);

    do {
        cout << "\n----------------MENU----------------" << endl;
        cout << "1. Push data\n";
        cout << "2. Pop data\n";
        cout << "3. Peek data\n";
        cout << "4. Get top value\n";
        cout << "5. Display stack\n";
        cout << "0. Exit\n"; 
        cout << "--------------------------------------" << endl;

        cout << "Enter your choice: ";
        cin >> choice;


        switch(choice)
        {
            case 1:
                cout << "Enter data to push into stack: ";
                cin >> data;
                mystack.push(data);
                break;
            case 2:
                mystack.pop();
                break;
            case 3:
                mystack.peek();
                break;
            case 4:
                mystack.getTop();
                break;
            case 5:
                mystack.display();
                break;
            case 0:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while(choice != 0);

    return 0;
}
