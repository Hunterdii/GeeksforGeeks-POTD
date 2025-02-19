//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}


// } Driver Code Ends
// Custom class for min heap

class Solution {
public:
    Node* mergeKLists(vector<Node*>& l) {
        auto c=[](Node* a,Node* b){return a->data>b->data;};
        priority_queue<Node*,vector<Node*>,decltype(c)> pq(c);
        for(auto x:l) if(x) pq.push(x);
        Node d(0),*t=&d;
        while(!pq.empty()){
            t->next=pq.top();t=pq.top();pq.pop();
            if(t->next) pq.push(t->next);
        }
        return d.next;
    }
};

2)
class Solution {
public:
    Node* mergeKLists(vector<Node*>& lists) {
        if (lists.empty()) return nullptr;
        while (lists.size() > 1) {
            vector<Node*> temp;
            for (int i = 0; i < lists.size(); i += 2) 
                temp.push_back(merge(lists[i], i + 1 < lists.size() ? lists[i + 1] : nullptr));
            lists = temp;
        }
        return lists[0];
    }

    Node* merge(Node* a, Node* b) {
        if (!a || !b) return a ? a : b;
        if (a->data > b->data) swap(a, b);
        a->next = merge(a->next, b);
        return a;
    }
};

3)
class Solution {
public:
    Node* mergeKLists(vector<Node*>& lists) {
        vector<int> v;
        for (auto l : lists) while (l) v.push_back(l->data), l = l->next;
        sort(v.begin(), v.end());
        Node d(0), *t = &d;
        for (int x : v) t->next = new Node(x), t = t->next;
        return d.next;
    }
};

4)
class Solution {
public:
    Node* merge(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;
        if (a->data < b->data) { a->next = merge(a->next, b); return a; }
        b->next = merge(a, b->next); return b;
    }
    
    Node* mergeKLists(vector<Node*>& lists) {
        if (lists.empty()) return nullptr;
        while (lists.size() > 1) {
            lists.push_back(merge(lists[0], lists[1]));
            lists.erase(lists.begin()), lists.erase(lists.begin());
        }
        return lists.front();
    }
};

//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->next = newNode;
                temp = temp->next;
            }
            v[i] = head->next;
        }

        Solution ob;
        Node* head = ob.mergeKLists(v);
        printList(head);
    }

    return 0;
}

// } Driver Code Ends
