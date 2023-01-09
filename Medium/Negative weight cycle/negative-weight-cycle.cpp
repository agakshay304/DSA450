//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	   //Approach:
	   //1.We will do Relaxing of edges n-1 times
	   //2.In case the graph contain negative cycle nth time too it will give a shorter distance which is not possible.
	   
	   int ans=0;
	   vector<int> distance(n,1e9);
	   distance[0]=0;
	   
	   //int n=edges.size();
	   //int m=edges[0].size();
	   
	   for(int j=0;j<n-1;j++)
	   {
	       for(auto x:edges)
	       {
	           int u=x[0];
	           int v=x[1];
	           int w=x[2];
	           
	           if(distance[u]!=1e9 and distance[u]+w<distance[v])
	           distance[v]=distance[u]+w;
	       }
	   }
	   
	   for(int i=0;i<n;i++)
	   {
	       for(auto x:edges)
	       {
	           int u=x[0];
	           int v=x[1];
	           int w=x[2];
	           
	           if(distance[u]!=1e9 and distance[u]+w<distance[v])
	           return true;
	       }
	   }
	   return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends