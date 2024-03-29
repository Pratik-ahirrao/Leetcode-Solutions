//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>> q;
        int vis[n][m] = {0};
        
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(i == 0 || j == 0 || i == n - 1 || j == m - 1){
                    if(grid[i][j] ==1){
                        q.push({i,j});
                        vis[i][j] = 1;
                    }
                    
                }
            }
        }
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(auto it: dir){
                int newrow = row + it[0];
                int newcol = col + it[1];
                
                if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m
                    && vis[newrow][newcol] == 0 && grid[newrow][newcol] == 1){
                    q.push({newrow, newcol});
                    vis[newrow][newcol] = 1;
                }
            }
        }
        int cnt = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(grid[i][j] == 1 && vis[i][j] == 0) cnt++;
            }
        }
        
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends