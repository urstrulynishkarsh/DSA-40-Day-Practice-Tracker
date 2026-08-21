#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_map>
#include <functional>
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

Node *first=NULL;
Node *second=NULL;
Node *previ=NULL;


void recoverTree(Node *&root)
{
    function<void(Node*)>inorder=[&](Node *root)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->left);

        if(previ!=NULL && previ->data>root->data)
        {
            if(first==NULL)
            {
                first=previ;
            }
            second=root;
        }

        previ=root;
        inorder(root->right);
    };
    inorder(root);
    swap(first->data,second->data);
}

int main()
{
    Node *root=NULL;
    cout<<"Enter the data for Node: "<<endl;
    takeinput(root);
    recoverTree(root);
}