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
    
    
     TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, 
                               int inStart, int inEnd, unordered_map<int, int> &mp ){
         if(preStart > preEnd || inStart > inEnd){
             return NULL;
         }
         
         TreeNode* root = new TreeNode(preorder[preStart]);
         
         int inroot = mp[root->val];
         int nums_on_left = inroot - inStart;
         
         root->left = build(preorder, preStart +1, preStart+nums_on_left, inorder, inStart, inroot-1 , mp);
         root->right = build(preorder, preStart+ nums_on_left+1, preEnd, inorder, inroot+1, inEnd,mp);
         return root;
     }
    
    // simplified function
    TreeNode* building(int i, int j, int &idx,vector<int>& preorder,
                       vector<int>& inorder,unordered_map<int, int> &mp ){
        if(i > j)
            return NULL;
         int root_val = preorder[idx];
         TreeNode* root = new TreeNode(root_val);
         idx++;
         int inroot = mp[root->val];
        
        root->left = building(i, inroot-1, idx, preorder, inorder, mp);
        root->right = building(inroot+1, j, idx, preorder, inorder, mp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        
        for(int i=0;i < inorder.size();i++){
            mp[inorder[i]] = i;
        }
        int idx = 0;
        TreeNode* root = build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size() - 1,mp );
        TreeNode* root1 = building(0, preorder.size() - 1, idx, preorder, inorder, mp);
        //return root;
        return root1;
    }
};