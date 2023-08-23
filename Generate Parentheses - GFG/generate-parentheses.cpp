//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    vector<string> ans;
    void solve(int n, string s, int open, int close){
        if(s.size() == 2*n){
            ans.push_back(s);
            return;
        }
        
        if(open < n)
            solve(n, s + '(', open+1, close);
            
        if(close < n && open > close)
            solve(n, s + ')', open, close+1);
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        solve(n, "", 0, 0);
        return ans;
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
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends