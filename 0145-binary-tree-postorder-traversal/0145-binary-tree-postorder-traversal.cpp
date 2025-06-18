/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void traverse(vector<int>& order, TreeNode* node) {
        if (node == nullptr)
            return;
        traverse(order, node->left);  // Left
        traverse(order, node->right); // Right
        order.push_back(node->val);   // Root
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> order;
        traverse(order, root);
        return order;
    }
};