//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
        vector<vector<int>> dir = {{1, 2}, {-1, 2}, {2, 1}, {-2, 1}, 
                                    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    // Code here
	    int tx = TargetPos[0] - 1;
	    int ty = TargetPos[1] - 1;
	    int sx = KnightPos[0] - 1;
	    int sy = KnightPos[1] - 1;
	    
	    
	    vector<vector<bool>> vis(n, vector<bool>(n, false));
	    
	    queue<pair<int, int>> q;
	    q.push({sx, sy});
	    vis[sx][sy] = true;
	    int moves = 0;
	    if(sx == tx && sy == ty) return 0;
	    while(!q.empty()){
	        int size = q.size();
	          moves++;
	        for(int i = 0;i < size;i++){
	            auto curr = q.front();
    	        int x = curr.first;
    	        int y = curr.second;
    	        q.pop();
    	      
    	        //if(x == tx && y == ty) return moves;
    	        for(auto it: dir){
    	            int nx = x + it[0];
    	            int ny = y + it[1];
    	            if(nx == tx && ny == ty) return moves;
    	            if(nx >= 0 && nx < n && ny >= 0 && ny < n){
    	                if(!vis[nx][ny]){
    	                    vis[nx][ny] = true;
    	                    q.push({nx, ny});
    	                }
    	            }
    	        }  
	        }
    	      
	    }
	    
	    return moves;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends