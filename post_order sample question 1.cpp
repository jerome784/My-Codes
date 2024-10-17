//Imagine you are given a series of integers that represent the data to be inserted into a binary tree using level-order traversal. Construct the binary tree with these integers and perform a post-order traversal. After printing the post-order traversal, calculate and print the sum of all odd values in the tree.

//Input format :
//The first line contains an integer n, the number of nodes.

//The second line contains n integers, which is the data to be inserted into the tree.

//Output format :
//The first line prints the post-order traversal of the tree, with each value separated by a space.

//The second line prints the sum of all odd values in the tree.

// You are using GCC
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int data) {
    Node* new_node=createNode(data);
    
    if(root==nullptr) return new_node;
    
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty()){
        Node* current=q.front();
        q.pop();
    
    if(current->left==nullptr){
        current->left=new_node;
        return root;
        
    }
    else{
        q.push(current->left);
    }
    if(current->right==nullptr){
        current->right=new_node;
        return root;
    }
    else{
        q.push(current->right);
    }
}
return root;
}

int oddSum = 0;

void postOrder(Node* root) {
    if(root==nullptr) return ;
    postOrder(root->left);
    postOrder(root->right);
    cout<< root->data<<" ";
    if(root->data%2!=0){
        oddSum+=root->data;
    }
    
}

int main() {
    Node* root = nullptr;
    int n, data;

    cin >> n;

    while (n-- > 0) {
        cin >> data;
        root = insert(root, data);
    }

    cout << "Postorder Traversal: ";
    postOrder(root);
    cout << endl << "Odd Sum: " << oddSum << endl;

    return 0;
}