
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



vector<int> inorder(Node *root)
{   
    vector<int> ans;
    Node *curr=root;
    while(curr)
    {
        if(curr->left==NULL)
        {
            ans.push_back(curr->data);
            curr=curr->right;
        }
        else{
            Node *pred=curr->left;
            while(pred->right)
            {
                pred=pred->right;
            }
            if(pred->right==NULL)
            {
                pred->right=curr;
                ans.push_back(curr->data);
                curr=curr->left;
            }
            else{
                pred->right=NULL;
                curr=curr->right;
            }
        }
    }
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
    vector<int> result=inorder(root);
    for(int num:result)
    {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
