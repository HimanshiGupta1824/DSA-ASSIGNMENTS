#include <iostream>
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
    if (root == NULL) return newNode(x);
    if (x < root->data) root->left = insertNode(root->left, x);
    else root->right = insertNode(root->right, x);
    return root;
}

bool isBSTUtil(Node* root, int minVal, int maxVal) {
    if (root == NULL) return true;
    if (root->data <= minVal || root->data >= maxVal) return false;
    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, -1000000, 1000000);
}

int main() {
    Node* root = NULL;
    int n, x;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insertNode(root, x);
    }

    if (isBST(root)) cout << "The tree IS a BST";
    else cout << "The tree is NOT a BST";
}
