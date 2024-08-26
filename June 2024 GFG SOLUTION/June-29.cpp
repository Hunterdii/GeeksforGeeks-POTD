//{ Driver Code Starts
#include <bits/stdc++.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

bool areIdentical(struct Node *head1, struct Node *head2);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n1, n2, tmp, d1, d2;
        struct Node *head1 = NULL, *tail1 = NULL;
        struct Node *head2 = NULL, *tail2 = NULL;
        cin >> n1;
        cin >> d1;
        head1 = new Node(d1);
        tail1 = head1;
        while (n1-- > 1) {
            cin >> tmp;
            tail1->next = new Node(tmp);
            tail1 = tail1->next;
        }
        cin >> n2;
        cin >> d2;
        head2 = new Node(d2);
        tail2 = head2;
        while (n2-- > 1) {
            cin >> tmp;
            tail2->next = new Node(tmp);
            tail2 = tail2->next;
        }

        areIdentical(head1, head2) ? cout << "true" << endl : cout << "false" << endl;
    }
    return 0;
}

// } Driver Code Ends


// Function to check whether two linked lists are identical or not
bool areIdentical(struct Node *head1, struct Node *head2) {
    while (head1 != NULL && head2 != NULL) {
        if (head1->data != head2->data)
            return false;
        head1 = head1->next;
        head2 = head2->next;
    }
    return (head1 == NULL && head2 == NULL);
}
