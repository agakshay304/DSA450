//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int N, int M, int x, int y){    
        // code here
        int cnt=0;
        int dx[]={0,1,0,-1};
        int dy[]={-1,0,1,0};
        vector<vector<int>>vis(N,vector<int>(M,0));
        queue<pair<int,int>>q;
        q.push({x-1,y-1});
        vis[x-1][y-1]=1;
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nr=i+dx[k];
                int nc=j+dy[k];
                if(nr>=0 and nr<N and nc>=0 and nc<M and vis[nr][nc]==0){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
            }
            ans++;
        }
        return ans-1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends