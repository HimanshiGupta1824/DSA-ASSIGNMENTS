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

int countAndDelete(Node*& head, int key) {
    int count = 0;
    Node* temp = head;
    Node* prev = nullptr;
    while (temp) {
        if (temp->data == key) {
            count++;
            if (prev) prev->next = temp->next;
            else head = temp->next;
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
    return count;
}

void display(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;
    int n, val, key;

    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        head = insertAtEnd(head, val);
    }

    cout << "Enter key to count and delete: ";
    cin >> key;

    int count = countAndDelete(head, key);
    cout << "Occurrences: " << count << endl;
    cout << "List after deletion: ";
    display(head);

    return 0;
}
