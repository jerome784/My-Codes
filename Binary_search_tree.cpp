/*Kamal is interested in managing a collection of integers using a Binary Search Tree (BST). He wants to write a program that constructs a BST from a given set of integers and then deletes all the nodes with values greater than the average value of all nodes in the BST.*/

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
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert(Node* root, int data) {
    if (root == NULL)
        return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

void inOrderTraversal(Node* root) {
    if (root) {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

int sumNodes(Node* root) {
    if(root==nullptr) return 0;
    return root->data +sumNodes(root->left)+sumNodes(root->right);
    
}

int countNodes(Node* root) {
    if(root==nullptr) return 0;
    return 1+countNodes(root->left)+countNodes(root->right);
}
Node* deletenode(Node* root,int key){
    if(root==nullptr) return root;
    if(key<root->data){
        root->left=deletenode(root->left,key);
    }
    else if(root->data<key){
        root->right=deletenode(root->right,key);
    }
    else{
        if(root->left==nullptr){
            Node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==nullptr){
            Node* temp=root->left;
            free(root);
            return temp;
        }
        Node* temp=root->right;
        while(temp && temp->left!=nullptr)
            temp=temp->left;
            root->data=temp->data;
            root->right=deletenode(root->right,temp->data);
            
    }
        return root;
    
}

void deleteGreaterThanAverage(Node** root, int avg) {
    if(*root==nullptr) return;
    deleteGreaterThanAverage(&(*root)->left,avg);
    deleteGreaterThanAverage(&(*root)->right,avg);
    
    if((*root)->data>avg){
        *root=deletenode(*root,(*root)->data);
        
    }
    
}

int main() {
    Node* root = NULL;
    int n, data;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> data;
        root = insert(root, data);
    }

    int sum = sumNodes(root);
    int count = countNodes(root);
    int avg = count ? sum / count : 0;
    deleteGreaterThanAverage(&root, avg);
    inOrderTraversal(root);
    return 0;
}