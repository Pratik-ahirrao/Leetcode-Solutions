//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  long long int wineSelling(vector<int>& arr, int N){
      //Code here.
      vector<pair<int, int>> buy, sell;
      
      for(int i = 0;i < N;i++){
          if(arr[i] > 0)
            buy.push_back({arr[i], i});
        
          else
            sell.push_back({arr[i], i});
      }
      
      long long int ans = 0;
      int i = 0;
      int j = 0;
      
      while(i < buy.size() && j < sell.size()){
          int mini = min(buy[i].first, -sell[j].first);
          buy[i].first -= mini;
          sell[j].first += mini;
          
          long long int diff = abs(buy[i].second - sell[j].second);
          ans += diff* (mini);
          if(buy[i].first == 0)
            i++;
          if(sell[j].first == 0)
            j++;
      }
      return ans;
  }
};



//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends