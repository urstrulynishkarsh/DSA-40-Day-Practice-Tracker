
#include<iostream>
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

class NodeData{
    public:
    int size;
    int minval;
    int maxval;
    bool validBST;

    NodeData(int size, int minval, int maxval,bool validBST)
    {
        this->size=size;
        this->minval=minval;
        this->maxval=maxval;
        this->validBST=validBST;
    }
};

NodeData *largestBST(Node *root, int &ans)
{
    if(root==NULL)
    {
        return new NodeData(0, INT_MAX, INT_MIN, true);
    }
    NodeData *leftAns=largestBST(root->left,ans);
    NodeData *rightAns=largestBST(root->right,ans);

    NodeData *currentNodeAns=new NodeData(0,0,0,false);

    if(leftAns->validBST && rightAns->validBST && root->data> leftAns->maxval && root->data<rightAns->minval)
    {
        currentNodeAns->validBST=true;
        currentNodeAns->size=leftAns->size+rightAns->size+1;
        currentNodeAns->minval=min(root->data,leftAns->minval);
        currentNodeAns->maxval=max(root->data,rightAns->maxval);
        ans=max(ans,currentNodeAns->size);
    }
    else{
        currentNodeAns->validBST=false;
        currentNodeAns->size=0;
        currentNodeAns->minval=INT_MIN;
        currentNodeAns->maxval=INT_MAX;
    }
    return currentNodeAns;
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
    int ans=0;
    largestBST(root,ans);
    cout<<ans;
    return 0;
}
