//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        vector<int> row_wise_sum, col_wise_sum;
        int maxi = INT_MIN;
        for(int i = 0;i < n;i++){
            int sum  = 0;
            for(int j = 0;j < n;j++){
                sum += matrix[i][j];
            }
            maxi = max(maxi, sum);
            row_wise_sum.push_back(sum);
        }
        
        for(int j = 0;j < n;j++){
            int sum = 0;
            for(int i = 0;i < n;i++){
                sum += matrix[i][j];
            }
            maxi = max(maxi, sum);
            col_wise_sum.push_back(sum);
        }
        
       // for(auto it: row_wise_sum) cout << it << " ";
        
        int cnt = 0;
        for(int i = 0;i < row_wise_sum.size();i++) 
            cnt += maxi - row_wise_sum[i];
        return cnt;
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
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends