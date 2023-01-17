//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxBinTreeGCD(vector<vector<int>> arr, int N) {
        // code here
        if(arr.size() == 0 || arr.size() == 1)
            return 0;
            
        sort(arr.begin(), arr.end());
        int ans = 0;
        vector<int> a = arr[0];
        vector<int> b;
        for(int i = 1;i < arr.size();i++){
            b = arr[i];
            
            if(a[0] == b[0])
                ans = max(ans, __gcd(a[1], b[1]));
                
            a = b;
        }
        
        return ans;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,u,v;
        cin>>N;
        
        vector<vector<int>> arr;
        
        for(int i=0; i<N-1; i++)
        {
            cin>>u>>v;
            vector<int> edge;
            edge.push_back(u);
            edge.push_back(v);
            arr.push_back(edge);
        }

        Solution ob;
        cout << ob.maxBinTreeGCD(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends