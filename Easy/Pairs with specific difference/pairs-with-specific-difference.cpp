//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k)
    {
       sort(arr,arr+n);
       int ans=0;
       for(int i=n-1;i>0;i--)
       {
           int diff=arr[i]-arr[i-1];
           if(diff<k)
           {
               ans+=arr[i]+arr[i-1];
               i--;
           }
       }
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}

// } Driver Code Ends