//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	
	   // int solve(string s, int n){
	   //      int count = 0;
		  //  if(n == 0 || n == 1)
		  //      return 1;
		        
		  //  if(s[0] == '0')
		  //      return 0;
		  //  if(s[n - 1] > '0'){
		  //      count = solve(s, n - 1);
		  //  }
		    
		  //  if(s[n - 2] == '1' || s[n - 2] == '2' && s[n - 1] < '7'){
		  //      count += solve(s, n - 2);
		  //  }
		    
		  //  return count;
	   // }
		int CountWays(string str){
		  int n = str.size();
		  //  // Code here
		  //  if(n == 0)
		  //      return 0;
		  //  return solve(str, n);
		  
		  
		  int dp[n+1];
		  
		  dp[0] = 1;
		  dp[1] = 1;
		  
		  for(int i = 2;i <= n;i++){
		      dp[i] = 0;
		      if(str[i - 1] > '0')
		        dp[i] = (int)dp[i - 1]%1000000007;
		        
		      if(str[i - 2] == '1' || (str[i - 2] == '2' && str[i - 1] < '7')){
		          dp[i] += (int)dp[i - 2]%1000000007;
		      }
		  }
		  return (int)dp[n]%1000000007;
		   
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends