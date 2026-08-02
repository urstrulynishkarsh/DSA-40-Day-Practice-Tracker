#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node* &head, Node* &tail, int data)
{
    Node * newnode=new Node(data);
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
        return;
        
    }
    tail->next = newnode;
    tail = newnode;
}

void takeInput(Node* &head, Node* &tail)
{
    int data;
    cin >> data;

    while(data != -1)
    {
        insertAtTail(head, tail, data);
        cin >> data;
    }
}
void print(Node *head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}


int gelength(Node *&head)
{
    int len=0;
    Node *temp=head;
    while(temp!=NULL)
    {
        len++;
        temp=temp->next;
    }
    return len;
}

Node* reverseKGroup(Node *&head, int k)
{
    if(head==NULL)
    {
        return NULL;
    }
    int len=gelength(head);
    if(k>len)
    {
        return head;
    }
    Node *prev=NULL;
    Node *curr=head;
    Node *forward=curr;
    int count=0;
    while(count<k)
    {
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        count++;
    }
    if(forward!=NULL)
    {
        head->next=reverseKGroup(forward,k);
    }
    return prev;
}

int main()
{
    Node *head=NULL;
    Node *tail=NULL;

    cout << "Enter linked list (-1 to stop): ";
    takeInput(head, tail);
    print(head);
    cout<<endl;

    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    
    Node *result=reverseKGroup(head,k);

    print(result);
}