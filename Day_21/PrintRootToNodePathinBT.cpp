
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

void binaryTreePaths(Node *&root, vector<string> &ans, string paths)
{   
    if(root->left==NULL && root->right==NULL)
    {
        ans.push_back(paths);
        return;
    }
    if(root->left)
    {
        binaryTreePaths(root->left,ans,paths+"->"+to_string(root->left->data));
    }
    if(root->right)
    {
        binaryTreePaths(root->right,ans,paths+"->"+to_string(root->right->data));
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
    vector<string> ans;
    string path=to_string(root->data);
    binaryTreePaths(root,ans,path);
    for(auto val:ans)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}
