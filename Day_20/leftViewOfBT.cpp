
#include<iostream>
#include<queue>
#include<map>
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

void leftViewBT(Node *root, vector<int> &ans,int level)
{
    if(root==NULL)
    {
        return;
    }
    if(ans.size()==level)
    {
        ans.push_back(root->data);
    }
    leftViewBT(root->left,ans,level+1);
    leftViewBT(root->right,ans,level+1);
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
    int level=0;
    vector<int> ans;
    leftViewBT(root,ans,level);
    for(int val:ans)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}
