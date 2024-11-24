//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(struct Node **headRef, char data) {
    struct Node *new_node = new Node(data);
    struct Node *last = *headRef;

    if (*headRef == NULL) {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }

};
*/

class Solution
{
public:
    struct Node* arrangeCV(Node *head)
    {
        Node* dummy1 = new Node(-1); 
        Node* ptr1 = dummy1;
        Node* dummy2 = new Node(-1); 
        Node* ptr2 = dummy2;
        
        for (Node* curr = head; curr != nullptr; curr = curr->next) {
            char c = curr->data;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                ptr1->next = curr;
                ptr1 = ptr1->next;
            } else {
                ptr2->next = curr;
                ptr2 = ptr2->next;
            }
        }
        
        ptr1->next = dummy2->next;
        ptr2->next = nullptr;
        
        Node* newHead = dummy1->next;
        delete dummy1; 
        delete dummy2;
        
        return newHead;
    }
};



//{ Driver Code Starts.

// task is to complete this function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        char tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
    return 0;
}

// } Driver Code Ends
