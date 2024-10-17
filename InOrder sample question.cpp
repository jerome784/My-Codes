//A company is designing an organizational structure to manage employees hierarchically. Each employee is represented as a node in a binary tree, where each node (positive integer) contains the employee's ID. The organization uses a level-order approach to insert employees into the tree. Each new employee is added to the next available position in the current level of the binary tree.



The system needs to:



Insert new employee's ID positive integers into the organizational structure following a level-order traversal.
Print out the IDs of employees in the organization using an in-order traversal.

// You are using GCC
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

struct BinaryTree {
    Node* root;
};

void insert(BinaryTree* binaryTree, int data, Node** queue, int* front, int* rear) 
{
    Node* newNode=createNode(data);
    if(binaryTree->root==nullptr){
        binaryTree->root=newNode;
    }
    else{
        Node* current=queue[*front];
        if(current->left==nullptr){
            current->left=newNode;
        }
        else if(current->right==nullptr){
            current->right=newNode;
            (*front)++;
        }
    }
    queue[++(*rear)]=newNode;
}

void inOrder(Node* root) 
{
    if(root==nullptr) return;
    
    inOrder(root->left);
    
    cout<<root->data<<" ";
    
    inOrder(root->right);
}

int main() {
    BinaryTree binaryTree;
    binaryTree.root = nullptr;
    Node* queue[100]; 
    int front = 0, rear = -1;

    int i;
    while (true) {
        cin >> i;
        if (i < 1)
            break;
        insert(&binaryTree, i, queue, &front, &rear);
    }

    inOrder(binaryTree.root);
    return 0;
}

