//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

#define pp pair<int, pair<int, int>>

vector<vector<int>> dir = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        queue<pp> q;
        q.push({0, source}); // dist, x, y
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int d = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;
            
            if(x == destination.first && y == destination.second) return d;
            for(auto it: dir){
                int nx = x + it[0];
                int ny = y + it[1];
                
                if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                    if(grid[nx][ny] == 1){
                        grid[nx][ny] = 0;
                        q.push({d + 1, {nx, ny}});
                    }
                }
            }
        }
        
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends