//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         
        //  [[1, 9], [2, 4], [4, 7], [6, 8]] // sortedorder
        //  [1, 9] [2, 4]
        //  [1, 9] [4 , 7]
        //   9 > 4 we can merge it
        //   similarly for [1, 9] [6, 8] 9 > 6 [1, 9]
          
        //  [[1, 3], [2, 4], [6, 8], [9, 10]]
        //  [1, 3] [2, 4]
        //  3 > 2 --> [1, 4]
        //  [1, 4] [6, 8]
        //  4 < 6 
        //  [6, 8] [9, 10]
        
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int a = intervals[0][0]; // 1
        int b = intervals[0][1]; // 9
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        
        for(int i = 1;i < n;i++){
            if(ans.back()[1] >= intervals[i][0]){
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends