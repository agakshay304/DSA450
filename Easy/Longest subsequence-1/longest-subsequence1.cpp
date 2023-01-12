//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{

public:

    int f(int n,int arr[],int i,int p){

        if(i==n) return 0;

        int nt=f(n,arr,i+1,p);

        int t=0;

        if((arr[p]-arr[i])==1 || p==-1 ||(arr[p]-arr[i])==-1) t=1+f(n,arr,i+1,i);

        return max(t,nt);

    }

    int longestSubsequence(int n, int arr[])

    {

        // code here

        return f(n,arr,0,-1);

    }

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends