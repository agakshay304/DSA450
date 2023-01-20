//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
     long long int  countPS(string str)
    {
       //Your code her
       
       int mod = 1e9+7;
       
       long long dp[str.length()][str.length()];
       
       for(int g = 0; g<str.length(); g++)
       {
           for(int i = 0, j = g; j<str.length(); i++,j++)
           {
              if(g == 0)
              {
                dp[i][j] = 1;  
              }
              
              else if(g == 1)
              {
                dp[i][j] = (str[i] == str[j]) ? 3 : 2;
              }
              
              else
              {
                  if(str[i] == str[j])
                  {
                      dp[i][j] = (dp[i][j-1] + dp[i+1][j] + 1) % mod;
                  }
                  
                  else
                  {
                      dp[i][j] = (dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1]) % mod;
                  }
              }
           }
       }
       
       return (mod + dp[0][str.length()-1]) % mod;
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends