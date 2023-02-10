//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        
        int l=s.size();
        
        map<char,int> mp;
        
        for(int i=0;i<l;i++)
        {
            mp[s[i]]++;
        }
        
        mp['l']=mp['l']/2;
        mp['o']=mp['o']/2;
        
        int temp=min(mp['b'],mp['a']);
        int temp1=min(mp['l'],min(mp['o'],mp['n']));
        return min(temp,temp1);
        
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends