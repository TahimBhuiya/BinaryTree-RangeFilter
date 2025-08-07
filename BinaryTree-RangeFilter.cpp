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
}