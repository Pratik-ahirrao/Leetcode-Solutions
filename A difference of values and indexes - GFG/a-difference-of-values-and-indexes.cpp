//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 



// } Driver Code Ends
class Solution{
  public:
    int maxDistance(int arr[], int n) 
    { 
        // Complete the function
        int max1 = INT_MIN;
        int min1 = INT_MAX;
        int max2 = INT_MIN;
        int min2 = INT_MAX;
        int t1, t2;
        for(int i = 0;i < n;i++){
            t1 = arr[i] - i;
            t2 = arr[i] + i;
            max1 = max(max1, t1);
            min1 = min(min1, t1);
            max2 = max(max2, t2);
            min2 = min(min2, t2);
        }
        
        return max((max1 - min1), max2 - min2);
    } 
};

//{ Driver Code Starts.
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0; i<n; i++)
	        cin>>arr[i];
	    Solution obj;
	    cout<<obj.maxDistance(arr, n)<<endl;
	}
} 

// } Driver Code Ends