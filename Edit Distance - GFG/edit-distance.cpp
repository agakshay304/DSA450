//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  //Approach:
  //1.The above problem is not a part of LCS.
  //2.Because here one more operation that is replace char is added.
  //3.In initialisation we have to initialise the 0 row or col with
  //  its respective size (which represents number of insertion)
  //4.In the main loop we will take the min of three i.e (insertion,deletion or replacement)
  //5.Finally 1 is added to add one operation in either of the three cases
  
  
    int dp[1001][1001];
    int solve(string s,int n,string t,int m)
    {
        //Initialisation
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++)
            {
                if(j==0)
                    dp[i][j]=i;
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
       int ans=solve(s,n,t,m);
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