//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N)
    {
        // Write Your Code here
        bool prime[N+1];
        memset(prime, true, sizeof(prime));
        
        for(int p = 2; p*p <= N;p++){
            
            if(prime[p] == true){ // not unmarked
                
                for(int i = p*p;i <= N;i+=p)
                    prime[i] = false; // unmark it;
            }
        }
        
        vector<int> ans;
        
        for(int p = 2;p <= N;p++){
            if(prime[p]) ans.push_back(p);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends