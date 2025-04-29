//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends

/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/

class Solution {
  public:
    Node* segregate(Node* head) {
        int count[3] = {0};
        for (Node* curr = head; curr; curr = curr->next) count[curr->data]++;
        Node* curr = head;
        for (int i = 0; i < 3; i++)
            while (count[i]--) curr->data = i, curr = curr->next;
        return head;
    }
};


2)
class Solution {
  public:
    Node* segregate(Node* head) {
        Node *z = new Node(0), *o = new Node(0), *t = new Node(0);
        Node *zero = z, *one = o, *two = t, *curr = head;
        while (curr) {
            if (curr->data == 0) zero->next = curr, zero = curr;
            else if (curr->data == 1) one->next = curr, one = curr;
            else two->next = curr, two = curr;
            curr = curr->next;
        }
        zero->next = o->next ? o->next : t->next;
        one->next = t->next;
        two->next = nullptr;
        head = z->next;
        delete z, delete o, delete t;
        return head;
    }
};

3)
class Solution {
  public:
    Node* segregate(Node* head) {
        vector<int> A;
        for (Node* p = head; p; p = p->next) A.push_back(p->data);
        sort(A.begin(), A.end());
        Node* p = head; int i = 0;
        while (p) p->data = A[i++], p = p->next;
        return head;
    }
};

4)
class Solution {
  public:
    Node* segregate(Node* head) {
        if (!head) return head;
        Node* zeroD = new Node(0);
        Node* oneD = new Node(0);
        Node* twoD = new Node(0);
        Node *zero = zeroD, *one = oneD, *two = twoD;
        Node* curr = head;
        while (curr) {
            if (curr->data == 0) {
                zero->next = curr;
                zero = zero->next;
            } else if (curr->data == 1) {
                one->next = curr;
                one = one->next;
            } else {
                two->next = curr;
                two = two->next;
            }
            curr = curr->next;
        }
        zero->next = (oneD->next) ? oneD->next : twoD->next;
        one->next = twoD->next;
        two->next = nullptr;
        Node* newHead = zeroD->next;
        delete zeroD;
        delete oneD;
        delete twoD;

        return newHead;
    }
};



//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends
