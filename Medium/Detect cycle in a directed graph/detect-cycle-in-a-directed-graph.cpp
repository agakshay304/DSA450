//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool checkCycle(int V,vector<int> adj[],vector<bool> &vis,vector<bool> &dfsvis,int target)
    {
        vis[target]=1;
        dfsvis[target]=1;
        
        for(auto x:adj[target])
        {
            if(!vis[x])
            {
            if(checkCycle(V,adj,vis,dfsvis,x))
            return true;
            }
            else if(dfsvis[x])
            return true;
        }
        
        dfsvis[target]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        
        vector<bool> visited(V,0);
        vector<bool> dfsVisited(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(checkCycle(V,adj,visited,dfsVisited,i))
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends