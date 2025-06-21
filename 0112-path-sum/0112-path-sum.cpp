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
    bool found(TreeNode* node, int currSum, int targetSum){
        if(!node) return false;

        if(!node->right && !node->left && node->val + currSum == targetSum){
            return true;
        }

        return found(node->left,currSum+node->val, targetSum) || found(node->right, currSum+node->val, targetSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return found(root,0,targetSum);
    }
};