//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
    public:
    int helper(vector<int>&dp,int n,int x,int y,int z){

        if(n==0){
            return 0;
        }

        if(n<0){
            return INT_MIN;
        }

        if(dp[n]!=-1){
            return dp[n];
        }

        int sumx = helper(dp,n-x,x,y,z);
        int sumy = helper(dp,n-y,x,y,z);
        int sumz = helper(dp,n-z,x,y,z);

        return dp[n] = 1+max(sumx,max(sumy,sumz));

    }

    

    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n+1,-1);

        int ans = helper(dp,n,x,y,z);

        if(ans<0){

            return 0;

        }

        else{

            return ans;

        }

    }

};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends