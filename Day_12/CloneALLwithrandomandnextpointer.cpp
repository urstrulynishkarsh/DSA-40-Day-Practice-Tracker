#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int x) {
        val = x;
        next = NULL;
        random = NULL;
    }
};

Node *helper(unordered_map<Node*,Node*> &hashmap,Node *head)
{
    if(head==NULL)
    {
        return NULL;
    }
    Node *newnode=new Node(head->val);
    hashmap[head]=newnode;
    newnode->next=helper(hashmap,head->next);
    if(head->random)
    {
        newnode->random=hashmap[head->random];
    }
    return newnode;

}
Node *CopyRandomList(Node *head)
{
    unordered_map<Node*,Node*> hashmap;
    return helper(hashmap,head);
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<Node*> nodes(n);
    vector<int> randomIndex(n);

    // Read values and create nodes
    cout << "Enter value and random index (-1 for NULL):\n";
    for (int i = 0; i < n; i++) {
        int value, idx;
        cin >> value >> idx;

        nodes[i] = new Node(value);
        randomIndex[i] = idx;
    }

    // Connect next pointers
    for (int i = 0; i < n - 1; i++) {
        nodes[i]->next = nodes[i + 1];
    }

    // Connect random pointers
    for (int i = 0; i < n; i++) {
        if (randomIndex[i] != -1)
            nodes[i]->random = nodes[randomIndex[i]];
    }

    Node* head = nodes[0];

    // Print the linked list
    cout << "\nLinked List:\n";
    Node* temp = head;
    while (temp) {
        cout << "Value: " << temp->val << " Random: ";
        if (temp->random)
            cout << temp->random->val;
        else
            cout << "NULL";
        cout << endl;
        temp = temp->next;
    }

    Node *result=CopyRandomList(head);
}