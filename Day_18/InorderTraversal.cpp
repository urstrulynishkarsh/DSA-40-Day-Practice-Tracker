
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

void solve(Node *root, vector<int> &ans)
{
    if(root==NULL)
    {
        return ;
    }
   
    solve(root->left,ans);
     ans.push_back(root->data);
    solve(root->right,ans);
}

vector<int> inorder(Node *root)
{   
    vector<int> ans;
    solve(root,ans);
    return ans;
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
    
    return 0;
}
