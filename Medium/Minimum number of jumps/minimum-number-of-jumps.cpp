//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        //Approach
        //1.Their will be a distance var which stores the max distance which it can take for min jump
        //2.As soon as pos will be i which means it reaches the corner most element of a that jump it will use the distance value
        //3. Example:
        // 1 3 5 8 9 ... 
        // first jump will be of 1 length,2nd of 3 length but after that we have three options 5,8,9 which will be determined by our distance variable
        // as soon as we completes out 3 iteration pos will be i and we will be having the max value between the three.
        
        int pos=0;
        int distance=0;
        int jumps=0;
        for(int i=0;i<n-1;i++)
        {
            distance=max(distance,arr[i]+i);
            
            if(pos==i)
            {
               pos=distance;
               jumps++;
            }
        }
        if(pos>=n-1)
        return jumps;
        return -1;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends