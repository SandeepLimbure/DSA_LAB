#include "ll.h"
#include <iostream>
using namespace std;

int main()
{
    LinkedList list;
    int choice;
    int element;

    do {
        cout << "\n==============================\n";
        cout << "      LINKED LIST MENU        \n";
        cout << "==============================\n";
        cout << "1. Add Node at End\n";
        cout << "2. Delete Node from End\n";
        cout << "3. Display List\n";
        cout << "4. Exit\n";
        cout << "==============================\n";

        cout << "Enter your choice (1-4): \n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter integer value to add: ";
                cin >> element;
        
                list.setHead(list.addNode(list.getHead(), element));
                cout << "Element added successfully.\n";
                break;

            case 2:
                list.setHead(list.DeleteNode(list.getHead()));
                break;

            case 3:
                list.display(list.getHead());
                break;

            case 4:
                cout << "Exiting program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Please choose an option between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;
}
