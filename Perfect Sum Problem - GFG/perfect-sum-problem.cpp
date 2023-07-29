//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
        long long MOD = 1e9 + 7;
        int solve(int arr[], int n, int sum, int idx, vector<vector<int>> &dp){
            
            if(idx == n){
                if(sum == 0) return 1;
                else return 0;
            }
            
            if(dp[idx][sum] != -1) return dp[idx][sum];
            int notPick = solve(arr, n, sum, idx+1, dp);
            int pick = 0;
            if(sum - arr[idx] >= 0)
                pick = solve(arr, n, sum - arr[idx], idx+1, dp);
                
            return dp[idx][sum] = (pick + notPick)% MOD;
        }
	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        return solve(arr, n, sum, 0, dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends