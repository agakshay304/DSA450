//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int f(int i,string &s,unordered_set<string>&hash,vector<int>&dp)
    {
        if(i == s.size())
            return true;
        
        if(dp[i] != -1)
            return dp[i];
        for(int j=i;j<s.size();j++)
        {
            string prefix = s.substr(i,j-i+1);
            if(hash.find(prefix) != hash.end())
                if(f(j+1,s,hash,dp))
                    return dp[i] = true;
        }
        return dp[i] = false;
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
        unordered_set<string> hash(B.begin(),B.end());
        vector<int>dp(A.size()+1,-1);
        return f(0,A,hash,dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends