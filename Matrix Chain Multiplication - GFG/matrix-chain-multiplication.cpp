//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
        int solve(int arr[],int n,int i,int j,vector<vector<int>> &dp)
    {
        if(i>=j)
        return 0;
        int ans=INT_MAX;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        for(int k=i;k<j;k++)
        {
            int tempans=solve(arr,n,i,k,dp)+solve(arr,n,k+1,j,dp)+arr[i-1]*arr[k]*arr[j];
            if(tempans<ans)
            ans=tempans;
        }
        return dp[i][j]=ans;
    }
    
    int matrixMultiplication(int n, int arr[])
    {
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        return solve(arr,n,1,n-1,dp);
    }

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends