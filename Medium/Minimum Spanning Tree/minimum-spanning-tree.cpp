//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//This File Contains Solution Both in Kruskal as well as Prims;

//Kruskal's Algorithm ->

class DSU
{
    vector<int> rank,parent;
    public:
    DSU(int v)
    {
        rank.resize(v+1,0);
        parent.resize(v+1);
        
        for(int i=0;i<v+1;i++)
        {
            parent[i]=i;
        }
    }
    
    int findParent(int v)
    {
        if(v==parent[v])
        {
            return v;
        }
        //Compression
        return parent[v]=findParent(parent[v]);
    }
    
    void unionTree(int u,int v)
    {
        int u_parent=findParent(u);
        int v_parent=findParent(v);
        
        if(u_parent==v_parent)
        return ;
        
        if(rank[u_parent]<rank[v_parent])
        {
            parent[u_parent]=v_parent;
        }
        else if(rank[v_parent]<rank[u_parent])
        {
            parent[v_parent]=u_parent;
        }
        else
        {
            rank[u_parent]++;
            parent[v_parent]=u_parent;
        }
    }
};
class Solution
{
	public:
	int spanningTree(int V, vector<vector<int>> adj[])
	{
	    int ans=0;
	    //<weight,u,v>
	    vector<pair<int,pair<int,int>>> nodes;
	    for(int i=0;i<V;i++)
	    {
	        for(auto x:adj[i])
	        {
	            int weight=x[1];
	            int v=x[0];
	            int u=i;
	            
                nodes.push_back(make_pair(weight,make_pair(u,v)));
	        }
	    }
	    sort(nodes.begin(),nodes.end());
	    
	    //Just Printing & Checking
	   // for(int i=0;i<2*V;i++)
	   // {
	   //     cout<<nodes[i].first<<"->"<<nodes[i].second.first<<"->"<<nodes[i].second.second<<endl;
	   // }
	   
	   DSU dsu(V);
	   
	   for(int i=0;i<nodes.size();i++)
	   {
	       int newu=nodes[i].second.first;
	       int newv=nodes[i].second.second;
	       int newWt=nodes[i].first;
	        if(dsu.findParent(newu)!=dsu.findParent(newv))
	        {
	            dsu.unionTree(newu,newv);
	            ans+=newWt;
	        }
	   }
	    return ans;
	}
	

	
	//Prim's Algorithm ->
	
    // int spanningTree(int V, vector<vector<int>> adj[])
    // {
    //     //<Weight, Node> 
    //     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > q;
    //     vector<int> visited(V,0);
    //     q.push(make_pair(0,0));
    //     int ans=0;
    //     while(!q.empty())
    //     {
    //         auto temp=q.top();
    //         q.pop();
            
    //         int wt=temp.first;
    //         int node=temp.second;

    //         if(visited[node])
    //         continue;
            
    //         visited[node]=1;
    //         ans+=wt;
    //         for(auto x:adj[node])
    //         {
    //             int newWt=x[1];
    //             int newNode=x[0];
    //             if(!visited[newNode])
    //             {
    //                 q.push(make_pair(newWt,newNode));
    //             }
    //         }
    //     }
    //     return ans;
    // }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends