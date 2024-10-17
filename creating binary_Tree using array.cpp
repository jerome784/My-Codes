


//Athulya needs a program that constructs a binary tree from a given array of integers and prints its in-order traversal. The program should take an integer n as input, followed by n integers representing the elements of the array. 



Then, it constructs a binary tree using the array elements in level order and prints the in-order traversal of the constructed binary tree.






#include <iostream>
#include <vector>
using namespace std;

// Define the structure for a TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to insert nodes in level order
TreeNode* buildTree(const vector<int>& arr, int n, int index) {
    if (index >= n) return nullptr;

    // Create a new node for the current index
    TreeNode* root = new TreeNode(arr[index]);

    // Recursively build the left and right subtrees
    root->left = buildTree(arr, n, 2 * index + 1);
    root->right = buildTree(arr, n, 2 * index + 2);

    return root;
}

// Function for in-order traversal
void inorderTraversal(TreeNode* root, vector<int>& result) {
    if (root == nullptr) return;

    // Visit left subtree
    inorderTraversal(root->left, result);

    // Visit root
    result.push_back(root->val);

    // Visit right subtree
    inorderTraversal(root->right, result);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Build the binary tree using the array
    TreeNode* root = buildTree(arr, n, 0);

    // Store the in-order traversal result
    vector<int> inorderResult;
    inorderTraversal(root, inorderResult);

    // Print the result in the required format
    cout << "Inorder traversal: ";
    for (size_t i = 0; i < inorderResult.size(); ++i) {
        cout << inorderResult[i];
        if (i < inorderResult.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
