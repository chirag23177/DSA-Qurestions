/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traverse(vector<int>& order, TreeNode* node) {
        if (node == nullptr)
            return;
        traverse(order, node->left);
        order.push_back(node->val);
        traverse(order, node->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> order;
        traverse(order,root);
        return order[k-1];
    }
};