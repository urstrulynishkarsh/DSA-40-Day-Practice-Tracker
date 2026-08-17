#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Node{
    public:
    int data;
    Node *left,*right;

    Node(int val)
    {
        this->data=val;
        this->left=this->right=NULL;
    }
};

Node *insertIntoBST(Node *root,int data)
{
    if(root==NULL)
    {
        root=new Node(data);
        return root;
         
    }
    if(root->data>data)
    {
        root->left=insertIntoBST(root->left,data);
    }
    else{
        root->right=insertIntoBST(root->right,data);
    }
    return root;
}

void takeinput(Node *&root)
{
    int data;
    cin>>data;
    while(data!=-1)
    {
        root=insertIntoBST(root,data);
        cin>>data;
    }

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



int KthSmallest(Node *root, int &k)
{
    if(root==NULL)
    {
        return -1;
    }
    int leftans=KthSmallest(root->left,k);
    if(leftans!=-1)
    {
        return leftans;
    }
    k--;
    if(k==0)
    {
        return root->data;
    }
    int rightans=KthSmallest(root->right,k);
    return rightans;
}
int main()
{
    Node *root=NULL;
    cout<<"Enter the data for Node: "<<endl;
    takeinput(root);
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    cout<<KthSmallest(root,k);
}