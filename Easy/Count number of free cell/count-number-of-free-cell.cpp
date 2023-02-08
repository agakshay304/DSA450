//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

#define ll long long int
class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      
      unordered_set<int> row;
      unordered_set<int> col;
      
      vector<ll> ans(k,0);
      ll total_zero=n*n;
      ll total_one,r,c;
      
      for(int i=0;i<k;i++)
      {
          row.insert(arr[i][0]);
          col.insert(arr[i][1]);
          
          r=row.size();
          c=col.size();
          
          total_one=((r+c)*n)-(r*c);
          
          ans[i]=total_zero-total_one;
      }
      return ans;
  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends