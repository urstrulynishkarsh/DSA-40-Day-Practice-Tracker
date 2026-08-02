#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class Solution {
public:
    Node* merge(Node* list1, Node* list2) {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        Node* dummy = new Node(-1);
        Node* temp = dummy;

        while (list1 && list2) {
            if (list1->data < list2->data) {
                temp->bottom = list1;
                list1 = list1->bottom;
            } else {
                temp->bottom = list2;
                list2 = list2->bottom;
            }

            temp = temp->bottom;
            temp->next = NULL;
        }

        while (list1) {
            temp->bottom = list1;
            temp = temp->bottom;
            list1 = list1->bottom;
            temp->next = NULL;
        }

        while (list2) {
            temp->bottom = list2;
            temp = temp->bottom;
            list2 = list2->bottom;
            temp->next = NULL;
        }

        return dummy->bottom;
    }

    Node* flatten(Node* head) {
        if (head == NULL || head->next == NULL)
            return head;

        head->next = flatten(head->next);

        return merge(head, head->next);
    }
};

// Function to take input
Node* takeInput() {
    int n;
    cout << "Enter number of horizontal lists: ";
    cin >> n;

    Node* head = NULL;
    Node* prevHead = NULL;

    for (int i = 0; i < n; i++) {
        int m;
        cout << "Enter size of list " << i + 1 << ": ";
        cin >> m;

        Node* verticalHead = NULL;
        Node* verticalTail = NULL;

        cout << "Enter " << m << " sorted elements: ";

        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;

            Node* newNode = new Node(x);

            if (verticalHead == NULL) {
                verticalHead = newNode;
                verticalTail = newNode;
            } else {
                verticalTail->bottom = newNode;
                verticalTail = newNode;
            }
        }

        if (head == NULL) {
            head = verticalHead;
            prevHead = verticalHead;
        } else {
            prevHead->next = verticalHead;
            prevHead = verticalHead;
        }
    }

    return head;
}

// Print original 2D linked list
void print2D(Node* head) {
    cout << "\nOriginal Linked List:\n";

    Node* row = head;

    while (row) {
        Node* col = row;

        while (col) {
            cout << col->data << " ";
            col = col->bottom;
        }

        cout << endl;
        row = row->next;
    }
}

// Print flattened linked list
void printFlatten(Node* head) {
    cout << "\nFlattened Linked List:\n";

    while (head) {
        cout << head->data << " ";
        head = head->bottom;
    }
    cout << endl;
}

int main() {

    Node* head = takeInput();

    print2D(head);

    Solution obj;

    head = obj.flatten(head);

    printFlatten(head);

    return 0;
}