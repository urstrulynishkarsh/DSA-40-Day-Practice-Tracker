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

Node *deleteMiddleNode(Node *head)
{
    if (head == NULL)
        return NULL;

    if( head->next == NULL)
        return NULL;
    
    Node *slow=head;
    Node *fast=head;
    Node *prev=NULL;
    while(fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next;
        }
    }
    prev->next=slow->next;
    delete slow;
    return head;

}


int main()
{
    Node *head=NULL;
    Node *tail=NULL;

    cout << "Enter linked list (-1 to stop): ";
    takeInput(head, tail);
    print(head);
    cout<<endl;
    

    Node *result=deleteMiddleNode(head);

    print(result);
}