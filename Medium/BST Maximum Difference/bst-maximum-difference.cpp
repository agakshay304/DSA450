//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int tilltarget=0;
    int aftertarget=INT_MAX;
    Node* tar=NULL;
    
    int maxDifferenceBST(Node *root,int target){
       find(root,target,0);
       if(tar==NULL)
       return -1;
       
       minSum(tar,0);
       return tilltarget-aftertarget+target;
    }
    
    void find(Node* root,int target,int sum)
    {
        if(root==NULL)
        return ;
        
        if(root->data==target)
        {
            tilltarget=sum;
            tar=root;
        }
        find(root->left,target,sum+root->data);
        find(root->right,target,sum+root->data);
    }
    
    void minSum(Node* root,int sum)
    {
        if(root==NULL)
        return ;
        
        sum+=root->data;
        if(root->left==NULL and root->right==NULL)
        {
            aftertarget=min(aftertarget,sum);
            return ;
        }
        minSum(root->left,sum);
        minSum(root->right,sum);
    }
    
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends