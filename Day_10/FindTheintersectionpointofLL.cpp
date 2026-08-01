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

Node* getNode(Node *head, int pos)
{
    int cnt = 1;

    while(head != NULL && cnt < pos)
    {
        head = head->next;
        cnt++;
    }

    return head;
}

void createIntersection(Node *headA, Node *headB, int pos)
{
    Node *intersection = getNode(headA, pos);

    if(intersection == NULL)
    {
        cout << "Invalid Position!" << endl;
        return;
    }

    Node *temp = headB;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = intersection;
}

int length(Node *head)
    {
        int len=0;
        Node *temp=head;
        while(temp)
        {
            len++;
            temp=temp->next;
        }
        return len;
    }


Node *getIntersectionNode(Node *headA, Node *headB) {
    int len1=length(headA);
    int len2=length(headB);

    int count;
    if(len1<len2)
    {
        count=len2-len1;
        while(count--)
        {
            headB=headB->next;
        }
    }
    else{
        count=len1-len2;
        while(count--)
        {
            headA=headA->next;
        }
    }

     while(headA && headB)
        {
            if(headA==headB)
            {
                return headA;
            }
             headA=headA->next;
             headB=headB->next;
        }
        return NULL;


}
int main()
{
    Node *headA = NULL, *tailA = NULL;
    Node *headB = NULL, *tailB = NULL;

    cout << "Enter List A (-1 to stop): ";
    takeInput(headA, tailA);

    cout << "Enter List B (-1 to stop): ";
    takeInput(headB, tailB);

    int pos;
    cout << "Enter intersection position in List A: ";
    cin >> pos;

    createIntersection(headA, headB, pos);

    cout << "\nList A: ";
    print(headA);
    cout<<endl;

    cout << "List B: ";
    print(headB);
    cout<<endl;
    
   
    Node *result=getIntersectionNode(headA,headB);

    cout<<result->data;
}