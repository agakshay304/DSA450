//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    int n=S.size();
	    int currSum=0;
	    int ans=0;
	    
	    for(int i=0;i<n;i++)
	    {
	        currSum+=S[i]=='0'? 1:-1;
	        
	        if(currSum<0)
	        currSum=0;
	        
	        ans=max(ans,currSum);
	    }
	    if(ans==0)
	    return -1;
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}

// } Driver Code Ends