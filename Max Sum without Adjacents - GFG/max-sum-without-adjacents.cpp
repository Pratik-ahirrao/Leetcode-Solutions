//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    int dp[n][2];
	   // dp[0][0] = 0;
	   // dp[0][1] = arr[0];
	    int exclu = 0;
	    int inclu = arr[0];
	    int exclu_new;
	    for(int i = 1;i < n;i++){
	       // inclu = exclu + arr[i];
	        exclu_new = max(inclu, exclu);
	        inclu = exclu + arr[i];
	        exclu = exclu_new;
	    }
	    
	    return max(inclu, exclu);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends