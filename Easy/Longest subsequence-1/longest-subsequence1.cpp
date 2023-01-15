//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int longestSubsequence(int n, int A[])
    {
        //Approach:
        //1. Same as LIS
        //2.Instead of increasing seq we will check abs(arr[i]-arr[j])==1
        
        vector<int> dp(n,1);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(abs(A[i]-A[j])==1)
                {
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends