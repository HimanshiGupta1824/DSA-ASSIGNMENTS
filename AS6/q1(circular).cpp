#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head = NULL;

void insertBegin(int x) {
    Node* n = new Node{x, NULL};
    if (!head) {
        head = n;
        n->next = n;
    } else {
        Node* t = head;
        while (t->next != head) t = t->next;
        n->next = head;
        t->next = n;
        head = n;
    }
}

void insertEnd(int x) {
    Node* n = new Node{x, NULL};
    if (!head) {
        head = n;
        n->next = n;
    } else {
        Node* t = head;
        while (t->next != head) t = t->next;
        t->next = n;
        n->next = head;
    }
}

void insertAfter(int key, int x) {
    if (!head) return;
    Node* t = head;
    do {
        if (t->data == key) {
            Node* n = new Node{x, t->next};
            t->next = n;
            return;
        }
        t = t->next;
    } while (t != head);
}

void insertBefore(int key, int x) {
    if (!head) return;
    if (head->data == key) {
        insertBegin(x);
        return;
    }
    Node* t = head;
    do {
        if (t->next->data == key) {
            Node* n = new Node{x, t->next};
            t->next = n;
            return;
        }
        t = t->next;
    } while (t != head);
}

void deleteNode(int key) {
    if (!head) return;
    Node *t = head, *p = NULL;
    do {
        if (t->data == key) {
            if (t == head) {
                Node* last = head;
                while (last->next != head) last = last->next;
                if (head->next == head) {
                    head = NULL;
                } else {
                    head = head->next;
                    last->next = head;
                }
                delete t;
                return;
            } else {
                p->next = t->next;
                delete t;
                return;
            }
        }
        p = t;
        t = t->next;
    } while (t != head);
}

bool searchNode(int key) {
    if (!head) return false;
    Node* t = head;
    do {
        if (t->data == key) return true;
        t = t->next;
    } while (t != head);
    return false;
}

void display() {
    if (!head) {
        cout << "Empty\n";
        return;
    }
    Node* t = head;
    do {
        cout << t->data << " ";
        t = t->next;
    } while (t != head);
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
