//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define pp pair<int, int>


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

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        // priority_queue<pp, vector<pp>, greater<pp>> pq;
        // vector<int> vis(V, 0);
        
        // pq.push({0, 0}); // (wt, node)
        // int sum = 0;
        
        // while(!pq.empty()){
        //     auto curr = pq.top();
        //     pq.pop();
        //     int node = curr.second;
        //     int wt = curr.first;
            
        //     if(vis[node] == 1) continue;
        //     vis[node] = 1;
            
        //     sum += wt;
            
        //     for(auto it: adj[node]){
        //         int adjNode = it[0];
        //         int edWt = it[1];
        //         if(!vis[adjNode]){
        //             pq.push({edWt, adjNode});
        //         }
        //     }
        // }
        
        // return sum;
        
        
        vector<pair<int, pair<int, int>>> edges;
        
        for(int i = 0;i < V;i++){
            for(auto it: adj[i]){
                int adjNode = it[0];
                int edgeWt = it[1];
                int node = i;
                edges.push_back({edgeWt, {node, adjNode}});
            }
        }
        
        sort(edges.begin(), edges.end());
        DisjointSet ds(V);
        int mstwt = 0;
        
        for(auto it: edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.find_ultimate_parent(u) != ds.find_ultimate_parent(v)){
                mstwt += wt;
                ds.unionBySize(u, v);
            }
        }
        
        return mstwt;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends