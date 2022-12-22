//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        //code here
       long long int prefixSum[n];
       prefixSum[0] = arr[0];
       
       unordered_map<int, int> mp;
       for(int i = 1;i < n;i++){
           prefixSum[i] = prefixSum[i - 1] + arr[i];
       }
       long long int count = 0;
       for(int i = 0;i < n;i++){
           if(prefixSum[i] == 0)
                count++;
            
           if(mp.find(prefixSum[i] - 0) != mp.end()){
               count += mp[prefixSum[i] - 0];
           }
           
           mp[prefixSum[i]]++;
       }
       return count;
        
    }
       
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends