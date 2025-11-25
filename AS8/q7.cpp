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

Node* buildTreeInPost(int inorder[], int postorder[], int inStart, int inEnd, int &postIndex, unordered_map<int,int> &mp) {
    if (inStart > inEnd) return NULL;

    int curr = postorder[postIndex--];
    Node* node = newNode(curr);

    if (inStart == inEnd) return node;

    int inIndex = mp[curr];

    node->right = buildTreeInPost(inorder, postorder, inIndex + 1, inEnd, postIndex, mp);
    node->left = buildTreeInPost(inorder, postorder, inStart, inIndex - 1, postIndex, mp);

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
    int postorderArr[] = {20, 40, 30, 60, 80, 70, 50};
    int n = sizeof(inorderArr)/sizeof(inorderArr[0]);

    unordered_map<int,int> mp;
    for (int i = 0; i < n; i++) mp[inorderArr[i]] = i;

    int postIndex = n - 1;
    Node* root = buildTreeInPost(inorderArr, postorderArr, 0, n-1, postIndex, mp);

    cout << "Inorder traversal of constructed tree: ";
    inorder(root);
}
