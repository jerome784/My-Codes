#include<iostream>
using namespace std;
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    public:
    TreeNode(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
TreeNode* createNode(int val){
    return new TreeNode(val);
}

TreeNode* build_Tree(){
    cout<<"Enter the value of Node(-1 if no Node): ";
    int val;
    cin>>val;
    if(val==-1){
        return nullptr;
    }
    
    TreeNode* root=createNode(val);
    
    cout<<"Enter the left child Node: "<<val<<endl;
    root->left=build_Tree();
    
    cout<<"Enter the right child Node: "<<val<<endl;
    root->right=build_Tree();
    return root;
    
}
void In_order_Traversal(TreeNode* root){
    if(root==nullptr){
        return;
    }
    In_order_Traversal(root->left);
    cout<<root->data<<" ";
    In_order_Traversal(root->right);
}
int main(){
    TreeNode* root=build_Tree();
    
    cout<<"In order Traversal of the tree: ";
    In_order_Traversal(root);
    
    
}