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
    int maxSum = INT_MIN;

    int findMax(TreeNode* node) {
        if (!node) return 0;

        int left = max(0, findMax(node->left));
        int right = max(0, findMax(node->right));

        maxSum = max(maxSum, node->val + left + right);

        // Return the path sum including only one subtree (cannot take both)
        return node->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) { 
        findMax(root);
        return maxSum;
    }
};
