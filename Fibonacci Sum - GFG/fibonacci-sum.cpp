//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    long long int fibSum(long long int N){
        //code here
        
        int dp[N+1];
        dp[0] = 0;
        dp[1] = 1;
        int sum = 0;
        for(int i = 2;i <= N;i++){
            dp[i] = dp[i - 1]%1000000007 +dp[i - 2]%1000000007;
            sum = sum%1000000007 +  dp[i]%1000000007;
        }
        return sum%1000000007 + 1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        Solution ob;
        cout << ob.fibSum(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends