
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

int widthOfBinaryTree(Node *root) {
        // code here
    if(root==NULL)
    {
        return 0;
    }
    queue<pair<Node *,unsigned long long> >q;
    q.push({root,0});
    int ans=0;

    while(!q.empty())
    {
        unsigned long long first;
        unsigned long long second;
        unsigned long long start=q.front().second;
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            Node *currNode=q.front().first;
            unsigned long long index=q.front().second;
            q.pop();
            index=index-start;
            if(i==0)
            {
                first=index;
            }
            if(i==n-1)
            {
                second=index;
            }
            if(currNode->left)
            {
                q.push({currNode->left,2*index});
            }
            if(currNode->right)
            {
                q.push({currNode->right,2*index+1});
            }
        }
        int width=second-first+1;
        ans=max(ans,width);
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
    
    cout<<widthOfBinaryTree(root);
    
    return 0;
}
