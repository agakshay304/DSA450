//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
       //Approach
       //1. We will use a formula min(a[i][j-1],min(a[i-1][j-1],a[i-1][j]))
       //2. Out of the minimum we will add 1 and store in our dp
       //3.At the last we will Just return the max value of our dp matrix
       //4.Each value in dp matrix corresponds to number of square possible taking that coordinate as the bottom rightmost
       
       int res = 0;
        for(int i=0;i<n;i++)
            res = max(mat[i][0],res);
            
        for(int i=0;i<m;i++)
            res = max(mat[0][i],res);
            
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(mat[i][j] == 1)
                {
                    int val = min(mat[i-1][j],mat[i][j-1]);
                    mat[i][j] = min(val,mat[i-1][j-1]) + 1;
                }
                res = max(res,mat[i][j]);
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends