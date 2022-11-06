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
    
    TreeNode* build(int i, int j, int &idx, vector<int>& inorder,
                    vector<int>& postorder, unordered_map<int, int> &mp){
        if(i > j || idx < 0)
            return NULL;
        
        int root_val = postorder[idx];
        TreeNode* root = new TreeNode(root_val);
        idx--;
        if(i == j)
            return root;
        int inroot = mp[root->val];
        // we recursively call for the right subtree before the left subtree 
        //as we decrease the index of the postorder index whenever we create a new node. 
        root->right = build(inroot+1, j, idx,inorder, postorder, mp);
       
        root->left = build(i, inroot-1,idx, inorder, postorder, mp);
        
        return root;
        // Tc --> O(N) [tree tarversal] x O(N) [for the hashmap]
        // Sc --> O(N) [for the hashmap] + O(N) [ for the stack space]
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        for(int i = 0;i < postorder.size();i++){
            mp[inorder[i]] = i;
        }
        int idx = inorder.size() - 1;
        TreeNode* root = build(0, inorder.size()-1, idx, inorder, postorder, mp);
        return root;
    }
};