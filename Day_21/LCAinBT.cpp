
#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include<string.h>
using namespace std;
static int idx=-1;
class Node{
    public:
    int data;
    Node *left,*right;
    Node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }

};



Node *buildtree(vector<int> &nums)
{
    idx++;
    if(nums[idx]==-1)
    {
        return NULL;
    }
    Node *root=new Node(nums[idx]);
    root->left=buildtree(nums);
    root->right=buildtree(nums);
    return root;
}

Node * LCA(Node* root, Node *p, Node *q)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==p->data)
    {
        return p;
    }
    if(root->data==q->data)
    {
        return q;
    }
    Node *leftAns=LCA(root->left,p,q);
    Node *rightAns=LCA(root->right,p,q);

    if(leftAns==NULL && rightAns==NULL)
    {
        return NULL;
    }
    else if(leftAns!=NULL && rightAns==NULL){
        return leftAns;
    }
    else if(leftAns==NULL && rightAns!=NULL)
    {
        return rightAns;
    }
    else{
        return root;
    }
}


int main()
{
    int n;
    cout<<"Enter the size of Array: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the element in the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    Node *root=buildtree(nums);
    int p,q;
    cout<<"Enter the value of p and q node: ";
    cin>>p>>q;
    Node *pq=new Node(p);
    Node *qp=new Node(q);
    Node *ans=LCA(root,pq,qp);
    cout<<ans->data;
    cout<<endl;
    return 0;
}
