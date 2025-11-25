#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertEnd(int x) {
    Node* newNode = new Node{x, NULL};

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

int listSize() {
    if (head == NULL) return 0;

    int count = 1;
    Node* temp = head->next;

    while (temp != head) {
        count++;
        temp = temp->next;
    }

    return count;
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);

    cout << "Size of Circular Linked List = " << listSize();

    return 0;
}
