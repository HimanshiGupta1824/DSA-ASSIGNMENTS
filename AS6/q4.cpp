#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void insertEnd(char x) {
    Node* newNode = new Node{x, NULL, NULL};

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

bool isPalindrome() {
    if (head == NULL || head->next == NULL)
        return true;

    Node* left = head;
    Node* right = head;

    while (right->next != NULL)
        right = right->next;

    while (left != right && right->next != left) {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }

    return true;
}

int main() {
    insertEnd('r');
    insertEnd('a');
    insertEnd('c');
    insertEnd('e');
    insertEnd('c');
    insertEnd('a');
    insertEnd('r');

    if (isPalindrome())
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}
