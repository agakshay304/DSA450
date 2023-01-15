//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    //Approach 
	    //1. Same as LIS 
	    //2. here instead of initialising 1d DP with 1 and incrementing by 1.
	    //3. We will initialise with the same arr[i] value
	    //4.and will increment by the prev number instead of 1
	    
	    vector<int> dp(n);
	    for(int i=0;i<n;i++)
	    {
	        dp[i]=arr[i];
	    }
	    int ans=INT_MIN;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<i;j++)
	        {
	            if(arr[j]<arr[i])
	            {
	                dp[i]=max(dp[i],dp[j]+arr[i]);
	            }
	        }
	       ans=max(ans,dp[i]); 
	    }
	    return ans;
	    
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends