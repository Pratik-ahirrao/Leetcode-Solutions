//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    
private:
    int solve(int row, int col, vector<vector<int>> mat, int n, int m, int &maxi){
        if(row < 0 || row >= n || col < 0 || col >= m) return 0;
        
        
        int right = solve(row, col+1, mat, n, m, maxi);
        int diagonal = solve(row+1, col+1, mat, n, m, maxi);
        int down = solve(row+1, col, mat, n, m, maxi);
        
        
        if(mat[row][col] == 1){
            int ans = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, ans);
            return ans;
        }
        
        else return 0;
    }
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        int maxi = 0;
       // solve(0 , 0, mat, n, m, maxi);
       vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int row = n - 1;row >= 0;row--){
            for(int col = m - 1;col >= 0;col--){
                int right = dp[row][col+1];//olve(row, col+1, mat, n, m, maxi);
                int diagonal = dp[row+1][col+1];//solve(row+1, col+1, mat, n, m, maxi);
                int down = dp[row+1][col];//solve(row+1, col, mat, n, m, maxi);
        
        
                if(mat[row][col] == 1){
                    int ans = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, ans);
                    dp[row][col]= ans;
                }
        
                else dp[row][col]= 0;
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends