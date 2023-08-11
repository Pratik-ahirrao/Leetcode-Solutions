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
    long long int count(int coins[], int n, int sum) {

        // code here.
        // vector<vector<long long int>> dp(N, vector<long long int>(sum+1, -1));
        // return solve(coins, sum, 0, N, dp);
        
        vector<vector<long long int>> dp(n+1, vector<long long int>(sum+1, 0));
        
        for(int i = 0;i < n;i++) dp[i][0] = 1;
        
        for(int i = n - 1;i >= 0;i--){
            for(int amt = 1;amt <= sum;amt++){
                long long int notPick = dp[i+1][amt];//solve(coins, sum, idx+1, N, dp);
                long long int pick = 0;
        
                if(amt - coins[i] >= 0)
                    pick = dp[i][amt - coins[i]];//solve(coins, sum - coins[idx], idx, N, dp);
            
                dp[i][amt] = pick + notPick;
            }
        }
        
        return dp[0][sum];
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