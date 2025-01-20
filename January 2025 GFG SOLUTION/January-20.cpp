//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << "\n~\n";
}

Node *insertSorted(Node *head, int data) {
    Node *new_node = new Node(data);
    if (!head || head->data >= data) {
        new_node->next = head;
        return new_node;
    }

    Node *current = head;
    while (current->next && current->next->data < data) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    return head;
}


// } Driver Code Ends
/* Link list Node
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
class Solution {
public:
    Node* sortedMerge(Node* head1, Node* head2) {
        Node dummy(0), *tail = &dummy;
        while (head1 && head2) {
            tail->next = (head1->data <= head2->data) ? head1 : head2;
            tail = tail->next;
            if (head1->data <= head2->data) head1 = head1->next;
            else head2 = head2->next;
        }
        tail->next = head1 ? head1 : head2;
        return dummy.next;
    }
};

2)
class Solution {
public:
    Node* sortedMerge(Node* head1, Node* head2) {
        if (!head1) return head2;
        if (!head2) return head1;
        if (head1->data <= head2->data) {
            head1->next = sortedMerge(head1->next, head2);
            return head1;
        }
        head2->next = sortedMerge(head1, head2->next);
        return head2;
    }
};

3)
class Solution {
public:
    Node* sortedMerge(Node* head1, Node* head2) {
        Node dummy(0), *tail = &dummy;
        for (; head1 && head2; tail = tail->next)
            tail->next = (head1->data <= head2->data) ? std::exchange(head1, head1->next) : std::exchange(head2, head2->next);
        tail->next = head1 ? head1 : head2;
        return dummy.next;
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n1, n2, tmp;
        Node *head1 = nullptr, *head2 = nullptr;
        string input1, input2;

        getline(cin, input1); // Read the entire line for the LL1 elements
        stringstream ss1(input1);
        while (ss1 >> tmp) {
            head1 = insertSorted(head1, tmp);
        }

        getline(cin, input2); // Read the entire line for the LL2 elements
        stringstream ss2(input2);
        while (ss2 >> tmp) {
            head2 = insertSorted(head2, tmp);
        }

        Solution obj;
        Node *head = obj.sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends
