//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
     int minimizeSum(int N, vector<int> arr) {

        // code her

 

     priority_queue<int>pq ;

     

     for( auto i : arr )

     {

         pq.push(-1*i) ;

     }

     

     int ans = 0 ;

     

     while (pq.size() > 1 )

     {

         int a = -1*pq.top() ;

         pq.pop() ;

         

         int b = -1*pq.top() ;

         pq.pop() ;

         

         ans += a + b ;

         pq.push(-1*(a+b)) ;

     }

     

     return ans ;

    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minimizeSum(n, arr) << "\n";
    }
}
// } Driver Code Ends