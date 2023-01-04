//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int dp[1001][1001];
    int LCS(string s,int n,string t,int m)
    {
        //Initialisation
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++)
            {
                if(j==0)
                {
                    dp[i][j]=i;
                }
                if(i==0)
                dp[i][j]=j;
            }
        }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=1+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    int editDistance(string s, string t) {
        memset(dp,-1,sizeof(dp));
       int n=s.size();
       int m=t.size();
       int ans=LCS(s,n,t,m);
       
    //   return ((m-ans)+(n-ans));
    return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends