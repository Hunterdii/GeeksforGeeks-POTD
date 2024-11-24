//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
public:
    Node *reverse(Node *head)
    {
        Node *prev = NULL;
        Node *current = head;
        Node *next;

        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }

    struct Node *addTwoLists(struct Node *num1, struct Node *num2)
    {
      
        num1 = reverse(num1);
        num2 = reverse(num2);

        Node *sum = NULL;
        int carry = 0;

        while (num1 != NULL || num2 != NULL || carry != 0)
        {
            int newVal = carry;

            if (num1)
                newVal += num1->data;
            if (num2)
                newVal += num2->data;

           
            carry = newVal / 10;

            
            newVal = newVal % 10;

         
            Node *newNode = new Node(newVal);

           
            newNode->next = sum;

           
            sum = newNode;

            
            if (num1)
                num1 = num1->next;
            if (num2)
                num2 = num2->next;
        }

       
        while (sum != NULL && sum->data == 0)
        {
            Node *temp = sum->next;
            sum->next = NULL;
            delete (sum);
            sum = temp;
        }

        if (sum == NULL)
            return new Node(0);
        return sum;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends
