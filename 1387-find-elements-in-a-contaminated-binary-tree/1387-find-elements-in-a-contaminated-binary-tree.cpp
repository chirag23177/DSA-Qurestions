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
class FindElements {
public:
    set<int> s;
  
    
    FindElements(TreeNode* root) {
        // We need to traverse the tree
        queue<TreeNode*> q;
        q.push(root);
        root->val = 0;
        s.insert(0);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if (node->left) {
                    node->left->val = 2 * node->val + 1;
                    q.push(node->left);
                    s.insert(node->left->val);  // Insert left node value
                }
                
                if (node->right) {
                    node->right->val = 2 * node->val + 2;
                    q.push(node->right);
                    s.insert(node->right->val);  // Insert right node value
                }
            }
        }
    }
    
    bool find(int target) {
        // We need to find the target in the tree
        if (s.find(target) != s.end()) {
            return true;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */