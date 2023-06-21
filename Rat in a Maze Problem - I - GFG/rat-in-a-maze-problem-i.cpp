//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(int row,int col,vector<vector<int>> &m,int n,vector<string> &ans,string temp,vector<vector<int>> &vis)
    {
        if(row<0 || row>=n || col<0 || col>=n || m[row][col]==0 || vis[row][col]==1)
        return ;
        if(row==n-1 and col==n-1 and m[row][col]==1)
        {
            ans.push_back(temp);
            return ;
        }
        
        vis[row][col]=1;
        //D
        solve(row+1,col,m,n,ans,temp+'D',vis);
        //L
        solve(row,col-1,m,n,ans,temp+'L',vis);
        //R
        solve(row,col+1,m,n,ans,temp+'R',vis);
        //U
        solve(row-1,col,m,n,ans,temp+'U',vis);
        vis[row][col]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
       vector<string> ans;
       vector<vector<int>> vis(n,vector<int>(n,0));
       solve(0,0,m,n,ans,"",vis);
       
       return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends