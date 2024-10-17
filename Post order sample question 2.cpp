//Alice is working on a project where she needs to build a complete binary tree from an array of integers. After constructing the tree, she wants to perform a post-order traversal to retrieve the node values in a specific order. 



//Write a program that takes the number of nodes and the array as input and outputs the post-order traversal of the tree.

//Input format :
//The first line contains an integer n, representing the number of elements in the array.

//The second line contains n space-separated integers, representing the values of the nodes in the binary tree.

//Output format :
//The output displays a single line containing n space-separated integers, which represent the postorder traversal of the binary tree constructed from the input array.
// You are using GCC
#include <iostream>
#include <cstring>

using namespace std;

const int MAX_NODES = 100;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int ans[MAX_NODES];
int idx = 0;

void postorder(TreeNode* root) {
    if(root==nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
    
}

void fillArray(TreeNode* root) {
    postorder(root);
}

int* postorderTraversal(TreeNode* root) {
    fillArray(root);
    return ans;
}

TreeNode* createTree(int arr[], int i, int n) {
    if(i>=n){
        return nullptr;
        
    }
    
    TreeNode* root=new TreeNode(arr[i]);
    
    root->left=createTree(arr,2*i+1,n);
    root->right=createTree(arr,2*i+2,n);
    
    return root;
}

int main() {
    int n;
    cin >> n;

    int arr[MAX_NODES];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    TreeNode* root = createTree(arr, 0, n);

    postorderTraversal(root);


    return 0;
}