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


Node *constructBST(vector<int> inorderVector,int s, int e)
{
    if(s>e)
    {
        return NULL;
    }
    int mid=s+(e-s)/2;
    Node * root=new Node(inorderVector[mid]);
    root->left=constructBST(inorderVector,s,mid-1);
    root->right=constructBST(inorderVector,mid+1,e);
    return root;
}

// Preorder traversal
void preorder(Node *root)
{
    if(root == NULL)
    {
        return;
    }

    cout << root->data << " ";

    preorder(root->left);
    preorder(root->right);
}

int main()
{
    Node *root=NULL;
    cout<<"Enter the data for Node: "<<endl;
    takeinput(root);
    vector<int> result=inorder(root);

    Node *head=constructBST(result,0,result.size()-1);

    cout << "Preorder of Balanced BST: ";

    preorder(head);

    return 0;

}