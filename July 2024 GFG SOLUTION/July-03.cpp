//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
//Back-end complete function Template for C++
class Solution {
public:
    Node* removeAllDuplicates(Node* head) {
        if (!head) return nullptr;

        Node dummy(-1); 
        dummy.next = head;
        Node* prev = &dummy;
        Node* current = head;

        while (current) {
            bool isDuplicate = false;
            while (current->next && current->data == current->next->data) {
                current = current->next;
                isDuplicate = true;
            }
            if (isDuplicate) {
                prev->next = current->next; 
            } else {
                prev = prev->next;
            }
            current = current->next;
        }

        return dummy.next;
    }
};


//{ Driver Code Starts.
/* Function to print linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;

        cin >> N;

        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < N; i++) {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;
        head = ob.removeAllDuplicates(head);
        printList(head);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
