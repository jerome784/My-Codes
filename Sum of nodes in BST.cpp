/*Revi is fascinated by binary search trees (BSTs) and wants to perform some operations on them. He wishes to construct a binary search tree from a series of positive integers and calculate the sum of all the nodes in the BST.



Write a program to help Revi implement these operations using the BST concept.

Input format :
The input consists of a series of positive integers (greater than zero) separated by a space.

The input ends when -1 is entered.

The integers represent the elements to be inserted into the binary search tree.*/
#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Initialize root globally to nullptr
struct node* root = nullptr;

// Function to create a new node
struct node* createNode(int d) {
    node* new_node = new node;
    new_node->data = d;
    new_node->left = new_node->right = nullptr;
    return new_node;
}

// Function to insert a new node into the BST
struct node* insert(struct node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to calculate the sum of all nodes in the BST
int addBST(struct node* root) {
    if (root == nullptr)
        return 0;

    return (root->data + addBST(root->left) + addBST(root->right));
}

int main() {
    int d;

    // Input positive integers and insert into BST until -1 is encountered
    do {
        cin >> d;
        if (d > 0)
            root = insert(root, d);
    } while (d != -1);

    // Calculate and print the sum of all nodes
    int sum = addBST(root);
    cout << "Sum of all nodes in the BST is " << sum;

    return 0;
}
