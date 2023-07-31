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
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(n, m , pattern, str, dp);
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