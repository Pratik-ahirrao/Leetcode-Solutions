//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
  private:
    long long int solve(int coins[], int sum, int idx, int N, vector<vector<long long int>> &dp){
        if(idx == N){
            if(sum == 0) return 1;
            return 0;
        }
        
        if(dp[idx][sum] != -1) return dp[idx][sum];
        long long int notPick = solve(coins, sum, idx+1, N, dp);
        long long int pick = 0;
        
        if(sum - coins[idx] >= 0)
            pick = solve(coins, sum - coins[idx], idx, N, dp);
            
        return dp[idx][sum] = pick + notPick;
    }
  public:
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long long int>> dp(N, vector<long long int>(sum+1, -1));
        return solve(coins, sum, 0, N, dp);
        
        vector<vector<long 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends