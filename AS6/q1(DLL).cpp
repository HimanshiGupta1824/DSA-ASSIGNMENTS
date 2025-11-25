#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
};
Node* head = NULL;

void insertBegin(int x) {
    Node* n = new Node{x, NULL, head};
    if (head) head->prev = n;
    head = n;
}

void insertEnd(int x) {
    Node* n = new Node{x, NULL, NULL};
    if (!head) head = n;
    else {
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
        n->prev = t;
    }
}

void insertAfter(int key, int x) {
    Node* t = head;
    while (t) {
        if (t->data == key) {
            Node* n = new Node{x, t, t->next};
            if (t->next) t->next->prev = n;
            t->next = n;
            return;
        }
        t = t->next;
    }
}

void insertBefore(int key, int x) {
    if (!head) return;
    if (head->data == key) {
        insertBegin(x);
        return;
    }
    Node* t = head->next;
    while (t) {
        if (t->data == key) {
            Node* n = new Node{x, t->prev, t};
            t->prev->next = n;
            t->prev = n;
            return;
        }
        t = t->next;
    }
}

void deleteNode(int key) {
    Node* t = head;
    while (t) {
        if (t->data == key) {
            if (t == head) {
                head = t->next;
                if (head) head->prev = NULL;
                delete t;
                return;
            }
            if (t->next) t->next->prev = t->prev;
            t->prev->next = t->next;
            delete t;
            return;
        }
        t = t->next;
    }
}

bool searchNode(int key) {
    Node* t = head;
    while (t) {
        if (t->data == key) return true;
        t = t->next;
    }
    return false;
}

void display() {
    Node* t = head;
    if (!t) {
        cout << "Empty\n";
        return;
    }
    while (t) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << "\n";
}

int main() {
    int ch, x, key;
    while (true) {
        cout << "\n1.Insert Begin\n2.Insert End\n3.Insert After\n4.Insert Before\n5.Delete\n6.Search\n7.Display\n8.Exit\n";
        cin >> ch;
        if (ch == 8) break;

        if (ch >= 3 && ch <= 6) {
            cout << "Enter key: ";
            cin >> key;
        }

        if (ch != 5 && ch != 6) {
            if (ch != 7) {
                cout << "Enter value: ";
                cin >> x;
            }
        }

        if (ch == 1) insertBegin(x);
        else if (ch == 2) insertEnd(x);
        else if (ch == 3) insertAfter(key, x);
        else if (ch == 4) insertBefore(key, x);
        else if (ch == 5) deleteNode(key);
        else if (ch == 6) cout << (searchNode(key) ? "Found\n" : "Not Found\n");
        else if (ch == 7) display();
    }
}
