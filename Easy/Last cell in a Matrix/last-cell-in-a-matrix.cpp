//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix, int r, int c){
        
        int x,y;
        int dir=0;
        int i=0;
        int j=0;
        while(i>=0 and j>=0 and i<r and j<c)
        {
            if(matrix[i][j])
            {
                dir=(dir+1)%4;
                matrix[i][j]=0;
            }
            x=i;
            y=j;
            if(dir==0)
            j++;
            else if(dir==1)
            i++;
            else if(dir==2)
            j--;
            else
            i--;
        }
       return make_pair(x,y);
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends