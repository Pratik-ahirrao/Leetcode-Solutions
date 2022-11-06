//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    int getTime(unordered_map<Node*, Node*> &parent_track, Node* target){
        queue<Node*> q;
        unordered_map<Node*, bool> vis;
        q.push(target);
        vis[target] = true;
        int mini = 0;
        while(!q.empty()){
            int size = q.size();
            bool flag = false;
            for(int i = 0;i < size;i++){
                Node* curr = q.front();
                q.pop();
                
                if(curr->left && !vis[curr->left]){
                    flag = true;
                    q.push(curr->left);
                    vis[curr->left] = true;
                }
                
                if(curr->right && !vis[curr->right]){
                    flag = true;
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
                
                if(parent_track[curr] != NULL && !vis[parent_track[curr]]){
                    flag = true;
                    q.push(parent_track[curr]);
                    vis[parent_track[curr]] = true;
                }
            }
            // flag is true it means i have burned someone that was adjacebt to the current node
            if(flag)
                 mini++;
        }
        return mini;
    }
  
    Node* mark_parents(Node* root, unordered_map<Node*, Node*> &parent_track,int start){
        queue<Node*> q;
        q.push(root);
        Node* res;
        while(!q.empty()){
            Node* curr = q.front();
            if(curr->data == start)
                res = curr;
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
        return res;
    }
    int minTime(Node* root, int start) 
    {
        // Your code goes here
        unordered_map<Node*, Node*> parent_track;
        Node* target = mark_parents(root, parent_track, start);
        int mini = getTime(parent_track ,target);
        return mini;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends