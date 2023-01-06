//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    //Approach:
    //1. We will iterate from back of matrix keeping column constant
    //2. From back side we will check all the three direction that is right,right up,right down
    //3. of the three choices we will choose the max and store in dp table
    //4. At the last we will check the max value in our 0th Col of dp table

    int maxGold(int n, int m, vector<vector<int>> M)
    {
       vector<vector<int> >dp(n,vector<int>(m,0));
       int ans=0;
       
       if(n==1)
       {
           for(int i=0;i<m;i++)
           {
              ans+=M[0][i]; 
           }
           return ans;
       }
       
       for(int j=m-1;j>=0;j--)
       {
           for(int i=n-1;i>=0;i--)
           {
               //Four cases
               //Case 1:we are at the last column (no choice) 
               //Case2: We are at the last row (2 choice)
               //Case3: We are at the first row (2 Choice)
               //Case 4: We are somewhere in between of table
               
               //Case 1->
               if(j==m-1)
               {
                   dp[i][j]=M[i][j];
               }
               //Case 2->
               else if(i==n-1)
               {
                   dp[i][j]=M[i][j]+max(dp[i-1][j+1],dp[i][j+1]);
               }
               //Case 3->
               else if(i==0)
               {
                   dp[i][j]=M[i][j]+max(dp[i+1][j+1],dp[i][j+1]);
               }
               //Case 4->
               else
               {
                   dp[i][j]=M[i][j]+max(dp[i][j+1],max(dp[i+1][j+1],dp[i-1][j+1]));
               }
           }
       }
       
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
              if(j==0)
              {
                  ans=max(ans,dp[i][j]);
              }
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
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends