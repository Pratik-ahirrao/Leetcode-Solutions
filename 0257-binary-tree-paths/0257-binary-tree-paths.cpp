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
    
    
    void recursion(TreeNode* root, vector<string>& ans, string s){
        if(root->left == NULL && root->right == NULL){
            ans.push_back(s);
        }
        
        if(root->left)
            recursion(root->left, ans, s + "->" + to_string(root->left->val));
        if(root->right)
            recursion(root->right, ans, s + "->" + to_string(root->right->val));
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root == NULL)
            return ans;
        recursion(root, ans, to_string(root->val));
        return ans;
    }
};