#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* insertAtEnd(Node* head, int val) {
    Node* newNode = new Node{val, nullptr};
    if (!head) return newNode;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

void findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (slow) cout << "Middle element: " << slow->data << endl;
}

int main() {
    Node* head = nullptr;
    int n, val;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        head = insertAtEnd(head, val);
    }

    findMiddle(head);
    return 0;
}
