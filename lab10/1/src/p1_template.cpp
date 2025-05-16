#include <iostream>
#include <vector>

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Function to insert a value into a BST
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }
    return root;
}

// Function to build a BST from a vector of integers
TreeNode* constructBST(const std::vector<int>& elements) {
    TreeNode* root = nullptr;
    for (int val : elements) {
        root = insertBST(root, val);
    }
    return root;
}

// Function to search a value in a BST
TreeNode* searchBST(TreeNode* root, int val) {
// ********************** your code bellow **********************
    if (!root) return nullptr;
    if (root->val == val) return root;
    if (val < root->val) {
        return searchBST(root->left, val);
    } else {
        return searchBST(root->right, val);
    }

// ********************** your code above **********************
}

// Helper function to print the tree in pre-order traversal
void preOrderTraversal(TreeNode* root) {
    if (!root) return;
    std::cout << root->val << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main() {
    std::vector<int> elements = {4, 2, 7, 1, 3};
    // int val = 2;
    int val = 5;

    // Construct BST from the elements
    TreeNode* root = constructBST(elements);

    // Search the val in the BST
    TreeNode* result = searchBST(root, val);

    std::cout << "Pre-order traversal of the BST subtree with root value " << val << ":" << std::endl;
    preOrderTraversal(result);
    return 0;
}
