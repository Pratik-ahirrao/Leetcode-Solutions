//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    bool solve(string &s, int i, int j){
        if(i > j) return true;
        
        if(s[i] == s[j])
            if(solve(s, i +1, j - 1)) return true;
        return false;
    }
    string longestPalindrome(string S){
        // code here 
        int len = 0;
        int low;
        int high;
        int start = 0;
        for(int i = 0;i < S.size();i++){
            
            low = i - 1;
            high = i;
            
            while(low >= 0 && high < S.size() && S[low] == S[high]){
                if(len < high - low + 1){
                    len = high - low + 1;
                    start = low;
                
                }
                low--;
                high++;
            }
            
            low = i - 1;
            high = i + 1;
            
            while(low >= 0 && high < S.size() && S[low] == S[high]){
                if(len < high - low + 1){
                    len = high - low + 1;
                start = low;}
                low--;
                high++;
            }
        }
        if(len == 0) return S.substr(0, 1);
        return S.substr(start, len);
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends