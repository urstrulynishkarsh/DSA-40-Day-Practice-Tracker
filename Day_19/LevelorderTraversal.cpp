
#include<iostream>
#include<queue>
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



void levelOrderTraversal(Node *&root)
{   
    if(root==NULL)
    {
        return;
    }
    queue<Node*> q;
    q.push(root);
    // q.push(NULL);
    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            Node *temp=q.front();
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
        cout<<endl;
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
    
    levelOrderTraversal(root);
  
    return 0;
}
