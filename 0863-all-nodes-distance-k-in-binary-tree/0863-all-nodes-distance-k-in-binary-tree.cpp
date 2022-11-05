/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // we keep track of parent nodes using map
    // we then apply bfs traversal on the target node
    // we go to parent, left and right till the required distance and then move out of the loop
    
    void mark_parents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_track){
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr->left != NULL){
                parent_track[curr->left] = curr;
                q.push(curr->left);
            }
            
            if(curr->right != NULL){
                parent_track[curr->right] = curr;
                q.push(curr->right);
            }
                
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        unordered_map<TreeNode*, TreeNode*> parent_track;
        mark_parents(root, parent_track);
        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;
        int dist = 0;
        while(!q.empty()){
            int size = q.size();
           
            if(dist == k)
                break;
             dist++;
            for(int i = 0;i < size;i++){
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left] = true;
                }
                
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
                
                if(parent_track[curr] != NULL && !vis[parent_track[curr]]){
                    q.push(parent_track[curr]);
                    vis[parent_track[curr]] = true;
                }
            }
        }
        
        while(!q.empty()){
            int a = q.front()->val;
            q.pop();
            res.push_back(a);
        }
        return res;
    }
};