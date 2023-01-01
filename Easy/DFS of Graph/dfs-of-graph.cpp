//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void dfs(int V,vector<int> adj[],vector<bool> &visited,vector<int> &ans,int target)
    {
        if(visited[target]==1)
        return;
        
        visited[target]=1;
        ans.push_back(target);
        for(auto x: adj[target])
        {
            if(!visited[x])
            {
                dfs(V,adj,visited,ans,x);
            }
        }
        return ;
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
       
       vector<int> ans;
       
       vector<bool> visited(V,0);
       
       for(int i=0;i<V;i++)
       {
           if(!visited[i])
           {
               dfs(V,adj,visited,ans,i);
           }
       }
       return ans;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends