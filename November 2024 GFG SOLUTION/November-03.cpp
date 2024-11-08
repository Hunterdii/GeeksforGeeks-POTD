//{ Driver Code Starts
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <ios>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

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
1)
class Solution {
  public:
    bool isLengthEven(struct Node **head) {
        Node *current = *head;
        int count = 0;

        while (current != NULL) {
            count++;
            current = current->next;
        }

        return (count % 2 == 0);
    }
};

2)
class Solution {
  public:
    bool isLengthEven(struct Node **head) {
        Node *fast = *head;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
        }

        return (fast == NULL);
    }
};

3)
class Solution {
  public:
    bool isLengthEven(struct Node **head) {
        struct Node *curr = *head, *t;
        while (curr &&
               curr->next) 
        {
            curr = curr->next->next; 
        }
        if (!curr) 
            return true; 
        return false;    
    }
};




//{ Driver Code Starts.

/* Function to print nodes in a given linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
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

        if (arr.empty()) {
            cout << "empty" << endl;
            continue;
        }

        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution ob;
        if (ob.isLengthEven(&head))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        // Clean up the remaining nodes to avoid memory leaks
        while (head != NULL) {
            struct Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    return 0;
}

// } Driver Code Ends
