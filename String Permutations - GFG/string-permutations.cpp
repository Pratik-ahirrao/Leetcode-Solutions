//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
    void solve(string s, int idx, vector<string>& ans){
        if(idx == s.size()){
            ans.push_back(s);
        }
        
        for(int i = idx;i < s.size();i++){
            swap(s[idx], s[i]);
            solve(s, idx+1, ans);
            swap(s[idx], s[i]);
        }
    }
    
    vector<string> permutation(string s)
    {
        //Your code here
        vector<string> ans;
        solve(s, 0, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends