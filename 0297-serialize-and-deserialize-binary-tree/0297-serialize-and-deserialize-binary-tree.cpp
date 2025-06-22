/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void traverse(TreeNode* node, string& res){
        if(!node){
            res.append("N,");
            return;
        }

        res.append(to_string(node->val) + ",");
        traverse(node->left,res);
        traverse(node->right,res);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;

        traverse(root, res);
        if (!res.empty()) res.pop_back();
        return res;

    }

    TreeNode* makeTree(queue<string>& values){
        string snum = values.front();
        values.pop();
        if(snum == "N"){
            return nullptr;
        }

        int num = stoi(snum);
        TreeNode* root = new TreeNode(num);
        root->left = makeTree(values);
        root->right = makeTree(values);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> values;

        stringstream ss(data);
        string token;
        while(getline(ss,token,',')){
            values.push(token);
        }

        return makeTree(values);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));