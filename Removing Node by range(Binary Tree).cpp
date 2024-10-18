
/*Yogi is working on a program to manage a binary search tree (BST) containing integer values. He wants to implement a function that removes nodes from the tree that fall outside a specified range defined by a minimum and maximum value.
Help Yogi by writing a function that achieves this.

Input format :
The first line of input consists of an integer N, representing the number of elements to be inserted into the BST.
The second line consists of N space-separated integers, representing the elements to be inserted into the BST.
The third line consists of two space-separated integers min and max, representing the minimum value and the maximum value of the range.*/
#include <iostream>
using namespace std;

struct node {
    int key;
    node* left;
    node* right;
};

// Function to create a new node
node* newNode(int num) {
    node* temp = new node;
    temp->key = num;
    temp->left = temp->right = nullptr;
    return temp;
}

// Function to insert a node into the BST
node* insert(node* root, int key) {
    if (root == nullptr)
        return newNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

// Function to remove nodes outside the given range [min, max]
node* removeOutsideRange(node* root, int min, int max) {
    if (root == nullptr) {
        return nullptr;
    }

    // Recur for the left and right subtrees
    root->left = removeOutsideRange(root->left, min, max);
    root->right = removeOutsideRange(root->right, min, max);

    // If the current node's key is less than min, return the right subtree
    if (root->key < min) {
        node* rightChild = root->right;
        delete root;
        return rightChild;
    }

    // If the current node's key is greater than max, return the left subtree
    if (root->key > max) {
        node* leftChild = root->left;
        delete root;
        return leftChild;
    }

    // Return the current node if it's within the range
    return root;
}

// Function for in-order traversal of the BST
void inorderTraversal(node* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->key << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    node* root = nullptr;
    int num, min, max;

    // Read the number of elements to be inserted
    cin >> num;

    // Insert elements into the BST
    for (int i = 0; i < num; i++) {
        int key;
        cin >> key;
        root = insert(root, key);
    }

    // Read the range [min, max]
    cin >> min >> max;

    // Remove nodes outside the specified range
    root = removeOutsideRange(root, min, max);

    // Perform in-order traversal to print the remaining elements in ascending order
    inorderTraversal(root);

    return 0;
}





