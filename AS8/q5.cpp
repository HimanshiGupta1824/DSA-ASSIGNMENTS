#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int x) {
    Node* t = new Node;
    t->data = x;
    t->left = t->right = NULL;
    return t;
}

Node* insertNode(Node* root, int x) {
    if (!root) return newNode(x);
    if (x < root->data) root->left = insertNode(root->left, x);
    else root->right = insertNode(root->right, x);
    return root;
}

void inorderNonRecursive(Node* root) {
    stack<Node*> s;
    Node* curr = root;

    while (curr != NULL || !s.empty()) {
        while (curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top(); s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

int main() {
    Node* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 70);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 60);
    insertNode(root, 80);

    cout << "Inorder traversal (non-recursive): ";
    inorderNonRecursive(root);
}
