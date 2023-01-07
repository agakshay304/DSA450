//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //<Weight, Node> 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > q;
        vector<int> visited(V,0);
        q.push(make_pair(0,0));
        int ans=0;
        while(!q.empty())
        {
            auto temp=q.top();
            q.pop();
            
            int wt=temp.first;
            int node=temp.second;
            
            
            if(visited[node])
            continue;
            
            visited[node]=1;
            ans+=wt;
            for(auto x:adj[node])
            {
                int newWt=x[1];
                int newNode=x[0];
                if(!visited[newNode])
                {
                    q.push(make_pair(newWt,newNode));
                }
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