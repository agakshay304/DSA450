//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    void dfs(vector<vector<char>>& grid,int n,int m,vector<vector<int> > &visited,int x,int y)
    {
        if(x<0 || x>=n || y<0 || y>=m || visited[x][y]==1 || grid[x][y]=='0')
        {
            return ;
        }
        
        visited[x][y]=1;
        
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                int newx=x+i;
                int newy=y+j;
                if(newx>=0 and newx<n and newy>=0 and newy<m)
                {
                if(!visited[newx][newy] and grid[newx][newy]=='1')
                {
                    dfs(grid,n,m,visited,newx,newy);
                }
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       vector<vector<int> >visited(n,vector<int>(m,0));
       int count=0;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(!visited[i][j] and grid[i][j]=='1')
               {
                   dfs(grid,n,m,visited,i,j);
                   count++;
               }
           }
       }
       return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends