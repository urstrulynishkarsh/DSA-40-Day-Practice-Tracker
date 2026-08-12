#include<iostream>
#include <queue>
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


int search(vector<int> &inorder, int left, int right, int value)
{
    for(int i=left;i<=right;i++)
    {
        if(inorder[i]==value)
        {
            return i;
        }
    }
    return -1;
}
Node *treebuild(vector<int> &preorder,vector<int> &inorder, int &index, int left, int right)
{
    if(left>right)
    {
        return NULL;
    }
    Node *root=new Node(preorder[index]);
    int inorderindex=search(inorder,left,right,preorder[index]);
    index++;
    root->left=treebuild(preorder,inorder,index, left,inorderindex-1);
    root->right=treebuild(preorder,inorder,index,inorderindex+1,right);
    return root;
}


int main()
{
    int n;
    cout<<"Enter the size of Array: ";
    cin>>n;
    vector<int> preorder(n);
    cout<<"Enter the element in the preorder array: ";
    for(int i=0;i<n;i++)
    {
        cin>>preorder[i];
    }
    vector<int> inorder(n);
    cout<<"Enter the element in the inorder array: ";
    for(int i=0;i<n;i++)
    {
        cin>>inorder[i];
    }
    int index=0;
    int left=0;
    int right=inorder.size()-1;
    Node *root=treebuild(preorder,inorder,index,left,right);
    levelOrderTraversal(root);
    cout<<endl;
    return 0;
}
