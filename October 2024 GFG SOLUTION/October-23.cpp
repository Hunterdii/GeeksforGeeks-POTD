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


// } Driver Code Ends

class Solution {
public:
    int sumOfLastN_Nodes(struct Node* head, int n) {
        if (n <= 0 || head == NULL) return 0;

        Node* fast = head;
        Node* slow = head;

        for (int i = 0; i < n; i++) {
            if (fast == NULL) return 0; 
            fast = fast->next;
        }

        int sum = 0;
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        while (slow != NULL) {
            sum += slow->data;
            slow = slow->next;
        }

        return sum;
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
        int n;
        cin >> n;
        cin.ignore();
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution ob;
        cout << ob.sumOfLastN_Nodes(head, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
