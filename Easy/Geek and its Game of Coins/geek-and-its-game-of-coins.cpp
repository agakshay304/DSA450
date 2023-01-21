//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
	int dp[1000001];
// here dp[i] = true means A win for n = i
int helper(int N,int X,int Y){
    if(N == 0) return (0);
    if(N == 1) return (1);
    
    if(dp[N] != -1) return (dp[N]);
    
    int res1 = N-X >= 0 ? helper(N-X,X,Y) : 1;
    if(res1 == 0) return (dp[N] = 1);
    int res2 = N-Y >= 0 ? helper(N-Y,X,Y) : 1;
    if(res2 == 0) return (dp[N] = 1);
    int res3 = N-1 >= 0 ? helper(N-1,X,Y) : 1;
    if(res3 == 0) return (dp[N] = 1);
    return (dp[N] = 0);
}

int findWinner(int N, int X, int Y)
{
    memset(dp,-1,sizeof(dp));
 return helper(N,X,Y);
}

};
	

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
       	int n, x, y;
       	cin >> n >> x >> y;

       

        Solution ob;
        cout << ob.findWinner(n, x, y);
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends