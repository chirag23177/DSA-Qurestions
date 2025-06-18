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
    void traverse(vector<int>& res, TreeNode* node){
        if(node == nullptr) return;
        res.push_back(node->val);
        traverse(res, node->left);
        traverse(res, node->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        traverse(res, root);
        return res;

    }
};