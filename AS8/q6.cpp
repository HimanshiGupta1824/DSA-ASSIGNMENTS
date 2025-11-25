#include <iostream>
#include <unordered_map>
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

Node* buildTreePreIn(int preorder[], int inorder[], int inStart, int inEnd, int &preIndex, unordered_map<int,int> &mp) {
    if (inStart > inEnd) return NULL;

    int curr = preorder[preIndex++];
    Node* node = newNode(curr);

    if (inStart == inEnd) return node;

    int inIndex = mp[curr];
    node->left = buildTreePreIn(preorder, inorder, inStart, inIndex - 1, preIndex, mp);
    node->right = buildTreePreIn(preorder, inorder, inIndex + 1, inEnd, preIndex, mp);

    return node;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int inorderArr[] = {20, 30, 40, 50, 60, 70, 80};
    int preorderArr[] = {50, 30, 20, 40, 70, 60, 80};
    int n = sizeof(inorderArr)/sizeof(inorderArr[0]);

    unordered_map<int,int> mp;
    for (int i = 0; i < n; i++) mp[inorderArr[i]] = i;

    int preIndex = 0;
    Node* root = buildTreePreIn(preorderArr, inorderArr, 0, n-1, preIndex, mp);

    cout << "Inorder traversal of constructed tree: ";
    inorder(root);
}
