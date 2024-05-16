#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        // If the root is NULL or the value is 0, return false
        if (root == NULL || root->val == 0)
            return false;
        // If the value is 1, return true
        else if (root->val == 1)
            return true;
        // If the value is 2, perform logical OR on left and right children
        else if (root->val == 2)
            return (evaluateTree(root->left) || evaluateTree(root->right));
        // If the value is 3, perform logical AND on left and right children
        else if (root->val == 3)
            return (evaluateTree(root->left) && evaluateTree(root->right));

        // Default return value, in case of unexpected values
        return true;
    }
};

// Function to create a sample tree for testing
TreeNode* createSampleTree() {
    // Creating a sample tree:
    //      2
    //     / \
    //    1   3
    //       / \
    //      0   1
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);
    return root;
}

int main() {
    // Create a solution object
    Solution solution;

    // Create a sample tree
    TreeNode* root = createSampleTree();

    // Evaluate the tree and print the result
    bool result = solution.evaluateTree(root);
    cout << "The result of evaluating the tree is: " << (result ? "true" : "false") << endl;

    // Clean up the allocated memory for the tree nodes
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
