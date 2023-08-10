//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    
    int solve(int i, int j, string &s1, string &s2, int n, int m, vector<vector<int>> &dp){
        
        if(i ==0 || j == 0) return 0;
        int ans = 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i - 1] == s2[j - 1])
            ans = 1 + solve(i-1, j-1, s1,s2,n, m, dp);
        else
            ans = max(solve(i-1, j, s1,s2, n, m, dp), solve(i, j-1, s1,s2, n, m, dp));
            
        return dp[i][j] = ans;
    }
    int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // return solve(n, m, s1,s2, n, m, dp);
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i = 1;i <= n;i++){
            int ans = 0;
            for(int j = 1;j <= m;j++){
                if(s1[i - 1] == s2[j - 1])
                    ans = 1 + dp[i - 1][j - 1];//solve(i-1, j-1, s1,s2,n, m, dp);
                else
                    ans = max(dp[i - 1][j], dp[i][j - 1]);//solve(i, j-1, s1,s2, n, m, dp));
            
                dp[i][j] = ans;
            }
        }
        
        return dp[n][m];
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends