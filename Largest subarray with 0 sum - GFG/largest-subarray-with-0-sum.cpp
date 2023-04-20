//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        // Your code here
        map<long long , int> prefixSumMap;
    int k = 0;
    int maxLen = 0;
    long long  sum = 0;
    for(int i = 0;i < arr.size();i++){
      sum += arr[i];
      if(sum == k)
        maxLen = max(maxLen, i+1);
      
      int rem = sum - k;

      if(prefixSumMap.find(rem) != prefixSumMap.end()){
        maxLen = max(maxLen, i - prefixSumMap[rem]);
      }
      else // without else, code fails for [2, 0, 0, 3]
      prefixSumMap[sum] = i;
    }
    return maxLen;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends