//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int solve(vector<vector<int> > &dp,vector<int> arr,int k,int i,int j)
    {
        if(i>=j)
        return 0;
        
        if(arr[j]-arr[i]<=k)
        return 0;
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        if(arr[j]-arr[i]>k)
        return dp[i][j]=1+min(solve(dp,arr,k,i+1,j),solve(dp,arr,k,i,j-1));
    }
    
    int removals(vector<int>& arr, int k){
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        return solve(dp,arr,k,0,n-1);
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends