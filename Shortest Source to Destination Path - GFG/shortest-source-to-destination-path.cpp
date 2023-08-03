//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0] == 0) return -1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        //vector<vector<int>> vis(N, vector<int>(M, 0));
        //vis[0][0] = 1;
        A[0][0] = 0;
        int moves = 0;
        while(!q.empty()){
            int len = q.size();
            
            for(int i =0;i < len;i++){
                auto curr = q.front();
                q.pop();
                int x = curr.first;
                int y = curr.second;
                
                if(x == X && y == Y) return moves;
                
                for(auto it: dir){
                    int nx = x + it[0];
                    int ny = y + it[1];
                    
                    if(nx >= 0 && nx < N && ny >= 0 && ny < M){
                        if(A[nx][ny] == 1){
                            A[nx][ny] = 0;
                            q.push({nx, ny});
                        }
                       
                    }
                }
                
            }
            
            moves++;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends