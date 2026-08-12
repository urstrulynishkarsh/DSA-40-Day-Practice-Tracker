
#include<iostream>
#include<vector>
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

bool checkmirror(Node *left,Node *right)
{
    
    if(left==NULL && right==NULL)
    {
        return true;
    }
    if(left==NULL || right==NULL)
    {
        return false;
    }
    if(left->data!=right->data)
    {
        return false;
    }
    return checkmirror(left->left,right->right) && checkmirror(left->right,right->left);
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
    if(root==NULL)
    {
        cout<<true;
    }
    cout<<checkmirror(root->left,root->right);
    cout<<endl;
    return 0;
}
