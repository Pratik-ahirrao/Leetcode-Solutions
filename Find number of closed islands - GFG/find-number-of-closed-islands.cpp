//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    vector<vector<int>> dir = {{1, 0}, {0,1},{-1, 0}, {0,-1}};
    void dfs(int i, int j, vector<vector<int>>& matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        
        if(i <0 || i >= n || j < 0 || j >=m || matrix[i][j] != 1) return ;
        matrix[i][j] = 0; // change land to water
        
        for(auto it: dir){
            int nx = i + it[0];
            int ny = j + it[1];
            dfs(nx, ny, matrix);
        }
    }
    
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        // Code here
        // 1 is land
        // 0 is water
        int count = 0;
        
        for(int i = 0;i < N;i++){
            for(int j = 0;j < M;j++){
                if((i == 0 || j == 0 || i == N -1 || j == M -1) && matrix[i][j] == 1)
                    dfs(i, j, matrix);
            }
        }
        

        for(int i = 1;i  < N-1;i++){
            for(int j = 1;j < M-1;j++){
                if(matrix[i][j] == 1){
                    dfs(i,j, matrix);
                    count++;
                }
            }
        }
        
        
        return count;
        
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends