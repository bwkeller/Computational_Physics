#include <iostream>

using namespace std;

struct linkedlist {
    float data;
    struct linkedlist *next;
};

int main() {
    struct linkedlist *head, *tail;

    head = NULL; // the very first element in our linked list
    tail = NULL; // the very last element in our linked list
    cout << "Enter positive data values (0 to end, -1 to see current list, -2 to delete element):" << endl;
    while(true) {
        float data;

        cin >> data;
        // Action: exit program
        if (data == 0) exit(0);
        // Action: add new list element
        if (data > 0) {
            struct linkedlist *newitem = new linkedlist;
            newitem->data = data;
            newitem->next = NULL;
            if (tail != NULL) {
                tail->next = newitem;
            }
            tail = newitem;
            if (head == NULL) {
                head = newitem;
            }
        } 
        // Action (Default): list all current list elements
        else if (data == -1) {
            struct linkedlist *current;
            int n;
               
            current = head;
            for (n=0;current!=NULL;n++) {
                cout << "data[" << n << "] = " << current->data << endl;
                current = current->next;
            }
        }
        else if (data == -2) {
            /*
             * You need to write some code here to remove an element from the linked list.
             * Think about which pointers you will need to update to do this.
             */
        }
    }
}
