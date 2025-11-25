#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node{val, head};
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node{val, nullptr};
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void insertBeforeAfter(int target, int val, bool after=true) {
        if (!head) return;
        Node* newNode = new Node{val, nullptr};
        Node* temp = head;

        if (!after && head->data == target) {
            newNode->next = head;
            head = newNode;
            return;
        }

        while (temp && temp->next) {
            if (after && temp->data == target) {
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            if (!after && temp->next->data == target) {
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
    }

    void deleteFromBeginning() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteNode(int key) {
        if (!head) return;
        if (head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != key) temp = temp->next;
        if (temp->next) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    int search(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) return pos;
            temp = temp->next;
            pos++;
        }
        return -1;
    }

    void display() {
        Node* temp = head;
        if (!temp) {
            cout << "List is empty.\n";
            return;
        }
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list;
    int choice, val, key;
    bool after;

    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert Before/After Node\n";
        cout << "4. Delete from Beginning\n5. Delete from End\n6. Delete specific Node\n";
        cout << "7. Search Node\n8. Display List\n9. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                list.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                list.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter target node value: ";
                cin >> key;
                cout << "Enter new value to insert: ";
                cin >> val;
                cout << "Insert after target? (1 for yes, 0 for before): ";
                cin >> after;
                list.insertBeforeAfter(key, val, after);
                break;
            case 4:
                list.deleteFromBeginning();
                break;
            case 5:
                list.deleteFromEnd();
                break;
            case 6:
                cout << "Enter value to delete: ";
                cin >> key;
                list.deleteNode(key);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> key;
                val = list.search(key);
                if (val != -1) cout << "Node found at position: " << val << endl;
                else cout << "Node not found.\n";
                break;
            case 8:
                list.display();
                break;
            case 9:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 9);

    return 0;
}
