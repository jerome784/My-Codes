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
TreeNode* buildTree(){
    int val;
    cout<<"Enter the value for the Node(-1 for no node): "<<endl;
    cin>>val;
    
    if(val==-1){
        return nullptr;
    }
    TreeNode* root =createNode(val);
    
    
    cout<<"Enter the left child: "<<endl;
    root->left=buildTree();
    
    cout<<"Enter the right tree: "<<endl;
    root->right=buildTree();
    return root;
}

void PreOrder_Traversal(TreeNode* root){
    if(root==nullptr){
        return;
    }
    cout<<root->data<<" ";
    PreOrder_Traversal(root->left);
    PreOrder_Traversal(root->right);
}
int main(){
    TreeNode* root=buildTree();
    
    cout<<"PreOrder Taversal Of the tree: ";
    PreOrder_Traversal(root);
}


























