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


Node *segregate(Node *&head)
{
    int zerocount=0;
    int onecount=0;
    int twocount=0;
    Node *temp=head;
    while(temp!=NULL)
    {
        if(temp->data==0)
        {
            zerocount++;
        }
        else if(temp->data==1)
        {
            onecount++;
        }
        else if(temp->data==2)
        {
            twocount++;
        }
        temp=temp->next;
    }
    temp=head;
    while(zerocount--)
    {
        temp->data=0;
        temp=temp->next;
    }
    while(onecount--)
    {
        temp->data=1;
        temp=temp->next;
    }
    while(twocount--)
    {
        temp->data=2;
        temp=temp->next;
    }
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
    

    Node *result=segregate(head);

    print(result);
}