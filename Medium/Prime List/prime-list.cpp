//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
public:
bool check(int n)
{
    for(int i=2;i*i<=n;i++)
        if(n%i==0)return false;
        
    return n>=2;
}
int getVal(int n)
{
    if(check(n)) return n;
    int x = n;
    while(x>=2&&!check(x))
    {
        x--;
    }
    int y = n;
    while(!check(y))
    {
        y++;
    }
    return  x>1?n-x <= y-n ? x :y:y;
}
Node *primeList(Node *head){
    Node*curr = head;
    while(curr)
    {
        curr->val = getVal(curr->val);
        curr=curr->next;
    }
    return head;
}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends