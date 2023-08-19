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
        int start = 0;
        int end = 0;
        for(int i = 0;i < S.size();i++){
            for(int j = i;j < S.size();j++){
                if(solve(S, i, j)){
                    if(len < (j - i + 1)){
                        len = j - i + 1;
                        start = i;
                        end = j;
                    }
                }
            }
        }
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