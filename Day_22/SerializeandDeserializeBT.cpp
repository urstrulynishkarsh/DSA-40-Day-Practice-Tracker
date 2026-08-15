
#include<iostream>
#include<vector>
#include <sstream>
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



class Codec{
    public:
        string seralize(Node *root)
        {
            if(root==NULL)
            {
                return "null ";
            }
            return to_string(root->data)+" "
            + seralize(root->left)
            +seralize(root->right);
        }

        Node * rebuild(istringstream &ss)
        {
            string s;
            ss>>s;
            if(s=="null")
            {
                return NULL;
            }
            Node *curr=new Node(stoi(s));
            curr->left=rebuild(ss);
            curr->right=rebuild(ss);
            return curr;
        }

        Node *deserialize(string &data)
        {
            if(data.empty())
            {
                return NULL;
            }
            istringstream ss(data);
            return rebuild(ss);
        }
};
// Inorder traversal to verify the tree
void inorder(Node* root) {
    if(root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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

    Codec codec;

    // Serialize
    string data = codec.seralize(root);

    cout << "\nSerialized tree: ";
    cout << data << endl;

    // Deserialize
    Node* newRoot = codec.deserialize(data);

    // Verify reconstructed tree
    cout << "Inorder of deserialized tree: ";
    inorder(newRoot);
    cout << endl;

    return 0;
   
}
