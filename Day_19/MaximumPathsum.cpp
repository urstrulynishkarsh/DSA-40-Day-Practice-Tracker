
#include<iostream>
#include<vector>
using namespace std;
static int idx=-1;
class Node{
    public:
    int val;
    Node *left,*right;
    Node(int data)
    {
        this->val=data;
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


int maxsum=INT_MIN;
    int solve(Node *root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int l=solve(root->left);
        int r=solve(root->right);
        int nichekaanswer=l+r+root->val;
        int becchkaanswer=max(l,r)+root->val;
        int upperkaanswer=root->val;
        maxsum=max({maxsum,nichekaanswer,becchkaanswer,upperkaanswer});
        return max(becchkaanswer,upperkaanswer);

    }
    int maxPathSum(Node* root) {
        
        solve(root);
        return maxsum;
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
    maxPathSum(root);
    cout<<maxsum;
    
   
    return 0;
}
