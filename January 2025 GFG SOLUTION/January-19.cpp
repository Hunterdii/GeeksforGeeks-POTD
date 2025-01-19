//{ Driver Code Starts
// Initial Template for C++
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

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

class Solution {
 public:
  Node* rotate(Node* head, int k) {
    if (!head || !head->next || k == 0) {
      return head;
    }

    int len = 1;
    Node* tail = head;
    while (tail->next) {
      tail = tail->next;
      len++;
    }

    k %= len;

    if (k == 0) {
      return head;
    }

    Node* newTail = head;
    for (int i = 1; i < k; i++) { // LEFT rotation
      newTail = newTail->next;
    }

    Node* newHead = newTail->next;
    newTail->next = nullptr;
    tail->next = head;

    return newHead;
  }
};

2)
class Solution {
 public:
  Node* rotate(Node* head, int k) {
    if (!head || !head->next || !k) return head;
    int len = 1;
    Node* tail = head;
    while (tail->next) tail = tail->next, len++;
    k %= len;
    if (!k) return head;
    Node* newTail = head;
    for (int i = 1; i < k; i++) newTail = newTail->next;
    Node* newHead = newTail->next;
    newTail->next = nullptr;
    tail->next = head;
    return newHead;
  }
};
//{ Driver Code Starts.

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

        Node* head = nullptr;

        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
        cout << "~\n";
    }
    return 1;
}

// } Driver Code Ends
