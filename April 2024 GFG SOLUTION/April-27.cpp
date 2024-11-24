//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next, *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};


// } Driver Code Ends

/* Structure of the node of the list is as
struct Node
{
    int data;
    struct Node *next, *prev;
    Node (int x){
        data = x;
        next = prev = NULL;
    }
};
*/


class Solution {
public:
    struct Node* mergeSort(struct Node* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        struct Node* mid = getMid(head);
        struct Node* nextToMid = mid->next;
        mid->next = nullptr;
        nextToMid->prev = nullptr;

        struct Node* left = mergeSort(head);
        struct Node* right = mergeSort(nextToMid);

        return merge(left, right);
    }

    struct Node* merge(struct Node* left, struct Node* right) {
        if (left == nullptr) {
            return right;
        }
        if (right == nullptr) {
            return left;
        }

        struct Node* result = nullptr;
        if (left->data <= right->data) {
            result = left;
            result->next = merge(left->next, right);
            if (result->next) {
                result->next->prev = result;
            }
        } else {
            result = right;
            result->next = merge(left, right->next);
            if (result->next) {
                result->next->prev = result;
            }
        }

        return result;
    }

    struct Node* getMid(struct Node* head) {
        struct Node* slow = head;
        struct Node* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    struct Node* sortDoubly(struct Node* head) {
        return mergeSort(head);
    }
};



//{ Driver Code Starts.

void insert(struct Node **head, int data) {
    struct Node *temp = new Node(data);
    if (!(*head))
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

void print(struct Node *head) {
    struct Node *temp = head;
    while (head) {
        cout << head->data << ' ';
        temp = head;
        head = head->next;
    }
    cout << endl;
    while (temp) {
        cout << temp->data << ' ';
        temp = temp->prev;
    }
    cout << endl;
}

// Utility function to swap two integers
void swap(int *A, int *B) {
    int temp = *A;
    *A = *B;
    *B = temp;
}

// Driver program
int main(void) {
    long test;
    cin >> test;
    while (test--) {
        int n, tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            insert(&head, tmp);
        }
        Solution ob;
        head = ob.sortDoubly(head);
        print(head);
    }
    return 0;
}

// } Driver Code Ends
