//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool detectCycle(int V,vector<int> adj[],vector<bool> &visited,int target,int parent)
    {
         visited[target]=1;
        
        for(auto x: adj[target])
        {
            if(!visited[x])
            {
            if(detectCycle(V,adj,visited,x,target))
                return true;
            }
            else if(parent!=x)
            return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        
        vector<bool> visited(V,0);
        bool ans=false;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(detectCycle(V,adj,visited,i,-1))
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends