#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void display() {
    if (head == NULL) return;

    Node* temp = head;

    while (temp->next != head) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << temp->data << " ";  
    cout << head->data;         
}

int main() {
    
    Node* n1 = new Node{20, NULL};
    Node* n2 = new Node{100, NULL};
    Node* n3 = new Node{40, NULL};
    Node* n4 = new Node{80, NULL};
    Node* n5 = new Node{60, NULL};

    head = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = head;

    display();

    return 0;
}
