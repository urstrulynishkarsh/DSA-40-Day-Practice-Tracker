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



Node *Predecessor(Node* root, int key)
    {
        Node *pred=0;
        Node *curr=root;
        while(curr)
        {
            if(curr->data<key)
            {
                pred=curr;
                curr=curr->right;
            }
            else{
                curr=curr->left;
            }
        }
        return pred;
    }
    Node *Sucessor(Node* root, int key)
    {
        Node *succ=0;
        Node *curr=root;
        while(curr)
        {
            if(curr->data>key)
            {
                succ=curr;
                curr=curr->left;
            }
            else{
                
                curr=curr->right;
            }
        }
        return succ;
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node * pred=Predecessor(root,key);
        Node *succ=Sucessor(root,key);
        return {pred,succ};
    }
int main()
{
    Node *root = NULL;

    cout << "Enter the data for Node: ";
    takeinput(root);

    int key;
    cout << "Enter the key: ";
    cin >> key;

    vector<Node*> result = findPreSuc(root, key);

    if(result[0] != NULL)
        cout << "Predecessor: " << result[0]->data << endl;
    else
        cout << "Predecessor: -1" << endl;

    if(result[1] != NULL)
        cout << "Successor: " << result[1]->data << endl;
    else
        cout << "Successor: -1" << endl;

    return 0;
}