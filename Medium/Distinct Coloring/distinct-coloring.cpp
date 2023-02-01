//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long int f(int ind,int N,int r[],int g[],int b[],int prev,vector<vector<long long int>>& dp)
    {
        if(ind==N) return 0;
        
        if(dp[ind][prev]!=-1) return dp[ind][prev];
        
        long long int taker=1e11,takeg=1e11,takeb=1e11;
        if(prev==0) // If no color painted
        {
            taker=r[ind]+f(ind+1,N,r,g,b,1,dp);
            takeg=g[ind]+f(ind+1,N,r,g,b,2,dp);
            takeb=b[ind]+f(ind+1,N,r,g,b,3,dp);
        }
        else if(prev==1) // If red color painted
        {
            takeg=g[ind]+f(ind+1,N,r,g,b,2,dp);
            takeb=b[ind]+f(ind+1,N,r,g,b,3,dp);
        }
        else if(prev==2) // If Green Color painted
        {
            taker=r[ind]+f(ind+1,N,r,g,b,1,dp);
            takeb=b[ind]+f(ind+1,N,r,g,b,3,dp);
        }
        else // If Blue Color painted
        {
            takeg=r[ind]+f(ind+1,N,r,g,b,1,dp);
            takeb=g[ind]+f(ind+1,N,r,g,b,2,dp);
        }
        return dp[ind][prev]=min(taker,min(takeb,takeg));
    }
    long long int distinctColoring(int N, int r[], int g[], int b[]){
        vector<vector<long long int>>  dp(N,vector<long long int>(4,-1));
        return f(0,N,r,g,b,0,dp);
        // 0 -> no color
        // 1 -> red color
        // 2 -> green color
        // 3 -> blue color
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends