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
    else root->right = insertNode(root->right, x);
    return root;
}

Node* searchRecursive(Node* root, int key) {
    if (root == NULL || root->data == key) return root;
    if (key < root->data) return searchRecursive(root->left, key);
    else return searchRecursive(root->right, key);
}

Node* searchIterative(Node* root, int key) {
    Node* temp = root;
    while (temp != NULL) {
        if (temp->data == key) return temp;
        if (key < temp->data) temp = temp->left;
        else temp = temp->right;
    }
    return NULL;
}

Node* findMin(Node* root) {
    if (root == NULL) return NULL;
    while (root->left != NULL) root = root->left;
    return root;
}

Node* findMax(Node* root) {
    if (root == NULL) return NULL;
    while (root->right != NULL) root = root->right;
    return root;
}

Node* inorderSuccessor(Node* root, int key) {
    Node* target = searchIterative(root, key);
    if (target == NULL) return NULL;

    if (target->right != NULL)
        return findMin(target->right);

    Node* succ = NULL;
    Node* p = root;
    while (p != target) {
        if (key < p->data) {
            succ = p;
            p = p->left;
        } else {
            p = p->right;
        }
    }
    return succ;
}

Node* inorderPredecessor(Node* root, int key) {
    Node* target = searchIterative(root, key);
    if (target == NULL) return NULL;

    if (target->left != NULL)
        return findMax(target->left);

    Node* pred = NULL;
    Node* p = root;
    while (p != target) {
        if (key > p->data) {
            pred = p;
            p = p->right;
        } else {
            p = p->left;
        }
    }
    return pred;
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

    int key = 40;

    cout << "Recursive Search: ";
    if (searchRecursive(root, key)) cout << "Found\n";
    else cout << "Not Found\n";

    cout << "Iterative Search: ";
    if (searchIterative(root, key)) cout << "Found\n";
    else cout << "Not Found\n";

    cout << "Minimum: " << findMin(root)->data << endl;
    cout << "Maximum: " << findMax(root)->data << endl;

    Node* succ = inorderSuccessor(root, key);
    Node* pred = inorderPredecessor(root, key);

    if (succ) cout << "Inorder Successor of " << key << ": " << succ->data << endl;
    else cout << "No Successor\n";

    if (pred) cout << "Inorder Predecessor of " << key << ": " << pred->data << endl;
    else cout << "No Predecessor\n";

    return 0;
}
