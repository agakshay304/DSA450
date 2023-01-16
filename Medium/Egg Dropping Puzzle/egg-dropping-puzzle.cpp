//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int t[201][201];
     int solve(int n,int k)
        {
        if(k==0 ||k==1)
            return k;
            
        if(n==1)
            return k;
            
        if(t[n][k]!=-1)
            return t[n][k];
            
        int mn=INT_MAX;
        for(int i=1;i<=k;i++)
        {
            int temp=1+ max(solve(n-1,i-1),solve(n,k-i));
            mn=min(mn,temp);
        }
        return t[n][k]=mn;

    }
    int eggDrop(int n, int k) 
    {
        //Approach:
        //1.Here we will use MCM code snippet
        //2.We will start dropping the egg from first floor
        //3.At any floor their will be two possiblity either egg with break or will not break
        //4.If it will not break decrease just floor recursively
        //5.Else decrease egg and the threshold floor will be k-1 if k is breaking point.
        
        
        //Recursive Solution: 
       memset(t,-1,sizeof(t));
       return solve(n,k);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends