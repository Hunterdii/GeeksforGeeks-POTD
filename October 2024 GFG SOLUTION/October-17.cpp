//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
public:
    vector<Node*> alternatingSplitList(Node* head) {
        if (head == NULL) return {NULL, NULL}; 

        Node* a_head = nullptr; 
        Node* b_head = nullptr; 
        Node* a_tail = nullptr; 
        Node* b_tail = nullptr; 
        Node* current = head; 

        while (current != NULL) {
            if (a_head == nullptr) {
                a_head = new Node(current->data);
                a_tail = a_head; 
            } else {
                a_tail->next = new Node(current->data);
                a_tail = a_tail->next; 
            }
            current = current->next;

            if (current != NULL) {
                if (b_head == nullptr) {
                    b_head = new Node(current->data);
                    b_tail = b_head; 
                } else {
                    b_tail->next = new Node(current->data);
                    b_tail = b_tail->next; 
                }
                current = current->next;
            }
        }
        return {a_head, b_head}; 
    }
};

//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

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

        while (ss >> number) {
            arr.push_back(number);
        }

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends
