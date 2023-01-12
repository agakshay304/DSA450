//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

    bool isSafe(vector<int> &color,bool graph[101][101],int m,int n,int col,int node)
    {
        for(int k=0;k<n;k++)
        {
            if(k!=node and graph[k][node]==1 and color[k]==col)
            return false;
        }
        return true;
    }

    bool solve(vector<int> &color,bool graph[101][101],int m,int n,int node)
    {
        if(node==n)
        return true;
        
        for(int i=1;i<=m;i++)
        {
            if(isSafe(color,graph,m,n,i,node))
            {
                color[node]=i;
                if(solve(color,graph,m,n,node+1))
                return true;
            }
            color[node]=0;
        }
        return false;
    }

    bool graphColoring(bool graph[101][101], int m, int n) {
        
        vector<int> color(n,0);
        
        if(solve(color,graph,m,n,0))
        return true;
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends