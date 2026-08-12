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
Node* helper(vector<int>& inorder, vector<int>& postorder, int &index, int left, int right)
    {
        if(left>right)
        {
            return NULL;
        }
       
        Node *root=new Node(postorder[index]);
        int inorderindex=search(inorder, left,right,postorder[index]);
        index--;
        root->right=helper(inorder,postorder,index,inorderindex+1,right);
        root->left=helper(inorder,postorder,index,left,inorderindex-1);
        return root;
    }


int main()
{
    int n;
    cout<<"Enter the size of Array: ";
    cin>>n;
    vector<int> postorder(n);
    cout<<"Enter the element in the postorder array: ";
    for(int i=0;i<n;i++)
    {
        cin>>postorder[i];
    }
    vector<int> inorder(n);
    cout<<"Enter the element in the inorder array: ";
    for(int i=0;i<n;i++)
    {
        cin>>inorder[i];
    }
  
        int index=n-1;
        int left=0;
        int right=n-1;
        Node *root=helper(inorder,postorder,index,left,right);
    levelOrderTraversal(root);
    cout<<endl;
    return 0;
}
