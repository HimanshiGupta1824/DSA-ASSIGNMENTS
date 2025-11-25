#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

bool isCircular() {
    if (head == NULL) 
        return false;

    Node* temp = head->next;

    while (temp != NULL && temp != head) {
        temp = temp->next;
    }

    return (temp == head);
}

int main() {
    Node* n1 = new Node{10, NULL};
    Node* n2 = new Node{20, NULL};
    Node* n3 = new Node{30, NULL};

    head = n1;
    n1->next = n2;
    n2->next = n3;

    if (isCircular())
        cout << "Circular Linked List";
    else
        cout << "Not Circular";

    return 0;
}
