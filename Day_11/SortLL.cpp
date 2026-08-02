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

Node *tortoiseAlgo(Node *head)
{
    Node *slow=head;
    Node *fast = head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

Node *Merge(Node *list1,Node *list2)
{
    if(list1==NULL)
    {
        return list2;
    }
    if(list2==NULL)
    {
        return list1;
    }
    if(list1==NULL && list2==NULL)
    {
        return NULL;
    }
    Node *result=new Node(-1);
    Node *temp=result;
    while(list1 && list2)
    {
        if(list1->data<list2->data)
        {
            temp->next=list1;
            list1=list1->next;
        }
        else{
            temp->next=list2;
            list2=list2->next;
        }
        temp=temp->next;
    }
    while(list1)
    {
        temp->next=list1;
            list1=list1->next;
            temp=temp->next;
    }
    while(list2)
    {
        temp->next=list2;
            list2=list2->next;
            temp=temp->next;

    }
    return result->next;

}
Node *sortList(Node *head)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->next==NULL)
    {
        return head;
    }
    Node *mid=tortoiseAlgo(head);
    Node *list2=mid->next;
    mid->next=NULL;
    Node *list1=head;
    list1=sortList(list1);
    list2=sortList(list2);
    Node *merge=Merge(list1,list2);
    return merge;


}

int main()
{
    Node *head=NULL;
    Node *tail=NULL;

    cout << "Enter linked list (-1 to stop): ";
    takeInput(head, tail);
    print(head);
    cout<<endl;
    

    Node *result=sortList(head);

    print(result);
}