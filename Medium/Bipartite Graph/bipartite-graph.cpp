//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool bfs(vector<int> adj[],vector<int> &visited,int target)
    {
        queue<int> q;
	    q.push(target);
	    visited[target]=0;
        while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        
	        for(auto x:adj[node])
	        {
	            if(visited[x]==-1)
	            {
	                visited[x]=!visited[node];
	                q.push(x);
	            }
	            else if(visited[x]==visited[node])
	            {
	                return false;
	            }
	            
	        }
	    }
	    return true;
    }
	bool isBipartite(int V, vector<int>adj[]){

	    vector<int> visited(V,-1);

	    for(int i=0;i<V;i++)
	    {
	        if(visited[i]==-1)
	        {
	            if(!bfs(adj,visited,i))
	            return false;
	        }
	    }
	    return true;
	    
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends