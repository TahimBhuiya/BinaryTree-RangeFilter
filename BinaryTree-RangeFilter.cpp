//Created by Tahim Bhuiya
//Program to display a binary tree using BFS (level-order traversal and remove nodes whose values fall outside a given range.
#include <iostream>  // For input/output operations
#include <queue>     // For queue container (used in BFS)
#include <limits>    // For numeric limits (used in input validation)
using namespace std; 

// Definition of Tree Node
struct TreeNode {
    int val;           // Value stored in the node
    TreeNode *left;    // Pointer to left child
    TreeNode *right;   // Pointer to right child

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void BFS(TreeNode* root) {
    if (!root) return; // If tree is empty, nothing to print
    queue<TreeNode*> q; // Queue to hold nodes for BFS

    q.push(root);       // Start with the root node

    while (!q.empty()) {
        int levelSize = q.size(); // Number of nodes at current level

        // Process all nodes in the current level
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();

            cout << node->val << " "; // Print current node's value

            // Push children into queue if they exist
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl; // Newline after each level
    }
}

TreeNode* removeOutsideRange(TreeNode* root, int minVal, int maxVal) {
    if (!root) return nullptr; // Base case: null node

    // Recursively process left and right subtrees    
    root->left = removeOutsideRange(root->left, minVal, maxVal);
    root->right = removeOutsideRange(root->right, minVal, maxVal);

    // If node value is too small, replace with right child
    if (root->val < minVal) {
        TreeNode* rightChild = root->right;
        delete root; // Free memory
        return rightChild;
    }

    // If node value is too large, replace with left child
    if (root->val > maxVal) {
        TreeNode* leftChild = root->left;
        delete root; // Free memory
        return leftChild;
    }

    // Node is within range; keep it
    return root;

}

// Reads a valid integer from the user with prompt
int readValidInteger(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) { // Successfully read integer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        } 
        else {
            cout << "Please enter a valid integer.\n";
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return value;
}


void readValidRange(int& minVal, int& maxVal) {
    while (true) {
        minVal = readValidInteger("Enter the minimum value of the range: ");
        maxVal = readValidInteger("Enter the maximum value of the range: ");

        if (minVal < maxVal) break;
        cout << "The minimum value must be less than the maximum value. Try again.\n";
}}


int main() {
    // Manually construct example binary tree:
    //         8
    //       /   \
    //      5     11
    //     / \   /  \
    //    2   7 9   12
    //       /    \    \
    //      6     10    13
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(5);
    root->right = new TreeNode(11);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(12);
    root->left->right->left = new TreeNode(6);
    root->right->left->right = new TreeNode(10);
    root->right->right->right = new TreeNode(13);

    // Display original tree
    cout << "Original Tree:" << endl;
    BFS(root);
}