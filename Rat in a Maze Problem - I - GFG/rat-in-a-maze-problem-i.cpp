//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void solve(vector<string>& ans, vector<vector<int>> &vis, vector<vector<int>> &m, string move, int i, int j, int n){
        if(i == n - 1 && j == n - 1){
            ans.push_back(move);
            return;
        }
        
        // down
        if(i + 1 < n && !vis[i+1][j] && m[i+1][j] == 1){
            vis[i][j] = 1;
            solve(ans, vis, m, move + "D", i+1, j, n);
            vis[i][j] = 0;
        }
        
        // left
        if(j - 1 >= 0 && !vis[i][j - 1] && m[i][j - 1] == 1){
            vis[i][j] = 1;
            solve(ans, vis,m, move + "L", i, j - 1, n);
            vis[i][j] = 0;
        }
        
        // Right
        if(j + 1 < n && !vis[i][j + 1] && m[i][j + 1] == 1){
            vis[i][j] = 1;
            solve(ans, vis, m,move + "R", i, j + 1, n);
            vis[i][j] = 0;
        }
        
        // Up
        if(i - 1 >= 0 && !vis[i-1][j] && m[i-1][j] == 1){
            vis[i][j] = 1;
            solve(ans, vis, m, move + "U", i-1, j, n);
            vis[i][j] = 0;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        if(m[0][0] == 0) return {"-1"};
        solve(ans, vis, m, "", 0, 0, n);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends