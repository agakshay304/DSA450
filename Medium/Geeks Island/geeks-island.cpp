//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    
    vector<vector<int>> dir{
        {0,1},
        {1,0},
        {0,-1},
        {-1,0}
    };
    
    bool isPos(int x,int y,vector<vector<int>> &arr,vector<vector<bool>> &vis,int &curr){
        int n = arr.size();
        int m = arr[0].size();
        if(x < 0 || y<0 || x>=n || y>=m || vis[x][y] || curr>arr[x][y]) return false;
        return true;
    }
    
    void dfs(vector<vector<int>> &arr,vector<vector<bool>> &sea,int i,int j){
        sea[i][j] = 1;
        int curr = arr[i][j];
        for(auto dirr : dir){
            int x = i + dirr[0];
            int y = j + dirr[1];
            if(isPos(x,y,arr,sea,curr))
                dfs(arr,sea,x,y);
            }
    }


    int water_flow(vector<vector<int>> &arr,int n,int m){
        vector<vector<bool>> sea1(n,vector<bool> (m,false));
        vector<vector<bool>> sea2(n,vector<bool> (m,false));
        for(int i= 0 ; i<n;i++){
            dfs(arr,sea1,i,0);
            dfs(arr,sea2,i,m-1);
        }
        for(int i =  0 ;i<m;i++){
            dfs(arr,sea1,0,i);
            dfs(arr,sea2,n-1,i);
        }
        int ans =0 ;
        for(int i =0 ; i<n;i++){
            for(int j =0 ;j<m;j++){
                if(sea1[i][j] && sea2[i][j]) ans++;
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends