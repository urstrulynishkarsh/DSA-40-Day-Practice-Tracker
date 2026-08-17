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

class BSTIterator{
    public:
    stack<Node *> st;
    void leftpush(Node *root)
    {
        st.push(root);
        root=root->left;
    }

    BSTIterator(Node *root)
    {
        leftpush(root);
    }
    int next()
    {
        Node *curr=st.top();
        st.pop();
        if(curr->right)
        {
            leftpush(curr->right);
        }
        return curr->data;
    }

    bool hasnext()
    {
        return st.size()>0;
    }
};


int main()
{
    Node *root=NULL;

    cout << "Enter BST elements (-1 to stop): ";

    takeinput(root);

    BSTIterator it(root);

    cout << "BST in sorted order: ";

    while(it.hasnext())
    {
        cout << it.next() << " ";
    }

    return 0;
}