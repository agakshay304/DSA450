//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    bool isValid(int x,int y,vector<vector<bool>> &vis,int n)
    {
        if(x<0 || x>=n ||y < 0 || y>=n || vis[x][y]==1)
        return false;
        
        return true;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    int x=KnightPos[0]-1; int y=KnightPos[1]-1;
	    int xt=TargetPos[0]-1; int yt=TargetPos[1]-1;
	    
	    if(x==xt and y==yt)
	    return 0;
	    
	    queue<pair<int,int> >  q;
	    q.push(make_pair(x,y));
	    vector<vector<bool>> vis(n,vector<bool>(n,false));
	    vis[x][y]=1;
	    int ans=0;
	    while(!q.empty())
	    {
	        int size=q.size();
	        ans++;
	        for(int i=0;i<size;i++)
	        {
	            auto temp=q.front();
	            q.pop();
	            
	            x=temp.first;
	            y=temp.second;
	            
	            int posx[8]={1,1,-1,-1,2,-2,2,-2};
	            int posy[8]={2,-2,2,-2,1,1,-1,-1};
	            
	            for(int i=0;i<8;i++)
	            {
	                int newx=x+posx[i];
	                int newy=y+posy[i];
	                
	                if(newx==xt and newy==yt)
	                {
	                    return ans;
	                }
	                
	                if(isValid(newx,newy,vis,n))
	                {
	                    vis[newx][newy]=1;
	                    q.push(make_pair(newx,newy));
	                }
	            }
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends