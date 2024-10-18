//Sita is working on implementing a binary search tree (BST). She wants to write functions to insert nodes into the BST, delete nodes from the BST (the number of nodes she wants to delete and then request the values of those nodes), and perform an in-order traversal of the BST to display the updated BST. 



//Help her in implementing the function to delete the specified nodes.

//Input format :
//The first line of input consists of an integer N, representing the number of nodes to be inserted into the BST.

//The second line consists of N space-separated integers, representing the values of the nodes to be inserted into the BST.

//The third line consists of an integer M, representing the number of nodes to delete.

//The fourth line consists of M space-separated integers key, representing the values of the nodes to be deleted from the BST.
// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to insert a node into the BST
Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
Node* minValueNode(Node* node){
    Node* current=node;
    
    while(current && current->left!=nullptr){
        current=current->left;
    }
    return current;
}
Node* deleteNode(Node* root, int key) {
    if(root==nullptr){
        return nullptr;
    }
    if(key<root->data){
        root->left=deleteNode(root->left,key);
    }
    else if(key>root->data){
        root->right=deleteNode(root->right,key);
    }
    else{
        if(root->left==nullptr){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==nullptr){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        Node* temp=minValueNode(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
        
    }
    return root;
    
}

int main() {
    Node* root = nullptr;
    int n, data;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> data;
        root = insert(root, data);
    }

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> data;
        root = deleteNode(root, data);
    }

    inorderTraversal(root);

    return 0;
}