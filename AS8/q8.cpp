#include <iostream>
#include <stack>
#include<vector>
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

void inorder(Node* root, vector<int> &v) {
    if (!root) return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

DNode* mergeSortedArraysToDLL(vector<int> &a, vector<int> &b) {
    vector<int> merged;
    int i = 0, j = 0;
    while(i<a.size() && j<b.size()) {
        if(a[i] < b[j]) merged.push_back(a[i++]);
        else merged.push_back(b[j++]);
    }
    while(i<a.size()) merged.push_back(a[i++]);
    while(j<b.size()) merged.push_back(b[j++]);

    DNode* head = NULL;
    DNode* prev = NULL;
    for(int x : merged) {
        DNode* n = new DNode{x, prev, NULL};
        if(prev) prev->next = n;
        else head = n;
        prev = n;
    }
    return head;
}

void printDLL(DNode* head) {
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* root1 = newNode(10);
    root1->left = newNode(5);
    root1->right = newNode(15);

    Node* root2 = newNode(20);
    root2->left = newNode(16);
    root2->right = newNode(25);

    vector<int> v1, v2;
    inorder(root1, v1);
    inorder(root2, v2);

    DNode* head = mergeSortedArraysToDLL(v1, v2);

    cout << "Merged DLL: ";
    printDLL(head);
}
