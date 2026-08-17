#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Node{
    public:
    int val;
    Node *left,*right;

    Node(int val)
    {
        this->val=val;
        this->left=this->right=NULL;
    }
};



Node * build(vector<int>& preorder, int &index, long long mini, long long maxi)
    {
        if(index>=preorder.size())
        {
            return NULL;
        }
        Node *root=NULL;
        if(preorder[index]>mini && preorder[index]<maxi)
        {
            root=new Node(preorder[index++]);
            root->left=build(preorder,index,mini,root->val);
            root->right=build(preorder,index,root->val,maxi);
        }
        return root;
    }
    Node* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        return build(preorder,index,LONG_MIN,LONG_MAX);
    }

    void inorder(Node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main()
{

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> preorder(n);

    cout << "Enter preorder elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> preorder[i];
    }

    Node* root = bstFromPreorder(preorder);

    cout << "Inorder traversal: ";
    inorder(root);

    return 0;
}

