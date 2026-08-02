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
    Node *newNode = new Node(data);

    if(head == NULL)
    {
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
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
    while(head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Return node at given position (1-based)
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

// Create loop
void createLoop(Node *head, Node *tail, int pos)
{
    if(pos == 0)
        return;

    Node *loopNode = getNode(head, pos);

    if(loopNode == NULL)
    {
        cout << "Invalid Position!" << endl;
        return;
    }

    tail->next = loopNode;
}

int cycleStart(Node *head)
{
    Node *slow=head;
    Node *fast=head;
    while(fast != nullptr && fast->next != nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            slow=head;
            while(slow!=fast)
            {
                slow = slow->next;
                fast = fast->next;
            }

            return slow->data;
        }
    }
    return -1;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    cout << "Enter linked list (-1 to stop): ";
    takeInput(head, tail);

    int pos;
    cout << "Enter position to create loop (0 for no loop): ";
    cin >> pos;

    createLoop(head, tail, pos);

    cout << "Loop created successfully." << endl;

    cout<<cycleStart(head);
    
}