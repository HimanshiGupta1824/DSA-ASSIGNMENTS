#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int x) {
    Node* t = new Node;
    t->data = x;
    t->left = NULL;
    t->right = NULL;
    return t;
}

Node* insertNode(Node* root, int x) {
    if (root == NULL) return createNode(x);
    if (x < root->data) root->left = insertNode(root->left, x);
    else if (x > root->data) root->right = insertNode(root->right, x);
    return root;
}

Node* findMin(Node* root) {
    while (root->left != NULL) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int x) {
    if (root == NULL) return root;

    if (x < root->data)
        root->left = deleteNode(root->left, x);

    else if (x > root->data)
        root->right = deleteNode(root->right, x);

    else {
        if (root->left == NULL) {
            Node* t = root->right;
            delete root;
            return t;
        }
        else if (root->right == NULL) {
            Node* t = root->left;
            delete root;
            return t;
        }
        Node* t = findMin(root->right);
        root->data = t->data;
        root->right = deleteNode(root->right, t->data);
    }
    return root;
}

int maxDepth(Node* root) {
    if (root == NULL) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return 1 + (l > r ? l : r);
}

int minDepth(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL) return 1 + minDepth(root->right);
    if (root->right == NULL) return 1 + minDepth(root->left);

    int l = minDepth(root->left);
    int r = minDepth(root->right);
    return 1 + (l < r ? l : r);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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

    cout << "BST (Inorder): ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 30);

    cout << "After deleting 30: ";
    inorder(root);
    cout << endl;

    cout << "Maximum Depth: " << maxDepth(root) << endl;
    cout << "Minimum Depth: " << minDepth(root) << endl;

    return 0;
}
