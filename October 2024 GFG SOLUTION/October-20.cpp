//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// a node of the doubly linked list
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};


// } Driver Code Ends
// User function Template for C++

/*
// a node of the doubly linked list
class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;
    DLLNode(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Compare {
  public:
    bool operator()(DLLNode *a, DLLNode *b) {
        return a->data > b->data;
    }
};

class Solution {
  public:
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        if (!head) return nullptr;
        priority_queue<DLLNode *, vector<DLLNode *>, Compare> pq;
        DLLNode *newHead = nullptr, *last = nullptr;
        for (int i = 0; head != nullptr && i <= k; i++) {
            pq.push(head);
            head = head->next;
        }
        while (!pq.empty()) {
            if (newHead == nullptr) {
                newHead = pq.top();
                newHead->prev = nullptr;
                last = newHead;
            } else {
                last->next = pq.top();
                pq.top()->prev = last;
                last = pq.top();
            }
            pq.pop();
            if (head != nullptr) {
                pq.push(head);
                head = head->next;
            }
        }
        last->next = nullptr;
        return newHead;
    }
};


//{ Driver Code Starts.

// Function to insert a node at the end
// of the Doubly Linked List
void push(DLLNode **tailRef, int new_data) {
    // allocate node
    DLLNode *newNode = new DLLNode(new_data);

    // since we are adding at the end,
    // next is NULL
    newNode->next = NULL;

    newNode->prev = (*tailRef);

    // change next of tail node to new node
    if ((*tailRef) != NULL)
        (*tailRef)->next = newNode;

    (*tailRef) = newNode;
}

// Function to print nodes in a given doubly linked list
void printList(DLLNode *head) {
    // if list is empty
    if (head == NULL)
        return;

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

// Driver
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        int k;
        cin >> k;
        cin.ignore();

        DLLNode *head = new DLLNode(arr[0]);
        DLLNode *tail = head;

        // Check if the array is empty
        for (size_t i = 1; i < arr.size(); ++i) {
            push(&tail, arr[i]);
        }
        Solution obj;
        printList(obj.sortAKSortedDLL(head, k));
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends
