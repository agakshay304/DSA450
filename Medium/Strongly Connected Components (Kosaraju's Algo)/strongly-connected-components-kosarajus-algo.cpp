//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	int dfs1(int v,vector<int> adj[],vector<int> &vis,int target,stack<int> &s)
	{
	    vis[target]=1;
	    
	    for(int x:adj[target])
	    {
	        if(!vis[x])
	        {
	            dfs1(v,adj,vis,x,s);
	        }
	    }
	    s.push(target);
	}
	
	int dfs2(int v,vector<int> adj2[],vector<int> &vis,int target)
	{
	    vis[target]=1;
	    
	    for(int x:adj2[target])
	    {
	        if(!vis[x])
	        {
	            dfs2(v,adj2,vis,x);
	        }
	    }
	    
	}
    int kosaraju(int V, vector<int> adj[])
    {
        //Approach:
        //1. Call the dfs and store according to dfs completion time in a stack
        //2. Reverse the adj list so that NON SCC is not accesible
        //3, Call another dfs function with reference to the stack elements present.
        
        vector<int> vis(V,0);
        stack<int> s;
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            dfs1(V,adj,vis,i,s);
        }
        
        
        //Reversing the graph adj list
        vector<int> adj2[V];
        for(int i=0;i<V;i++)
        {
            for(auto x:adj[i])
            {
                adj2[x].push_back(i);
            }
        }
        for(int i=0;i<V;i++)
        {
            vis[i]=0;
        }
        //Calling dfs for stack
        int ans=0;
        while(!s.empty())
        {
            int node=s.top();
            s.pop();
            if(!vis[node])
            {
            ans++;
            dfs2(V,adj2,vis,node);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends