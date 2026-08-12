
#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;
typedef pair<int,int> pii;

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



vector<vector<int> > verticalOrderTraversal(Node *&root)
{   
    vector<vector<int> > ans;
    map<int,vector<pii> >mp;
    queue<pair<Node *,pii> >q;
    q.push({root,{0,0}});

    while(!q.empty())
    {
        Node *curr=q.front().first;
        int row=q.front().second.first;
        int col=q.front().second.second;
        q.pop();
        mp[row].push_back({col,curr->data});
        if(curr->left)
            {
                q.push({curr->left,{row+1,col-1}});
            }
            if(curr->right)
            {
                q.push({curr->right,{row+1,col+1}});
            }
    }

    for(auto it:mp)
    {
        sort(it.second.begin(),it.second.end());
        vector<int> temp;
        for(auto p:it.second)
        {
            temp.push_back(p.second);
        }
        ans.push_back(temp);
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
    
    vector<vector<int> > result=verticalOrderTraversal(root);
    for(auto row:result)
    {
        for(int col:row)
        {
            cout<<col<<" ";
        }
        cout<<endl;

    }
    return 0;
}
