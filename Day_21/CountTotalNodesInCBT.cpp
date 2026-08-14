
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

int getleftNodes(Node *root)
{
    Node *temp=root;
    int lh=0;
    while(temp)
    {
        /* code */
        temp=temp->left;
        lh++;
    }
    return lh;
}
int getrightNodes(Node*root)
{
    Node *temp=root;
    int rh=0;
    while(temp)
    {
        temp=temp->right;
        rh++;
    }
    return rh;
}
int countNodesCBT(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lh=getleftNodes(root);
    int rh=getrightNodes(root);
    if(lh==rh)
    {
        return pow(2,lh)-1;
    }

    return countNodesCBT(root->left)+countNodesCBT(root->right)+1;
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
  
    cout<<countNodesCBT(root);
   
    cout<<endl;
    return 0;
}
