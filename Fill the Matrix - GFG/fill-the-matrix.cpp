//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int N, int M, int x, int y){    
        // code here
        vector<vector<bool>> vis(N, vector<bool> (M, false));
        queue<pair<int, int>> q;
        q.push({x - 1, y - 1});
        vis[x - 1][y - 1] = true;
        int count = 0;
        
        while(!q.empty()){
            int len = q.size();
            count++;
            
            for(int i = 0;i < len;i++){
                pair<int, int> p = q.front();
                q.pop();
                int x_cord = p.first;
                int y_cord = p.second;
                
                if(x_cord > 0 && !vis[x_cord - 1][y_cord]){
                    q.push({x_cord - 1, y_cord});
                    vis[x_cord - 1][y_cord] = true;
                }
                
                if(x_cord < N - 1 && !vis[x_cord+1][y_cord]){
                    q.push({x_cord + 1, y_cord});
                    vis[x_cord + 1][y_cord] = true;
                }
                
                if(y_cord > 0 && !vis[x_cord][y_cord - 1]){
                    q.push({x_cord , y_cord - 1});
                    vis[x_cord ][y_cord - 1] = true;
                }
                
                if(y_cord < M - 1 && !vis[x_cord][y_cord+1]){
                    q.push({x_cord, y_cord + 1});
                    vis[x_cord][y_cord + 1] = true;
                }
            }
        }
        return count - 1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends