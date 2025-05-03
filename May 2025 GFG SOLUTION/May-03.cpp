//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

// User function Template for C++

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/

class Solution {
public:
    Node* primeList(Node* h) {
        int m = 0;
        for (auto p = h; p; p = p->next) m = max(m, p->val);
        vector<char> s(2*m+1, 1);
        s[0] = s[1] = 0;
        for (int i = 2; i*i <= 2*m; ++i)
            if (s[i])
                for (int j = i*i; j <= 2*m; j += i)
                    s[j] = 0;
        for (auto p = h; p; p = p->next) {
            int x = p->val, d = 0;
            while (1) {
                if (x-d > 1 && s[x-d]) { p->val = x-d; break; }
                if (x+d <= 2*m && s[x+d]) { p->val = x+d; break; }
                ++d;
            }
        }
        return h;
    }
};

2)
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i*i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}

class Solution {
public:
    Node* primeList(Node* h) {
        for (auto p = h; p; p = p->next) {
            int x = p->val, d = 0;
            while (true) {
                if (x-d > 1 && isPrime(x-d)) { p->val = x-d; break; }
                if (isPrime(x+d)) { p->val = x+d; break; }
                ++d;
            }
        }
        return h;
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

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.primeList(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
