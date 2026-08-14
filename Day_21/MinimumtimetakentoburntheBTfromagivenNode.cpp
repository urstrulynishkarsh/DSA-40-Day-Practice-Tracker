
#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include<unordered_set>
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

void makeGraph(unordered_map<int,vector<int> > adj,int parent,Node *root)
{
    if(root==NULL)
    {
        return;
    }
    if(parent!=-1)
    {
        adj[root->data].push_back(parent);
    }
    if(root->left)
    {
        adj[root->data].push_back(root->left->data);
    }
    if(root->right)
    {
        adj[root->data].push_back(root->right->data);
    }
    makeGraph(adj,root->data,root->left);
    makeGraph(adj,root->data,root->right);
}

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

int BurnTree(Node *root, int start)
{
    unordered_map<int,vector<int> > adj;
    int parent=-1;
    makeGraph(adj,parent,root);
    queue<int>Q;
    unordered_set<int> visited;
    Q.push(start);
    visited.insert(start);
    int minutes=0;
    while(!Q.empty())
    {
        int n=Q.size();
        while(n--)
        {
            int curr=Q.front();
            Q.pop();
            for(int &nbr:adj[curr])
            {
                if(visited.find(nbr)==visited.end())
                {
                    Q.push(nbr);
                    visited.insert(nbr);
                }
            }
        }
        minutes++;
    }
    return minutes-1;

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
    int start;
    cout<<"Enter valid start value: ";
    cin>>start;
    cout<<BurnTree(root,start);
    
    return 0;
}
