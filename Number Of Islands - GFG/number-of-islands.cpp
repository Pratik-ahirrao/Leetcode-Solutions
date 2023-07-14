//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisjointSet {
    vector<int> rank, parent, size;

    public:
        DisjointSet(int n){
            rank.resize(n+1, 0);
            parent.resize(n+1);
            size.resize(n+1);

            for(int i = 0;i < n;i++){
                parent[i] = i;
                size[i] = 1;
            }
        }

        int find_ultimate_parent(int node){
            if(node == parent[node]) return node;
            return parent[node] = find_ultimate_parent(parent[node]);
        }


        void unionByRank(int u, int v){
            int ultimateparent_u = find_ultimate_parent(u);
            int ultimateparent_v = find_ultimate_parent(v);

            if(ultimateparent_u == ultimateparent_v) return;

            if(rank[ultimateparent_u] < rank[ultimateparent_v]){
                parent[ultimateparent_u] = ultimateparent_v;
                // No change in the rank
            }

            else if(rank[ultimateparent_v] < rank[ultimateparent_u]){
                parent[ultimateparent_v] = ultimateparent_u;
                // No change in the rank
            }

            else{
                parent[ultimateparent_v] = ultimateparent_u; // attach v to u
                rank[ultimateparent_u]++;
            }
        }

        void unionBySize(int u, int v){
            int ultimateparent_u = find_ultimate_parent(u);
            int ultimateparent_v = find_ultimate_parent(v);

            if(ultimateparent_u == ultimateparent_v) return;

            if(size[ultimateparent_u] < size[ultimateparent_v]){
                parent[ultimateparent_u] = ultimateparent_v;
                size[ultimateparent_v] += size[ultimateparent_u];
            }

            else {
                parent[ultimateparent_v] = ultimateparent_u;
                size[ultimateparent_u] += size[ultimateparent_v];
            }

            
        }
};

class Solution {
  private:
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        int vis[n][m];
        memset(vis, 0, sizeof(vis));
        int cnt = 0;
        
        vector<int> ans;
        
        for(auto it: operators){
            int row = it[0];
            int col = it[1];
            
            if(vis[row][col] == 1){
                ans.push_back(cnt);
                continue;
            }
            
            vis[row][col] = 1;
            cnt++;
            
            for(auto d: dirs){
                int nrow = row + d[0];
                int ncol = col + d[1];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                    if(vis[nrow][ncol] == 1){
                        int nodeNo = row * m + col;
                        int adjNodeNo = nrow * m + ncol;
                        
                        if(ds.find_ultimate_parent(nodeNo) != ds.find_ultimate_parent(adjNodeNo)){
                            cnt--;
                            ds.unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
            }ans.push_back(cnt);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends