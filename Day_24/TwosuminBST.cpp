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


bool TwoSumBST(Node *root, int target)
{
    vector<int> ans;
    function<void(Node*)> inorder=[&](Node *root){
        if(root==NULL)
        {
            return;
        }
        inorder(root->left);
        ans.push_back(root->data);
        inorder(root->right);
    };
    inorder(root);
    int i=0;
    int j=ans.size()-1;
    while(i<j)
    {
        if(ans[i]+ans[j]<target)
        {
            i++;
        }
        else if(ans[i]+ans[j]>target)
        {
            j--;
        }
        else if(ans[i]+ans[j]==target)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    Node *root=NULL;
    cout<<"Enter the data for Node: "<<endl;
    takeinput(root);
    int target;
    cout<<"Enter the target: ";
    cin>>target;
    cout<<TwoSumBST(root,target);
}