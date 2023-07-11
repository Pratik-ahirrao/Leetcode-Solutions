//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define pp pair<int, pair<int, int>>
vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int n = heights.size();
        int m = heights[0].size();
        
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        pq.push({0, {0,0}});
        dist[0][0] = 0;
        
        
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int diff = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;
            
            if(x == n - 1 && y == m - 1) return diff;
            for(auto it: dir){
                int nx = x + it[0];
                int ny = y + it[1];
                
                if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                    int newh = max(diff, abs(heights[nx][ny] - heights[x][y]));
                    if(newh < dist[nx][ny]){
                        dist[nx][ny] = newh;
                        pq.push({newh, {nx, ny}});
                    }
                }
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends