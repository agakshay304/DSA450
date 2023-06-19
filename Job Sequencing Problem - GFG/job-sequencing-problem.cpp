//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool comp(Job a,Job b)
    {
        return a.profit>b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
       vector<int> ans(2);
       
       sort(arr,arr+n,comp);
       int max_dead=INT_MIN;
       
       for(int i=0;i<n;i++)
           max_dead=max(max_dead,arr[i].dead);
        
        vector<int> slots(max_dead+1,-1);
        
        int count_jobs=0;
        int jobs_sum=0;
        
        for(int i=0;i<n;i++){
            int curr_job=arr[i].id;
            int curr_dead=arr[i].dead;
            int curr_profit=arr[i].profit;
            
            for(int j=curr_dead;j>0;j--)
            {
                if(slots[j]==-1)
                {
                    slots[j]=curr_job;
                    count_jobs++;
                    jobs_sum+=curr_profit;
                    break;
                }
            }
        }
        
        ans[0]=count_jobs;
        ans[1]=jobs_sum;
        
        return ans;
       
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends