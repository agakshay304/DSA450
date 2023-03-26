//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
      int unvisitedLeaves(int N, int leaves, int frogs[]) {
        vector<bool> leaf(leaves+1,true);
        for(int i=0;i<N;i++)
        {
            if(frogs[i]>leaves||leaf[frogs[i]]==false)continue;
            
            for(int j=frogs[i];j<=leaves;j+=frogs[i])
            {
                leaf[j]=false;
            }
        }
        int ans=0;
        for(int i=1;i<=leaves;i++)
        {
            if(leaf[i]==true)ans++;
        }
        return ans;
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends