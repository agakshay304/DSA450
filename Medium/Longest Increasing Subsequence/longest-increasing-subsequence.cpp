//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    int LCS(int a[],int b[],int n)
    {
        n=n+1;
        vector<vector<int>>dp(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j]=0;
                }
            }
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(a[i-1]==b[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n-1][n-1];
    }
    int longestSubsequence(int n, int a[])
    {
       int b[n];
       int i;
       for(i=0;i<n-1;i++)
       {
           if(a[i]!=a[i+1])
           b[i]=a[i];
       }
       b[i]=a[i];
       sort(b,b+n);
       
       return LCS(a,b,n);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends