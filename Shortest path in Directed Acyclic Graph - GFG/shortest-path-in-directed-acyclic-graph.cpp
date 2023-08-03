//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  private:
    void topo(vector<pair<int, int>> adj[], int node, stack<int>&st, vector<int> &vis){
        vis[node] = 1;
        
        for(auto it: adj[node]){
            if(!vis[it.first])
                topo(adj, it.first, st, vis);
        }
        
        st.push(node);
    }
    
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        
        vector<pair<int, int>> adj[N];
        
        for(auto it: edges){
            int e1 = it[0];
            int e2 = it[1];
            int wt = it[2];
            adj[e1].push_back({e2, wt});
        }
        
        vector<int> vis(N, 0);
        stack<int> st;
        for(int i = 0;i < N;i++){
            if(!vis[i])
                topo(adj, i, st, vis);
        }
        
        vector<int> dist(N, 1e9);
        dist[0] = 0;
        while(!st.empty()){
            int curr = st.top();
            st.pop();
            
            for(auto it: adj[curr]){
                int v =  it.first;
                int wt = it.second;
                
                if(dist[curr] + wt < dist[v])
                    dist[v] = dist[curr] + wt;
                
            }
        }
        
        for(int i = 0;i < N;i++){
            if(dist[i] == 1e9) dist[i] = -1;
        }
        
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends