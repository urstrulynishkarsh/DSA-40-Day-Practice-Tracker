
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

void printLeftNodes(Node *root,vector<int> &ans)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        return;
    }
    ans.push_back(root->data);
    if(root->left)
        printLeftNodes(root->left,ans);
    else
        printLeftNodes(root->right,ans);
}



void  printLeafNodes(Node *root,vector<int> &ans)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        ans.push_back(root->data);
        return;
    }
     printLeafNodes(root->left,ans);
     printLeafNodes(root->right,ans);
}

void printRightNodes(Node *root,vector<int> &ans)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        return;
    }
    if(root->right)
        printRightNodes(root->right,ans);
    else 
        printRightNodes(root->left,ans);
      ans.push_back(root->data);
}


void BoundaryTraversal(Node *root, vector<int> &ans)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
            return;
        }
    ans.push_back(root->data);
    printLeftNodes(root->left,ans);
    printLeafNodes(root,ans);
    printRightNodes(root->right,ans);
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
    vector<int> ans;
    BoundaryTraversal(root,ans);
    for(int val:ans)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}
