
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

 vector<int> bottomViewBT(Node *root) {
        // code here
        vector<int> ans;
        if(root==NULL)
        {
            return ans;
        }
        queue<pair<Node*,int> >q;
        q.push({root,0});
        map<int,int> mp;
        while(!q.empty())
        {
            Node *curr=q.front().first;
            int currHD=q.front().second;
            q.pop();
            
            mp[currHD]=curr->data;
            
            
            if(curr->left)
            {
                q.push({curr->left,currHD-1});
            }
            if(curr->right)
            {
                q.push({curr->right,currHD+1});
            }
        }
        for(auto it:mp)
        {
            ans.push_back(it.second);
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
    
    vector<int> ans=bottomViewBT(root);
    for(int val:ans)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}
