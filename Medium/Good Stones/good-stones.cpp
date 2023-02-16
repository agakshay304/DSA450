//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
        int goodStones(int n,vector<int> &arr){
        // Code here
        vector<int> dp(n,0);
        
        for(int i=0;i<n;i++){
            if(dp[i] == 0){
                int temp=i;
                bool good = false;
                while(dp[temp] != 1){
                    if(arr[temp] == 0) break;
                    dp[temp] = 1;
                    temp += arr[temp];
                    if(temp<0 || temp>=n || dp[temp] == 2){
                        good = true;
                        break;
                    }
                }
                
                if(good){
                    temp = i;
                    while(temp>=0 && temp<n){
                        dp[temp] = 2;
                        temp += arr[temp];
                    }
                }
            }
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            if(dp[i] == 2){
                ans++;
            }
        }
        
        return ans;
    }  
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends