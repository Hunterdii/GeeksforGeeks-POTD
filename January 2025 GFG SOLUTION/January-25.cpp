//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void loopHere(Node *head, Node *tail, int position) {
    if (position == 0)
        return;

    Node *walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}


// } Driver Code Ends
// User function Template for C++

/*struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
// class Solution {
// public:
//     Node* findFirstNode(Node* head) {
//         Node *slow = head, *fast = head;
//         while (fast && fast->next) {
//             slow = slow->next;
//             fast = fast->next->next;
//             if (slow == fast) {
//                 slow = head;
//                 while (slow != fast) {
//                     slow = slow->next;
//                     fast = fast->next;
//                 }
//                 return slow;
//             }
//         }
//         return nullptr;
//     }
// };

class Solution {
public:
    Node* findFirstNode(Node* head) {
        Node *slow = head, *fast = head;
        while (fast && fast->next) {
            if ((slow = slow->next) == (fast = fast->next->next)) {
                for (slow = head; slow != fast; slow = slow->next, fast = fast->next);
                return slow;
            }
        }
        return nullptr;
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
        while (ss >> number) {
            arr.push_back(number);
        }
        int k;
        cin >> k;
        cin.ignore();
        assert(k <= arr.size());
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        loopHere(head, tail, k);

        Solution ob;
        Node *ans = ob.findFirstNode(head);
        cout << (ans == NULL ? -1 : ans->data) << "\n";
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends
