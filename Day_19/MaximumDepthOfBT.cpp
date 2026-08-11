
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

int height(Node *&root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
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
    cout<<height(root);
    
   
    return 0;
}
