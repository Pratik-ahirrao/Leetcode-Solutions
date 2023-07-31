//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/

    int solve(int i, int j, string pattern, string str, vector<vector<int>> &dp){
        
        
        if(i == 0 && j == 0) return 1;
        if(i == 0 && j > 0) return 0;
        
        if(i > 0 && j == 0){
            for(int idx = 1;idx <= i;idx++){
                if(pattern[idx - 1] != '*') return 0;
            }
            return 1;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        if(pattern[i - 1] == str[j - 1] || pattern[i - 1] == '?')
            return dp[i][j] = solve(i - 1, j - 1, pattern, str, dp);
            
        else if(pattern[i - 1] == '*'){
            return dp[i][j] = solve(i - 1, j, pattern,str, dp) | solve(i, j - 1, pattern, str, dp);
        }
        
        return dp[i][j] = 0;
    }
    
    int wildCard(string pattern,string str)
    {
        int n = pattern.size();
        int m = str.size();
        //vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        //return solve(n, m , pattern, str, dp);
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        dp[0][0] = 1;
        for(int j = 1;j <= m;j++) dp[0][j] = 0;
        for(int i = 1;i <= n;i++){
            int flag = 1;
            for(int idx = 1;idx <= i;idx++){
                if(pattern[idx - 1] != '*'){
                    flag = 0;
                    break;
                }
                dp[i][0] = flag;
            }
        }
        
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(pattern[i - 1] == str[j - 1] || pattern[i - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];//solve(i - 1, j - 1, pattern, str, dp);
            
                else if(pattern[i - 1] == '*'){
                    dp[i][j] = dp[i - 1][j] | dp[i][j - 1];//solve(i, j - 1, pattern, str, dp);
                }
        
                else dp[i][j] = 0;
            }
        }
        
        return dp[n][m];
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends