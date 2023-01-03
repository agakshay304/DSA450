//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    //Approach
    // 1.We will think it as a pascal Triangle approach
    // 2.Rows will be value of n 
    // 3.Cols will be value of r 
    // 4.Each box in a matrix represent nCr
    
    int dp[1001][1001];
    
    int nCr(int n, int r){
        
        memset(dp,0,sizeof(dp));
        
        int mod=1e9+7;
       
       //first row first and second element will always be 1
       dp[0][0]=1;
       dp[0][1]=1;
       
       //All rows will be intialised with 1
       for(int i=0;i<=n;i++)
       {
           for(int j=0;j<=r;j++)
           {
               if(j==0)
               {
                   dp[i][j]=1;
               }
           }
       }
       
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=r;j++)
           {
               dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
           }
       }
       
       return dp[n-1][r];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends