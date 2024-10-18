//Kishore is studying data structures, and he is currently working on implementing a binary search tree (BST) and exploring its basic operations. He wants to practice creating a BST, inserting elements into it, and performing a specific operation, which is deleting the minimum element from the tree.



//Write a program to help him perform the delete operation.
// You are using GCC
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

Node* insert(Node* root, int data) {
    if (root == nullptr)
        return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

Node* minValueNode(Node* node) {
    Node* current=node;
    
    while(current && current->left!=nullptr){
        current=current->left;
        return current;
    }
    
}

Node* deleteMin(Node* root) {
    if(root==nullptr) return nullptr;
    
    if(root->left==nullptr){
        Node* temp=root->right;
        free(root);
        return temp;
    }
    
    root->left=deleteMin(root->left);
    return root;
    
}

void inOrderTraversal(Node* root) {
    if (root) {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

int main() {
    Node* root = nullptr;
    int n, data;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> data;
        root = insert(root, data);
    }

    root = deleteMin(root);

    inOrderTraversal(root);
    return 0;
}