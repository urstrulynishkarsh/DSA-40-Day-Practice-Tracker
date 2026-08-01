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


Node *tortoiseAlgo(Node *&head)
{
    Node *fast=head;
    Node *slow=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next;
        if(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
    }
    return slow;
}
Node *reverse(Node *&head)
{
    Node*curr=head;
    Node *prev=NULL;
    while(curr)
    {
        Node*temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}

bool checkPalindrome(Node *head)
{
    if(head == NULL || head->next == NULL)
        return true;

    Node *mid=tortoiseAlgo(head);
    Node *secondHalf = reverse(mid->next);
    mid->next = secondHalf;
    Node *first=head;
    Node *second=secondHalf;
    while(first!=NULL && second!=NULL)
    {
        if(first->data!=second->data)
            return false;

        first=first->next;
        second=second->next;
    }
    return true;
    
}
int main()
{
    Node *head=NULL;
    Node *tail=NULL;

    cout << "Enter linked list (-1 to stop): ";
    takeInput(head, tail);
    print(head);
    cout<<endl;
    
    
    cout<<checkPalindrome(head);

    // print(head);
}