//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long countWays(int n, int k){
        
        //Approach:
        //We will make 2 Rows in the matrix
        //  (a)First Row is "When n-2 elements are something but last 2 are same"
        //  (b)Second Row is "When n-2 elements are something but last 2 are diff"
        //After Some traversing in columns we observe the firstrow = prev secondRow*1
        //And Second Row is Total of prev*k-1
        long long mod=1e9+7;
        long long same=k*1;
        long long diff=(k*(k-1))%mod;
        long long total=(same+diff)%mod;
        
        if(n==1)
        return k;
        
        for(int i=3;i<=n;i++)
        {
            same=diff*1;
            diff=(total*(k-1))%mod;
            total=(same+diff)%mod;
        }
        return total%mod;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends