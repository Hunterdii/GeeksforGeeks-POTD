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
/*
  Node is defined as
struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }
}*head;
*/
1)
class Solution {
public:
    int count(Node* head, int key) {
        int count = 0;
        for (Node* current = head; current != nullptr; current = current->next) {
            count += (current->data == key);
        }
        return count;
    }
};
2)
class Solution {
public:
    int count(struct Node* head, int key) {
        int count = 0;
        while (head != NULL) {
            count += (head->data == key);
            head = head->next;
        }
        return count;
    }
};
3)
class Solution {
  public:
    int count(Node* head, int key) {
        int count = 0;
        while (head) { 
            if (head->data == key)
                ++count;
            head = head->next;
        }
        return count;
    }
};


4)
class Solution {
  public:
    int count(struct Node* head, int key) {
        struct Node* current = head;
        int count = 0;
        while (current != NULL) {
            if (current->data == key)
                count++;
            current = current->next;
        }
        return count;
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
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        int key;
        cin >> key;
        cin.ignore();
        Solution ob;
        cout << ob.count(head, key) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
